#include <iostream>
#include <string>
#include <sstream>
#include "Structure.h"
#include "Node.h"
#include "InterfaceAnalogue.h"


using namespace std;




int main(int nbParam, char * param[])
{
        int i;
        string parametres[nbParam];
        string nomFic;
        InterfaceAnalogue ia;
        string test;

        for(i = 0; i < nbParam; ++i)
        {
                string chaine(param[i]);
                parametres[i] = chaine;
        }

        // test du -config pour configurer le site depuis lequel nous analysons le fichier de log
        bool testConfig = false;
        // test du -help pour afficher la manuel d'utilisation
        bool testHelp = false;
        
        for (i = 0; i < nbParam; ++i)
        {
                if (parametres[i] == "-help")
                        testHelp = true;
        }

        if (testHelp)
        {
                cout << endl;
                cout << "pour configurer l’adresse locale sur laquelle nous effectuons l’analyse de fichier : \n" ;
                cout << "Lancer le programme avec l’option -config, soit ./analog -config. \n";
                cout << "(si d’autres options sont écrites, elles ne seront pas prises en compte)\n";
                cout << "Pour écrire l’adresse de base de l’url, écrire l’adresse sans le / à la fin \n";
                cout << "exemple : http://intranet-if.insa-lyon.fr et pas http://intranet-if.insa-lyon.fr/. \n";
                cout << "Une fois l’adresse enregistrée, vous pouvez éxecuter le programme normalement :";
                cout << "\t ./analog [options] nomFichier.log \n \n";

                cout << "NB : si aucune adresse locale est enregistrée, le programme ne s’exécutera pas ! \n";
                cout << "Néanmoins, lorsqu’une adresse est enregistrée, il n’est pas nécessaire de l’enregistrer \n";
                cout << "à nouveau pour exécuter le programme si vous ne souhaitez pas changer cette adresse. \n";
                cout << "Le programme s’exécutera avec la dernière adresse enregistrée. \n";
                cout << "Si vous voulez changer d’adresse locale, relancer le programme avec l’option -config \n \n";

                cout << "Les options, s’il y en a plusieurs, peuvent être écrites dans n’importe quel ordre sans problème. \n \n";
                cout << "pour l’option -g : \n ";
                cout << "\t écrire le nom du fichier .dot directement après le -g en cas de plusieurs options. \n ";
                cout << "\t Exemple : ./analog -g nomfichier.dot -e nomfic.log et non pas ./analog -g -e nomfichier.dot nomfic.log \n \n";
                cout << "pour l’option -t : \n ";
                cout << "\t L’heure sera un entier entre 0 et 23. Le programme ne prévoit pas les minutes. \n";
                cout << "\t Ainsi, les écritures 10:30 ou 10h30 ne prendront en compte que 10 pour 10h. \n";
                cout << "\t écrire l’heure directement après le -t en cas de plusieurs options. \n";
                cout << "\t Exemple : ./analog -t heure -e nomfichier.log et non pas ./analog -t -e heure nomfichier.log \n";
                cout << endl;
                return 0;
        }


        for (i = 0; i < nbParam; ++i)
        {
                if (parametres[i] == "-config")
                        testConfig = true;
        }

        ifstream config("config.txt");
        string adBase;
        config >> adBase;

        config.close();

        if (!testConfig)
        {
                if (adBase == "")
                {
                        cerr << "Avant de lancer le programme, il est nécesaire de taper './analog -config' pour configuer l'adresse locale" << endl;
                        return 0;
                }
        }

        else
        {
                cout << "Entrez l'adresse de base du site depuis lequel nous analysons le fichier de log : " << endl << "\t" ; 
                cin >> adBase;

                ofstream configW("config.txt");
                configW << adBase;

                configW.close();
                return 0;
        }


        // Cas où il n'y a pas d'option
        if (nbParam <= 2)
        {
                if (nbParam == 1)
                {
                        cerr << "Nom de fichier .log incorrect" << endl;
                        return 0;
                }
                else
                {
                        nomFic = parametres[1];
                        ia.AnalogueSansOp(nomFic);
                }
        }

        // Cas où il y'a une option
        if (nbParam == 3)
        {
                if(parametres[2].size() > 4)
                {
                        test = parametres[2].substr(parametres[2].size()-4,4);
                }
                else
                {
                        test = string(parametres[2]);
                }
                
                if(test != ".log")
                {
                        cerr << "nom du fichier .log manquant" << endl;
                        return 0;
                }

                else if( parametres[1] == "-e")
                {
			nomFic =  string(parametres[2]);
                        ia.AnalogueOp_e(nomFic);
                }

                else if( parametres[1] == "-g")
                {
                        cerr << "Nom de fichier .dot incorrect" << endl;
                        return 0;
                }

                else if( parametres[1] == "-t")
                {
                        cerr << "Heure incorrecte" << endl;
                        return 0;
                }

        }

        // Cas où on a -g ou -t 

        if (nbParam == 4)
        {
                if(parametres[3].size() > 4)
                {
                        test = parametres[3].substr(parametres[3].size()-4,4);
                }
                else
                {
                        test = string(parametres[3]);
                }
                
                if(test != ".log")
                {
                        cerr << "nom du fichier .log manquant" << endl;
                        return 0;
                }

                else if (parametres[1] == "-e" || parametres[2] == "-e")
                {
                        cerr << "Erreur : pensez à respecter la syntaxe des options" << endl;
                        return 0;
                }

                else if (parametres[1] == "-g")
                {
                        if (parametres[2].substr(parametres[2].size()-4,4) != ".dot")
                        {
                                cerr << "Nom du fichier .dot incorrect" << endl;
                                return 0;
                        }
                        else
                        {
                                //ia.AnalogueOp_g(nomFic, parametres[2]);
                                ia.AnalogueOp_g(parametres[3], parametres[2]);
                        }
                }

                else if (parametres[1] == "-t")
                {
                        istringstream iss(parametres[2]);
                        
                        if ((iss >> i).fail())
                        {
                                cerr << "l'heure saisie n'est pas un entier" << endl;
                                return 0;
                        }

                        else
                        {
                               //ia.AnalogueOp_t (nomFic, i); 
                               ia.AnalogueOp_t (parametres[3], i); 
                        }

                        
                }
        }

        // Cas où il y'a 2 options dont -e incluse obligatoirement sinon il y'a nécessairement un problème d'option 
        // (comme -g sans .dot ou -t sans heure)

        if (nbParam == 5)
        {
                if(parametres[4].size() > 4)
                {
                        test = parametres[4].substr(parametres[4].size()-4,4);
                }
                else
                {
                        test = string(parametres[4]);
                }

                if(test != ".log")
                {
                        cerr << "nom du fichier .log manquant" << endl;
                        return 0;
                }

                if (parametres[1] != "-e" && parametres[3] != "-e")
                {
                        cerr << "Erreur : pensez à respecter la syntaxe des options" << endl;
                }

                // -e est écrit en premier
                else if (parametres[1] == "-e")
                {
                        
                        // Cas où on a -e -g nom.dot
                        if (parametres[2] == "-g")
                        {
                            if (parametres[3].substr(parametres[3].size()-4,4) != ".dot")
                                {
                                        cerr << "Nom du fichier .dot incorrect" << endl;
                                        return 0;
                                }
                                else
                                {
                                        //ia.AnalogueOp_e_g(nomFic, parametres[3]);
                                        ia.AnalogueOp_e_g(parametres[4], parametres[3]);
                                }    
                        }
                        
                        // Cas où on a -e -t heure
                        else if (parametres[2] == "-t")
                        {
                                istringstream iss(parametres[3]);
                        
                                if ((iss >> i).fail())
                                {
                                        cerr << "l'heure saisie n'est pas un entier" << endl;
                                        return 0;
                                }

                                else
                                {
                                        ia.AnalogueOp_e_t (parametres[4], i); 
                                }  

                                  
                        }

                        else
                        {
                                cerr << "Erreur : Pensez à respecter la syntaxe des options" << endl;
                                return 0;
                        }
                }

                // -e est écrit en deuxième option
                else if (parametres[3] == "-e")
                {
                        // Cas où on a -g nom.dot -e
                        if (parametres[1] == "-g")
                        {
                            if (parametres[2].substr(parametres[2].size()-4,4) != ".dot")
                                {
                                        cerr << "Nom du fichier .dot incorrect" << endl;
                                        return 0;
                                }
                                else
                                {
                                        ia.AnalogueOp_e_g(parametres[4], parametres[2]);
                                }    
                        }
                        
                        // Cas où on a -t heure -e
                        else if (parametres[1] == "-t")
                        {
                                istringstream iss(parametres[2]);
                        
                                if ((iss >> i).fail())
                                {
                                        cerr << "l'heure saisie n'est pas un entier" << endl;
                                        return 0;
                                }

                                else
                                {
                                        ia.AnalogueOp_e_t (parametres[4], i); 
                                }   
                        }

                        else
                        {
                                cerr << "Erreur : Pensez à respecter la syntaxe des options" << endl;
                                return 0;
                        }
                }
        }


        // Cas où on a 2 options qui sont nécessairement -g et -t car s'il y'avait -e, il y'aurait un problème
        // au niveau des options (soit -g sans nom.dot soit -t sans heure)

        if (nbParam == 6)
        {
                if(parametres[5].size() > 4)
                {
                        test = parametres[5].substr(parametres[5].size()-4,4);
                }
                else
                {
                        test = string(parametres[5]);
                }

                if(test != ".log")
                {
                        cerr << "nom du fichier .log manquant" << endl;
                        return 0;
                }

                // on teste s'il y'a -e dans un des arguments
                if (parametres[1] == "-e" || parametres[2] == "-e" || parametres[3] == "-e" || parametres[4] == "-e")
                {
                        cerr << "Erreur : pensez à respecter la syntaxe des options" << endl;
                        return 0;
                }

                // Cas où -g est écrit en premier
                else if (parametres[1] == "-g")
                {
                        if (parametres[2].substr(parametres[2].size()-4,4) != ".dot")
                        {
                                cerr << "Nom du fichier .dot incorrect" << endl;
                                return 0;
                        }
                        else
                        {
                               if (parametres[3] == "-t")
                                {
                                        istringstream iss(parametres[4]);
                                        if ((iss >> i).fail())
                                        {
                                                cerr << "l'heure saisie n'est pas un entier" << endl;
                                                return 0;
                                        }

                                        else
                                        {
                                                ia.AnalogueOp_g_t (parametres[5], i, parametres[2]); 
                                        }  

                                        
                                }
                                
                                else 
                                {
                                        cerr << "Erreur : pensez à respecter la syntaxe des options" << endl;
                                        return 0;
                                }
                        } 
                } 
                
                // Cas où -t est écrit en premier
                else if (parametres[1] == "-t")
                {
                        istringstream iss(parametres[2]);

                        if ((iss >> i).fail())
                        {
                                cerr << "l'heure saisie n'est pas un entier" << endl;
                                return 0;
                        }

                        else
                        {
                                if (parametres[3] == "-g")
                                {
                                        if (parametres[4].substr(parametres[4].size()-4,4) != ".dot")
                                        {
                                                cerr << "Nom du fichier .dot incorrect" << endl;
                                                return 0;
                                        }
                                        else
                                        {
                                                ia.AnalogueOp_g_t(parametres[5], i, parametres[4]);
                                        }  
                                }

                                else
                                {
                                        cerr << "Erreur : pensez à respecter la syntaxe des options" << endl;
                                }
                        }      
                } 

        }

        // Cas où il y'a les 3 options combinées

        if (nbParam == 7)
        {
                if(parametres[6].size() > 4)
                {
                        test = parametres[6].substr(parametres[6].size()-4,4);
                }
                else
                {
                        test = string(parametres[6]);
                }

                if(test != ".log")
                {
                        cerr << "nom du fichier .log manquant" << endl;
                        return 0;
                }

                // Cas où -e est écrit en premier

                if (parametres[1] == "-e")
                {
                        
                        // Cas où on a -e -g nom.dot -t heure
                        if (parametres[2] == "-g")
                        {
                                if (parametres[3].substr(parametres[3].size()-4,4) != ".dot")
                                {
                                        cerr << "Nom du fichier .dot incorrect" << endl;
                                        return 0;
                                }
                                else
                                {
                                        if (parametres[4] == "-t")
                                        {
                                                istringstream iss(parametres[5]);
                                                if ((iss >> i).fail())
                                                {
                                                        cerr << "l'heure saisie n'est pas un entier" << endl;
                                                        return 0;
                                                }

                                                else
                                                {
                                                        ia.AnalogueOp_e_g_t (parametres[6], i, parametres[3]); 
                                                }   
                                        }
                                        
                                        else 
                                        {
                                                cerr << "Erreur : pensez à respecter la syntaxe des options" << endl;
                                                return 0;
                                        }
                                } 
                        }

                        // Cas où on a -e -t heure -g nom.dot
                        else if (parametres[2] == "-t")
                        {
                                istringstream iss(parametres[3]);

                                if ((iss >> i).fail())
                                {
                                        cerr << "l'heure saisie n'est pas un entier" << endl;
                                        return 0;
                                }

                                else
                                {
                                        if (parametres[4] == "-g")
                                        {
                                                if (parametres[5].substr(parametres[5].size()-4,4) != ".dot")
                                                {
                                                        cerr << "Nom du fichier .dot incorrect" << endl;
                                                        return 0;
                                                }
                                                else
                                                {
                                                        ia.AnalogueOp_e_g_t(parametres[6], i, parametres[5]);
                                                }  
                                        }

                                        else
                                        {
                                                cerr << "Erreur : pensez à respecter la syntaxe des options" << endl;
                                                return 0;
                                        }
                                }  

                        }
                }

                // Cas où on écrit -g en premier

                else if (parametres[1] == "-g")
                {
                        
                        if (parametres[2].substr(parametres[2].size()-4,4) != ".dot")
                        {
                                cerr << "Nom du fichier .dot incorrect" << endl;
                                return 0;
                        }
                        else
                        {
                                // Cas où on a -g nom.dot -e -t heure
                                if (parametres[3] == "-e")
                                {
                                        if (parametres[4] == "-t")
                                        {
                                                istringstream iss(parametres[5]);
                                                if ((iss >> i).fail())
                                                {
                                                        cerr << "l'heure saisie n'est pas un entier" << endl;
                                                        return 0;
                                                }

                                                else
                                                {
                                                        ia.AnalogueOp_e_g_t (parametres[6], i, parametres[2]); 
                                                }
                                        }

                                        else
                                        {
                                                cerr << "Erreur : pensez à respecter la syntaxe des options" << endl;
                                                return 0;
                                        }
                                }
                                
                                // Cas où on a -g nom.dot -t heure -e
                                else if (parametres[3] == "-t")
                                {
                                        istringstream iss(parametres[4]);

                                        if ((iss >> i).fail())
                                        {
                                                cerr << "l'heure saisie n'est pas un entier" << endl;
                                                return 0;
                                        }

                                        else
                                        {
                                                if (parametres[5] == "-e")
                                                {
                                                        ia.AnalogueOp_e_g_t (parametres[6], i, parametres[2]);
                                                }

                                                else
                                                {
                                                        cerr << "Erreur : pensez à respecter la syntaxe des options" << endl;
                                                        return 0;
                                                }
                                        }
                                }

                                else
                                {
                                        cerr << "Erreur : pensez à respecter la syntaxe des options" << endl;
                                        return 0;
                                }


                        }
                }

                // Cas où on a -t en premier

                else if (parametres[1] == "-t")
                {
                        istringstream iss(parametres[2]);

                        if ((iss >> i).fail())
                        {
                                cerr << "l'heure saisie n'est pas un entier" << endl;
                                return 0;
                        }

                        else
                        {
                                // Cas où on a -t heure -e -g nom.dot
                                if (parametres[3] == "-e")
                                {
                                        if (parametres[4] == "-g")
                                        {
                                                if (parametres[5].substr(parametres[5].size()-4,4) != ".dot")
                                                {
                                                        cerr << "Nom du fichier .dot incorrect" << endl;
                                                        return 0;
                                                }
                                                else
                                                {
                                                        ia.AnalogueOp_e_g_t(parametres[6], i, parametres[5]);
                                                } 
                                        }

                                        else 
                                        {
                                                cerr << "Erreur : pensez à respecter la syntaxe des options" << endl;
                                                return 0;
                                        }
                                }

                                // Cas où on a -t heure -g nom.dot -e
                                else if (parametres[3] == "-g")
                                {
                                        if (parametres[4].substr(parametres[4].size()-4,4) != ".dot")
                                        {
                                                cerr << "Nom du fichier .dot incorrect" << endl;
                                                return 0;
                                        }
                                        else
                                        {
                                                if (parametres[5] == "-e")
                                                {
                                                        ia.AnalogueOp_e_g_t(parametres[6], i, parametres[4]);
                                                }

                                                else
                                                {
                                                        cerr << "Nom du fichier .dot incorrect" << endl;
                                                        return 0;
                                                }
                                        } 
                                }

                                else
                                {
                                        cerr << "Nom du fichier .dot incorrect" << endl;
                                        return 0;
                                }
                        }
                }
        }

}