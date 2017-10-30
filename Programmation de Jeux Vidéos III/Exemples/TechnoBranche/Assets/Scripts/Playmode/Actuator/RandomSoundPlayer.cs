using UnityEngine;
using Harmony;
using JetBrains.Annotations;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Actuator/RandomSoundPlayer")]
    public class RandomSoundPlayer : GameScript
    {
        [NotNull] [SerializeField] private AudioClip[] sounds;

        private AudioSource audioSource;

        private void InjectRandomSoundPlayer([GameObjectScope] AudioSource audioSource)
        {
            this.audioSource = audioSource;
        }

        private void Awake()
        {
            InjectDependencies("InjectRandomSoundPlayer");
        }

        public void Play()
        {
            if (sounds.Length > 0)
            {
                audioSource.PlayOneShot(sounds[Random.Range(0, sounds.Length - 1)]);
            }
        }
    }
}