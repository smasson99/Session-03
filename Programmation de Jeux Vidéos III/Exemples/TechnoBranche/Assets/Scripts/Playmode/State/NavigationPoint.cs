using Harmony;
using UnityEngine;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/State/NavigationPoint")]
    public class NavigationPoint : GameScript
    {
        [SerializeField] private float distanceBetweenPointsHorizontal = 2f;
        [SerializeField] private float distanceBetweenPointsVertical = 4f;
        [SerializeField] [Range(0, 1)] private float anglePrecision = 0.9f;

        private NavigationPoint leftPoint;
        private NavigationPoint rightPoint;
        private NavigationPoint leftJumpPoint;
        private NavigationPoint rightJumpPoint;
        private NavigationPoint leftDropPoint;
        private NavigationPoint rightDropPoint;

        private GameObject navigationPointsContainer;

        private void InjectNavigationPoint([TagScope(R.S.Tag.Navigation)] GameObject navigationPointsContainer)
        {
            this.navigationPointsContainer = navigationPointsContainer;
        }

        private void Awake()
        {
            InjectDependencies("InjectNavigationPoint");

            leftPoint = GetNearestPointInDirection(Vector3.left, distanceBetweenPointsHorizontal);
            rightPoint = GetNearestPointInDirection(Vector3.right, distanceBetweenPointsHorizontal);
            leftJumpPoint = GetNearestPointInDirection(Vector3.up + Vector3.left, distanceBetweenPointsVertical);
            rightJumpPoint = GetNearestPointInDirection(Vector3.up + Vector3.right, distanceBetweenPointsVertical);
            leftDropPoint = GetNearestPointInDirection(Vector3.down + Vector3.left, distanceBetweenPointsVertical);
            rightDropPoint = GetNearestPointInDirection(Vector3.down + Vector3.right, distanceBetweenPointsVertical);
        }

        public NavigationPoint LeftPoint
        {
            get { return leftPoint; }
        }

        public NavigationPoint RightPoint
        {
            get { return rightPoint; }
        }

        public NavigationPoint LeftJumpPoint
        {
            get { return leftJumpPoint; }
        }

        public NavigationPoint RightJumpPoint
        {
            get { return rightJumpPoint; }
        }

        public NavigationPoint LeftDropPoint
        {
            get { return leftDropPoint; }
        }

        public NavigationPoint RightDropPoint
        {
            get { return rightDropPoint; }
        }

        private NavigationPoint GetNearestPointInDirection(Vector3 direction, float maxDistance)
        {
            GameObject nearestPoint = null;
            float nearestDistanceSquared = float.MaxValue;
            float maxDistanceSquared = maxDistance * maxDistance;

            for (int i = 0; i < navigationPointsContainer.transform.childCount; i++)
            {
                GameObject point = navigationPointsContainer.transform.GetChild(i).gameObject;

                if (point != gameObject)
                {
                    Vector3 directionToPoint = point.transform.position - transform.position;
                    if (VectorExtensions.IsSameDirection(direction, directionToPoint, anglePrecision))
                    {
                        float distanceSquared = directionToPoint.sqrMagnitude;
                        if (distanceSquared <= maxDistanceSquared && distanceSquared < nearestDistanceSquared)
                        {
                            nearestPoint = point;
                            nearestDistanceSquared = distanceSquared;
                        }
                    }
                }
            }

            return nearestPoint == null ? null : nearestPoint.GetComponent<NavigationPoint>();
        }
    }
}