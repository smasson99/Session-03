namespace ProjetSynthese
{
    public abstract class InputSensor : GameScript
    {
        protected abstract class InputDevice : IInputDevice
        {
            public event MoveLeftEventHandler OnMoveLeft;
            public event MoveRightEventHandler OnMoveRight;
            public event JumpLeftEventHandler OnJumpLeft;
            public event JumpRightEventHandler OnJumpRight;
            public event DropLeftEventHandler OnDropLeft;
            public event DropRightEventHandler OnDropRight;

            protected virtual void NotifyMoveLeft()
            {
                if (OnMoveLeft != null) OnMoveLeft();
            }

            protected virtual void NotifyMoveRight()
            {
                if (OnMoveRight != null) OnMoveRight();
            }

            protected virtual void NotifyJumpLeft()
            {
                if (OnJumpLeft != null) OnJumpLeft();
            }

            protected virtual void NotifyJumpRight()
            {
                if (OnJumpRight != null) OnJumpRight();
            }

            protected virtual void NotifyDropLeft()
            {
                if (OnDropLeft != null) OnDropLeft();
            }

            protected virtual void NotifyDropRight()
            {
                if (OnDropRight != null) OnDropRight();
            }
        }
    }
}