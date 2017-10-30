using Harmony;
using UnityEngine;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Aspect/DestroyOnEffectStimulus")]
    public class DestroyOnEffectStimulus : GameScript
    {
        private EffectStimulus effectStimulus;
        private EntityDestroyer entityDestroyer;

        private void InjectDestroyOnEffectStimulus([EntityScope] EffectStimulus effectStimulus,
                                                   [GameObjectScope] EntityDestroyer entityDestroyer)
        {
            this.effectStimulus = effectStimulus;
            this.entityDestroyer = entityDestroyer;
        }

        private void Awake()
        {
            InjectDependencies("InjectDestroyOnEffectStimulus");
        }

        private void OnEnable()
        {
            effectStimulus.OnEffectStimulus += OnEffectStimulus;
        }

        private void OnDisable()
        {
            effectStimulus.OnEffectStimulus -= OnEffectStimulus;
        }

        private void OnEffectStimulus(GameEffect effect)
        {
            entityDestroyer.Destroy();
        }
    }
}