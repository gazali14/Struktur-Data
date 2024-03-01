/* Aturan Scope pada Bahasa C */
#include<stdio.h>
int main()
{
    {
      int x = 10, y = 20;// variabel global
        {
          printf("x = %d, y = %d\n", x, y);//menampilkan variabel global x=10 dan y=20
            {
              int y = 40; // variabel y bertindak sebagai variabel lokal
              x++; // x= x + 1, sehingga menjadi x=11
              y++; // y=y+1, sehingga variabel y lokal menjadi y=41
              printf("x = %d, y = %d\n", x, y);// menampilkan x = 11, y =41
            }
          printf("x = %d, y = %d\n", x, y);
          /* Disini kembali menjadi variabel global, x global sebelumnya telah bertambah 1, menjadi x=11
            sedangkan y global tetap y=20, karena yang sebelumnya bertambah 1 adalah variabel y lokal*/
        }
    }
    return 0;
}
