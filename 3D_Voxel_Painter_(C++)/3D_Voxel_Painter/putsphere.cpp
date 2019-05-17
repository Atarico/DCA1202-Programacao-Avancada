#include "putsphere.h"

PutSphere::PutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius, float _r, float _g, float _b, float _a)
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}
PutSphere::~PutSphere()
{

}

void PutSphere::draw(Sculptor &t)
{
    for(int i = 0; i<t.nx; i++){
        for(int j = 0; j<t.ny; j++){
            for(int k = 0; k<t.nz; k++){
                if(
                        ((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter)) <= radius*radius
                        ){
                    t.setColor(r, g, b, a);
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}
