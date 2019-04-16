#include "matriz.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Matriz::Matriz(Voxel*** _v, int _nl, int _nc, int _np)
{
    nl = _nl; nc = _nc; np = _np;
    v = _v;

    //allocates X
    v = new Voxel**[nl];
    //verifies if X has been allocated
    if(v == nullptr)
    {
        cout<<"Error allocating the lines of the voxel matrix"<<endl;
        exit(0);
    }

    //allocates X's collumns
    v[0] = new Voxel*[nl*nc];
    //verifies if X[0] has been allocated
    if(v[0] == nullptr)
    {
        cout<<"Error allocating the columns of the voxel matrix"<<endl;
        exit(0);
    }

    //allocates X's planes
    v[0][0] = new Voxel[nl*nc*np];
    //verifies if X[0] has been allocated
    if(v[0][0] == nullptr)
    {
        cout<<"Error allocating the planes of the voxel matrix"<<endl;
        exit(0);
    }


    //indexing X's collumns
    for(int i = 1; i<nl; i++){
        v[i] = v[i-1] + nc;
    }

    //indexing X's planes
    for(int i = 1; i<nc*np; i++){
        v[0][i] = v[0][i-1] + np;
    }

    //making every voxel invisible so we have a clean canvas
    for(int i = 0; i<nl; i++){
        for(int j = 0; j<nc; j++){
            for(int k = 0; k<np; k++){
                v[i][j][k].isOn = false;
                v[i][j][k].r = 255;
                v[i][j][k].g = 255;
                v[i][j][k].b = 255;
            }
        }
    }
}

Matriz::~Matriz()
{
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

Matriz::print()
{
    for(int i = 0; i<nl; i++){
        for(int j = 0; j<nc; j++){
            for(int k = 0; k<np; k++){
                cout<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].r<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
    }
}
