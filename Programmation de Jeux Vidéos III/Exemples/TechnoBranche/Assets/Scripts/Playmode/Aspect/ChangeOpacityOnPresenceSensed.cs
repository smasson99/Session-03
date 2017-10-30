using Harmony;
using UnityEngine;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Aspect/ChangeOpacityOnPresenceSensed")]
    public class ChangeOpacityOnPresenceSensed : GameScript
    {
        [SerializeField] [Range(0, 1)] private float opacityWhenPrecenceDetected = 0.5f;
        [SerializeField] [Range(0, 1)] private float opacityWhenNoPrecenceDetected = 1f;

        private PresenceSensor presenceSensor;
        private OpacityChanger opacityChanger;

        private int presenceCount;

        private void InjectChangeOpacityOnDetectPresence([EntityScope] PresenceSensor presenceSensor,
                                                         [GameObjectScope] OpacityChanger opacityChanger)
        {
            this.opacityChanger = opacityChanger;
            this.presenceSensor = presenceSensor;
        }

        private void Awake()
        {
            InjectDependencies("InjectChangeOpacityOnDetectPresence");

            presenceCount = 0;
        }

        private void Start()
        {
            UpdateOpacity();
        }

        private void OnEnable()
        {
            presenceSensor.OnDetect += OnDetectPresence;
            presenceSensor.OnUndetect += OnUndetectPresence;
        }

        private void OnDisable()
        {
            presenceSensor.OnDetect -= OnDetectPresence;
            presenceSensor.OnUndetect -= OnUndetectPresence;
        }

        private void OnDetectPresence(GameObject detectedGameObject)
        {
            presenceCount++;

            UpdateOpacity();
        }

        private void OnUndetectPresence(GameObject detectedGameObject)
        {
            presenceCount--;

            UpdateOpacity();
        }

        private void UpdateOpacity()
        {
            opacityChanger.ChangeOpacity(isActiveAndEnabled && presenceCount > 0 ? opacityWhenPrecenceDetected : opacityWhenNoPrecenceDetected);
        }
    }
}