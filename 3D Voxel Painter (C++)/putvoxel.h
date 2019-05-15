#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "geometricfigure.h"

class PutVoxel : public GeometricFigure
{
protected:
    int x, y, z;
    float r, g, b, a;
public:
    PutVoxel(int _x, int _y, int _z, float _r, float _g, float _b, float _a);
    ~PutVoxel();
    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
