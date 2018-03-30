#include "Fournisseur.h"
#include <iostream>

Fournisseur::Fournisseur()
    : Usager()
{
	catalogue_ = new GestionnaireProduits;
}

Fournisseur::Fournisseur(const string &nom, const string &prenom, int identifiant,
                         const string &codePostal)
    : Usager(nom, prenom, identifiant, codePostal)
{
	catalogue_ = new GestionnaireProduits;
}

Fournisseur::~Fournisseur()
{
	delete catalogue_;
}

GestionnaireProduits* Fournisseur::obtenirCatalogue() const
{
    return catalogue_;
}

void Fournisseur::afficherCatalogue() const
{
	// TODO : À modifier
    cout << "CATALOGUE (de " << obtenirNom() << ")"
         << "\n";
	catalogue_->afficher();
}

void Fournisseur::afficher() const
{
	// TODO : À modifier
    Usager::afficher();
    cout << "\t\tcatalogue:\t" << size_t(catalogue_) << " elements" << endl;
}

void Fournisseur::reinitialiser()
{
	// TODO : À modifier
	catalogue_->reinitialiserFournisseur();
}

void Fournisseur::ajouterProduit(Produit *produit)
{
	// TODO : À modifier
    /*for (unsigned int i = 0; i < catalogue_.size(); i++)
        if (catalogue_[i] == produit)
            return;
    Fournisseur *fournisseur = produit->obtenirFournisseur();
    if (fournisseur != nullptr && fournisseur != this)
        fournisseur->enleverProduit(produit);
    catalogue_.push_back(produit);*/
	catalogue_->ajouter(produit);
}

void Fournisseur::enleverProduit(Produit *produit)
{
	catalogue_->supprime(produit);
}

Produit * Fournisseur::trouverProduitPlusCher() const
{
	return catalogue_->trouverProduitPlusCher();
}

void Fournisseur::DiminuerPrix(int pourcent) const
{
	FoncteurDiminuerPourcent diminuerPrix(pourcent);
	catalogue_->pourChaqueElement(diminuerPrix);
}
