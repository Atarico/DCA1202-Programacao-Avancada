#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "sculptor.h"
#include "geometricfigure.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "putvoxel.h"
#include "cutvoxel.h"

using namespace std;

int main()
{
    Sculptor *sculptor;
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
        ss.clear();
        ss.str(s);
        ss>>s;

        cout<< s <<endl;

        if(s.compare("dim")==0){
            int dx, dy, dz;
            ss>>dx>>dy>>dz;
            sculptor = new Sculptor(dx, dy, dz);
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
        else if(s.compare("putsphere")==0){
            int xcenter, ycenter, zcenter, radius;
            float r, g, b, a;
            ss>>xcenter>>ycenter>>zcenter>>radius>>r>>g>>b>>a;
            figs.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
        }
        else if(s.compare("cutsphere")==0){
            int xcenter, ycenter, zcenter, radius;
            ss>>xcenter>>ycenter>>zcenter>>radius;
            figs.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
        }
        else if(s.compare("putellipsoid")==0){
            int xcenter, ycenter, zcenter, rx, ry, rz;
            float r, g, b, a;
            ss>>xcenter>>ycenter>>zcenter>>rx>>ry>>rz>>r>>g>>b>>a;
            figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
        }
        else if(s.compare("cutellipsoid")==0){
            int xcenter, ycenter,  zcenter,  rx,  ry, rz;
            ss>>xcenter>>ycenter>>zcenter>>rx>>ry>>rz;
            figs.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
        }
        else if(s.compare("putvoxel")==0){
            int x, y, z;
            float r, g, b, a;
            ss>>x>>y>>z>>r>>g>>b>>a;
            figs.push_back(new PutVoxel(x, y, z, r, g, b, a));
        }
        else if(s.compare("cutvoxel")==0){
            int x, y, z;
            ss>>x>>y>>z;
            figs.push_back(new CutVoxel(x, y, z));
        }
//        else {
//            cout<<"Error reading file, program execution interupted!"<<endl<<"Please make sure your instructions are correctly under our guidelines before trying again."<<endl;
//        }
    }

    for(int i = 0; i< figs.size(); i++){
        figs[i]->draw(*sculptor);
    }

    //*sculptor->writeOFF("OFF_file");

    return 0;
}
