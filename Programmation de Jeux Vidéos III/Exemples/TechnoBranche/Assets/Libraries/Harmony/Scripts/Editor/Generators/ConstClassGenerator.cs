using System.Diagnostics;
using System.IO;
using UnityEditor;
using UnityEngine;
using Debug = UnityEngine.Debug;

namespace Harmony
{
    public static class ConstClassGenerator
    {
        [MenuItem("Harmony/Generate Const Classes", priority = 11)]
        public static void GenerateConstClasses()
        { 
            DeleteGeneratedScripts();

            GenerateScripts();

            ReloadGeneratedScripts();
        }

        private static void GenerateScripts()
        {
            string pathToCodeGenerator = Path.GetFullPath(Path.Combine(Application.dataPath, "../BuildTools/Harmony/HarmonyCodeGenerator.exe"));
            string pathToProjectDirectory = Path.GetFullPath(Path.Combine(Application.dataPath, ".."));
            string pathToGeneratedDirectory = Path.GetFullPath(Path.Combine(Application.dataPath, "Generated"));

            ProcessStartInfo processStartInfo = new ProcessStartInfo
            {
                FileName = pathToCodeGenerator,
                Arguments = "\"" + pathToProjectDirectory + "\" \"" + pathToGeneratedDirectory + "\"",
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                UseShellExecute = false,
                CreateNoWindow = true
            };
            Process codeGenerationProcess = Process.Start(processStartInfo);
            if (codeGenerationProcess != null)
            {
                codeGenerationProcess.WaitForExit();
            }
            else
            {
                Debug.Log("Code Generation is probably complete, but Unity doesn't know it yet. Please save your work to " +
                          "let Unity reload and compile the generated code.");
            }
        }

        private static void DeleteGeneratedScripts()
        {
            foreach (string file in Directory.GetFiles(Path.Combine("Assets", "Generated"), "*.cs", SearchOption.AllDirectories))
            {
                AssetDatabase.DeleteAsset(file);
            }
        }

        private static void ReloadGeneratedScripts()
        {
            foreach (string file in Directory.GetFiles(Path.Combine("Assets", "Generated"), "*.cs", SearchOption.AllDirectories))
            {
                AssetDatabase.ImportAsset(file);
            }
        }
    }
}