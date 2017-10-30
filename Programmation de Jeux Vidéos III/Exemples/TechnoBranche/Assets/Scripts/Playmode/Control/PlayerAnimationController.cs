using UnityEngine;
using Harmony;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Control/PlayerAnimationController")]
    public class PlayerAnimationController : GameScript
    {
        private RandomSoundPlayer footStepPlayer;
        private RandomSoundPlayer loudFootStepPlayer;

        private void InjectPlayerAnimationEvents([Named(R.S.GameObject.Footsteps)] [ChildrensScope] RandomSoundPlayer footStepPlayer,
                                                 [Named(R.S.GameObject.LoudFootsteps)] [ChildrensScope] RandomSoundPlayer loudFootStepPlayer)
        {
            this.footStepPlayer = footStepPlayer;
            this.loudFootStepPlayer = loudFootStepPlayer;
        }

        private void Awake()
        {
            InjectDependencies("InjectPlayerAnimationEvents");
        }

        [CalledOutsideOfCode]
        public void PlayFootstep()
        {
            footStepPlayer.Play();
        }

        [CalledOutsideOfCode]
        public void PlayLoudFootstep()
        {
            loudFootStepPlayer.Play();
        }
    }
}