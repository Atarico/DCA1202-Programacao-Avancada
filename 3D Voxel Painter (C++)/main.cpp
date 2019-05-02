#include <iostream>
#include "sculptor.h"

using namespace std;

int main()
{
    //float r = 0, g = 0, b = 0, a = 0;
    //int nx, ny, nz;

    //cout<<"Digite, em sequencia, as dimensoes do seu canvas (x, y, z): "<<endl;
    //cin>>nx>>ny>>nz;

    //cout<<"Digite, em sequencia, os valores rgb e o alpha: "<<endl;
    //cin>>r>>g>>b>>a;

    //Declarando o objeto escultor1, usado como exemplo para escrever o arquivo .vect
    Sculptor escultor1(3, 2, 2);

    escultor1.setColor(1, 0, 0, 1);
    escultor1.putBox(0,1,0,1,0,1);
    escultor1.cutVoxel(0,0,0);
    escultor1.setColor(0, 1, 0, 1);
    escultor1.putVoxel(1,1,1);

    string vect_scr("VECT_file");
    escultor1.writeVECT(vect_scr);


    //Declarando o objeto escultor2 usado como exemplo para escrever o arquivo .off
    Sculptor escultor2(25,35,25);

    escultor2.setColor(0,1,0,0.7);
    escultor2.putEllipsoid(12,16,12,12,16,12);
    escultor2.cutEllipsoid(12,16,12,11,15,11);
    escultor2.setColor(1,1,1,0.5);
    escultor2.putSphere(6,16,8,4);
    escultor2.cutSphere(6,16,8,3);
    escultor2.putSphere(6,16,16,4);
    escultor2.cutSphere(6,16,16,3);
    escultor2.setColor(0,0,0,1);
    escultor2.putSphere(6,16,8,2);
    escultor2.putSphere(6,16,16,2);
    escultor2.cutBox(0,4,0,25,0,25);


    string off_scr("OFF_file");
    escultor2.writeOFF(off_scr);

    return 0;
}
