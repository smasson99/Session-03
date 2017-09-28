#define _USE_MATH_DEFINES
#include <cmath>
#include "Movable.h"

/// <summary>
/// Constructeur dont le r�le est d'initialiser les variables par d�faut.
/// </summary>
Movable::Movable()
{
    //Initialisation des valeurs par d�faut
    SetPosition(0, 0);
    speed = 10.0f;
}

/// <summary>
/// Fonction dont le r�le est d'initialiser les variables du visuel et des collisions de l'objet en question
/// </summary>
/// <param name="path">The path.</param>
/// <returns>bool.</returns>
bool Movable::Init(std::string path)
{
    //Loading des textures
    bool result = texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    //Initialiser les collisions en fonction de la texture
    sphereCollider.SetRayon(texture.getSize().x / 2);
    sphereCollider.SetPosition(sprite.getPosition().x, sprite.getPosition().y);
    //Retourner le r�sultat de l'op�ration de chargement
    return result;
}

/// <summary>
/// Changer la position de l'objet
/// </summary>
/// <param name="x">La position en X de l'objet</param>
/// <param name="y">La position en Y de l'objet</param>
void Movable::SetPosition(float x, float y)
{
    //Setter les nouvelles valeurs
    sprite.setPosition(x, y);
    sphereCollider.SetPosition(x, y);
}

/// <summary>
/// Changer la vitesse de l'objet
/// </summary>
/// <param name="newSpeed">La nouvelle vitesse de l'objet</param>
void Movable::SetSpeed(float newSpeed)
{
    //Attribuer la nouvelle valeur
    speed = newSpeed;
}

/// <summary>
/// Fonction dont le r�le est d'additionner une valeur � la grandeur courante de l'objet
/// </summary>
/// <param name="scaleAddition">Le nombre en float a ajouter � la sph�re</param>
void Movable::AScaleFrom(float scaleAddition)
{
    sprite.setScale(sprite.getScale().x + scaleAddition, sprite.getScale().y + scaleAddition);
    sphereCollider.SetRayon(texture.getSize().x + texture.getSize().x*(1/sprite.getScale().x));
}

/// <summary>
/// Fonction dont le r�le est de setter une nouvelle`valeur � la transparence de l'objet
/// </summary>
/// <param name="transparency">La valeur de l'alpha de la transparence en float, maximum 255</param>
void Movable::SetTransparencyAlpha(float transparency)
{
    sprite.setColor(sf::Color(sprite.getColor().r, sprite.getColor().g, sprite.getColor().b, 
        transparency));
}

/// <summary>
/// Fonction dont le r�le est de reseter la valeur de la grandeur de l'object
/// </summary>
void Movable::ResetScale()
{
    sprite.setScale(1, 1);
    sphereCollider.SetRayon(texture.getSize().x / 2);
}

/// <summary>
/// Fonction dont le r�le est d'effectuer une rotation et de convertir le param�tre entr� en degr�s si n�cessaire
/// </summary>
/// <param name="unit">La veleur de rotation en float</param>
/// <param name="isRadian">Bool�en indiquant Vrai si la valeur de rotation est en radian ou Faux si elle ne l'est pas</param>
/// <returns>Float repr�sentant la rotation effectu�e en degr�s.</returns>
float Movable::SetRotation(float unit, bool isRadian)
{
    if (isRadian)
        unit = ToDegree(unit);
    if (unit < 0)
        unit += 360.0f;
    sprite.setRotation(unit);
    return unit;
}

/// <summary>
/// Fonction dont le r�le est de g�n�rer une dirrection selon les param�tres entr�s
/// </summary>
/// <param name="angle">Float de la mesure de l'angle</param>
/// <param name="isRadian">Bool�en indiquant Vrai si la valeur de rotation est en radian ou Faux si elle ne l'est pas</param>
/// <returns>Vecteur 2 float repr�sentant la dirrection g�n�r�e par la m�thode</returns>
sf::Vector2f Movable::GenerateDirection(float angle, bool isRadian)
{
    if (!isRadian)
        angle = ToRadian(angle);
    direction.x = cos(angle);
    direction.y = sin(angle);
    return direction;
}
/// <summary>
/// Fonction dont le r�le est de retourner la position de l'objet
/// </summary>
/// <returns>Vector2f repr�sentant la position de l'objet</returns>
sf::Vector2f Movable::GetPosition() const
{
    return sprite.getPosition();
}

/// <summary>
/// Fonction dont le ^r�le est de retourner la position en X de l'objet
/// </summary>
/// <returns>float.repr�sentant la position en X de l'objet</returns>
float Movable::GetX() const
{
    return sprite.getPosition().x;
}
/// <summary>
/// Fonction dont le ^r�le est de retourner la position en Y de l'objet
/// </summary>
/// <returns>float.repr�sentant la position en Y de l'objet</returns>
float Movable::GetY() const
{
    return sprite.getPosition().y;
}
/// <summary>
/// Fonction dont le r�le est de dessiner � l'�cran l'objet
/// </summary>
/// <param name="mainWin">RenderWindow repr�sentant l'�cran qui affichera l'objet</param>
void Movable::Draw(sf::RenderWindow & mainWin)
{
    mainWin.draw(sprite);
}
/// <summary>
/// Fonction dont le r�le est de retourner la collision de l'objet
/// </summary>
/// <returns>CollisionSphere.</returns>
CollisionSphere Movable::GetCollider() const
{
    return sphereCollider;
}
/// <summary>
/// Fonction dont le r�le est de retourner la texture de l'objet
/// </summary>
/// <returns>Texture repr�sentant la texture de l'objet.</returns>
sf::Texture Movable::GetTexture()
{
    return texture;
}
/// <summary>
/// Fonction dont le r�le est de convertir en degr�s une unit� en radians re�ue et de retourner le r�sultat
/// </summary>
/// <param name="radians">L'unit� en radians � convertir en degr�s</param>
/// <returns>float.repr�sentant la valeur en degr�s de l'unit� re�ue en radians</returns>
float Movable::ToDegree(float radians) const
{
    return radians *(180/M_PI);
}
/// <summary>
/// Fonction dont le r�le est de convertir en radians une unit� en degr�s re�ue et de retourner le r�sultat
/// </summary>
/// <param name="radians">L'unit� en degr�s � convertir en radians</param>
/// <returns>float.repr�sentant la valeur en radians de l'unit� re�ue en degr�s</returns>
float Movable::ToRadian(float degrees) const
{
    return degrees *(M_PI / 180);
}