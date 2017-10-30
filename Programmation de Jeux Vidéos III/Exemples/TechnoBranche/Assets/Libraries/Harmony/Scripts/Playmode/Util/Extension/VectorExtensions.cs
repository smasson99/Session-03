using System;
using UnityEngine;

namespace Harmony
{
    /// <summary>
    /// Contient nombre de méthodes d'extensions pour des vecteurs Unity.
    /// </summary>
    public static class VectorExtensions
    {
        /// <summary>
        /// Effectue la rotation d'un point autour d'un pivot avec des angles en degrés.
        /// </summary>
        /// <param name="point">Point ayant à subir la rotation.</param>
        /// <param name="pivot">Pivot de rotation.</param>
        /// <param name="x">Angle de rotation en degrés sur l'axe des X.</param>
        /// <param name="y">Angle de rotation en degrés sur l'axe des Y.</param>
        /// <param name="z">Angle de rotation en degrés sur l'axe des Z.</param>
        /// <returns>Nouveau point avec la rotation souhaité.</returns>
        public static Vector3 RotateAround(this Vector3 point, Vector3 pivot, float x = 0, float y = 0, float z = 0)
        {
            return Quaternion.Euler(x, y, z) * (point - pivot) + pivot;
        }

        /// <summary>
        /// Permet de savoir si deux vecteurs de direction sont dans la même direction.
        /// </summary>
        /// <param name="direction1">Point de début de la direction.</param>
        /// <param name="direction2">Point de fin de la direction.</param>
        /// <param name="precision">
        /// Précision. À 0, l'angle maximal entre les deux vecteurs est de 180. 
        /// À 1, l'angle maximal entre les deux vecteurs est de 0.
        /// À 0.5, l'angle maximal entre les deux vecteurs est de 90.
        /// </param>
        /// <returns>Vrai si "direction1" et "direction2" sont dans la même direction.</returns>
        public static bool IsSameDirection(Vector3 direction1, Vector3 direction2, float precision = 0)
        {
            if (precision < 0 || precision > 1)
            {
                throw new ArgumentException("Precision must be between 0 and 1, inclusive.");
            }
            return Vector3.Dot(direction1.normalized, direction2.normalized) >= precision;
        }

        /// <summary>
        /// Indique si un point est proche d'un autre point avec une marge d'erreur.
        /// </summary>
        /// <param name="point1">Point 1.</param>
        /// <param name="point2">Point 2.</param>
        /// <param name="precision">Marge d'erreur.</param>
        /// <returns>Vrai si le "point1" est proche du "point2" avec une certaine marge d'erreur.</returns>
        public static bool IsCloseOf(Vector3 point1, Vector3 point2, float precision = 0f)
        {
            return (point2 - point1).sqrMagnitude < precision * precision;
        }

        /// <summary>
        /// Permet de savoir si un point a dépassé un autre point dans une direction.
        /// </summary>
        /// <param name="point1">Point de début de la direction.</param>
        /// <param name="point2">Point de fin de la direction.</param>
        /// <param name="pointToCheck">Point à vérifier.</param>
        /// <returns>Vrai si "pointToCheck" a dépassé "point2" dans la direction que donne la ligne entre "point1" et "point2", faux sinon.</returns>
        public static bool IsPointPassedOtherPoint(Vector3 point1, Vector3 point2, Vector3 pointToCheck)
        {
            return Vector3.Dot((point2 - point1).normalized, (point2 - pointToCheck).normalized) <= 0f;
        }

        /// <summary>
        /// Permet de savoir si un point est entre deux autres points sur une ligne droite.
        /// </summary>
        /// <param name="point1">Point de début de la ligne.</param>
        /// <param name="point2">Point de fin de la ligne.</param>
        /// <param name="pointToCheck">Point à vérifier.</param>
        /// <returns>Vrai si "pointToCheck" est sur la même ligne que "point1" et "point2" et entre les deux points sur la ligne, faux sinon.</returns>
        public static bool IsPointBetween(Vector3 point1, Vector3 point2, Vector3 pointToCheck)
        {
            return Vector3.Dot((point2 - point1).normalized, (pointToCheck - point2).normalized) <= 0f &&
                   Vector3.Dot((point1 - point2).normalized, (pointToCheck - point1).normalized) <= 0f;
        }
        
    }
}