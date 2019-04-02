#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned char *** generateMatrix(int nl, int nc, int np);
void printMatrix(int nl, int nc, int np, unsigned char *** matrix);
void freeAllocMatrix(int nl, int nc, int np, unsigned char *** matrix);
void drawElipsoidOnMatrix(int nl, int nc, int np, unsigned char *** matrix, int x0, int y0, int z0);

int main()
{
    int nl=13, nc=13, np=13;
    unsigned char ***space3D;

    space3D = generateMatrix(nl, nc, np);
//  printMatrix(nl, nc, np, space3D);
    drawElipsoidOnMatrix(nl, nc, np, space3D, 6, 6, 6);
    printMatrix(nl, nc, np, space3D);
//  freeAllocMatrix(nl, nc, np, space3D);

    return 0;
}


unsigned char *** generateMatrix(int nl, int nc, int np){
    int i, j;
    unsigned char ***space3D;

    space3D = (unsigned char***) malloc(np*sizeof(unsigned char**));

    for( i = 0; i < np; i++){
        space3D[i] = (unsigned char**) malloc(nl*sizeof(unsigned char*));
        for(j = 0; j<nl; j++){
            space3D[i][j] = (unsigned char*) calloc(1,nc*sizeof(unsigned char));
        }
    }
    return space3D;
}

void printMatrix(int nl, int nc, int np, unsigned char *** matrix){
    int i, j, k;

    for( i = 0; i < np; i++){
       for( j = 0; j < nl; j++){
           for( k = 0; k < nc; k++){
               printf("%d", matrix[i][j][k]);
           }
           printf("\n");
       }
       for (int aux = 0; aux < nc; aux++){
           printf("-");
       }
       printf("\n");
    }
}

void freeAllocMatrix(int nl, int nc, int np, unsigned char *** matrix){
    int i, j, k;

    for( i = 0; i < np; i++){
       for( j = 0; j < nl; j++){
           for( k = 0; k < nc; k++){
               free(&matrix[i][j][k]);
           }
       }
    }
}

void drawElipsoidOnMatrix(int nl, int nc, int np, unsigned char *** matrix, int x0, int y0, int z0){
    int i; int j; int k;

    for(i = 0; i < np; i++){
        for(j = 0; j < nl; j++){
            for(k = 0; k < nc; k++){
                if(
                    (pow((k-z0),2) / pow(nc/2, 2) + pow((j-y0),2) / pow(nl/2, 2) + pow((i-x0),2) / pow(np/2, 2)) <= 1
                ){
                    matrix[i][j][k] = 1;
                }
            }
        }
    }
}

