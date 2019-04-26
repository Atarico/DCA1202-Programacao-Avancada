#include <iostream>
#include "sculptor.h"

using namespace std;

int main()
{
    //float r = 0, g = 0, b = 0, a = 0;
    //int nx, ny, nz;

    //cout<<"Digite, em sequencia, as dimensoes do seu canvas (x, y, z): "<<endl;
    //cin>>nx>>ny>>nz;

    Sculptor escultor(3, 2, 2);

    //cout<<"Digite, em sequencia, os valores rgb e o alpha: "<<endl;
    //cin>>r>>g>>b>>a;

    escultor.setColor(1, 0, 0, 1);
    //escultor.print();
    //cout<<"---------------------"<<endl;
    //escultor.putEllipsoid(4,4,4,2,4,2);
    //escultor.print();
    //cout<<"---------------------"<<endl;
    //escultor.cutEllipsoid(4,4,4,1,2,1);
    //escultor.print();

    escultor.putBox(0,1,0,1,0,1);
    escultor.cutVoxel(0,0,0);
    //escultor.cutVoxel(1,1,1);
    escultor.setColor(0, 1, 0, 1);
    escultor.putVoxel(1,1,1);
    escultor.print();


    Sculptor escultor2(1, 1, 1);
    escultor2.setColor(1, 1, 1, 1);
    escultor2.putVoxel(0,0,0);
    escultor2.print();

    string vect_scr("VECT_file");
    string off_scr("OFF_file");

    escultor.writeVECT(vect_scr);
    escultor2.writeOFF(off_scr);

    return 0;
}
