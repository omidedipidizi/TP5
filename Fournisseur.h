#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include "Usager.h"
#include "GestionnaireProduits.h"

using namespace std;

class Fournisseur : public Usager
{
  public:
    Fournisseur();
    Fournisseur(const string &nom, const string &prenom, int identifiant, const string &codePostal);
	~Fournisseur();
	// TODO : Modifier l'implémentation de ses méthodes : ----
	GestionnaireProduits* obtenirCatalogue() const;
    void afficherCatalogue() const;
    virtual void afficher() const;
    virtual void reinitialiser();
    virtual void ajouterProduit(Produit *produit);
    virtual void enleverProduit(Produit *produit);   
	// -------------------------------------------------------

	// TODO : implémenter les méthodes suivantes :
	Produit* trouverProduitPlusCher() const;
	void DiminuerPrix(int pourcent) const;

  private:
   // vector<Produit *> catalogue_;
	GestionnaireProduits*  catalogue_;
};

#endif
