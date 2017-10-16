#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>

using namespace sf;

namespace pusg
{
	class Balle
	{
	public:
		Balle();
		void init(const Texture& texture, const int noBalle);

		int getNoBalle() const;

		float getVitesse() const;
		void setVitesse(const float vitesse);

		Vector2f& getMouvement();
		void setMouvement(float mouvementX, float mouvementY);

		const Vector2f& getPosition() const;
		void setPosition(const Vector2f& position);
		void setPosition(const float positionX, const float positionY);

		void injectionDeForce();
		bool testerCollision(Balle& autreBalle);
		void ajusterChevauchement(Balle& autreBalle);
		void appliquerFriction();

		void dessiner(RenderWindow& fenetre, Sprite& spriteBalle, Text& text);
		
		void hit();
		bool enMouvement() const;
		bool estMort() const;


	private:
		float vitesse;
		Vector2f position;
		Vector2f mouvement;
		float rayon;
		float friction;
		bool arret;
		int noBalle;
		int pv;

		Vector2f calculerVecteurUnitaire(const Vector2f normale) const;
		void resoudreCollision(Balle &autreBalle);
		void testerArret();
	};
}

