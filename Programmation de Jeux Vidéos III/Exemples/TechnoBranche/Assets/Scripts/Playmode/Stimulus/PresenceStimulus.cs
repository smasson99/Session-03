using System;
using UnityEngine;
using Harmony;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Stimulus/PresenceStimulus")]
    public class PresenceStimulus : GameScript
    {
        private GameObject rootGameObject;
        private new Collider2D collider2D;

        private void InjectPresenceStimulus([RootScope] GameObject rootGameObject,
                                            [GameObjectScope] Collider2D collider2D)
        {
            this.rootGameObject = rootGameObject;
            this.collider2D = collider2D;
        }

        private void Awake()
        {
            InjectDependencies("InjectPresenceStimulus");

            int layer = LayerMask.NameToLayer(R.S.Layer.PresenceSensor);
            if (layer == -1)
            {
                throw new Exception("In order to use a PresenceSensor, you must have a " + R.S.Layer.PresenceSensor + " layer.");
            }
            gameObject.layer = layer;
            collider2D.isTrigger = true;
        }

        private void OnEnable()
        {
            collider2D.Events().OnEnterTrigger += OnEnterTrigger;
            collider2D.Events().OnExitTrigger += OnExitTrigger;
        }

        private void OnDisable()
        {
            collider2D.Events().OnEnterTrigger -= OnEnterTrigger;
            collider2D.Events().OnExitTrigger -= OnExitTrigger;
        }

        private void OnEnterTrigger(Collider2D other)
        {
            PresenceSensor presenceSensor = other.GetComponent<PresenceSensor>();
            if (presenceSensor != null)
            {
                presenceSensor.Detect(rootGameObject);
            }
        }

        private void OnExitTrigger(Collider2D other)
        {
            PresenceSensor presenceSensor = other.GetComponent<PresenceSensor>();
            if (presenceSensor != null)
            {
                presenceSensor.Undetect(rootGameObject);
            }
        }
    }
}