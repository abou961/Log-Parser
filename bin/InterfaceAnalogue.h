/*************************************************************************
                           INTERFACE_ANALOGUE  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <INTERFACE_ANALOGUE> (fichier INTERFACE_ANALOGUE.h) ----------------
#if ! defined ( INTERFACE_ANALOGUE_H )
#define INTERFACE_ANALOGUE_H

#include <string>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <INTERFACE_ANALOGUE>
//
//
//------------------------------------------------------------------------

class InterfaceAnalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques



//-------------------------------------------- Constructeurs - destructeur
    InterfaceAnalogue ( const InterfaceAnalogue & unInterfaceAnalogue );

    InterfaceAnalogue ( );

    //Les fonctions ci-dessous permettent de définir les fonctions associées aux différentes options de notre commande analog
    //Les noms sont explicites et permettent de gérer les fonctions associées aux commandes -x et -y telles que AnalogueOp_x_y par exemple.
    void AnalogueSansOp(string nomFic);
    void AnalogueOp_e(string nomFic);
    void AnalogueOp_g(string nomFic, string nomFicDot);
    void AnalogueOp_t(string nomFic, int heure);
    void AnalogueOp_e_g(string nomFic, string nomFicDot);
    void AnalogueOp_e_t(string nomFic, int heure);
    void AnalogueOp_g_t(string nomFic, int heure, string nomFicDot);
    void AnalogueOp_e_g_t(string nomFic, int heure, string nomFicDot);

    virtual ~InterfaceAnalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    Structure s;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <InterfaceAnalogue>

#endif // InterfaceAnalogue_H

