using Harmony;

namespace ProjetSynthese
{
    public class ScoreEvent : IEvent
    {
        public Score Score { get; private set; }

        public ScoreEvent(Score score)
        {
            Score = score;
        }
    }
}