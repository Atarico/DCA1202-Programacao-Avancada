#include "cutsphere.h"

CutSphere::CutSphere(int _xcenter, int _ycenter, int _zcenter, int _radius )
{
    xcenter = _xcenter;
    ycenter = _ycenter;
    zcenter = _zcenter;
    radius = _radius;
}

CutSphere::~CutSphere()
{

}
void CutSphere::draw(Sculptor &t)
{
    for(int i = 0; i<t.nx; i++){
        for(int j = 0; j<t.ny; j++){
            for(int k = 0; k<t.nz; k++){
                if( ((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter)) <= radius*radius ){
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}
