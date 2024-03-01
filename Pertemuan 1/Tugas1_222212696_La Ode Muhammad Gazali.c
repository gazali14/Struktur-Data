#include <stdio.h>
int main()
{
  int kuis,uts,uas;
  char nama[10],nim[10];
  float nilai_akhir;

      printf("Masukan nama : ");fgets(nama,10,stdin);
      printf("Masukan nim : "); scanf("%s", &nim);
      printf("Masukan kuis : "); scanf("%d", &kuis);
      printf("Masukan uts : "); scanf("%d", &uts);
      printf("Masukan uas : "); scanf("%d", &uas);

      nilai_akhir = 0.2*kuis + 0.3*uts + 0.5*uas;


      printf("Nama : %s",nama);
      printf("NIM : %s\n",nim);
      printf("Nilai Kuis : %d\n",kuis);
      printf("Nilai UTS : %d\n",uts);
      printf("Nilai UAS : %d\n",uas);
      printf("Nilai Akhir : %.2f\n",nilai_akhir);


}
