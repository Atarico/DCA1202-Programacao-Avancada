#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <iostream>
//#include "matriz.h"

using namespace std;

//definition of our voxel type
struct Voxel {
  float r,g,b; // Colors
  float a; // Transparency
  bool isOn; // Included or not
};


//definition of our sculptor class
class Sculptor {
protected:
  Voxel ***v; // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
  Sculptor(Voxel*** _v, int _nx, int _ny, int _nz);
  ~Sculptor();
  Voxel& operator () (int i, int j, int k);
  void print();
  void setColor(float red, float green, float blue, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(string filename);
  void writeVECT(string filename);
};

#endif // SCULPTOR_H
