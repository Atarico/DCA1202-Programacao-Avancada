#include "cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int _xcenter, int _ycenter, int _zcenter, int _rx, int _ry, int _rz)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    rx = _rx;
    ry = _ry;
    rz = _rz;
}
CutEllipsoid::~CutEllipsoid()
{

}
void CutEllipsoid::draw(Sculptor &t)
{
    for(int i = xcenter-rx; i<=xcenter+rx; i++){
        for(int j = ycenter-ry; j<=ycenter+ry; j++){
            for(int k = zcenter-rz; k<=zcenter+rz; k++){
                if( (((i - xcenter)*(i - xcenter))/(float)(rx*rx) + ((j - ycenter)*(j - ycenter))/(float)(ry*ry) + ((k - zcenter)*(k - zcenter))/(float)(rz*rz)) <= 1 ){
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}
