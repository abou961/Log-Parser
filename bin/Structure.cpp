/*************************************************************************
                           Structure  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Structure> (fichier Structure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <utility>

//------------------------------------------------------ Include personnel
#include "Structure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Structure::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

int Structure::index ;


void Structure::Top10 (ostream &os)
{
    multimap<int, string> Top10;//structure permettant de stocker le Top 10 pour l'affichage

    for (auto const i: CollectionComplexe)
    {
        Top10.insert(make_pair(i.second.second, i.first));
    }

    multimap<int , string>::reverse_iterator it = Top10.rbegin();

    for(int i = 0; i < 10; i++)
    {
            if(it != Top10.rend())
            {
                os << it->second << " ( " << it->first << " hits )"<<  endl;
                ++it;
            }
    }
}


ostream& operator <<(ostream& os, const Structure & s)
{
    //StructureComplexe::const_iterator it = s.CollectionComplexe.begin();
    StructureIndex::const_iterator iti = s.nodeIndex.begin();

    os << "digraph { \n";

    while (iti != s.nodeIndex.end()) 
    {
        os << "node"<< iti->second << " [label=\"" << iti->first<<"\"];" << endl;
        iti++;
    }

    StructureComplexe::const_iterator it = s.CollectionComplexe.begin();

    while (it != s.CollectionComplexe.end()) 
    {
        map< string,int>::const_iterator it2 = it->second.first.begin();
        while (it2 != it->second.first.end()) 
        {
            os << "node"<< s.nodeIndex.find(it2->first)->second <<" -> node"<< s.nodeIndex.find(it->first)->second<<" [label=\"" << it2->second<< "\"];"<< endl;
            it2++;
        }
        it++;
    }

    os << "}";

    return os;
}



//------------------------------------------------- Surcharge d'opérateurs
Structure & Structure::operator = ( const Structure & unStructure )
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Structure::Structure ( const Structure & unStructure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Structure>" << endl;
#endif
} //----- Fin de Structure (constructeur de copie)


Structure::Structure ( )
// Algorithme :
//
{
    Structure::index = 0;
#ifdef MAP
    cout << "Appel au constructeur de <Structure>" << endl;
#endif
} //----- Fin de Structure


Structure::~Structure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Structure>" << endl;
#endif
} //----- Fin de ~Structure

string Structure::OptimisationLog(string & chaine)
{
    int pos = chaine.find("?");
    if(pos != string::npos)
    {
        chaine = chaine.substr(0, pos+1);
    }
    return chaine;
}

void Structure::AjoutLog(string noeudReferent, string noeudCible)
{
    int nbPassages = 1;
    noeudReferent = OptimisationLog(noeudReferent);
    noeudCible = OptimisationLog(noeudCible);
    CollectionComplexe[noeudCible].first[noeudReferent] +=nbPassages;
    CollectionComplexe[noeudCible].second +=nbPassages;
    if ( nodeIndex.find(noeudReferent) == nodeIndex.end() ) {
        nodeIndex[noeudReferent] = Structure::index++;
    }

    if ( nodeIndex.find(noeudCible) == nodeIndex.end() ) {
        nodeIndex[noeudCible] = Structure::index++;
    }
    // not found
    
    
    

    /*cout << noeudReferent << " -> " << noeudCible<< " " <<CollectionComplexe[noeudCible].first[noeudReferent] << endl;
    cout << noeudCible << ": " << CollectionComplexe[noeudCible].second << endl;*/
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

