#include "putellipsoid.h"

PutEllipsoid::PutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz, float _r, float _g, float _b, float _a)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx = _rx;
    ry = _ry;
    rz = _rz;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}
PutEllipsoid::~PutEllipsoid()
{

}

void PutEllipsoid::draw(Sculptor &t)
{
    for(int i = xcenter-rx; i<=xcenter+rx; i++){
        for(int j = ycenter-ry; j<=ycenter+ry; j++){
            for(int k = zcenter-rz; k<=zcenter+rz; k++){
                if( (((i - xcenter)*(i - xcenter))/(float)(rx*rx) + ((j - ycenter)*(j - ycenter))/(float)(ry*ry) + ((k - zcenter)*(k - zcenter))/(float)(rz*rz)) <= 1 ){
                    t.setColor(r, g, b, a);
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}
