#include "Balle.h"

using namespace pusg;

Balle::Balle(): vitesse(0), mouvement(0,0), arret(true), pv(100), friction(0.9975f)
{
	//Friction de 1.0f: aucune friction
	//friction = 0.9975f; //1,0f 0.9975f 0.995f 0.99f
}

void Balle::appliquerFriction() 
{
	//Moment où on peut appliquer la friction.
	mouvement.x *= friction;
	mouvement.y *= friction;

	testerArret();
}

Vector2f& Balle::getMouvement()
{
	return mouvement;
}

const Vector2f& Balle::getPosition() const
{
	return position;
}

float Balle::getVitesse() const
{
	return vitesse;
}

int Balle::getNoBalle() const
{
	return noBalle;
}

void Balle::testerArret()
{
	if (abs(mouvement.x) < 0.1f && abs(mouvement.y) < 0.1f)
	{
		mouvement.x = 0.0f;
		mouvement.y = 0.0f;
		arret = true;
	}
}

void Balle::setMouvement(float mouvementX, float mouvementY)
{
	this->mouvement.x = mouvementX;
	this->mouvement.y = mouvementY;
}

void Balle::setPosition(const Vector2f& position)
{
	this->position = position;
}

void Balle::setPosition(const float positionX, const float positionY)
{
	this->position.x = positionX;
	this->position.y = positionY;
}

void Balle::setVitesse(const float vitesse)
{
	this->vitesse = vitesse;
}

void Balle::init(const Texture& texture, const int noBalle)
{
	rayon = texture.getSize().x /2 ;
	this->noBalle = noBalle;
}

void Balle::hit()
{
	pv -= 1;
}

bool Balle::enMouvement() const
{
	return !arret;
}

bool Balle::estMort() const
{
	return pv <= 0;
}

void Balle::injectionDeForce()
{
	//La force est de 1 à 25
	float force = ((float)(rand() % 100)) / 100.0f;  //Valeur de 0.00 à 0.99
	force *= 24.0f;
	force += 1.0f;

	float angle = ((float)(rand() % 100)) / 100.0f;  //Valeur de 0.00 à 0.99
	angle *= (M_PI * 2.0f);

	setMouvement(cos(angle) * force, sin(angle) * force);
	arret = false;
}

/// <summary>
/// L'algo classique des sphères de collision, avec un peu de
/// poutine supplémentaire pour gérer le résultat.
/// </summary>
/// <param name="autreBalle">L'autre balle.</param>
/// <returns>S'il y a eu collision ou non</returns>
bool Balle::testerCollision(Balle& autreBalle)
{
	float dX = this->getPosition().x - autreBalle.getPosition().x;
	float dY = this->getPosition().y - autreBalle.getPosition().y;

	float distance = sqrt(dX * dX + dY * dY);

	//Si pas de collision, on termine la méthode
	if (distance > rayon + autreBalle.rayon)
	{
		return false;
	}

	//S'il y a collision, probable que les balles ne seront plus aux arrêts non?
	arret = false;
	autreBalle.arret = false;

	resoudreCollision(autreBalle);
	
	hit();
	autreBalle.hit();

	return true;
}

/// <summary>
///Attention, ici c'est de la trigo un peu plus avancée, mais c'est l'algo classique pour 
///résoudre la redirection des directions de deux balles suite à une collision entre celles-ci.
///C'est une version simplifiée car on considère que toutes les balles ont le même poids.
/// </summary>
/// <param name="autreBalle"L'autre balle impliquée dans la collision.</param>
void Balle::resoudreCollision(Balle &autreBalle)
{
	Vector2f vecteurUnitaire = calculerVecteurUnitaire(autreBalle.getPosition() - this->getPosition());
	Vector2f tangenteUnitaire(-vecteurUnitaire.y, vecteurUnitaire.x);

	Vector2f vitesseNormale1 = (vecteurUnitaire.x * autreBalle.getMouvement().x + vecteurUnitaire.y * autreBalle.getMouvement().y) * vecteurUnitaire;
	Vector2f vitesseTangente1 = (tangenteUnitaire.x * this->getMouvement().x + tangenteUnitaire.y * this->getMouvement().y) * tangenteUnitaire;
	Vector2f vitesseNormale2 = (vecteurUnitaire.x * this->getMouvement().x + vecteurUnitaire.y * this->getMouvement().y) * vecteurUnitaire;
	Vector2f vitesseTangente2 = (tangenteUnitaire.x * autreBalle.getMouvement().x + tangenteUnitaire.y * autreBalle.getMouvement().y) * tangenteUnitaire;

	this->setMouvement(vitesseNormale1.x + vitesseTangente1.x, vitesseNormale1.y + vitesseTangente1.y);
	autreBalle.setMouvement(vitesseNormale2.x + vitesseTangente2.x, vitesseNormale2.y + vitesseTangente2.y);
}

Vector2f Balle::calculerVecteurUnitaire(Vector2f normale) const
{
	float pente = sqrt(normale.x * normale.x + normale.y * normale.y);

	//Si 0, ça provoque une division par 0.
	if (pente != 0.0f)
	{
		return Vector2f(normale.x / pente, normale.y / pente);
	}

	return Vector2f(0.0f, 0.0f);
}


/// <summary>
/// S'il y a chevauchement, on replace simplement une 
/// des balles à la toute limite de l'autre balle.
/// </summary>
/// <param name="autreBalle">L'autre balle impliquée dans la collision.</param>
void Balle::ajusterChevauchement(Balle &autreBalle)
{
	//AVEC CES TROIS LIGNES DE CODE ON CALCULE LA DISTANCE ENTRE LES DEUX BALLES
	float dX = getPosition().x - autreBalle.getPosition().x;
	float dY = getPosition().y - autreBalle.getPosition().y;
	float distance = sqrt(dX * dX + dY * dY);

	//S'IL Y A CHEVAUCHEMENT
	if (distance < rayon + autreBalle.rayon)
	{
		//AVEC CES TROIS LIGNES DE CODE ET LE IF QUI SUIT ON CALCULE 
		//L'ANGLE ENTRE LES DEUX BALLES
		float diffX = autreBalle.getPosition().x - getPosition().x;
		float diffY = autreBalle.getPosition().y - getPosition().y;
		float angle = atanf(diffY / diffX);

		if (autreBalle.getPosition().x < getPosition().x)
		{
			angle += M_PI;
		}
		//FIN DU CALCUL DE L'ANGLE

		//ON OBTIENT LA DIFFÉRENCE ENTRE LA DISTANCE ACTUELLE DES DEUX BALLES
		//ET CELLE ENTRE LES DEUX BALLES QUAND ELLES SE TOUCHENT SANS SE CHEVAUCHER
		float difference = (rayon + autreBalle.rayon) - distance;
		
		//ON AUGMENTE LA DISTANCE EN DÉPLACANT LÉGEÈREMENT AUTREBALLE SUIVANT L'AXE DE L'ANGLE ENTRE LES DEUX BALLES
		autreBalle.setPosition(autreBalle.getPosition().x + difference * cos(angle), autreBalle.getPosition().y + difference * sin(angle));
	}
}

void Balle::dessiner(RenderWindow& fenetre, Sprite& spriteBalle, Text& text)
{
	text.setString(std::to_string(noBalle) + ": " + std::to_string(pv));

	spriteBalle.setPosition(this->position);
	text.setPosition(this->position.x - 20, this->position.y - 10);

	fenetre.draw(spriteBalle);
	fenetre.draw(text);
}
