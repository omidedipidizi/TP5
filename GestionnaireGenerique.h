/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once

// TODO : Créer la classe GestionnaireGenerique

// TODO : Méthodes :
/*
- ajouter()
- supprime()
- obtenirConteneur()
- pourChaqueElement()
*/
#include "Foncteur.h"
template<typename T, typename C , typename A ,typename S>
class GestionnaireGenerique {
public:
	GestionnaireGenerique():ajouter_(conteneur_),supprimer_(conteneur_) {

	}
	C obtenirConteneur() const {
		return conteneur_;
	}
	void ajouter(T* pointeurGenerique) {
		ajouter_(pointeurGenerique);
	};
	void supprime(T* pointeurGenerique) {
		supprimer_(pointeurGenerique);
	};
	template<typename Predicat>
	void pourChaqueElement(Predicat foncteur) const {
		for_each(conteneur_.begin(),conteneur_.end(),foncteur);
	}
protected:
	C conteneur_;
	A ajouter_;
	S supprimer_;
};