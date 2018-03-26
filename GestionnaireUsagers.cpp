/********************************************
* Titre: Travail pratique #5 - GestionnaireUsagers.cpp
* Date: 9 mars 2018
* Auteur: Ryan Hardie
*******************************************/

#include "GestionnaireUsagers.h"

double GestionnaireUsager::obtenirChiffreAffaires() const
{
	double sommes=0.0;
	//remplacer par pourChaqueElements?
	for (auto it = conteneur_.begin; it != conteneur_.end; it++) {
		sommes += (*it)->obtenirTotalAPayer();
	}
	return sommes;
}


