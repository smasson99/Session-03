using UnityEngine;

namespace ProjetSynthese
{
    public delegate void ScoreChangedEventHandler();

    [AddComponentMenu("Game/State/Score")]
    public class Score : GameScript
    {
        private uint coins;
        private uint steps;

        public event ScoreChangedEventHandler OnScoreChanged;

        public uint Coins
        {
            get { return coins; }
            private set
            {
                coins = value;
                NotifyScoreChanged();
            }
        }

        public uint Steps
        {
            get { return steps; }
            set
            {
                steps = value;
                NotifyScoreChanged();
            }
        }

        public void CollectCoin()
        {
            Coins++;
        }

        public void MakeStep()
        {
            Steps++;
        }

        public void Reset()
        {
            Coins = 0;
            Steps = 0;
        }

        private void NotifyScoreChanged()
        {
            if (OnScoreChanged != null) OnScoreChanged();
        }
    }
}