#include <stdio.h>
struct Pegawai{
    char nama[30],nip[10],divisi[15];
};
int main(){
    int n;
    printf("Masukan jumlah pegawai : ");scanf("%d",&n);
    getchar();

    struct Pegawai pgw[n];
    for(int i=0;i<n;i++){
        printf("Pegawai ke-%d\n",i+1,"\n");
        printf("Nama : ");gets(pgw[i].nama);
        printf("NIP : ");gets(pgw[i].nip);
        printf("Divisi : ");gets(pgw[i].divisi);
        printf("\n");
    }
    printf("====Data Pegawai====\n");
    for(int i=0;i<n;i++){
        printf("Pegawai ke-%d",i+1,"\n");
        printf("Nama : %s\n",pgw[i].nama);
        printf("NIP : %s\n",pgw[i].nip);
        printf("Divisi : %s\n",pgw[i].divisi);
        printf("\n");
    }

    return 0;
}
