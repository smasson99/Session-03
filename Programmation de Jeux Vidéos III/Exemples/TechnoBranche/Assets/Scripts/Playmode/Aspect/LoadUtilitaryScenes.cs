using System;
using Harmony;
using UnityEngine;
using UnityEngine.SceneManagement;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Aspect/LoadUtilitaryScenes")]
    public class LoadUtilitaryScenes : GameScript
    {
        [SerializeField] private R.E.Scene[] scenes;

        [SerializeField] private LoadSceneMode mode = LoadSceneMode.Additive;

        private void Start()
        {
            foreach (R.E.Scene scene in scenes)
            {
                string sceneName = R.S.Scene.ToString(scene);

#if UNITY_EDITOR
                //Can't load scene if it is not in the BuildSettings. Can only check this while in Editor.
                string scenePath = AssetsExtensions.FindScenePath(sceneName).Replace("\\", "/");

                bool founded = false;
                foreach (UnityEditor.EditorBuildSettingsScene sceneInBuildSettings in UnityEditor.EditorBuildSettings.scenes)
                {
                    if (sceneInBuildSettings.path == scenePath)
                    {
                        founded = true;
                        break;
                    }
                }

                if (!founded)
                {
                    throw new Exception("Unable to load utilitary scene named \"" + sceneName + "\". It is not in the Unity BuildSettings. " +
                                        "Thus, Unity can't load it. To solve this, go to the \"Harmony/Settings\" menu and add it to the Utilitary" +
                                        "Scenes. If it's already added, just click the \"Harmony/Generate Build Settings From Activities\" " +
                                        "and try again.");
                }
#endif
                SceneManager.LoadScene(sceneName, mode);
            }
        }
    }
}