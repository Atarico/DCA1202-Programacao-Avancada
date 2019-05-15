#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "geometricfigure.h"

class CutSphere : public GeometricFigure
{
protected:
    int xcenter, ycenter, zcenter, radius;
public:
    CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius);
    ~CutSphere();
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
