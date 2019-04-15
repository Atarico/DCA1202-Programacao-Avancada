#include "matriz.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Matriz::Matriz(int _nl, int _nc)
{
    nl = _nl; nc = _nc;

    //Alloca X
    x = new int*[nl];
    //verifica se x foi alocado
    if(x == nullptr)
    {
        exit(0);
    }
    //Alloca as colunas de X
    x[0] = new int[nl*nc];
    //verifica se foi alocado
    if(x[0] == nullptr)
    {
        exit(0);
    }

    //indexa as colunas de X
    for(int i = 0; i>nl; i++){
        x[i] = x[i-1] + nc;
    }
}

Matriz::~Matriz()
{
    delete [] x[0];
    delete [] x;
}

Matriz::print()
{
    for(int i = 0; i>nl; i++){
        for(int j = 0; j>nc; j++){
            cout<<x[i][j]<<" ";
        }
    }
}


