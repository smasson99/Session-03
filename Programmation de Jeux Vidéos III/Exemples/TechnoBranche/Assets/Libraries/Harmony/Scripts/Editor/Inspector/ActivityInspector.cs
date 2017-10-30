using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;

namespace Harmony
{
    /// <summary>
    /// Inspecteur pour les Activités dans l'éditeur Unity.
    /// </summary>
    [CustomEditor(typeof(Activity), true)]
    public class ActivityInspector : Inspector
    {
        private Configuration configuration;
        private Activity activity;

        private EnumProperty scene;
        private EnumProperty controller;
        private ListProperty fragments;
        private ListProperty menus;

        protected override void Initialize()
        {
            configuration = Configuration.Get();
            activity = target as Activity;

            scene = GetEnumProperty("scene", typeof(R.E.Scene));
            controller = GetEnumProperty("controller", typeof(R.E.GameObject));
            fragments = GetListProperty("fragments");
            menus = GetListProperty("menus");
        }

        protected override void Draw()
        {
            DrawTitleLabel("Activity tools");

            bool hasStartupScene = configuration.StartingScene != R.E.Scene.None;
            if (!hasStartupScene)
            {
                DrawErrorBox("Cannot start an Activity without a Startup Scene. Please set one.");
                DrawButton("Open Configuration", ConfigurationInspector.OpenConfiguration);
            }

            if (!EditorApplication.isPlaying && hasStartupScene)
            {
                DrawButton("Open Activity", OpenActivityInEditor);
            }
            else
            {
                DrawDisabledButton("Open Activity");
            }

            DrawPropertyWithTitleLabel(scene);
            DrawPropertyWithTitleLabel(controller);
            DrawPropertyWithTitleLabel(fragments);
            DrawPropertyWithTitleLabel(menus);
        }

        private void OpenActivityInEditor()
        {
            if (configuration.StartingScene != R.E.Scene.None)
            {
                //Load starting scene. This scene is allways loaded.
                string sceneName = R.S.Scene.ToString(configuration.StartingScene);
                string scenePath = AssetsExtensions.FindScenePath(sceneName);

                if (scenePath != null)
                {
                    EditorSceneManager.OpenScene(scenePath, OpenSceneMode.Single);
                }
                else
                {
                    Debug.LogError("The Startup Scene named \"" + sceneName + "\" seems to have been renamed or doesn't exist anymore. You can't start " +
                                   "an activity without a Startup Scene on the project. To solve this problem, re-generate const classes " +
                                   "with the \"Harmony/Generate Const Class\" menu and re-assign the Startup Scene in the \"Harmony/Settings\" menu.");
                }

                //Load Activity scene
                if (activity.Scene != R.E.Scene.None)
                {
                    sceneName = R.S.Scene.ToString(activity.Scene);
                    scenePath = AssetsExtensions.FindScenePath(sceneName);
                    if (scenePath != null)
                    {
                        EditorSceneManager.OpenScene(scenePath, OpenSceneMode.Additive);
                    }
                    else
                    {
                        Debug.LogError("The Scene named \"" + sceneName + "\" of the activity you are trying to open " +
                                       "seems to have been renamed or doesn't exist anymore. To solve this problem, re-generate const classes " +
                                       "with the \"Harmony/Generate Const Class\" menu and re-assign the Scene in the Activity.");
                    }
                }

                //Load Activity fragments
                foreach (Fragment fragment in activity.Fragments)
                {
                    if (fragment != null && fragment.Scene != R.E.Scene.None)
                    {
                        sceneName = R.S.Scene.ToString(fragment.Scene);
                        scenePath = AssetsExtensions.FindScenePath(sceneName);
                        if (scenePath != null)
                        {
                            EditorSceneManager.OpenScene(scenePath, OpenSceneMode.Additive);
                        }
                        else
                        {
                            Debug.LogError("The Scene named \"" + sceneName + "\" of the Fragment named \"" + fragment.name +  "\" of the activity " +
                                           "you are trying to open seems to have been renamed or doesn't exist anymore. To solve this problem, " +
                                           "re-generate const classes with the \"Harmony/Generate Const Class\" menu and re-assign the Scene in " +
                                           "the Fragment.");
                        }
                    }
                }

                //Load Activity menus
                foreach (Menu menu in activity.Menus)
                {
                    if (menu != null && menu.Scene != R.E.Scene.None)
                    {
                        sceneName = R.S.Scene.ToString(menu.Scene);
                        scenePath = AssetsExtensions.FindScenePath(sceneName);
                        if (scenePath != null)
                        {
                            EditorSceneManager.OpenScene(scenePath, OpenSceneMode.Additive);
                        }
                        else
                        {
                            Debug.LogError("The Scene named \"" + sceneName + "\" of the Menu named \"" + menu.name + "\" of the activity " +
                                           "you are trying to open seems to have been renamed or doesn't exist anymore. To solve this problem, " +
                                           "re-generate const classes with the \"Harmony/Generate Const Class\" menu and re-assign the Scene in " +
                                           "the Menu.");
                        }
                    }
                }
            }
            else
            {
                DrawErrorBox("Cannot start an Activity without a Startup Scene. To solve this problem, open the \"Harmony/Settings\" menu " +
                             "and set a Startup Scene.");
            }
        }
    }
}