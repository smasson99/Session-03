using System.Collections;
using UnityEngine;
using Harmony;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Actuator/OpacityChanger")]
    public class OpacityChanger : GameScript
    {
        [SerializeField] [Range(0, 100)] private int delayInSeconds = 1;

        private SpriteRenderer spriteRenderer;

        private Coroutine opacityChangerCoroutine;

        private void InjectOpacityChanger([EntityScope] SpriteRenderer spriteRenderer)
        {
            this.spriteRenderer = spriteRenderer;
        }

        private void Awake()
        {
            InjectDependencies("InjectOpacityChanger");
        }

        public void ChangeOpacity(float opacity)
        {
            if (opacityChangerCoroutine != null)
            {
                StopCoroutine(opacityChangerCoroutine);
            }

            //Change will be instant if GameObject is disabled, because "Coroutines" can't
            //be started on disabled GameObjects.
            if (isActiveAndEnabled)
            {
                opacityChangerCoroutine = StartCoroutine(SetAlpha(opacity));
            }
            else
            {
                Color currentColor = spriteRenderer.color;
                spriteRenderer.color = new Color(currentColor.r,
                                                 currentColor.g,
                                                 currentColor.b,
                                                 opacity);
            }
        }

        private IEnumerator SetAlpha(float alpha)
        {
            Color currentColor = spriteRenderer.color;
            for (float time = 0.0f; time < 1.0f; time += Time.deltaTime / delayInSeconds)
            {
                currentColor = new Color(currentColor.r,
                                         currentColor.g,
                                         currentColor.b,
                                         Mathf.Lerp(currentColor.a, alpha, time));

                spriteRenderer.color = currentColor;

                yield return null;
            }
        }
    }
}