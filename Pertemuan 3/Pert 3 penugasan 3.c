#include <stdio.h>
#include <string.h>

struct mahasiswa {
    int no_urut;
    char nama[30];
    char jurusan[40];
    int angkatan;
};

int main()
{

    struct mahasiswa mhs;
    struct mahasiswa *ptr = &mhs;

    mhs.no_urut = 21;
    strcpy(mhs.nama, "La Ode Muhammad Gazali");
    strcpy(mhs.jurusan, "Komputasi Statistik");
    mhs.angkatan = 64;

    printf("Nomro urut: %d\n", (*ptr).no_urut);
    printf("Nama: %s\n", (*ptr).nama);
    printf("Jurusan: %s\n", (*ptr).jurusan);
    printf("Angkatan: %d", (*ptr).angkatan);

    return 0;
}
