/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

#include "GestionnaireGenerique.h"
#include "Produit.h"
#include "ProduitAuxEncheres.h"
#include <vector>
#include <functional> 
using namespace std;
// TODO : Cr�er la classe GestionnaireProduits

// TODO : M�thodes :
/*
- reinitialiserClient();
- reinitialiserFournisseur();
- afficher();
- obtenirTotalAPayer();
- obtenirTotalApayerPremium();
- trouverProduitPlusCher();
- obtenirProduitsEntre();
- obtenirProduitSuivant();
*/
class GestionnaireProduits:public GestionnaireGenerique<Produit, multimap<int,Produit*>, AjouterProduit, SupprimerProduit> {
	public:
	void reinitialiserClient();
	void reinitialiserFournisseur();
	void afficher() const;
	double obtenirTotalAPayer();
	double obtenirTotalApayerPremium();
	Produit* trouverProduitPlusCher();
    vector<pair<int,Produit*>> obtenirProduitsEntre(double borneInferieur,double borneSupperieur) const;
	Produit* obtenirProduitSuivant(Produit* produit) const;
};