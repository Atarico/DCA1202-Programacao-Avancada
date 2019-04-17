#ifndef MATRIZ_H
#define MATRIZ_H

#include "sculptor.h"

class Matrix
{
private:
    int nl, nc, np;
    Voxel*** v;
public:
    Matrix(Voxel*** _v, int _nl, int _nc, int _np);
    ~Matrix();
    Voxel& operator () (int i, int j, int k);
    void print();
};

#endif // MATRIZ_H
