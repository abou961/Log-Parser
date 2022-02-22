using namespace std;
#include <iostream>
#include <fstream>
#include "Node.h"
#include "Structure.h"


int main()
{
    
    Structure s;
    ifstream is ("test.txt");
    ofstream os ("graph.dot");

    Node n;
    while(is >> n)
    {
        s.AjoutLog( n.getRef(), n.getCible());
    }
   /* s.AjoutLog("C", "B", 10);
    s.AjoutLog("A", "D", 10);
    s.AjoutLog("A", "B", 40);
    s.AjoutLog("C", "B", 20);
    s.AjoutLog("D", "Z", 8);
    s.AjoutLog("X", "B", 8);*/

    //s.Top10(cout);
    os << s;
    os.close();
}