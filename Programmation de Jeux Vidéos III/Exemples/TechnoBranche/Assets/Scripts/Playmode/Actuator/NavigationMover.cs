using System.Collections;
using Harmony;
using UnityEngine;
using UnityEngine.Events;

namespace ProjetSynthese
{
    public delegate void DestinationReachedEventHandler();

    public class NavigationMover : GameScript
    {
        [Header("Movement")] [SerializeField] private float stopDistance = 1f;

        private Transform rootTransform;
        private AnimationMover animationMover;
        private GameObject navigationPointsContainer;

        public event DestinationReachedEventHandler OnDestinationReached;

        private void InjectNavigationMover([RootScope] Transform rootTransform,
                                           [GameObjectScope] AnimationMover animationMover,
                                           [TagScope(R.S.Tag.Navigation)] GameObject navigationPointsContainer)
        {
            this.rootTransform = rootTransform;
            this.animationMover = animationMover;

            this.navigationPointsContainer = navigationPointsContainer;
        }

        private void Awake()
        {
            InjectDependencies("InjectNavigationMover");

            GetNearestPoint();
        }

        public void NavigateLeft()
        {
            NavigationPoint from = GetNearestPoint();
            NavigationPoint to = from.LeftPoint;
            if (to != null)
            {
                StartCoroutine(Move(from, to));
            }
            else
            {
                NotifyDestinationReached();
            }
        }

        public void NavigateRight()
        {
            NavigationPoint from = GetNearestPoint();
            NavigationPoint to = from.RightPoint;
            if (to != null)
            {
                StartCoroutine(Move(from, to));
            }
            else
            {
                NotifyDestinationReached();
            }
        }

        public void NavigateUpLeft()
        {
            NavigationPoint from = GetNearestPoint();
            NavigationPoint to = from.LeftJumpPoint;
            if (to != null)
            {
                StartCoroutine(Move(from, to));
            }
            else
            {
                NotifyDestinationReached();
            }
        }

        public void NavigateUpRight()
        {
            NavigationPoint from = GetNearestPoint();
            NavigationPoint to = from.RightJumpPoint;
            if (to != null)
            {
                StartCoroutine(Move(from, to));
            }
            else
            {
                NotifyDestinationReached();
            }
        }

        public void NavigateDownLeft()
        {
            NavigationPoint from = GetNearestPoint();
            NavigationPoint to = from.LeftDropPoint;
            if (to != null)
            {
                StartCoroutine(Move(from, to));
            }
            else
            {
                NotifyDestinationReached();
            }
        }

        public void NavigateDownRight()
        {
            NavigationPoint from = GetNearestPoint();
            NavigationPoint to = from.RightDropPoint;
            if (to != null)
            {
                StartCoroutine(Move(from, to));
            }
            else
            {
                NotifyDestinationReached();
            }
        }

        private NavigationPoint GetNearestPoint()
        {
            GameObject nearestPoint = null;
            float nearestDistanceSquared = float.MaxValue;

            for (int i = 0; i < navigationPointsContainer.transform.childCount; i++)
            {
                GameObject point = navigationPointsContainer.transform.GetChild(i).gameObject;

                float distanceSquared = (point.transform.position - rootTransform.position).sqrMagnitude;
                if (distanceSquared < nearestDistanceSquared)
                {
                    nearestPoint = point;
                    nearestDistanceSquared = distanceSquared;
                }
            }

            return nearestPoint == null ? null : nearestPoint.GetComponent<NavigationPoint>();
        }

        private IEnumerator Move(NavigationPoint from, NavigationPoint to)
        {
            Vector3 destination = to.transform.position;

            while (!VectorExtensions.IsCloseOf(rootTransform.position, destination, stopDistance))
            {
                Vector3 direction = (destination - rootTransform.position).normalized;
                animationMover.Move(direction);
                yield return null;
            }

            NotifyDestinationReached();
        }

        private void NotifyDestinationReached()
        {
            if (OnDestinationReached != null) OnDestinationReached();
        }
    }
}