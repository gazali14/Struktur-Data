#include <stdio.h>

int main() {
    int matriks[3][4];

    //Menginputkan matriks
    for (int i = 0;i<=2;i++){
        for (int j = 0;j<=3;j++){
            printf("Masukan matriks ke %d,%d : ",i,j);scanf("%d", &matriks[i][j]);
        }
    }

    //Menampilkan matriks
    for (int i = 0;i<=2;i++){
        for (int j = 0;j<=3;j++){
            printf(" %d ",matriks[i][j]);
        }
        printf("\n");
    }
return 0;

}
