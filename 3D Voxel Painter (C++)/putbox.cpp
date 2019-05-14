#include "putbox.h"

PutBox::PutBox(int _x0, int _x1, int _y0, int _y1, int _z0, int _z1, float _r, float _g, float _b, float _a)
{
    x0 = _x0;
    x1 = _x1;
    y0 = _y0;
    y1 = _y1;
    z0 = _z0;
    z1 = _z1;
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

PutBox::~PutBox()
{

}

void PutBox::draw(Sculptor &t)
{
    for(int i = 0; i<t.nx; i++){
        for(int j = 0; j<t.ny; j++){
            for(int k = 0; k<t.nz; k++){
                if(i>=x0 && i<=x1 &&
                   j>=y0 && j<=y1 &&
                   k>=z0 && k<=z1){
                    t.setColor(r, g, b, a);
                    t.putVoxel(i, j, k);
                }
            }
        }
    }
}
