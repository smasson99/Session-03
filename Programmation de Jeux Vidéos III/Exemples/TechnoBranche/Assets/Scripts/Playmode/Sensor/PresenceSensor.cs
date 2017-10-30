using System;
using UnityEngine;
using Harmony;

namespace ProjetSynthese
{
    public delegate void PresenceSensorEventHandler(GameObject detectedGameObject);

    [AddComponentMenu("Game/Sensor/PresenceSensor")]
    public class PresenceSensor : GameScript
    {
        private new Collider2D collider2D;

        public event PresenceSensorEventHandler OnDetect;
        public event PresenceSensorEventHandler OnUndetect;

        private void InjectPresenceSensor([GameObjectScope] Collider2D collider2D)
        {
            this.collider2D = collider2D;
        }

        private void Awake()
        {
            InjectDependencies("InjectPresenceSensor");

            int layer = LayerMask.NameToLayer(R.S.Layer.PresenceSensor);
            if (layer == -1)
            {
                throw new Exception("In order to use a PresenceSensor, you must have a " + R.S.Layer.PresenceSensor + " layer.");
            }
            gameObject.layer = layer;
            collider2D.isTrigger = true;
        }

        public void Detect(GameObject gameObject)
        {
            if (OnDetect != null) OnDetect(gameObject);
        }

        public void Undetect(GameObject gameObject)
        {
            if (OnUndetect != null) OnUndetect(gameObject);
        }
    }
}