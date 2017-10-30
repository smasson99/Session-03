using System.Collections;
using Harmony;
using UnityEngine;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Aspect/TriggerAnimationAfterRandomDelay")]
    public class TriggerAnimationAfterRandomDelay : GameScript
    {
        [SerializeField] private R.E.AnimatorParameter trigger = R.E.AnimatorParameter.None;
        [Range(0, 10)] [SerializeField] private int minDelayInSeconds = 1;
        [Range(0, 10)] [SerializeField] private int maxDelayInSeconds = 10;

        private Animator animator;
        private Coroutine nextTriggerCoroutine;

        private void InjectTriggerAnimationRandomDelay([RootScope] Animator animator)
        {
            this.animator = animator;
        }

        private void Awake()
        {
            InjectDependencies("InjectTriggerAnimationRandomDelay");
        }

        private void OnEnable()
        {
            StopTriggerAnimation();

            StartTriggerAnimation();
        }

        private void OnDisable()
        {
            StopTriggerAnimation();
        }

        private void StartTriggerAnimation()
        {
            StartCoroutine(TriggerAnimation());
        }

        private void StopTriggerAnimation()
        {
            if (nextTriggerCoroutine != null)
            {
                StopCoroutine(nextTriggerCoroutine);
                nextTriggerCoroutine = null;
            }
        }

        private IEnumerator TriggerAnimation()
        {
            while (true)
            {
                yield return new WaitForSeconds(Random.Range(minDelayInSeconds, maxDelayInSeconds));

                animator.SetTrigger(R.S.AnimatorParameter.ToString(trigger));
            }
        }
    }
}