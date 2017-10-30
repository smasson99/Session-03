using Harmony;
using UnityEditor;

namespace ProjetSynthese
{
    [CustomEditor(typeof(EffectStimulus), true)]
    public class EffectStimulusInspector : SensorInspector
    {
        protected override void Draw()
        {
            base.Draw();
            DrawSensorInspector(typeof(EffectStimulus), R.E.Layer.EffectSensor);
        }
    }
}