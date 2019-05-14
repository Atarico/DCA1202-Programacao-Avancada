#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "sculptor.h"
#include "geometricfigure.h"
#include "putbox.h"
#include "cutbox.h"

using namespace std;

int main()
{
    Sculptor sculptor;
    vector<GeometricFigure*> figs;
    fstream fin;
    string s, filename;
    stringstream ss;

    filename = "teste";

    fin.open("./"+filename+".txt");
    if(!fin.is_open()){
        cout<<"Error while opening sculptor instruction file! Please make sure that your file is in the .exe directory"<<endl;
        exit(0);
    }
    while(fin.good()){
        getline(fin, s);
        ss.str(s);
        ss>>s;

//        int x,y,z;
        cout<< s <<endl;
//        ss>>x>>y;
//        cout <<x<<", "<<y<<", "<<endl;
        if(s.compare("dim")==0){
            int dx, dy, dz;
            ss>>dx>>dy>>dz;
            sculptor(dx, dy, dz);
        }
        else if(s.compare("putbox")==0){
            int x0, x1, y0, y1, z0, z1;
            float r, g, b, a;
            ss>>x0>>x1>>y0>>y1>>z0>>z1>>r>>g>>b>>a;
            figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        else if(s.compare("cutbox")==0){
            int x0, x1, y0, y1, z0, z1;
            ss>>x0>>x1>>y0>>y1>>z0>>z1;
            figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
        }
//        else {
//            cout<<"Error reading file, program execution interupted!"<<endl<<"Please make sure your instructions are correctly under our guidelines before trying again."<<endl;
//        }
    }

    for(int i = 0; i< figs.size(); i++){
        figs[i]->draw(sculptor);
    }

    sculptor.writeOFF("OFF_file");

    return 0;
}
