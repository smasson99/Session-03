﻿using System;
using System.Collections.Generic;
using System.Reflection;
using JetBrains.Annotations;

namespace Harmony
{
    /// <summary>
    /// Permet d'injecter les dépendances d'un objet. 
    /// </summary>
    /// <remarks>
    /// <para>
    /// Les scripts d'un jeu interagissent énormément entre eux. Certains sont même dépendants de d'autres scripts pour fonctionner, et 
    /// c'est très bien ainsi. Cela respecte les principes de l'orienté objet.
    /// </para>
    /// <para>
    /// Cependant, le plus gros défit des systèmes orienté objets est justement la gestion de ces dépendances : plusieurs objets peuvent 
    /// dépendre du même objet, qui à son tour dépend peut-être de d'autres objets qui dependent eux même de d'autres objets et ainsi 
    /// de suite. Contruire le système devient alors très long et complexe, surtout s'il y a des dépendances cycliques.
    /// </para>
    /// <para>
    /// En général, dans un projet Unity, les scripts obtiennent leurs dépendances en appelant la méthode <i>GetComponent</i>
    /// ou l'une de ses variantes. Cette façon de faire est relativement simple du moment que l'on reste dans le même GameObject 
    /// (voir même ses parents ou ses enfants). Par exemple :
    /// </para>
    /// <code>
    /// public class PlayerMovement : MonoBehaviour
    /// {
    ///     [SerializeField]
    ///     private float speed = 100;
    ///     
    ///     private Rigidbody2D rigidbody2D;
    ///     
    ///     public void Awake()
    ///     {
    ///         rigidbody2D = GetComponent<Rigidbody2D>();
    ///     }
    ///     
    ///     private void Update()
    ///     {
    ///         if (Input.GetKey(Keycode.UpArrow) 
    ///         {
    ///             rigidbody2D.AddForce(transform.Up * speed * Time.DeltaTime);
    ///         }
    ///     }
    /// }
    /// </code>
    /// <para>
    /// Or, il est beaucoup plus compliqué d'obtenir une dépendance située dans un autre GameObject. Une des options est de 
    /// procéder ainsi : 
    /// </para>
    /// <code>
    /// public class PlayerMovement : MonoBehaviour
    /// {
    ///     [SerializeField]
    ///     private float speed = 100;
    ///     
    ///     private Rigidbody2D rigidbody2D;
    ///     private GameInput gameInput;
    ///     
    ///     public void Awake()
    ///     {
    ///         rigidbody2D = GetComponent<Rigidbody2D>();
    ///     
    ///         GameObject appGameObject = GameObject.Find("App");
    ///         gameInput = appGameObject.GetComponent<GameInput>();
    ///     
    ///         gameInput.OnFoward += OnFoward;
    ///     }
    ///     
    ///     private void OnFoward()
    ///     {
    ///         rigidbody2D.AddForce(transform.Up * speed * Time.DeltaTime);
    ///     }
    /// }
    /// </code>
    /// <para>
    /// Cependant, c'est long non seulement à écrire, mais aussi particulièrement risqué : l'objet peut ne pas exister, avoir changé 
    /// de place, de nom, etc. L'application devient alors sujette à des NullReferenceException, sans aucune explication. De plus, 
    /// cette façon de faire empêche tout test unitaire des scripts (ou du moins, rend la chose trop compliquée pour que ce soit 
    /// envisageable).
    /// </para>
    /// <para>
    /// La solution ici proposée est l'injection de dépendance, c'est-à-dire de laisser une tierce partie fournir les dépendances de chacun
    /// en fonction de leurs demandes et de leurs contraintes. Harmony fourni un tel système, spécifiquement adapté au besoins de Unity.
    /// </para>
    /// <para>
    /// Pour utiliser cette fonctionalité, il faut tout d'abord créer un <see cref="Injector"/> qui effectura l'injection. L'<see cref="Injector"/>
    /// doit être unique au sein de l'application et accessible en tout temps. C'est pourquoi c'est généralement une singleton.
    /// Par exemple :
    /// </para>
    /// <code>
    /// public class GameSingleton : Script
    /// {
    ///     private static GameSingleton gameSingleton;
    ///     private Injector injector;
    /// 
    ///     public static Injector GetInjector()
    ///     {
    ///         return gameSingleton.injector;
    ///     }
    /// 
    ///     public void Awake()
    ///     {
    ///         gameSingleton = this;
    /// 
    ///         injector = new Injector();
    ///     }
    /// }
    /// </code>
    /// <para>
    /// L'obtention de dépendances avec l'injection est assez simple : créez une méthode (souvent nommée <i>Inject</i>) dont les 
    /// paramètres représentent les dépendances. L'injecteur va alors trouver ces dépendances et les envoyer à l'objet en appellant
    /// cette méthode. N'oubliez pas de lui indiquer le nom de votre méthode d'injection.
    /// </para>
    /// <para>
    /// Il faut par contre dire à l'injecteur où trouver ces dépendances afin d'éviter toute abiguité. L'injection de dépendance est 
    /// donc basée sur le principe de portée (voir <see cref="Scope"/>) auquel on ajoute des filtres (voir 
    /// <see cref="Filter"/>). Il en existe plusieurs de prédéfinis, mais il est aussi possible d'en définir soit même
    /// en héritant de ces classes. Consultez leur documentation respective pour les détails.
    /// </para>
    /// <para>
    /// Vous obtenez alors ceci :
    /// </para>
    /// <code>
    /// public class PlayerMovement : MonoBehaviour
    /// {
    ///     [SerializeField]
    ///     private float speed = 100;
    ///     
    ///     private Rigidbody2D rigidbody2D;
    ///     private GameInput gameInput;
    /// 
    ///     public void InjectPlayerMovement([EntityScope] Rigidbody2D rigidbody2D,
    ///                                      [ApplicationScope] GameInput gameInput) 
    ///     {
    ///         this.rigidbody2D = rigidbody2D;
    ///         this.gameInput = gameInput;
    ///     }
    /// 
    ///     public void Awake()
    ///     {
    ///         GameSingleton.GetInjector().InjectDependencies(this, "InjectPlayerMovement");
    ///     }
    ///     
    ///     public void Start() 
    ///     {
    ///         gameInput.OnFoward += OnFoward;
    ///     }
    /// 
    ///     private void OnFoward()
    ///     {
    ///         rigidbody2D.AddForce(transform.Up * speed * Time.DeltaTime);
    ///     }
    /// }
    /// </code>
    /// <para>
    /// Vous pouvez aussi envoyer des valeurs comme dépendances, de cette façon :
    /// </para>
    /// <code>
    /// public class PlayerMovement : MonoBehaviour
    /// {
    ///     [SerializeField]
    ///     private float speed = 100;
    ///     
    ///     private Rigidbody2D rigidbody2D;
    ///     private GameInput gameInput;
    /// 
    ///     public void InjectPlayerMovement(float speed,
    ///                                      [EntityScope] Rigidbody2D rigidbody2D,
    ///                                      [ApplicationScope] GameInput gameInput) 
    ///     {
    ///         this.rigidbody2D = rigidbody2D;
    ///         this.gameInput = gameInput;
    ///     }
    /// 
    ///     public void Awake()
    ///     {
    ///         GameSingleton.GetInjector().InjectDependencies(this, "InjectPlayerMovement", speed);
    ///     }
    ///     
    ///     public void Start() 
    ///     {
    ///         gameInput.OnFoward += OnFoward;
    ///     }
    /// 
    ///     private void OnFoward()
    ///     {
    ///         rigidbody2D.AddForce(transform.Up * speed * Time.DeltaTime);
    ///     }
    /// }
    /// </code>
    /// <para>
    /// Votre méthode d'injection (ici nommée <i>InjectPlayerMovement</i>) devient alors une sorte de constructeur, ce qui, durant 
    /// les tests, est FORT pratique. Notez que <i>speed</i> est envoyé à la méthode <i>InjectDependencies</i> pour être injectée.
    /// </para>
    /// <para>
    /// Enfin, voici un exemple d'usage des filtres : 
    /// </para>
    /// <code>
    /// public class SampleBehaviour : Script
    /// {
    ///     private MyDependency myDeppendency;
    /// 
    ///     public void InjectSampleBehaviour([Named("SomeName")][EntityScope] MyDependency myDeppendency)
    ///     {
    ///         this.myDeppendency = myDeppendency;
    ///     }
    /// 
    ///     public void Awake()
    ///     {
    ///         GameSingleton.GetInjector().InjectDependencies(this, "InjectSampleBehaviour");
    ///     }
    /// }
    /// </code>
    /// </remarks>
    public class Injector
    {
        /// <summary>
        /// Injecte les dépendances du Script reçu en paramètre.
        /// </summary>
        /// <param name="target">
        /// Le Script où effectuer l'injection des dépendances.
        /// </param>
        /// <param name="injectMethodName">
        /// Nom de la méthode où l'injection doit être effectuée.
        /// </param>
        /// <remarks>
        /// Pour supporter les cas avec héritage, il est recommandé à ce que toutes les méthodes d'injection aient un nom unique.
        /// Ainsi, une classe "B" héritant d'une classe "A" peut elle aussi utiliser l'injection de dépendances sans risquer de 
        /// priver la classe "A" des dépendances dont elle a besoin.
        /// </remarks>
        public void InjectDependencies([NotNull] IScript target, [NotNull] string injectMethodName)
        {
            MethodInfo injectMethod = GetInjectMethod(target, injectMethodName);
            if (injectMethod != null)
            {
                try
                {
                    injectMethod.Invoke(target, GetDependenciesForTarget(target, injectMethod));
                }
                catch (TargetParameterCountException e)
                {
                    throw new ArgumentException(
                        "Parameters of \"" + injectMethodName +
                        "\" method does not correspond to what was received in the \"InjectDependencies\" method. Check their number.", e);
                }
                catch (ArgumentException e)
                {
                    throw new ArgumentException(
                        "Parameters of \"" + injectMethodName +
                        "\" method does not correspond to what was received in the \"InjectDependencies\" method. Check their types.", e);
                }
            }
            else
            {
                throw new ArgumentException("No inject method named \"" + injectMethodName + "\" found.");
            }
        }

