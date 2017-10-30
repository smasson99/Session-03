using System;
using Harmony;
using JetBrains.Annotations;
using UnityEngine;

namespace ProjetSynthese
{
    public delegate void EffectStimulusEventHandler(GameEffect effect);

    [AddComponentMenu("Game/Stimulus/EffectStimulus")]
    public class EffectStimulus : GameScript
    {
        [NotNull] [SerializeField] private GameEffect effect;

        private new Collider2D collider2D;

        public event EffectStimulusEventHandler OnEffectStimulus;

        private void InjectEffectStimulus([GameObjectScope] Collider2D collider2D)
        {
            this.collider2D = collider2D;
        }

        private void Awake()
        {
            InjectDependencies("InjectEffectStimulus");

            int layer = LayerMask.NameToLayer(R.S.Layer.EffectSensor);
            if (layer == -1)
            {
                throw new Exception("In order to use a EffectStimulus, you must have a " + R.S.Layer.EffectSensor + " layer.");
            }
            gameObject.layer = layer;
            collider2D.isTrigger = true;
        }

        private void OnEnable()
        {
            collider2D.Events().OnEnterTrigger += OnEnterTrigger;
        }

        private void OnDisable()
        {
            collider2D.Events().OnEnterTrigger -= OnEnterTrigger;
        }

        private void OnEnterTrigger(Collider2D other)
        {
            EffectSensor effectSensor = other.GetComponent<EffectSensor>();
            if (effectSensor != null)
            {
                if (OnEffectStimulus != null) OnEffectStimulus(effect);

                effectSensor.SenseEffect(effect);
            }
        }
    }
}