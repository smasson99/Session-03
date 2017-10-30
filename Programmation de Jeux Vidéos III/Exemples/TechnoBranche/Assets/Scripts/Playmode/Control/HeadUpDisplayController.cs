using System;
using System.Collections;
using System.Collections.Generic;
using Harmony;
using UnityEngine;

namespace ProjetSynthese
{
    public class HeadUpDisplayController : GameScript
    {
        private ScoreView scoreView;
        private ScoreEventChannel scoreEventChannel;

        private void InjectHeadUpDisplayController([EntityScope] ScoreView scoreView,
                                                   [EventChannelScope] ScoreEventChannel scoreEventChannel)
        {
            this.scoreView = scoreView;
            this.scoreEventChannel = scoreEventChannel;
        }

        private void Awake()
        {
            InjectDependencies("InjectHeadUpDisplayController");
        }

        private void OnEnable()
        {
            scoreEventChannel.OnEventPublished += OnScoreEventPublished;
        }

        private void OnDisable()
        {
            scoreEventChannel.OnEventPublished -= OnScoreEventPublished;
        }

        private void OnScoreEventPublished(ScoreEvent scoreEvent)
        {
            scoreView.SetScore(scoreEvent.Score);
        }
    }
}