        private static MethodInfo GetInjectMethod([NotNull] IScript target, [NotNull] string injectMethodName)
        {
            Type currentType = target.GetType();
            while (currentType != null)
            {
                MethodInfo injectMethod = currentType.GetMethod(injectMethodName, BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance);
                if (injectMethod != null)
                {
                    return injectMethod;
                }
                currentType = currentType.BaseType;
            }
            return null;
        }

        private static object[] GetDependenciesForTarget(IScript target,
                                                         MethodInfo injectMethod)
        {
            List<object> dependencies = new List<object>();
            foreach (ParameterInfo parameter in injectMethod.GetParameters())
            {
                dependencies.Add(GetDependencyForTarget(target, parameter));
            }
            return dependencies.ToArray();
        }

        private static object GetDependencyForTarget(IScript target, ParameterInfo dependencyParameter)
        {
            IList<object> dependencies = FilterDependencies(GetDependencies(target, dependencyParameter), dependencyParameter);

            if (dependencies.Count == 0)
            {
                throw new DependencyNotFoundException(target, dependencyParameter.ParameterType, GetScopeOf(dependencyParameter));
            }
            if (dependencies.Count > 1)
            {
                throw new MoreThanOneDependencyFoundException(target, dependencyParameter.ParameterType, GetScopeOf(dependencyParameter));
            }

