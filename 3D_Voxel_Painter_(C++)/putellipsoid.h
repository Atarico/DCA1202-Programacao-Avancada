#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "geometricfigure.h"

class PutEllipsoid : public GeometricFigure
{
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz;
    float r, g, b, a;
public:
    PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a);
    ~PutEllipsoid();
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
