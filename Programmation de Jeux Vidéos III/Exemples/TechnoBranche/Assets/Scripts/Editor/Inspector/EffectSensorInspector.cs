using Harmony;
using UnityEditor;

namespace ProjetSynthese
{
    [CustomEditor(typeof(EffectSensor), true)]
    public class EffectSensorInspector : SensorInspector
    {
        protected override void Draw()
        {
            base.Draw();
            DrawSensorInspector(typeof(EffectSensor), R.E.Layer.EffectSensor);
        }
    }
}