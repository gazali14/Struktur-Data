#include <stdio.h>

struct mahasiswa {
    int *log10;//sturcture dengan elemen ponter
}hasil;

int main()
{
    int a=1;

    hasil.log10=&a;

    printf("Alamat variabel a : %d\n",hasil.log10);
    printf("Nilai variabel a (hasil log 10) : %d",*hasil.log10);

    return 0;
}
