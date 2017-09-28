#define _USE_MATH_DEFINES
#include <cmath>
#include "Movable.h"

/// <summary>
/// Constructeur dont le rôle est d'initialiser les variables par défaut.
/// </summary>
Movable::Movable()
{
    //Initialisation des valeurs par défaut
    SetPosition(0, 0);
    speed = 10.0f;
}

/// <summary>
/// Fonction dont le rôle est d'initialiser les variables du visuel et des collisions de l'objet en question
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
    //Retourner le résultat de l'opération de chargement
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
/// Fonction dont le rôle est d'additionner une valeur à la grandeur courante de l'objet
/// </summary>
/// <param name="scaleAddition">Le nombre en float a ajouter à la sphère</param>
void Movable::AScaleFrom(float scaleAddition)
{
    sprite.setScale(sprite.getScale().x + scaleAddition, sprite.getScale().y + scaleAddition);
    sphereCollider.SetRayon(texture.getSize().x + texture.getSize().x*(1/sprite.getScale().x));
}

/// <summary>
/// Fonction dont le rôle est de setter une nouvelle`valeur à la transparence de l'objet
/// </summary>
/// <param name="transparency">La valeur de l'alpha de la transparence en float, maximum 255</param>
void Movable::SetTransparencyAlpha(float transparency)
{
    sprite.setColor(sf::Color(sprite.getColor().r, sprite.getColor().g, sprite.getColor().b, 
        transparency));
}

/// <summary>
/// Fonction dont le rôle est de reseter la valeur de la grandeur de l'object
/// </summary>
void Movable::ResetScale()
{
    sprite.setScale(1, 1);
    sphereCollider.SetRayon(texture.getSize().x / 2);
}

/// <summary>
/// Fonction dont le rôle est d'effectuer une rotation et de convertir le paramètre entré en degrés si nécessaire
/// </summary>
/// <param name="unit">La veleur de rotation en float</param>
/// <param name="isRadian">Booléen indiquant Vrai si la valeur de rotation est en radian ou Faux si elle ne l'est pas</param>
/// <returns>Float représentant la rotation effectuée en degrés.</returns>
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
/// Fonction dont le rôle est de générer une dirrection selon les paramètres entrés
/// </summary>
/// <param name="angle">Float de la mesure de l'angle</param>
/// <param name="isRadian">Booléen indiquant Vrai si la valeur de rotation est en radian ou Faux si elle ne l'est pas</param>
/// <returns>Vecteur 2 float représentant la dirrection générée par la méthode</returns>
sf::Vector2f Movable::GenerateDirection(float angle, bool isRadian)
{
    if (!isRadian)
        angle = ToRadian(angle);
    direction.x = cos(angle);
    direction.y = sin(angle);
    return direction;
}
/// <summary>
/// Fonction dont le rôle est de retourner la position de l'objet
/// </summary>
/// <returns>Vector2f représentant la position de l'objet</returns>
sf::Vector2f Movable::GetPosition() const
{
    return sprite.getPosition();
}

/// <summary>
/// Fonction dont le ^rôle est de retourner la position en X de l'objet
/// </summary>
/// <returns>float.représentant la position en X de l'objet</returns>
float Movable::GetX() const
{
    return sprite.getPosition().x;
}
/// <summary>
/// Fonction dont le ^rôle est de retourner la position en Y de l'objet
/// </summary>
/// <returns>float.représentant la position en Y de l'objet</returns>
float Movable::GetY() const
{
    return sprite.getPosition().y;
}
/// <summary>
/// Fonction dont le rôle est de dessiner à l'écran l'objet
/// </summary>
/// <param name="mainWin">RenderWindow représentant l'écran qui affichera l'objet</param>
void Movable::Draw(sf::RenderWindow & mainWin)
{
    mainWin.draw(sprite);
}
/// <summary>
/// Fonction dont le rôle est de retourner la collision de l'objet
/// </summary>
/// <returns>CollisionSphere.</returns>
CollisionSphere Movable::GetCollider() const
{
    return sphereCollider;
}
/// <summary>
/// Fonction dont le rôle est de retourner la texture de l'objet
/// </summary>
/// <returns>Texture représentant la texture de l'objet.</returns>
sf::Texture Movable::GetTexture()
{
    return texture;
}
/// <summary>
/// Fonction dont le rôle est de convertir en degrés une unité en radians reçue et de retourner le résultat
/// </summary>
/// <param name="radians">L'unité en radians à convertir en degrés</param>
/// <returns>float.représentant la valeur en degrés de l'unité reçue en radians</returns>
float Movable::ToDegree(float radians) const
{
    return radians *(180/M_PI);
}
/// <summary>
/// Fonction dont le rôle est de convertir en radians une unité en degrés reçue et de retourner le résultat
/// </summary>
/// <param name="radians">L'unité en degrés à convertir en radians</param>
/// <returns>float.représentant la valeur en radians de l'unité reçue en degrés</returns>
float Movable::ToRadian(float degrees) const
{
    return degrees *(M_PI / 180);
}