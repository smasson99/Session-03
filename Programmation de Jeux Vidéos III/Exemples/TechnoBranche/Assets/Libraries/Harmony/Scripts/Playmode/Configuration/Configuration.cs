using System.IO;
using UnityEngine;

namespace Harmony
{
#if UNITY_EDITOR
    /// <summary>
    /// Représente la configuration de Harmony.
    /// </summary>
    public class Configuration : ScriptableObject
    {
        #region "Editor Configuration"

        private const string ConfigurationFolderPathRelativeAssets = "Data/Configuration";
        private const string ConfigurationFilePathRelativeAssets = ConfigurationFolderPathRelativeAssets + "/Harmony.asset";
        private const string ConfigurationFilePathRelativeProject = "Assets/" + ConfigurationFilePathRelativeAssets;

        public static Configuration Get()
        {
            CreateIfNotExists();

            return UnityEditor.AssetDatabase.LoadAssetAtPath<Configuration>(ConfigurationFilePathRelativeProject);
        }

        private static void CreateIfNotExists()
        {
            if (IsConfigurationDoesntExists())
            {
                Directory.CreateDirectory(Path.GetFullPath(Path.Combine(Application.dataPath, ConfigurationFolderPathRelativeAssets)));
                UnityEditor.AssetDatabase.CreateAsset(CreateInstance<Configuration>(), ConfigurationFilePathRelativeProject);
            }
        }

        private static bool IsConfigurationDoesntExists()
        {
            return !File.Exists(Path.GetFullPath(Path.Combine(Application.dataPath, ConfigurationFilePathRelativeAssets)));
        }

        #endregion

        [SerializeField] private R.E.Scene startingScene = R.E.Scene.None;
        [SerializeField] private R.E.Scene[] utilitaryScenes = { };

        public R.E.Scene StartingScene
        {
            get { return startingScene; }
        }

        public R.E.Scene[] UtilitaryScenes
        {
            get { return utilitaryScenes; }
        }
    }
#endif
}