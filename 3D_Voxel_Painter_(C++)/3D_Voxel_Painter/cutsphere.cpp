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
    for(int i = xcenter-radius; i<=xcenter+radius; i++){
        for(int j = ycenter-radius; j<=ycenter+radius; j++){
            for(int k = zcenter-radius; k<=zcenter+radius; k++){
                if( ((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter)) <= radius*radius ){
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}
