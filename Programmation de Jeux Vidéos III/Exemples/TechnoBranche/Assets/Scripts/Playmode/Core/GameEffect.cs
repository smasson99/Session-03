using UnityEngine;

namespace ProjetSynthese
{
    public abstract class GameEffect : ScriptableObject
    {
        public abstract void ApplyOn(GameObject gameObject);
    }
}