/*************************************************************************
                           InterfaceAnalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <InterfaceAnalogue> (fichier InterfaceAnalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "Structure.h"

//------------------------------------------------------ Include personnel
#include "InterfaceAnalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type InterfaceAnalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
InterfaceAnalogue::InterfaceAnalogue ( const InterfaceAnalogue & unInterfaceAnalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <InterfaceAnalogue>" << endl;
#endif
} //----- Fin de InterfaceAnalogue (constructeur de copie)


InterfaceAnalogue::InterfaceAnalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <InterfaceAnalogue>" << endl;
#endif
} //----- Fin de InterfaceAnalogue


void InterfaceAnalogue::AnalogueSansOp(string nomFic)
{
    ifstream is (nomFic);
    Node n;
    if(!is)
    {
        cerr << "Problème d'ouverture de fichier";
    }
    while(is >> n)
    {
        s.AjoutLog( n.getRef(), n.getCible());
    }

    s.Top10(cout);
}

void InterfaceAnalogue::AnalogueOp_e(string nomFic)
{
    ifstream is (nomFic);
    Node n;
    if(!is)
    {
        cerr << "Problème d'ouverture de fichier";
        return;
    }
    while(is >> n)
    {
        string ref_extension_3, ref_extension_4, cible_extension_3, cible_extension_4 ;
        if ( n.getRef().size() > 3 )
        {
            ref_extension_3 = n.getRef().substr(n.getRef().size()-3, 3); 
        }
        else
        {
            ref_extension_3 = n.getRef();
        }
        if ( n.getRef().size() > 4 )
        {
            ref_extension_4 = n.getRef().substr(n.getRef().size()-4, 4); 
        }
        else
        {
            ref_extension_4 = n.getRef();
        }
        if ( n.getCible().size() > 3)
        {
            cible_extension_3 = n.getCible().substr(n.getCible().size()-3, 3); 
        }
        else
        {
            cible_extension_3 = n.getCible();
        }
        if( n.getCible().size() > 4 )
        {
            cible_extension_4 = n.getCible().substr(n.getCible().size()-4, 4); 
        }
        else
        {
            cible_extension_4 = n.getCible();
        }

        
        if( (ref_extension_3 != ".js") && (cible_extension_3 != ".js") 
          && ref_extension_4 != ".jpg" && ref_extension_4 != ".png" && ref_extension_4 != ".css"
          && cible_extension_4 != ".jpg" && cible_extension_4 != ".png" && cible_extension_4 != ".css"
          && cible_extension_4 != ".gif")
        {
            s.AjoutLog( n.getRef(), n.getCible());
        }

    }
    s.Top10(cout);
}


void InterfaceAnalogue::AnalogueOp_g(string nomFic, string nomFicDot)
{
    ofstream os (nomFicDot);
    ifstream is (nomFic);

    if(!is)
    {
        cerr << "Problème d'ouverture de fichier";
        return;
    }

    Node n;
    while(is >> n)
    {
        s.AjoutLog( n.getRef(), n.getCible());
    }
    os << s;
    os.close();
    s.Top10(cout);
}

void InterfaceAnalogue::AnalogueOp_t(string nomFic, int heure)
{

    if( heure < 0 || heure > 23 )
    {
        cerr << "Veuillez rentrer une heure cohérente. Plus d'informations sur le format avec -help";
        return;
    }
    ifstream is (nomFic);
    Node n;
    if(!is)
    {
        cerr << "Problème d'ouverture de fichier";
        return;
    }
    while(is >> n)
    {
        if(n.getHeure()*3600 + n.getMinute()*60 + n.getSeconde() >= heure*3600
        && n.getHeure()*3600 + n.getMinute()*60 + n.getSeconde() < (heure+1)*3600)
        {
            s.AjoutLog( n.getRef(), n.getCible());
        }
    }
    s.Top10(cout);
}

void InterfaceAnalogue::AnalogueOp_e_g(string nomFic, string nomFicDot)
{
    AnalogueOp_e(nomFic);
    ofstream os (nomFicDot);
    os << s;
    os.close();
}

void InterfaceAnalogue::AnalogueOp_e_t(string nomFic, int heure)
{
    ifstream is (nomFic);
    if( heure < 0 || heure > 23 )
    {
        cerr << "Veuillez rentrer une heure cohérente. Plus d'informations sur le format avec -help";
        return;
    }
    if(!is)
    {
        cerr << "Problème d'ouverture de fichier";
        return;
    }
    Node n;
    while(is >> n)
    {
        string ref_extension_3, ref_extension_4 , cible_extension_3, cible_extension_4 ;
        if ( n.getRef().size() > 3 )
        {
            ref_extension_3 = n.getRef().substr(n.getRef().size()-3, 3); 
        }
        else
        {
            ref_extension_3 = n.getRef();
        }
        if ( n.getRef().size() > 4 )
        {
            ref_extension_4 = n.getRef().substr(n.getRef().size()-4, 4); 
        }
        else
        {
            ref_extension_4 = n.getRef();
        }
        if ( n.getCible().size() > 3)
        {
            cible_extension_3 = n.getCible().substr(n.getCible().size()-3, 3); 
        }
        else
        {
            cible_extension_3 = n.getCible();
        }
        if( n.getCible().size() > 4 )
        {
            cible_extension_4 = n.getCible().substr(n.getCible().size()-4, 4); 
        }
        else
        {
            cible_extension_4 = n.getCible();
        }

        
        if( (ref_extension_3 != ".js") && (cible_extension_3 != ".js") 
          && ref_extension_4 != ".jpg" && ref_extension_4 != ".png" && ref_extension_4 != ".css"
          && cible_extension_4 != ".jpg" && cible_extension_4 != ".png" && cible_extension_4 != ".css"
          && cible_extension_4 != ".gif")
        {
            if(n.getHeure()*3600 + n.getMinute()*60 + n.getSeconde() >= heure*3600
            && n.getHeure()*3600 + n.getMinute()*60 + n.getSeconde() < (heure+1)*3600)
            {
                s.AjoutLog( n.getRef(), n.getCible());
            }
        }

    }
    s.Top10(cout);
}

void InterfaceAnalogue::AnalogueOp_g_t(string nomFic, int heure, string nomFicDot)
{
    if( heure < 0 || heure > 23 )
    {
        cerr << "Veuillez rentrer une heure cohérente. Plus d'informations sur le format avec -help";
        return;
    }
    ofstream os (nomFicDot);
    ifstream is (nomFic);

     if(!is)
    {
        cerr << "Problème d'ouverture de fichier";
        return;
    }

    Node n;
    while(is >> n)
    {
       if(n.getHeure()*3600 + n.getMinute()*60 + n.getSeconde() >= heure*3600
        && n.getHeure()*3600 + n.getMinute()*60 + n.getSeconde() < (heure+1)*3600)
        {
            s.AjoutLog( n.getRef(), n.getCible());
        }
    }
    os << s;
    os.close();
    s.Top10(cout);
    
}

void InterfaceAnalogue::AnalogueOp_e_g_t(string nomFic, int heure, string nomFicDot)
{
    if( heure < 0 || heure > 23 )
    {
        cerr << "Veuillez rentrer une heure cohérente. Plus d'informations sur le format avec -help";
        return;
    }
    ofstream os (nomFicDot);
    ifstream is (nomFic);

     if(!is)
    {
        cerr << "Problème d'ouverture de fichier";
        return;
    }

    Node n;
    while(is >> n)
    {
       string ref_extension_3, ref_extension_4 , cible_extension_3, cible_extension_4 ;
        if ( n.getRef().size() > 3 )
        {
            ref_extension_3 = n.getRef().substr(n.getRef().size()-3, 3); 
        }
        else
        {
            ref_extension_3 = n.getRef();
        }
        if ( n.getRef().size() > 4 )
        {
            ref_extension_4 = n.getRef().substr(n.getRef().size()-4, 4); 
        }
        else
        {
            ref_extension_4 = n.getRef();
        }
        if ( n.getCible().size() > 3)
        {
            cible_extension_3 = n.getCible().substr(n.getCible().size()-3, 3); 
        }
        else
        {
            cible_extension_3 = n.getCible();
        }
        if( n.getCible().size() > 4 )
        {
            cible_extension_4 = n.getCible().substr(n.getCible().size()-4, 4); 
        }
        else
        {
            cible_extension_4 = n.getCible();
        }

        
        if( (ref_extension_3 != ".js") && (cible_extension_3 != ".js") 
          && ref_extension_4 != ".jpg" && ref_extension_4 != ".png" && ref_extension_4 != ".css"
          && cible_extension_4 != ".jpg" && cible_extension_4 != ".png" && cible_extension_4 != ".css"
          && cible_extension_4 != ".gif")
        {
            if(n.getHeure()*3600 + n.getMinute()*60 + n.getSeconde() >= heure*3600
            && n.getHeure()*3600 + n.getMinute()*60 + n.getSeconde() < (heure+1)*3600)
            {
                s.AjoutLog( n.getRef(), n.getCible());
            }
        }
    }
    os << s;
    os.close();
    s.Top10(cout);
}

InterfaceAnalogue::~InterfaceAnalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <InterfaceAnalogue>" << endl;
#endif
} //----- Fin de ~InterfaceAnalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

