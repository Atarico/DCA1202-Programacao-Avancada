#include <iostream>
#include "sculptor.h"

using namespace std;

int main()
{
    float r, g, b, a;
    int nx, ny, nz;

    cout<<"Digite, em sequencia, as dimensoes do seu canvas (x, y, z): "<<endl;
    cin>>nx>>ny>>nz;

    Sculptor escultor(nx, ny, nz, r, g, b, a);

    cout<<"Digite, em sequencia, os valores rgb e o alpha: "<<endl;
    cin>>r>>g>>b>>a;

    escultor.setColor(r, g, b, a);
    escultor.putVoxel(2,2,2);

    //escultor.print();
    return 0;
}
