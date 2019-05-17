#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "geometricfigure.h"

class CutVoxel : public GeometricFigure
{
protected:
    int x, y, z;
public:
    CutVoxel(int _x, int _y, int _z);
    ~CutVoxel();
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
