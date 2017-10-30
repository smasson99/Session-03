namespace ProjetSynthese
{
    public delegate void MoveLeftEventHandler();
    public delegate void MoveRightEventHandler();
    public delegate void JumpLeftEventHandler();
    public delegate void JumpRightEventHandler();
    public delegate void DropLeftEventHandler();
    public delegate void DropRightEventHandler();

    public interface IInputDevice
    {
        event MoveLeftEventHandler OnMoveLeft;
        event MoveRightEventHandler OnMoveRight;
        event JumpLeftEventHandler OnJumpLeft;
        event JumpRightEventHandler OnJumpRight;
        event DropLeftEventHandler OnDropLeft;
        event DropRightEventHandler OnDropRight;
    }
}