#pragma once
#include <SFML/Graphics.hpp>

class SFMLCircle
{
  public:    
    
    /// <summary>
    /// Constructeur sans paramètre du cercle
    /// </summary>
    SFMLCircle();
    /// <summary>
    /// Constructeur du cercle
    /// </summary>
    /// <param name="radius">Le rayon du cercle</param>
    SFMLCircle(float radius);
        
    /// <summary>
    /// Modifie la couleur de remplissage du cercle.
    /// </summary>
    /// <param name="color">La couleur de remplissage</param>
    void SetBackgroundColor(sf::Color color);
    
    /// <summary>
    /// Modifie la couleur de contour du cercle.
    /// </summary>
    /// <param name="color">La couleur de remplissage</param>
    void SetOutlineColor(sf::Color color);
        
    /// <summary>
    /// Modifie le rayon du cercle
    /// </summary>
    /// <param name="radius">Le nouveau rayon du cercle</param>
    void SetRadius(float radius);
        
    /// <summary>
    /// Retourne la position du cercle.
    /// </summary>
    /// <returns>La position du cercle</returns>
    sf::Vector2f GetPosition();

    /// <summary>
    /// Modifie la position du cercle
    /// </summary>
    /// <param name="x">La position en x, en coordonnées écran</param>
    /// <param name="y">La position en y, en coordonnées écran</param>
    void SetPosition(float x, float y);

    /// <summary>
    /// Modifie la position du cercle
    /// </summary>
    /// <param name="pos">La position , en coordonnées écran</param>
    void SetPosition(sf::Vector2f& pos);

    /// <summary>
    /// Dessine le cercle dans la fenêtre
    /// </summary>
    /// <param name="window">La fenêtre de rendu</param>
    void Draw(sf::RenderWindow& window);

  private:
    float radius;
    sf::CircleShape shape;
};