using ProjetSynthese;
using UnityEngine;

namespace Harmony
{
    [CreateAssetMenu(fileName = "New Add Coin Effect", menuName = "Game/Effect/Add Coin Effect")]
    public class AddCoinEffect : GameEffect
    {
        public override void ApplyOn(GameObject gameObject)
        {
            Score score = gameObject.GetComponentInChildren<Score>();
            if (score != null)
            {
                score.CollectCoin();
            }
        }
    }
}