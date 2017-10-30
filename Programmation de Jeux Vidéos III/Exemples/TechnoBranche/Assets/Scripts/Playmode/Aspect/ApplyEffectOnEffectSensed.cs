using Harmony;
using UnityEngine;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Aspect/ApplyEffectOnEffectSensed")]
    public class ApplyEffectOnEffectSensed : GameScript
    {
        private EffectSensor effectSensor;
        private GameObject rootGameObject;

        private void InjectApplyEffectOnEffectDetected([EntityScope] EffectSensor effectSensor,
                                                       [RootScope] GameObject rootGameObject)
        {
            this.effectSensor = effectSensor;
            this.rootGameObject = rootGameObject;
        }

        private void Awake()
        {
            InjectDependencies("InjectApplyEffectOnEffectDetected");
        }

        private void OnEnable()
        {
            effectSensor.OnEffectSensed += OnEffectSensed;
        }

        private void OnDisable()
        {
            effectSensor.OnEffectSensed -= OnEffectSensed;
        }

        private void OnEffectSensed(GameEffect effect)
        {
            effect.ApplyOn(rootGameObject);
        }
    }
}