            return dependencies[0];
        }

        private static IList<object> GetDependencies(IScript target, ParameterInfo dependencyParameter)
        {
            return GetScopeOf(dependencyParameter).GetDependencies(target, dependencyParameter.ParameterType);
        }

        private static IList<object> FilterDependencies(IList<object> dependencies, ParameterInfo dependencyParameter)
        {
            foreach (Filter filter in GetFiltersOf(dependencyParameter))
            {
                dependencies = filter.FilterDependencies(dependencies);
            }
            return dependencies;
        }

        private static Scope GetScopeOf(ParameterInfo parameter)
        {
            //Scope attribute is only allowed once, so it's safe to assume that if we find one, we get only one.
            foreach (object attribute in parameter.GetCustomAttributes(true))
            {
                if (attribute is Scope)
                {
                    return attribute as Scope;
                }
            }
            throw new Exception("Unable to inject dependency of type " + parameter.ParameterType.Name + " : it's not scoped.");
        }

        private static IList<Filter> GetFiltersOf(ParameterInfo parameter)
        {
            IList<Filter> filters = new List<Filter>();
            foreach (object attribute in parameter.GetCustomAttributes(true))
            {
                if (attribute is Filter)
                {
                    filters.Add(attribute as Filter);
                }
            }
            return filters;
        }
    }
}