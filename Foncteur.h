/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include <map>
#include <set>
#include <algorithm>
#include "Produit.h"
#include "Usager.h"
using namespace std;
// TODO : Créer le FoncteurEgal
template <typename T>
class FoncteurEgal {
	
public:
	FoncteurEgal( T* recherche) :t_(recherche) {};
	bool operator()(pair<int, T*> pair) {
		return pair.second == t_;
	}

private:
	template <typename T*>
		T* t_;
};


// TODO : Créer le FoncteurGenerateurId
class FoncteurGenerateurId {
public:
	FoncteurGenerateurId() :id_(0) {}
	void operator()() {
		id_++;
	}
private:
	int id_;
};


// TODO : Créer le FoncteurDiminuerPourcent
class FoncteurDiminuerPourcent {
public:
	FoncteurDiminuerPourcent(int pourcentage):pourcentage_(pourcentage){}
	void operator()(pair<int, Produit*> pair) {
		//ne pas reduire le prix sode
		pair.second->modifierPrix((pair.second->Produit::obtenirPrix()*(1- (pourcentage_/100.00))));
	}
private:
	int pourcentage_;
};

// TODO : Créer le FoncteurIntervalle
class FoncteurIntervalle {
public:
	FoncteurIntervalle(double borneInf,double borneSup) :borneInf_(borneInf), borneSup_(borneSup) {}
	bool operator()(pair<int, Produit*> pair) {
		return (pair.second->obtenirPrix() >= borneInf_ && pair.second->obtenirPrix() <= borneSup_);
	}
private:
	double borneInf_;
	double borneSup_;
};


// TODO : Créer le Foncteur AjouterProduit
class AjouterProduit {
public:
	AjouterProduit(multimap<int, Produit*>& multimap) :multimap_(multimap) {};
	multimap<int, Produit*>& operator()(const pair<int,Produit*>& pair) {
		multimap_.insert(make_pair(pair.first,pair.second));
		return multimap_;
	}
private:
	multimap<int, Produit*>& multimap_;
};
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Ajoute dans la multimap la pair passé par paramètre et retourne la multimap_;
*/

// TODO : Créer le Foncteur SupprimerProduit
class SupprimerProduit {
public:
	SupprimerProduit(multimap<int, Produit*>& multimap) :multimap_(multimap) {};
	multimap<int, Produit*>& operator()(const pair<int, Produit*>& pair) {
		FoncteurEgal<Produit> foncteurEgal(pair.second);
		auto it= find_if(multimap_.begin, multimap_.end, foncteurEgal(pair));//on cherche la paire dans toute la multimap  
		if (it != multimap_.end()) {//si on trouve la paire
			multimap_.erase(it);//on eleve la paire pointer par l'iterrateur
		}
		return multimap_; //on retourne la multimap modifiée ou non modifiée
	}
private:
	multimap<int, Produit*>& multimap_;
};
/*
Attributs :
- &multimap_;
Méthodes :
- operator(); Utilise la fonction find_if avec le FoncteurEgal. Si le Produit existe,
				on supprime le Produit et on retourne la multimap_,
				sinon on retourne juste la multimap_ sans supprimer l'élément.
*/

//TODO : Créer le Foncteur AjouterUsager
class AjouterUsager {
public:
	AjouterUsager(set<Usager*>& setUsage):set_(setUsage) {}
	set<Usager*>& operator()(Usager* usager) {
		set_.insert(usager);
		return set_;
	}
private:
	set<Usager*>& set_;
};
/*
Attributs :
- &set;
Méthodes :
- operateur(); Trouve l'Usager dans le set_, s'il existe on le supprime et on retourne le set_, sinon on retourne juste directement le set_.
*/
class SupprimerUsager {
public:
	SupprimerUsager(set<Usager*>& setUsage) :set_(setUsage){}
	set<Usager*>& operator()(Usager* usager) {
		set<Usager*>::iterator it = set_.find(usager);
		if (it != set_.end) {//si on trouve l'usager
			set_.erase(it);//on supprime l'usager à l'aide de l'itérateur
		}
		return set_;
	}
private:
	set<Usager*>& set_;
};