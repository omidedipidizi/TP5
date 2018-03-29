/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"

double GestionnaireUsagers::obtenirChiffreAffaires() const
{
	double somme=0.0;
	pourChaqueElement([&somme](Usager* n) {somme += n->obtenirTotalAPayer(); });
	return somme;
}

void GestionnaireUsagers::encherir(Client * client, ProduitAuxEncheres * produit, double montant) const
{
	if (produit->obtenirPrix() < montant)
		produit->mettreAJourEnchere(client, montant);
}

void GestionnaireUsagers::reinitialiser()
{
	//reinitialiser tous les usagers
	pourChaqueElement([](Usager* n) {n->reinitialiser();});
}

void GestionnaireUsagers::afficher() const
{
	pourChaqueElement([](Usager* n) {n->afficher(); });
}


