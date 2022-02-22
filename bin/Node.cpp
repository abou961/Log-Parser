
//---------- Réalisation de la classe <Node> (fichier Node.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>


//------------------------------------------------------ Include personnel
#include "Node.h"

//------------------------------------------------------------- Constantes

const char SPACE = ' ';
const char CORCHET_SORTANT = ']';
const char DOUBLE_POINT = ':';
const char GUILLEMET = '"';
const char SLASH = '/';




//------------------------------------------------- Surcharge de l'opérateur >> 

int Node::getHeure() const
{
    string tmp;
    istringstream iss(infos.heure);
    getline(iss, tmp, ':');
    int heure = stoi(tmp);
    //cout << infos.heure << endl;
    
    return heure;
}

int Node::getMinute() const
{
    string tmp;
    istringstream iss(infos.heure);
    getline(iss, tmp, ':');
    getline(iss, tmp, ':');
    int minute = stoi(tmp);
    //cout << infos.heure << endl;
    
    return minute;
}

int Node::getSeconde() const
{
    string tmp;
    istringstream iss(infos.heure);
    getline(iss, tmp, ':');
    getline(iss, tmp, ':');
    getline(iss, tmp, ' ');
    int seconde = stoi(tmp);
    //cout << infos.heure << endl;
    
    return seconde;
}

istream & operator >>(istream & is, Node & node)
{
    char poubelle;
    string poubelleString;

    ifstream config("config.txt");

    string adBase;
    config >> adBase;

    getline(is,node.infos.ip, SPACE);
    getline(is, node.infos.userLog, SPACE);
    getline(is, node.infos.authUser, SPACE);
    
    is >> poubelle;


    getline(is, node.infos.date, DOUBLE_POINT);
    getline(is, node.infos.heure, SPACE);
    getline(is, node.infos.gmt, CORCHET_SORTANT);

    is >> poubelle;

    getline(is, node.infos.typeRequete, SPACE);
    getline(is, node.cible, SPACE);
    getline(is, poubelleString, GUILLEMET);

    is >> node.infos.returnCode;

    getline(is, poubelleString, SPACE);
    getline(is, node.infos.quantiteDonnees, SPACE);

  

    string tmp;
    getline(is, poubelleString, GUILLEMET);
    getline(is, tmp, GUILLEMET);

    if(tmp == "-")
    {
        node.referant = "-";
    }
    else
    {
        if(tmp.length() < adBase.length())
        {
            node.referant = tmp;
            node.infos.adresseBase = "";
        }
        else
        {
            string tmp_test_base = tmp.substr(0, adBase.length());
            if(tmp_test_base == adBase)
            {
                node.referant = tmp.substr(adBase.length());
                node.infos.adresseBase = adBase;
            }
            else
            {
                node.referant = tmp;
                node.infos.adresseBase = "";
            }
        }
    }

    getline(is, poubelleString, GUILLEMET);
    getline(is, node.infos.idClient, GUILLEMET);

    return is;

}

//------------------------------------------------- Surcharge de l'opérateur <<

ostream & operator <<(ostream & os, const Node & node)
{
    os << " Référant : " << node.referant << endl;
    os << " Cible : " << node.cible << endl;
    os << "informations : " << endl;

    os << " ip : " << node.infos.ip << endl;
    os << " userLog : " << node.infos.userLog << endl;
    os << " authUser : " << node.infos.authUser << endl;
    os << " date : " << node.infos.date << endl;
    os << " heure : " << node.infos.heure << endl;
    os << " gmt : " << node.infos.gmt << endl;
    os << " typeRequete : " << node.infos.typeRequete << endl;
    os << " returnCode : " << node.infos.returnCode << endl;
    os << " quantitée de donnée : " << node.infos.quantiteDonnees << endl;
    os << " id Client : " << node.infos.idClient << endl;
    os << " adresse de base : " << node.infos.adresseBase << endl;

    return os;
}



