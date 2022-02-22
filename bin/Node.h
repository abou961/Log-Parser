
//---------- Interface de la classe <Node> (fichier Node.h) ----------------
#if ! defined ( NODE_H )
#define NODE_H
#include <string>
#include <fstream>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Node>
//
//
//------------------------------------------------------------------------

class Node
{
//----------------------------------------------------------------- PUBLIC

    typedef struct Log
        {
            string ip;
            string userLog;
            string authUser;
            string date;
            string heure;
            string gmt;
            string typeRequete;
            int returnCode;
            string quantiteDonnees;
            string idClient;
            string adresseBase;
            Log (string i= "", string ul = "", string au = "", string da = "", 
            string h = "", string g = "", string tr = "", int rc = 0, string qd = "", string idc = "", string ab = ""):
            ip(i), userLog(ul), authUser(au), date(da), heure(h),
            gmt(g), typeRequete(tr), returnCode(rc), quantiteDonnees(qd), idClient(idc), adresseBase(ab){};
        }
        Log;
        //Cette structure permet de récupérer toutes les informations utiles depuis 1 ligne du fichier log
        //Seule une poignée de ces informations seront exploitées et enregistrées dans notre programme.

public:

    // fonction amie de la classe Node qui permet de réaliser la surcharge
    // de l'opérateur >> pour récupérer les noeuds dans le fichier log

    friend istream & operator >>( istream & is, Node & node);


    friend ostream & operator <<(ostream & os, const Node & node);

    inline string getRef() const {return referant;}
    inline string getCible() const {return cible;}
    int getHeure() const;
    //les deux get suivants ne seront pas utilisés dans ce TP mais seront utiles lors de futures améliorations.
    int getMinute() const;
    int getSeconde() const;


//----------------------------------------------------- Méthodes publiques



//-------------------------------------------- Constructeurs - destructeur


    Node ( string ref = "", string cib = "", Log l = Log()):
    referant(ref), cible(cib), infos(l) {}
    
    // Constructeur


//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés

    string referant;
    string cible;
    Log infos;
    
};


#endif

