using System;
using Harmony;
using UnityEngine;

namespace ProjetSynthese
{
    public delegate void EffectSensorEventHandler(GameEffect effect);

    [AddComponentMenu("Game/Sensor/EffectSensor")]
    public class EffectSensor : GameScript
    {
        private new Collider2D collider2D;

        public event EffectSensorEventHandler OnEffectSensed;

        private void InjectEffectSensor([GameObjectScope] Collider2D collider2D)
        {
            this.collider2D = collider2D;
        }

        private void Awake()
        {
            InjectDependencies("InjectEffectSensor");

            int layer = LayerMask.NameToLayer(R.S.Layer.EffectSensor);
            if (layer == -1)
            {
                throw new Exception("In order to use a EffectSensor, you must have a " + R.S.Layer.EffectSensor + " layer.");
            }
            gameObject.layer = layer;
            collider2D.isTrigger = true;
        }

        public void SenseEffect(GameEffect effect)
        {
            if (OnEffectSensed != null) OnEffectSensed(effect);
        }
    }
}