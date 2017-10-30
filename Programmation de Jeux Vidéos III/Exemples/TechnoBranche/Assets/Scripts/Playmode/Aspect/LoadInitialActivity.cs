using System.Collections.Generic;
using Harmony;
using JetBrains.Annotations;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Aspect/LoadInitialActivity")]
    public class LoadInitialActivity : GameScript
    {
        [NotNull] [SerializeField] private Activity activity;

        private ActivityStack activityStack;

        private void InjectLoadInitialActivity([ApplicationScope] ActivityStack activityStack)
        {
            this.activityStack = activityStack;
        }

        protected void Awake()
        {
            InjectDependencies("InjectLoadInitialActivity");
        }

        private void Start()
        {
#if UNITY_EDITOR
            Activity currentPreloadedActivity = GetCurrentPreloadedActivityInEditor();
            if (currentPreloadedActivity != null)
            {
                activityStack.StartPreloadedActivity(currentPreloadedActivity);
            }
            else
            {
                if (SceneManager.sceneCount > 1)
                {
                    Debug.LogWarning("Are you trying to start the game without an activity ? " +
                                     "You have two options : load only the \"Main\" scene in the editor or load all the scenes " +
                                     "of an activity in the editor.");
                }
                activityStack.StartActivity(activity);
            }
#else
            activityStack.StartActivity(activity);
#endif
        }

#if UNITY_EDITOR
        private Activity GetCurrentPreloadedActivityInEditor()
        {
            IList<string> loadedScenes = SceneManagerExtensions.GetLoadedScenes();

            //Startup scene and Utilitary scenes should be ignored. They should not
            //be in any activity.
            Configuration configuration = Configuration.Get();
            loadedScenes.Remove(R.S.Scene.ToString(configuration.StartingScene));
            foreach (R.E.Scene scene in configuration.UtilitaryScenes)
            {
                loadedScenes.Remove(R.S.Scene.ToString(scene));
            }

            //If any activity scenes matches the currently loaded scenes, then this is
            //the current activity.
            foreach (Activity activity in AssetsExtensions.FindAssets<Activity>())
            {
                bool hasAllScenesLoaded = true;

                foreach (string scene in activity.GetScenes())
                {
                    hasAllScenesLoaded &= loadedScenes.Contains(scene);
                }

                if (hasAllScenesLoaded)
                {
                    return activity;
                }
            }
            return null;
        }
#endif
    }
}