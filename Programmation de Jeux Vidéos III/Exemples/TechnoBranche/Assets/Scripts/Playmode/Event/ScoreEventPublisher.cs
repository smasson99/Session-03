﻿using Harmony;
using UnityEngine;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Event/ScoreEventPublisher")]
    public class ScoreEventPublisher : GameScript
    {
        private Score score;
        private ScoreEventChannel eventChannel;

        private void InjectScoreEventPublisher([EntityScope] Score score,
                                               [EventChannelScope] ScoreEventChannel eventChannel)
        {
            this.score = score;
            this.eventChannel = eventChannel;
        }

        private void Awake()
        {
            InjectDependencies("InjectScoreEventPublisher");
        }

        private void OnEnable()
        {
            score.OnScoreChanged += OnScoreChanged;
        }

        private void OnDisable()
        {
            score.OnScoreChanged -= OnScoreChanged;
        }

        private void OnScoreChanged()
        {
            eventChannel.Publish(new ScoreEvent(score));
        }
    }
}