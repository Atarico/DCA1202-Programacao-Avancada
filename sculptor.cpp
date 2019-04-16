#include "sculptor.h"

Sculptor::Sculptor(Voxel ***_v, int _nx, int _ny, int _nz, float _r, float _g, float _b, float _a)
{
    v = _v;

    nx = _nx;
    ny = _ny;
    nz = _nz;

    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

Sculptor::setColor(float _r, float _g, float _b, float _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}
