using JetBrains.Annotations;
using UnityEngine;
using UnityEngine.UI;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/View/ScoreView")]
    public class ScoreView : GameScript
    {
        private const string NumberFormat = "D";
        private const string Prefix = "X";

        [Header("Views")] [NotNull] [SerializeField] private Text coinCountTextView;
        [NotNull] [SerializeField] private Text stepCountTextView;
        [Header("Configuration")] [SerializeField] [Range(0, 10)] private uint nbZeros = 2;

        public void SetScore(Score score)
        {
            coinCountTextView.text = Prefix + score.Coins.ToString(NumberFormat + nbZeros);
            stepCountTextView.text = Prefix + score.Steps.ToString(NumberFormat + nbZeros);
        }
    }
}