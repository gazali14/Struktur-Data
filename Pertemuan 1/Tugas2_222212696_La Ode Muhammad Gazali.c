#include <stdio.h>

int menghitung_luas(int panjang, int lebar)
{
    int luas;
    luas=panjang*lebar;

    return luas;
}
int menghitung_keliling(int panjang, int lebar)
{
    int keliling;
    keliling=2*panjang+2*lebar;
    return keliling;
}

int main()
{
  int panjang,lebar;

      printf("---Menghitung Luas & Keliling Persegi Panjang---\n");
      printf("Masukan panjang : ");scanf("%d",&panjang);
      printf("Masukan lebar : ");scanf("%d",&lebar);

      printf("luas :%d\n ",menghitung_luas(panjang,lebar));
      printf("keliling :%d ",menghitung_keliling(panjang,lebar));
}


