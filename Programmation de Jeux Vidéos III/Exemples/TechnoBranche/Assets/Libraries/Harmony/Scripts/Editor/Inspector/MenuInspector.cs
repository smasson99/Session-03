using UnityEditor;

namespace Harmony
{
    /// <summary>
    /// Inspecteur pour les Menus dans l'éditeur Unity.
    /// </summary>
    [CustomEditor(typeof(Menu), true)]
    public class MenuInspector : Inspector
    {
        private EnumProperty scene;
        private EnumProperty controller;
        private BasicProperty isAlwaysVisible;

        protected override void Initialize()
        {
            scene = GetEnumProperty("scene", typeof(R.E.Scene));
            controller = GetEnumProperty("controller", typeof(R.E.GameObject));
            isAlwaysVisible = GetBasicProperty("isAlwaysVisible");
        }

        private void OnDestroy()
        {
            scene = null;
            controller = null;
            isAlwaysVisible = null;
        }

        protected override void Draw()
        {
            DrawPropertyWithTitleLabel(scene);
            DrawPropertyWithTitleLabel(controller);
            DrawTitleLabel("Is Menu Always Visible on Screen?");
            DrawPropertyWithLabel(isAlwaysVisible);
        }
    }
}