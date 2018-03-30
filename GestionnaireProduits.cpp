/********************************************
* Titre: Travail pratique #5 - GestionnaireProduits.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireProduits.h"

void GestionnaireProduits::reinitialiserClient()
{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		ProduitAuxEncheres *produit = dynamic_cast<ProduitAuxEncheres *>(it->second);
		if (produit) {
			produit->modifierEncherisseur(nullptr);
			produit->modifierPrix(produit->obtenirPrixInitial());
		}
		conteneur_.erase(it);
	}
}

void GestionnaireProduits::reinitialiserFournisseur()
{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		it->second->modifierFournisseur(nullptr);
		conteneur_.erase(it);
	}
}

void GestionnaireProduits::afficher() const
{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) 
		it->second->afficher();

	cout << endl;
}

double GestionnaireProduits::obtenirTotalAPayer()
{
	double total=0.0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
		total+=it->second->obtenirPrix();
	return total;
}

double GestionnaireProduits::obtenirTotalApayerPremium()
{
	double montant = 0.0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		double prix = it->second->obtenirPrix();
		montant += prix < 5 ? 0 : prix - 5;
	}
	return montant;
}

Produit* GestionnaireProduits::trouverProduitPlusCher()
{
	 auto it =max_element(conteneur_.begin(), conteneur_.end(), [](Produit* p) {return p->obtenirPrix();});
	 return (it->second);//return le produit
}

vector<pair<int, Produit*>> GestionnaireProduits::obtenirProduitsEntre(double borneInferieur, double borneSupperieur) const
{
	FoncteurIntervalle intervalle(borneInferieur, borneSupperieur);
	vector<pair<int, Produit*>> pairIntervalle;//contient des paires dont le prix est compris entre borneInferieur et borneSupperieur 
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(pairIntervalle), intervalle);
	return pairIntervalle;
}


Produit* GestionnaireProduits::obtenirProduitSuivant(Produit* produit) const
{
	auto it = find_if(conteneur_.begin(), conteneur_.end(),bind(greater<pair<int, Produit*>>(),placeholders::_1,pair<int,Produit*>(produit->obtenirReference(),produit)));
	return it->second;
}
