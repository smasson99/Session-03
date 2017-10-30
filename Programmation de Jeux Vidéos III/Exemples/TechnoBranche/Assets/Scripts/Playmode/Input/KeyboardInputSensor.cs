using Harmony;
using UnityEngine;

namespace ProjetSynthese
{
    [AddComponentMenu("Game/Sensor/KeyboardInputSensor")]
    public class KeyboardInputSensor : InputSensor
    {
        private Keyboard keyboard;

        private KeyboardsInputDevice keyboardsInputDevice;

        public IInputDevice Keyboards
        {
            get { return keyboardsInputDevice; }
        }

        private void InjectKeyboardInputDevice([ApplicationScope] Keyboard keyboard)
        {
            this.keyboard = keyboard;
        }

        private void Awake()
        {
            InjectDependencies("InjectKeyboardInputDevice");

            keyboardsInputDevice = new KeyboardsInputDevice(keyboard);
        }

        private void Update()
        {
            keyboardsInputDevice.Update();
        }

        private class KeyboardsInputDevice : InputDevice
        {
            private readonly Keyboard keyboard;

            public KeyboardsInputDevice(Keyboard keyboard)
            {
                this.keyboard = keyboard;
            }

            public void Update()
            {
                if (keyboard.GetKey(KeyCode.Space))
                {
                    if (keyboard.GetKeyDown(KeyCode.LeftArrow))
                    {
                        NotifyJumpLeft();
                    }
                    if (keyboard.GetKeyDown(KeyCode.RightArrow))
                    {
                        NotifyJumpRight();
                    }
                }
                else if (keyboard.GetKey(KeyCode.LeftControl))
                {
                    if (keyboard.GetKeyDown(KeyCode.LeftArrow))
                    {
                        NotifyDropLeft();
                    }
                    if (keyboard.GetKeyDown(KeyCode.RightArrow))
                    {
                        NotifyDropRight();
                    }
                }
                else
                {
                    if (keyboard.GetKeyDown(KeyCode.LeftArrow))
                    {
                        NotifyMoveLeft();
                    }
                    if (keyboard.GetKeyDown(KeyCode.RightArrow))
                    {
                        NotifyMoveRight();
                    }
                }
            }
        }
    }
}