using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace Harmony
{
    /// <summary>
    /// Signature de toute fonction désirant être notifié d'un chargement d'activité.
    /// </summary>
    public delegate void ActivityLoadingEventHandler();

    /// <summary>
    /// Représente une pile d'<see cref="Activity"/>. Permet de démarer/arrêter/redémarer des activités.
    /// </summary>
    [AddComponentMenu("Game/Activity/ActivityStack")]
    public class ActivityStack : Script
    {
        private readonly Stack<StackedActivity> activityStack;
        private readonly Stack<StackedMenu> menuStack;

        /// <summary>
        /// Événement déclanché lorsque le chargement d'une activité débute.
        /// </summary>
        public event ActivityLoadingEventHandler OnActivityLoadingStarted;

        /// <summary>
        /// Événement déclanché lorsque le chargement des activités est terminé. Autrement dit, il n'y
        /// aucune activité en cours de chargement.
        /// </summary>
        public event ActivityLoadingEventHandler OnActivityLoadingEnded;

        /// <summary>
        /// Crée un nouveau ActivityStack vide.
        /// </summary>
        public ActivityStack()
        {
            activityStack = new Stack<StackedActivity>();
            menuStack = new Stack<StackedMenu>();
        }

        /// <summary>
        /// Démarre une activité et l'ajoute sur le dessus de la pile d'activités.
        /// </summary>
        /// <param name="activity">Activité à charger.</param>
        /// <remarks>
        /// <para>
        /// Seule l'activité sur le dessus de la pile est conservée. Autrement dit, s'il y a une activité en cours lors
        /// de l'appel à cette méthode, cette dernière est déchargée avant que la nouvelle soit chargée.
        /// </para>
        /// <para>
        /// Le chargement des Activités est asynchrone. Utilisez les évènements <see cref="OnActivityLoadingStarted"/>
        /// et <see cref="OnActivityLoadingEnded"/> pour être notifié du début et de la fin du chargement d'une activité.
        /// </para>
        /// <para>
        /// Au démarrage, IActivityStack cherche pour un <see cref="IActivityController"/> dans le GameObject supposé contenir
        /// le contrôleur de l'activité. S'il en trouve un, il appelle la méthode <see cref="IActivityController.OnCreate"/> dessus.
        /// </para>
        /// </remarks>
        public void StartActivity(Activity activity)
        {
            ValidateActivityBeforeStarting(activity);

            StartCoroutine(StartActivityProcedure(activity));
        }

#if UNITY_EDITOR

        /// <summary>
        /// Démarre une activité en assumant que cette dernière est déjà chargée.
        /// </summary>
        /// <param name="activity">Activité à démarrer</param>
        /// <remarks>
        /// Cette fonction ne devrait être utilisée que dans un cadre de développement et non pas dans un cadre de production.
        /// Elle est excessivement dangeureuse : À UTILISER AVEC PRÉCAUTION!
        /// </remarks>
        public void StartPreloadedActivity(Activity activity)
        {
            PushActivity(activity);

            StackedActivity currentActivity = GetCurrentActivity();
            currentActivity.Initialize();
            currentActivity.Start();
        }

#endif

        /// <summary>
        /// Redémarre l'activité courante, c'est-à-dire celle sur le dessus de la pile d'activités. 
        /// </summary>
        /// <remarks>
        /// <para>
        /// Rien ne se produit s'il n'y a aucune activité en cours.
        /// </para>
        /// <para>
        /// Le rechargement des Activités est asynchrone. Utilisez les évènements <see cref="OnActivityLoadingStarted"/> et 
        /// <see cref="OnActivityLoadingEnded"/> pour être notifié du début et de la fin du chargement asynchrone d'une activité.
        /// </para>
        /// <para>
        /// Au redémarrage, IActivityStack cherche pour un <see cref="IActivityController"/> dans le GameObject supposé contenir
        /// le contrôleur de l'activité. S'il en trouve un, il appelle la méthode <see cref="IActivityController.OnCreate"/> dessus.
        /// </para>
        /// </remarks>
        public void RestartCurrentActivity()
        {
            StartCoroutine(RestartCurrentActivityProcedure());
        }

        /// <summary>
        /// Arrête l'activité sur le dessus de la pile et la retire de la pile d'activités.
        /// La nouvelle activité sur le dessus de la pile se retrouve alors rechargée. 
        /// </summary>
        /// <remarks>
        /// <para>
        /// Si aucune activité est chargée, l'application est tout simplement arrêtée.
        /// </para>
        /// <para>
        /// Le déchargement des Activités est asynchrone. Utilisez les évènements <see cref="OnActivityLoadingStarted"/>
        /// et <see cref="OnActivityLoadingEnded"/> pour être notifié du début et de la fin du chargement d'une activité.
        /// </para>
        /// </remarks>
        public void StopCurrentActivity()
        {
            StartCoroutine(StopCurrentActivityProcedure());
        }

        /// <summary>
        /// Indique si, oui ou non, il y a une activité en cours.
        /// </summary>
        /// <returns>True s'il y a une activité en cours, false sinon.</returns>
        public bool HasActivityRunning()
        {
            return activityStack.Count > 0;
        }

        /// <summary>
        /// Démarre le fragment donné.
        /// </summary>
        /// <param name="fragment">Fragment à démarrer.</param>
        /// <remarks>
        /// <para>
        /// Rien ne se produit si le fragment est déjà démarré.
        /// </para>
        /// <para>
        /// Tous les GameObject à la racine du fragment sont activés, sauf si ces derniers était désactivés
        /// au moment de la désactivation du Fragment.
        /// </para>
        /// </remarks>
        public void StartFragment(Fragment fragment)
        {
            ValidateFragmentBeforeStarting(fragment);

            StartFragmentProcedure(fragment);
        }

        /// <summary>
        /// Arrête le fragment donné.
        /// </summary>
        /// <param name="fragment">Fragment à arrêter.</param>
        /// <remarks>
        /// <para>
        /// Rien ne se produit si le fragment est déjà arrêté.
        /// </para>
        /// <para>
        /// Tous les GameObject à la racine du fragment sont désactivés. Notez que tout nouveau GameObject ajouté à ce fragment
        /// après sa désactivation ne seront pas automatiquement désactivés.
        /// </para>
        /// </remarks>
        public void StopFragment(Fragment fragment)
        {
            ValidateFragmentBeforeStoping(fragment);

            StopFragmentProcedure(fragment);
        }

        /// <summary>
        /// Démarre le menu donné et l'ajoute sur le dessus de la pile de menus.
        /// </summary>
        /// <param name="menu">Menu à activer.</param>
        /// <param name="parameters">Paramêtres à envoyer au menu, si nécessaire.</param>
        /// <remarks>
        /// <para>
        /// Seul le menu sur le dessus de la pile est actif. Tous les menus sur la pile sont affichés en même temps.
        /// </para>
        /// <para>
        /// Pour qu'un menu puisse être démarré, ce dernier doit être chargé. Assurez-vous donc les menus 
        /// utilisés par l'activités soient chargés avant de les utiliser.
        /// </para>
        /// <para>
        /// Au démarrage d'un menu, IMenuStack cherche pour un <see cref="IMenuController"/> dans la scène
        /// du menu. S'il en trouve un, il appelle les méthodes <see cref="IMenuController.OnCreate"/> et 
        /// <see cref="IMenuController.OnResume"/> dessus.
        /// </para>
        /// <para>
        /// S'il y avait déjà un menu d'actif, IMenuStack appellera la méthode <see cref="IMenuController.OnPause"/> sur
        /// le contrôleur de l'ancien menu avant d'activer le nouveau menu.
        /// </para>
        /// </remarks>
        public void StartMenu(Menu menu, params object[] parameters)
        {
            ValidateMenuBeforeStarting(menu);

            StartMenuProcedure(menu, parameters);
        }

        /// <summary>
        /// Arrête le menu sur le dessus de la pile et la retire de la pile de menus.
        /// Le nouveau menu sur le dessus de la pile se retrouve alors activé, s'il y en a un. 
        /// </summary>
        /// <remarks>
        /// <para>
        /// Rien ne se produit s'il n'y a aucun menu actif.
        /// </para>
        /// <para>
        /// Lors de l'arrêt d'un menu, IMenuStack cherche pour un <see cref="IMenuController"/> dans la scène
        /// du menu. S'il en trouve un, il appelle les méthodes <see cref="IMenuController.OnPause"/> et 
        /// <see cref="IMenuController.OnStop"/> dessus.
        /// </para>
        /// <para>
        /// Si suivant le retrait du menu courant de la pile il existe toujours un menu dans cette pile, IMenuStack 
        /// appellera la méthode <see cref="IMenuController.OnResume"/> sur le contrôleur de ce menu.
        /// </para>
        /// </remarks>
        public void StopCurrentMenu()
        {
            StopCurrentMenuProcedure();
        }

        /// <summary>
        /// Indique si, oui ou non, il y a un menu en cours.
        /// </summary>
        /// <returns>True s'il y a un menu en cours, false sinon.</returns>
        public bool HasMenuRunning()
        {
            return menuStack.Count > 0;
        }

        private void ValidateActivityBeforeStarting(Activity activity)
        {
            //Create current scene name list for validations
            IList<string> currentSceneNames = new List<string>();
            if (HasActivityRunning())
            {
                currentSceneNames = GetCurrentActivity().GetScenes();
            }

            //Create new scene name list for validations
            IList<string> newSceneNames = activity.GetScenes();

            //Can't start Activity if it's already running.
            if (HasActivityRunning())
            {
                if (GetCurrentActivity().Is(activity))
                {
                    throw new Exception("Unable to start Activity : it is already running.");
                }
            }

#if UNITY_EDITOR
            //Can't start Activity if one of his scenes is not in the BuildSettings. Can only check this while in Editor.
            foreach (string sceneName in newSceneNames)
            {
                string scenePath = AssetsExtensions.FindScenePath(sceneName).Replace("\\", "/");

                bool founded = false;
                foreach (UnityEditor.EditorBuildSettingsScene scene in UnityEditor.EditorBuildSettings.scenes)
                {
                    if (scene.path == scenePath)
                    {
                        founded = true;
                        break;
                    }
                }

                if (!founded)
                {
                    throw new Exception("Unable to start Activity : scene named \"" + sceneName + "\" is not in the Unity BuildSettings. " +
                                        "Thus, Unity can't load it. To solve this, just click the \"Harmony/Generate Build Settings From Activities\" " +
                                        "and try again.");
                }
            }
#endif
            //Can't start an Activity if one of his scenes is already loaded and is not part of the current activity
            foreach (string sceneName in newSceneNames)
            {
                if (SceneManagerExtensions.IsSceneLoaded(sceneName) && !currentSceneNames.Contains(sceneName))
                {
                    throw new Exception("Unable to start Activity : scene named \"" + sceneName + "\" is already loaded and is not part of the " +
                                        "current Activity. You may have loaded it manually somewhere.");
                }
            }
        }

        private void ValidateMenuBeforeStarting(Menu menu)
        {
            //Can't start a menu if there's no activity running.
            if (!HasActivityRunning())
            {
                throw new Exception("Unable to start Menu : no Activity is currently running.");
            }

            //Can't start a menu if it's allways visible
            if (menu.IsAlwaysVisible())
            {
                throw new Exception("Unable to start Menu : it is allways visible.");
            }

            //Can't start menu if it's not part of the current activity.
            StackedActivity currentActivity = GetCurrentActivity();
            StackedMenu stackedMenu = currentActivity.GetMenu(menu);
            if (stackedMenu == null)
            {
                throw new Exception("Unable to start Menu : it is not part of the current Activity.");
            }

            //Can't start menu if it's allready started
            if (menuStack.Contains(stackedMenu))
            {
                throw new Exception("Unable to start Menu : it is already running.");
            }
        }

        private void ValidateFragmentBeforeStarting(Fragment fragment)
        {
            //Can't start a fragment if it's not part of the current activity.
            StackedActivity currentActivity = GetCurrentActivity();
            StackedFragment stackedFragment = currentActivity.GetFragment(fragment);
            if (stackedFragment == null)
            {
                throw new Exception("Unable to enable Fragment : it is not part of the current Activity.");
            }
        }

        private void ValidateFragmentBeforeStoping(Fragment fragment)
        {
            //Can't stop a fragment if it's not part of the current activity.
            StackedActivity currentActivity = GetCurrentActivity();
            StackedFragment stackedFragment = currentActivity.GetFragment(fragment);
            if (stackedFragment == null)
            {
                throw new Exception("Unable to disable Fragment : it is not part of the current Activity.");
            }
        }

        private void PushActivity(Activity activity)
        {
            activityStack.Push(new StackedActivity(activity));
        }

        private void PopActivity()
        {
            activityStack.Pop();
        }

        private void PushMenu(Menu menu)
        {
            StackedMenu stackedMenu = GetCurrentActivity().GetMenu(menu);
            menuStack.Push(stackedMenu);
        }

        private void PopMenu()
        {
            menuStack.Pop();
        }

        private StackedMenu GetCurrentMenu()
        {
            return menuStack.Peek();
        }

        private StackedActivity GetCurrentActivity()
        {
            return activityStack.Peek();
        }

        private IEnumerator StartActivityProcedure(Activity activity)
        {
            NotifyActivityLoadStart();

            if (HasActivityRunning())
            {
                yield return UnloadAndStopCurrentActivityProcedure();
            }

            PushActivity(activity);

            if (HasActivityRunning())
            {
                yield return LoadAndStartCurrentActivityProcedure();
            }

            NotifyActivityLoadEnd();
        }

        private IEnumerator RestartCurrentActivityProcedure()
        {
            NotifyActivityLoadStart();

            if (HasActivityRunning())
            {
                yield return UnloadAndStopCurrentActivityProcedure();
                yield return LoadAndStartCurrentActivityProcedure();
            }

            NotifyActivityLoadEnd();
        }

        private IEnumerator StopCurrentActivityProcedure()
        {
            NotifyActivityLoadStart();

            if (HasActivityRunning())
            {
                yield return UnloadAndStopCurrentActivityProcedure();
            }

            PopActivity();

            if (HasActivityRunning())
            {
                yield return LoadAndStartCurrentActivityProcedure();
            }

            if (!HasActivityRunning())
            {
                StopApplicationProcedure();
            }

            NotifyActivityLoadEnd();
        }

        private IEnumerator LoadAndStartCurrentActivityProcedure()
        {
            StackedActivity currentActivity = GetCurrentActivity();
            foreach (string scene in currentActivity.GetScenes())
            {
                yield return SceneManager.LoadSceneAsync(scene, LoadSceneMode.Additive);
            }

            menuStack.Clear();

            currentActivity.Initialize();
            currentActivity.Start();
        }

        private IEnumerator UnloadAndStopCurrentActivityProcedure()
        {
            menuStack.Clear();

            StackedActivity currentActivity = GetCurrentActivity();
            currentActivity.Stop();
            foreach (string scene in currentActivity.GetScenes())
            {
                if (SceneManagerExtensions.IsSceneLoaded(scene))
                {
                    yield return SceneManager.UnloadSceneAsync(scene);
                }
                else
                {
                    Debug.LogWarning("Problem while stopping current Activity : scene named \"" + scene + "\" is not loaded, but belongs to " +
                                     "the Activity being closed. You may have unloaded it manually somewhere.");
                }
            }
        }

        private void StartFragmentProcedure(Fragment fragment)
        {
            StackedActivity currentActivity = GetCurrentActivity();
            StackedFragment stackedFragment = currentActivity.GetFragment(fragment);
            stackedFragment.Start();
        }

        private void StopFragmentProcedure(Fragment fragment)
        {
            StackedActivity currentActivity = GetCurrentActivity();
            StackedFragment stackedFragment = currentActivity.GetFragment(fragment);
            stackedFragment.Stop();
        }

        private void StartMenuProcedure(Menu menu, params object[] parameters)
        {
            if (HasMenuRunning())
            {
                StackedMenu currentMenu = GetCurrentMenu();
                currentMenu.Pause();
            }

            PushMenu(menu);

            if (HasMenuRunning())
            {
                StackedMenu currentMenu = GetCurrentMenu();
                currentMenu.Start(menuStack.Count, parameters);
                currentMenu.Resume();
            }
        }

        private void StopCurrentMenuProcedure()
        {
            if (HasMenuRunning())
            {
                StackedMenu currentMenu = GetCurrentMenu();
                currentMenu.Pause();
                currentMenu.Stop();
            }

            PopMenu();

            if (HasMenuRunning())
            {
                StackedMenu currentMenu = GetCurrentMenu();
                currentMenu.Resume();
            }
        }

        private static void StopApplicationProcedure()
        {
#if UNITY_EDITOR
            UnityEditor.EditorApplication.isPlaying = false;
#else
            UnityEngine.Application.Quit();
#endif
        }

        private void NotifyActivityLoadStart()
        {
            if (OnActivityLoadingStarted != null) OnActivityLoadingStarted();
        }

        private void NotifyActivityLoadEnd()
        {
            if (OnActivityLoadingEnded != null) OnActivityLoadingEnded();
        }

        private sealed class StackedActivity
        {
            private readonly Activity activity;
            private readonly IList<StackedFragment> fragments;
            private readonly IList<StackedMenu> menus;

            private bool isRunning;
            private IActivityController controller;

            public StackedActivity(Activity activity)
            {
                this.activity = activity;
                fragments = new List<StackedFragment>();
                menus = new List<StackedMenu>();

                foreach (Fragment fragment in activity.Fragments)
                {
                    if (fragment != null)
                    {
                        fragments.Add(new StackedFragment(fragment));
                    }
                }

                foreach (Menu menu in activity.Menus)
                {
                    if (menu != null)
                    {
                        menus.Add(new StackedMenu(menu, activity.Menus.Count));
                    }
                }
            }

            public bool Is(Activity activity)
            {
                return this.activity == activity;
            }

            public IList<string> GetScenes()
            {
                return activity.GetScenes();
            }

            public StackedFragment GetFragment(Fragment fragment)
            {
                foreach (StackedFragment stackedFragment in fragments)
                {
                    if (stackedFragment.Is(fragment))
                    {
                        return stackedFragment;
                    }
                }
                return null;
            }

            public StackedMenu GetMenu(Menu menu)
            {
                foreach (StackedMenu stackedMenu in menus)
                {
                    if (stackedMenu.Is(menu))
                    {
                        return stackedMenu;
                    }
                }
                return null;
            }

            public void Initialize()
            {
                InitializeActivity();
                InitializeFragments();
                InitializeMenus();
            }

            public void Start()
            {
                if (!isRunning)
                {
                    StartActivity();
                    StartFragments();
                    StartMenus();

                    isRunning = true;
                }
            }

            public void Stop()
            {
                if (isRunning)
                {
                    StopMenus();
                    StopFragments();
                    StopActivity();

                    isRunning = false;
                }
            }

            private void InitializeActivity()
            {
                controller = null;
                isRunning = false;

                if (activity.Controller != R.E.GameObject.None)
                {
                    string gameObjectName = R.S.GameObject.ToString(activity.Controller);
                    GameObject gameObject = GameObject.Find(gameObjectName);

                    if (gameObject == null)
                    {
                        Debug.LogError("Unable to find controller for Activity : no GameObject of name \"" + gameObjectName + "\" found.");
                    }
                    else
                    {
                        controller = gameObject.GetComponentInChildren<IActivityController>();

                        if (controller == null)
                        {
                            Debug.LogError("Unable to find controller for Activity : no IActivityController exists on GameObject named " +
                                           "\"" + gameObjectName + "\".");
                        }
                    }
                }

                if (activity.Scene != R.E.Scene.None)
                {
                    SceneManager.SetActiveScene(SceneManager.GetSceneByName(R.S.Scene.ToString(activity.Scene)));
                }
            }

            private void InitializeFragments()
            {
                foreach (StackedFragment fragment in fragments)
                {
                    fragment.Initialize();
                }
            }

            private void InitializeMenus()
            {
                foreach (StackedMenu menu in menus)
                {
                    menu.Initialize();
                }
            }

            private void StartActivity()
            {
                if (controller != null)
                {
                    controller.OnCreate();
                }
            }

            private void StopActivity()
            {
                if (controller != null)
                {
                    controller.OnStop();
                }
            }

            private void StartFragments()
            {
                foreach (StackedFragment fragment in fragments)
                {
                    if (fragment.IsStartedOnLoad())
                    {
                        fragment.Start();
                    }
                }
            }

            private void StopFragments()
            {
                foreach (StackedFragment fragment in fragments)
                {
                    fragment.Stop();
                }
            }

            private void StartMenus()
            {
                int currentMenuIndex = 0;
                foreach (StackedMenu menu in menus)
                {
                    if (menu.IsAlwaysVisible())
                    {
                        menu.Start(currentMenuIndex);
                        menu.Resume();
                    }
                    currentMenuIndex++;
                }
            }

            private void StopMenus()
            {
                foreach (StackedMenu menu in menus)
                {
                    menu.Pause();
                    menu.Stop();
                }
            }
        }

        private sealed class StackedFragment
        {
            private readonly Fragment fragment;

            private bool isRunning;
            private readonly IList<GameObject> disabledGameObjects;
            private IFragmentController controller;

            public StackedFragment(Fragment fragment)
            {
                this.fragment = fragment;
                disabledGameObjects = new List<GameObject>();
            }

            public bool Is(Fragment fragment)
            {
                return this.fragment == fragment;
            }

            public bool IsStartedOnLoad()
            {
                return fragment.IsStartedOnLoad;
            }

            public void Initialize()
            {
                isRunning = false;
                disabledGameObjects.Clear();
                controller = null;

                if (fragment.Controller != R.E.GameObject.None)
                {
                    string gameObjectName = R.S.GameObject.ToString(fragment.Controller);
                    GameObject gameObject = GameObject.Find(gameObjectName);

                    if (gameObject == null)
                    {
                        Debug.LogError("Unable to find controller for Fragment : no GameObject of name \""
                                       + gameObjectName + "\" found.");
                    }
                    else
                    {
                        controller = gameObject.GetComponentInChildren<IFragmentController>();

                        if (controller == null)
                        {
                            Debug.LogError("Unable to find controller for Fragment : no IFragmentController exists on GameObject named " +
                                           "\"" + gameObjectName + "\".");
                        }
                    }
                }

                if (fragment.IsActiveOnLoad)
                {
                    SceneManager.SetActiveScene(SceneManager.GetSceneByName(R.S.Scene.ToString(fragment.Scene)));
                }               

                if (!IsStartedOnLoad())
                {
                    Disable();
                }
            }

            public void Start()
            {
                if (!isRunning)
                {
                    Enable();
                    if (controller != null)
                    {
                        controller.OnCreate();
                    }

                    isRunning = true;
                }
            }

            public void Stop()
            {
                if (isRunning)
                {
                    if (controller != null)
                    {
                        controller.OnStop();
                    }
                    Disable();

                    isRunning = false;
                }
            }

            private void Enable()
            {
                foreach (GameObject gameObject in disabledGameObjects)
                {
                    gameObject.SetActive(true);
                }
                disabledGameObjects.Clear();
            }

            private void Disable()
            {
                disabledGameObjects.Clear();
                foreach (GameObject gameObject in SceneManager.GetSceneByName(R.S.Scene.ToString(fragment.Scene)).GetRootGameObjects())
                {
                    if (gameObject.activeInHierarchy)
                    {
                        disabledGameObjects.Add(gameObject);
                        gameObject.SetActive(false);
                    }
                }
            }
        }

        private sealed class StackedMenu
        {
            private readonly Menu menu;
            private readonly int nbMenusTotal;

            private bool isRunning;
            private bool isShown;
            private Canvas canvas;
            private GameObject topParent;
            private IMenuController controller;

            public StackedMenu(Menu menu, int nbMenusTotal)
            {
                this.menu = menu;
                this.nbMenusTotal = nbMenusTotal;
            }

            public bool Is(Menu menu)
            {
                return this.menu == menu;
            }

            public bool IsAlwaysVisible()
            {
                return menu.IsAlwaysVisible();
            }

            public void Initialize()
            {
                isRunning = false;
                isShown = false;
                topParent = null;
                canvas = null;
                controller = null;

                try
                {
                    Scene scene = SceneManager.GetSceneByName(R.S.Scene.ToString(menu.Scene));
                    foreach (GameObject gameObject in scene.GetRootGameObjects())
                    {
                        canvas = gameObject.GetComponentInChildren<Canvas>();
                        if (canvas != null)
                        {
                            topParent = gameObject;
                            break;
                        }
                    }
                }
                catch (ArgumentException)
                {
                    Debug.LogError("Unable to find Canvas for Menu named \"" + menu.name + "\".");
                }

                if (canvas == null || topParent == null)
                {
                    Debug.LogError("Unable to find Canvas for Menu named \"" + menu.name + "\".");
                }

                if (menu.Controller != R.E.GameObject.None)
                {
                    string gameObjectName = R.S.GameObject.ToString(menu.Controller);
                    GameObject gameObject = GameObject.Find(gameObjectName);

                    if (gameObject == null)
                    {
                        Debug.LogError("Unable to find controller for Menu : no GameObject of name \""
                                       + gameObjectName + "\" found.");
                    }
                    else
                    {
                        controller = gameObject.GetComponentInChildren<IMenuController>();

                        if (controller == null)
                        {
                            Debug.LogError("Unable to find controller for Menu : no IMenuController exists " +
                                           "on GameObject named \"" + gameObjectName + "\".");
                        }
                    }
                }

                if (topParent != null && canvas != null)
                {
                    if (!IsAlwaysVisible())
                    {
                        topParent.SetActive(false);
                        canvas.sortingOrder = 0;
                    }
                }
            }

            public void Start(int orderInStack, params object[] parameters)
            {
                if (!isRunning)
                {
                    if (topParent != null && canvas != null)
                    {
                        topParent.SetActive(true);
                        canvas.sortingOrder = (menu.IsAlwaysVisible() ? 0 : nbMenusTotal) + orderInStack + 1;
                    }
                    if (controller != null)
                    {
                        controller.OnCreate(parameters);
                    }

                    isRunning = true;
                }
            }

            public void Resume()
            {
                if (!isShown)
                {
                    if (topParent != null && canvas != null)
                    {
                        topParent.SetActive(true);
                    }
                    if (controller != null)
                    {
                        controller.OnResume();
                    }

                    isShown = true;
                }
            }

            public void Pause()
            {
                if (isShown)
                {
                    if (topParent != null && canvas != null)
                    {
                        topParent.SetActive(false);
                    }
                    if (controller != null)
                    {
                        controller.OnPause();
                    }

                    isShown = false;
                }
            }

            public void Stop()
            {
                if (isRunning)
                {
                    if (topParent != null && canvas != null)
                    {
                        topParent.SetActive(false);
                        canvas.sortingOrder = 0;
                    }
                    if (controller != null)
                    {
                        controller.OnStop();
                    }

                    isRunning = false;
                }
            }
        }
    }
}