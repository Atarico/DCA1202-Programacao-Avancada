#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "geometricfigure.h"

class CutEllipsoid : public GeometricFigure
{
protected:
    int xcenter, ycenter,  zcenter,  rx,  ry, rz;
public:
    CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz);
    ~CutEllipsoid();
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
