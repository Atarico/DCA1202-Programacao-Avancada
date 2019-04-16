#include "sculptor.h"
#include "matriz.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz, float _r, float _g, float _b, float _a)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

    r = _r;
    g = _g;
    b = _b;
    a = _a;

    Matriz matriz(v, nx, ny, nz);
    matriz.print();
}

void Sculptor::setColor(float red, float green, float blue, float alpha)
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    for(int i = 0; i<nx; i++){
        for(int j = 0; j<ny; j++){
            for(int k = 0; k<nz; k++){
                if(x == i && y == j && z == k)
                {
//                    this->v[i][j][k].isOn = true;
                    this->v[i][j][k].r = r;
//                    this->v[i][j][k].g = g;
//                    this->v[i][j][k].b = b;
//                    this->v[i][j][k].a = a;
                }
            }
        }
    }
}
