using UnityEngine;
using Harmony;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Actuator/AnimationMover")]
    public class AnimationMover : GameScript
    {
        [Header("Movement")] [SerializeField] private R.E.AnimatorParameter horizontalVelocityParameter = R.E.AnimatorParameter.None;
        [SerializeField] [Range(0, 1)] private float horizontalAccelerationDelayInSeconds = 0.2f;
        [SerializeField] [Range(0, 1)] private float horizontalDecelerationDelayInSeconds = 0.35f;
        [SerializeField] [Range(0, 1)] private float horizontalTreshold = 0.2f;
        [Header("Jumping")] [SerializeField] private R.E.AnimatorParameter verticalVelocityParameter = R.E.AnimatorParameter.None;
        [SerializeField] [Range(0, 1)] private float verticalAccelerationDelayInSeconds = 1f;
        [SerializeField] [Range(0, 1)] private float verticalDecelerationDelayInSeconds = 1f;
        [SerializeField] [Range(0, 1)] private float verticalTreshold = 0.2f;

        private Transform rootTransform;
        private Animator animator;

        private int horizontalVelocityParameterId;
        private int verticalVelocityParameterId;
        private bool movedHorizontaly;
        private bool movedVerticaly;

        private void InjectAnimationMover([RootScope] Transform rootTransform,
                                          [RootScope] Animator animator)
        {
            this.rootTransform = rootTransform;
            this.animator = animator;
        }

        private void Awake()
        {
            InjectDependencies("InjectAnimationMover");

            horizontalVelocityParameterId = Animator.StringToHash(R.S.AnimatorParameter.ToString(horizontalVelocityParameter));
            verticalVelocityParameterId = Animator.StringToHash(R.S.AnimatorParameter.ToString(verticalVelocityParameter));
            movedHorizontaly = false;
            movedVerticaly = false;
        }

        private void LateUpdate()
        {
            if (!movedHorizontaly)
            {
                animator.SetFloat(horizontalVelocityParameterId, 0, horizontalDecelerationDelayInSeconds, Time.deltaTime);
            }
            else
            {
                movedHorizontaly = false;
            }
            if (!movedVerticaly)
            {
                animator.SetFloat(verticalVelocityParameterId, 0, verticalDecelerationDelayInSeconds, Time.deltaTime);
            }
            else
            {
                movedVerticaly = false;
            }
        }

        public void Move(Vector3 direction)
        {
            MoveHorizontally(direction.x);
            MoveVertically(direction.y);
        }

        private void MoveHorizontally(float horizontalDirection)
        {
            if (Mathf.Abs(horizontalDirection) > horizontalTreshold)
            {
                rootTransform.localScale = new Vector3(horizontalDirection >= 0 ? 1 : -1, rootTransform.localScale.y, rootTransform.localScale.z);
                animator.SetFloat(horizontalVelocityParameterId, 1, horizontalAccelerationDelayInSeconds, Time.deltaTime);

                movedHorizontaly = true;
            }
        }

        private void MoveVertically(float verticalDirection)
        {
            if (Mathf.Abs(verticalDirection) > verticalTreshold)
            {
                animator.SetFloat(verticalVelocityParameterId, verticalDirection >= 0 ? 1 : -1, verticalAccelerationDelayInSeconds, Time.deltaTime);

                movedVerticaly = true;
            }
        }
    }
}