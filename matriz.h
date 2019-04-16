#ifndef MATRIZ_H
#define MATRIZ_H

#include "sculptor.h"

class Matriz
{
private:
    int nl, nc, np;
    Voxel*** v;
public:
    Matriz(Voxel*** _v, int _nl, int _nc, int _np);
    ~Matriz();
    print();
};

#endif // MATRIZ_H
