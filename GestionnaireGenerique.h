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
	C obtenirConteneur() const {
		return conteneur_;
	}
	void ajouter(T* pointeurGenerique) {
		A(pointeurGenerique);
	};
	void supprime(T* pointeurGenerique) {
		S(pointeurGenerique);
	};
	template<typename Predicat>
	void pourChaqueElement(Predicat foncteur) {
		for_each(conteneur_.begin,conteneur_.end,foncteur);
	}
protected:
	C conteneur_;
};