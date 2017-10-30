using System.Collections.Generic;
using Harmony;
using UnityEngine;
using UnityEngine.Events;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Control/PlayerController")]
    public class PlayerController : GameScript
    {
        private KeyboardInputSensor keyboardInputSensor;
        private NavigationMover navigationMover;

        private Queue<UnityAction> playerCommandQueue;

        private void InjectPlayerController([ApplicationScope] KeyboardInputSensor keyboardInputSensor,
                                            [GameObjectScope] NavigationMover navigationMover)
        {
            this.keyboardInputSensor = keyboardInputSensor;
            this.navigationMover = navigationMover;
        }

        private void Awake()
        {
            InjectDependencies("InjectPlayerController");

            playerCommandQueue = new Queue<UnityAction>();
        }

        private void OnEnable()
        {
            keyboardInputSensor.Keyboards.OnMoveLeft += OnMoveLeft;
            keyboardInputSensor.Keyboards.OnMoveRight += OnMoveRight;
            keyboardInputSensor.Keyboards.OnJumpLeft += OnJumpLeft;
            keyboardInputSensor.Keyboards.OnJumpRight += OnJumpRight;
            keyboardInputSensor.Keyboards.OnDropLeft += OnDropLeft;
            keyboardInputSensor.Keyboards.OnDropRight += OnDropRight;

            navigationMover.OnDestinationReached += ExecuteNextPlayerCommand;
        }

        private void OnDisable()
        {
            keyboardInputSensor.Keyboards.OnMoveLeft -= OnMoveLeft;
            keyboardInputSensor.Keyboards.OnMoveRight -= OnMoveRight;
            keyboardInputSensor.Keyboards.OnJumpLeft -= OnJumpLeft;
            keyboardInputSensor.Keyboards.OnJumpRight -= OnJumpRight;
            keyboardInputSensor.Keyboards.OnDropLeft -= OnDropLeft;
            keyboardInputSensor.Keyboards.OnDropRight -= OnDropRight;

            navigationMover.OnDestinationReached -= ExecuteNextPlayerCommand;
        }

        private void OnMoveLeft()
        {
            EnqueuePlayerCommand(navigationMover.NavigateLeft);
        }

        private void OnMoveRight()
        {
            EnqueuePlayerCommand(navigationMover.NavigateRight);
        }

        private void OnJumpLeft()
        {
            EnqueuePlayerCommand(navigationMover.NavigateUpLeft);
        }

        private void OnJumpRight()
        {
            EnqueuePlayerCommand(navigationMover.NavigateUpRight);
        }

        private void OnDropLeft()
        {
            EnqueuePlayerCommand(navigationMover.NavigateDownLeft);
        }

        private void OnDropRight()
        {
            EnqueuePlayerCommand(navigationMover.NavigateDownRight);
        }

        private void EnqueuePlayerCommand(UnityAction playerCommand)
        {
            //Command on top of queue is the currently executed command.
            //If there's no command in the queue, add it to the queue
            //and start it.
            //
            //Otherwise, if there's a command being executed, just
            //add it to the queue. When the current command will finish,
            //we will remove it from the queue and start the next one.
            if (!HasPlayerCommands())
            {
                playerCommandQueue.Enqueue(playerCommand);

                playerCommand();
            }
            else
            {
                playerCommandQueue.Enqueue(playerCommand);
            }
        }

        private void ExecuteNextPlayerCommand()
        {
            if (HasPlayerCommands())
            {
                playerCommandQueue.Dequeue();
            }
            if (HasPlayerCommands())
            {
                playerCommandQueue.Peek()();
            }
        }

        private bool HasPlayerCommands()
        {
            return playerCommandQueue.Count > 0;
        }
    }
}