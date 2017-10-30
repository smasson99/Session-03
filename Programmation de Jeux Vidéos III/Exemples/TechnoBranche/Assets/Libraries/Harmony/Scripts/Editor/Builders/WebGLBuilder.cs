using UnityEditor;

namespace Harmony
{
    /// <summary>
    /// Builder pour WebGL
    /// </summary>
    /// <remarks>
    /// <para>
    /// Utiliez cette command pour faire un Build en WebGL à partir de l'invite de commandes.
    /// </para>
    /// <code>
    /// unity -quit -batchmode -executeMethod Harmomy.WebGlBuilder.Build
    /// </code>
    /// </remarks>
    public class WebGlBuilder
    {
        public static void Build()
        {
            BuildPipeline.BuildPlayer(EditorBuildSettings.scenes, "Build/TechnoBranche", BuildTarget.WebGL, BuildOptions.None);
        }
    }
}