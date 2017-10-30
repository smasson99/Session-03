using UnityEditor;

namespace Harmony
{
    /// <summary>
    /// Inspecteur pour les Fragments dans l'éditeur Unity.
    /// </summary>
    [CustomEditor(typeof(Fragment), true)]
    public class FragmentInspector : Inspector
    {
        private EnumProperty scene;
        private EnumProperty controller;
        private BasicProperty isActiveOnLoad;
        private BasicProperty isStartedOnLoad;

        protected override void Initialize()
        {
            scene = GetEnumProperty("scene", typeof(R.E.Scene));
            controller = GetEnumProperty("controller", typeof(R.E.GameObject));
            isActiveOnLoad = GetBasicProperty("isActiveOnLoad");
            isStartedOnLoad = GetBasicProperty("isStartedOnLoad");
        }

        protected override void Draw()
        {
            DrawPropertyWithTitleLabel(scene);
            DrawPropertyWithTitleLabel(controller);
            DrawTitleLabel("Is Fragment Active on load?");
            DrawPropertyWithLabel(isActiveOnLoad);
            DrawTitleLabel("Is Fragment Started on load?");
            DrawPropertyWithLabel(isStartedOnLoad);
        }
    }
}