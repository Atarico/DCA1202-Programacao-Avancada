#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*duvidas: 
-freeAlloc tá certo?
-da pra fz a indexação sem usar if?
-função com argumentos opcionais
*/

int *** generateMatrix(int nl, int nc, int np);
int *** generateMatrix2(int nl, int nc, int np);
void printMatrix(int nl, int nc, int np, int *** matrix);
void printMatrix2(int nl, int nc, int np, int *** matrix);
void freeAllocMatrix(int *** matrix);
void drawElipsoidOnMatrix(int nl, int nc, int np, int *** matrix, int x0, int y0, int z0, int tamX, int tamY, int tamZ);

int main()
{
    int nl, nc, np, cX, cY, cZ, sizeX, sizeY, sizeZ;
    int ***space3D;

    printf("Informe a quantidade de linhas, colunas e planos da sua matriz, respectivamente: \n");
    scanf("%d", &nl);
    scanf("%d", &nc);
    scanf("%d", &np);
    printf("\nInforme a posicao da elipsoide em termos de x, y, e z, respectivamente, considerando que "
           "(x,y,z) eh um ponto no espaco definido pela matriz 3D: \n");
    scanf("%d", &cX);
    scanf("%d", &cY);
    scanf("%d", &cZ);
    printf("\nInforme o tamanho dos eixos-maiores dessa elipse, ou seja, 2*a, 2*b, 2*c, onde a, b e c estao "
           "relacionados respectivamente aos eixos x, y e z da nossa matriz 3D: \n");
    scanf("%d", &sizeX);
    scanf("%d", &sizeY);
    scanf("%d", &sizeZ);

    printf("----------------------------------------------");
    printf("\nLembre-se de que na representacao abaixo, cada matriz bidimensional representa um plano de nossa matriz"
           " tridimensional. Os planos estao associados ao eixo X, as linhas ao eixo Y, e as colunas ao eixo Z.\n");
    printf("----------------------------------------------\n");

    space3D = generateMatrix(nl, nc, np);
    drawElipsoidOnMatrix(nl, nc, np, space3D, cX, cY, cZ, sizeX, sizeY, sizeZ);
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

    printf("\n\nBEGGIN OF MATRIX PRINTING:\n");
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
    printf("END OF MATRIX PRINTING \n\n");
}

void freeAllocMatrix(int *** matrix){
    free(matrix);
    free(matrix[0]);
    free(matrix[0][0]);
}

void drawElipsoidOnMatrix(int nl, int nc, int np, int *** matrix, int x0, int y0, int z0, int tamX, int tamY, int tamZ){
    int i; int j; int k;

    for(i = 0; i < np; i++){
        for(j = 0; j < nl; j++){
            for(k = 0; k < nc; k++){
                if(
                     (pow((i-x0),2) / (float)pow(tamX/2, 2) + pow((j-y0),2) / (float)pow(tamY/2, 2) + pow((k-z0),2) / (float)pow(tamZ/2, 2)) <= 1
                ){
                    matrix[i][j][k] = 1;
                }
            }
        }
    }
}
