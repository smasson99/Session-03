using System;
using SFML;
using SFML.Graphics;
using SFML.System;
using SFML.Window;

namespace SFMLApplication1
{
    class Application
    {
        private RenderWindow window = null;
        private Color backgroundColor = Color.Red;

        private void OnClose(object sender, EventArgs e)
        {
            RenderWindow window = (RenderWindow)sender;
            window.Close();
        }
        void OnMouseMoved(object sender, MouseMoveEventArgs e)
        {
            // A COMPLETER SELON LES BESOINS    
        }
        void OnMousePressed(object sender, MouseButtonEventArgs e)
        {
            // A COMPLETER SELON LES BESOINS     
        }
        void OnMouseReleased(object sender, MouseButtonEventArgs e)
        {
            // A COMPLETER SELON LES BESOINS
        }
        void OnKeyPressed(object sender, KeyEventArgs e)
        {
            // A COMPLETER SELON LES BESOINS
        }
        public Application(string windowTitle, uint width, uint height)
        {
            window = new RenderWindow(new SFML.Window.VideoMode(width, height), windowTitle);
            window.Closed += new EventHandler(OnClose);
            window.KeyPressed += new EventHandler<KeyEventArgs>(OnKeyPressed);
            window.MouseButtonPressed += new EventHandler<MouseButtonEventArgs>(OnMousePressed);
            window.MouseButtonReleased += new EventHandler<MouseButtonEventArgs>(OnMouseReleased);
            window.MouseMoved += new EventHandler<MouseMoveEventArgs>(OnMouseMoved);

        }


        public void Run()
        {
            window.SetActive();
            while (window.IsOpen)
            {
                window.Clear(backgroundColor);
                window.DispatchEvents();
                Draw();
                window.Display();
            }
        }

        public void Draw()
        {

        }
    }
}
