#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *** generateMatrix(int nl, int nc, int np);
int *** generateMatrix2(int nl, int nc, int np);
void printMatrix(int nl, int nc, int np, int *** matrix);
void printMatrix2(int nl, int nc, int np, int *** matrix);
void freeAllocMatrix(int *** matrix);
void drawElipsoidOnMatrix(int nl, int nc, int np, int *** matrix, int x0, int y0, int z0);

int main()
{
    int nl=9, nc=9, np=9;
    unsigned char ***space3D;

    space3D = generateMatrix(nl, nc, np);
//    printMatrix(nl, nc, np, space3D);
    drawElipsoidOnMatrix(nl, nc, np, space3D, 4, 5, 3);
    printMatrix(nl, nc, np, space3D);
    freeAllocMatrix(space3D);

    return 0;
}

int *** generateMatrix(int nl, int nc, int np){
    int i, j, k;
    int ***space3D;

    space3D = malloc(np*sizeof(int**));
    space3D[0] = malloc(np*nl*sizeof(int*));
    space3D[0][0] = malloc(np*nl*nc*sizeof(int));

    for(i = 1; i<np; i++){
        space3D[i] = space3D[i-1] + nl;
    }
    for(i = 0; i<np; i++){
        for(j=0; j<nl; j++){
            if(j != 0){
                space3D[i][j] = space3D[i][j-1] + (nc);
            }
            else if(i!=0 && j==0){
                space3D[i][j] = space3D[i-1][nl-1] + (nc);
            }
        }
    }
    for(i=0; i<np; i++){
        for(j=0; j<nl; j++){
            for(k=0; k<nc; k++){
                space3D[i][j][k] = 0;
            }
        }
    }
    return space3D;
}

void printMatrix(int nl, int nc, int np, int *** matrix){
    int i, j, k;

    printf("BEGGIN OF MATRIX PRINTING: \n");
    for( i = 0; i < np; i++){
       for( j = 0; j < nl; j++){
           for( k = 0; k < nc; k++){
               printf("%d ", matrix[i][j][k]);
           }
           printf("\n");
       }
       for (int aux = 0; aux < nc; aux++){
           printf("-");
       }
       printf("\n");
    }
    printf("END OF MATRIX PRINTING \n\n\n\n");
}

void freeAllocMatrix(int *** matrix){
    free(matrix);
    free(matrix[0]);
    free(matrix[0][0]);
}

void drawElipsoidOnMatrix(int nl, int nc, int np, int *** matrix, int x0, int y0, int z0){
    int i; int j; int k;

    for(i = 0; i < np; i++){
        for(j = 0; j < nl; j++){
            for(k = 0; k < nc; k++){
                if(
                    (pow((k-z0),2) / (float)pow(nc/2, 2) + pow((j-y0),2) / (float)pow(nl/2, 2) + pow((i-x0),2) / (float)pow(np/2, 2)) <= 1
                ){
                    matrix[i][j][k] = 1;
                }
            }
        }
    }
}
