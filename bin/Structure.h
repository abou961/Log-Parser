/*************************************************************************
                           Structure  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Structure> (fichier Structure.h) ----------------
#if ! defined ( Structure_H )
#define Structure_H

using namespace std;
#include <map>
#include <utility>
#include <string>
#include <iostream>

typedef map< string, pair < map< string, int > , int> > StructureComplexe; // Structure pour stocker toutes les infos utiles
typedef map< string, int> StructureIndex; // Structure permettant de stocker les index associés aux noeuds pour produire le graphe

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Structure>
//
//
//------------------------------------------------------------------------

class Structure
{
//----------------------------------------------------------------- PUBLIC

public:
    static int index;
    //typedef struct Log;
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Structure & operator = ( const Structure & unStructure );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Structure ( const Structure & unStructure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Structure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Structure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjoutLog(string noeudCible, string noeudReferent);
    string OptimisationLog(string & chaineAOptimiser);
    // Mode d'emploi :
    //Ici l'optimisation s'effectuera sur les URL de recherche google, souvent longs.
    //On ne gardera que la partie qui informe que l'URL est une recherche du typ : "www.google.com/url?"
    friend ostream& operator<<(ostream& os, const Structure& s);//utile pour contruire le graphe
    void Top10(ostream& os);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    
    StructureComplexe CollectionComplexe;
    StructureIndex nodeIndex;


};

//-------------------------------- Autres définitions dépendantes de <Structure>

#endif // Structure_H



















