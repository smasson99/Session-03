using Harmony;
using UnityEngine;

namespace ProjetSynthese
{
    public delegate void EntityDestroyedEventHandler();

    [AddComponentMenu("Game/Actuator/EntityDestroyer")]
    public class EntityDestroyer : GameScript
    {
        private GameObject topParent;

        public virtual event EntityDestroyedEventHandler OnDestroyed;

        public void InjectEntityDestroyer([RootScope] GameObject topParent)
        {
            this.topParent = topParent;
        }

        private void Awake()
        {
            InjectDependencies("InjectEntityDestroyer");
        }

        [CalledOutsideOfCode]
        public void Destroy()
        {
            if (OnDestroyed != null) OnDestroyed();

            topParent.Destroy();
        }
    }
}