using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

namespace Harmony
{
    public static class BuildSettingsGenerator
    {
        [MenuItem("Harmony/Generate Build Settings From Activities", priority = 10)]
        public static void GenerateBuildSettings()
        {
            Configuration configuration = Configuration.Get();

            //This HashSet prevent from adding the same scene twice.
            HashSet<string> scenePaths = new HashSet<string>();

            //Add startup scene
            if (configuration.StartingScene != R.E.Scene.None)
            {
                string sceneName = R.S.Scene.ToString(configuration.StartingScene);
                string scenePath = AssetsExtensions.FindScenePath(sceneName);

                if (scenePath != null)
                {
                    scenePaths.Add(scenePath);
                }
                else
                {
                    Debug.LogError("The Starting Scene previously named \"" + sceneName + "\" seems to have been renamed or doesn't exist anymore. " +
                                   "Re-generate const classes with the \"Harmony/Generate Const Class\" menu and re-assign the" +
                                   "Starting Scene in the \"Harmony/Settings\" menu.");
                }
            }
            else
            {
                Debug.LogError("No scene configured as Starting Scene. Open \"Harmony/Settings\" to set it.");
            }

            //Add utilitary scenes
            foreach (R.E.Scene utilitaryScene in configuration.UtilitaryScenes)
            {
                string sceneName = R.S.Scene.ToString(utilitaryScene);
                string scenePath = AssetsExtensions.FindScenePath(sceneName);

                if (scenePath != null)
                {
                    scenePaths.Add(scenePath);
                }
                else
                {
                    Debug.LogError("The Utilitary Scene previously named \"" + sceneName + "\" seems to have been renamed or doesn't exist anymore. " +
                                   "To solve this problem, re-generate const classes with the \"Harmony/Generate Const Class\" menu " +
                                   "and re-assign the Starting Scene in the \"Harmony/Settings\" menu.");
                }
            }

            //Add Activity scenes
            foreach (Activity activity in AssetsExtensions.FindAssets<Activity>())
            {
                if (activity.Scene != R.E.Scene.None)
                {
                    string sceneName = R.S.Scene.ToString(activity.Scene);
                    string scenePath = AssetsExtensions.FindScenePath(sceneName);

                    if (scenePath != null)
                    {
                        scenePaths.Add(scenePath);
                    }
                    else
                    {
                        Debug.LogError("The Scene previously named \"" + sceneName + "\" in the Activity named \"" + activity.name + "\" " +
                                       "seems to have been renamed or doesn't exist anymore. To solve this problem, re-generate const classes " +
                                       "with the \"Harmony/Generate Const Class\" menu and re-assign the Scene in the Activity.");
                    }
                }

                foreach (Fragment fragment in activity.Fragments)
                {
                    if (fragment != null && fragment.Scene != R.E.Scene.None)
                    {
                        string sceneName = R.S.Scene.ToString(fragment.Scene);
                        string scenePath = AssetsExtensions.FindScenePath(sceneName);

                        if (scenePath != null)
                        {
                            scenePaths.Add(scenePath);
                        }
                        else
                        {
                            Debug.LogError("The Scene previously named \"" + sceneName + "\" in the Fragment named \"" + fragment.name + "\" " +
                                           "seems to have been renamed or doesn't exist anymore. To solve this problem, re-generate const classes " +
                                           "with the \"Harmony/Generate Const Class\" menu and re-assign the Scene in the Fragment.");
                        }
                    }
                }

                foreach (Menu menu in activity.Menus)
                {
                    if (menu != null && menu.Scene != R.E.Scene.None)
                    {
                        string sceneName = R.S.Scene.ToString(menu.Scene);
                        string scenePath = AssetsExtensions.FindScenePath(sceneName);

                        if (scenePath != null)
                        {
                            scenePaths.Add(scenePath);
                        }
                        else
                        {
                            Debug.LogError("The Scene previously named \"" + sceneName + "\" in the Menu named \"" + menu.name + "\" " +
                                           "seems to have been renamed or doesn't exist anymore. To solve this problem, re-generate const classes " +
                                           "with the \"Harmony/Generate Const Class\" menu and re-assign the Scene in the Menu.");
                        }
                    }
                }
            }

            //Set the Editor Build Settings
            List<EditorBuildSettingsScene> scenes = new List<EditorBuildSettingsScene>();
            foreach (string scenePath in scenePaths)
            {
                scenes.Add(new EditorBuildSettingsScene(scenePath, true));
            }
            EditorBuildSettings.scenes = scenes.ToArray();
        }
    }
}