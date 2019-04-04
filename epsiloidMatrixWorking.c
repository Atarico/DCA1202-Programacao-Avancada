#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *** generateMatrix(int nl, int nc, int np);
int *** generateMatrix2(int nl, int nc, int np);
void printMatrix(int nl, int nc, int np, int *** matrix);
void printMatrix2(int nl, int nc, int np, int *** matrix);
void freeAllocMatrix(int nl, int nc, int np, unsigned char *** matrix);
void drawElipsoidOnMatrix(int nl, int nc, int np, unsigned char *** matrix, int x0, int y0, int z0);

int main()
{
    int nl=5, nc=6, np=3;
    unsigned char ***space3D;
    int ** matriz2d;

    space3D = generateMatrix(nl, nc, np);
    matriz2d = generateMatrix2(nl, nc, np);
    printMatrix2(nl, nc, np, matriz2d);

//    printMatrix(nl, nc, np, space3D);
//    drawElipsoidOnMatrix(nl, nc, np, space3D, 6, 6, 6);
//    printMatrix(nl, nc, np, space3D);
//  freeAllocMatrix(nl, nc, np, space3D);

    return 0;
}


int *** generateMatrix2(int nl, int nc, int np){
    int i, j, k;
    int ***matrix2D;

    matrix2D = malloc(nl*sizeof(int**));
    matrix2D[0] = malloc(nl*nc*sizeof(int*));
    matrix2D[0][0] = malloc(nl*nc*np*sizeof(int));

    for(i = 1; i<nl; i++){
        matrix2D[i] = matrix2D[i-1] + nc;
    }
    for(i = 0; i<nl; i++){
        for(j=0; j<nc; j++){
            if(j != 0){
                matrix2D[i][j] = matrix2D[i][j-1] + (np);
            }
            else if(i!=0 && j==0){
                matrix2D[i][j] = matrix2D[i-1][nc-1] + (np);
            }
        }
    }
    for(i=0; i<nl; i++){
        for(j=0; j<nc; j++){
            for(k=0; k<np; k++){
                matrix2D[i][j][k] = i+j+k;
            }
        }
    }
    return matrix2D;
}


int *** generateMatrix(int nl, int nc, int np){
    int i, j;
    int ***space3D;

    space3D = malloc(np*sizeof(int**));
//    space3D[0] = malloc(np*nl*sizeof(int*));
//    space3D[0][0] = calloc(1, np*nl*nc*sizeof(int));

//    for (i = 1; i<np; i++){
//        space3D[i] = space3D[i-1] + (nl*nc);
//        for(j = 1; j<nl; j++){
//            space3D[i-1][j] = space3D[i-1][j-1] + nc;
//        }
//    }

//    for( i = 0; i < np; i++){
//        space3D[i] = (unsigned char**) malloc(nl*sizeof(unsigned char*));
//        for(j = 0; j<nl; j++){
//            space3D[i][j] = (unsigned char*) calloc(1,nc*sizeof(unsigned char));
//        }
//    }
    return space3D;
}

void printMatrix(int nl, int nc, int np, int *** matrix){
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

void printMatrix2(int nl, int nc, int np, int *** matrix){
    int i, j, k;

    for( i = 0; i < nl; i++){
       for( j = 0; j < nc; j++){
           for( k = 0; k < np; k++){
               printf("%d", matrix[i][j][k]);
           }
           printf("\n");
       }
       for (int aux = 0; aux < np; aux++){
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
