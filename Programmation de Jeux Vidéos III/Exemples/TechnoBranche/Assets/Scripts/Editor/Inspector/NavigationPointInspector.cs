using Harmony;
using UnityEditor;
using UnityEngine;

namespace ProjetSynthese
{
    [CustomEditor(typeof(NavigationPoint), true)]
    public class NavigationPointInspector : Inspector
    {
        private NavigationPoint navigationPoint;

        protected override void Initialize()
        {
            navigationPoint = target as NavigationPoint;
        }

        protected override void Draw()
        {
            DrawDefaultInspector();

            if (EditorApplication.isPlaying)
            {
                if (navigationPoint.LeftPoint != null)
                {
                    Debug.DrawLine(navigationPoint.transform.position, navigationPoint.LeftPoint.transform.position, Color.red);
                }
                if (navigationPoint.RightPoint != null)
                {
                    Debug.DrawLine(navigationPoint.transform.position, navigationPoint.RightPoint.transform.position, Color.red);
                }
                if (navigationPoint.LeftJumpPoint != null)
                {
                    Debug.DrawLine(navigationPoint.transform.position, navigationPoint.LeftJumpPoint.transform.position, Color.red);
                }
                if (navigationPoint.RightJumpPoint != null)
                {
                    Debug.DrawLine(navigationPoint.transform.position, navigationPoint.RightJumpPoint.transform.position, Color.red);
                }
                if (navigationPoint.LeftDropPoint != null)
                {
                    Debug.DrawLine(navigationPoint.transform.position, navigationPoint.LeftDropPoint.transform.position, Color.red);
                }
                if (navigationPoint.RightDropPoint != null)
                {
                    Debug.DrawLine(navigationPoint.transform.position, navigationPoint.RightDropPoint.transform.position, Color.red);
                }

                Repaint();
            }
        }
    }
}