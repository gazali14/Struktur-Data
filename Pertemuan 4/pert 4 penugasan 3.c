#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk merepresentasikan data mahasiswa
struct mahasiswa {
    int nim;
    char nama[50];
    struct mahasiswa* next;
};

typedef struct mahasiswa mhs;

// Fungsi untuk membuat node baru dengan data mahasiswa
mhs* createmhs(int nim, const char* nama) {
    mhs* mahasiswaBaru = (mhs*)malloc(sizeof(mhs));

    mahasiswaBaru->nim = nim;
    strncpy(mahasiswaBaru->nama, nama, sizeof(mahasiswaBaru->nama));
    mahasiswaBaru->next = NULL;

    return mahasiswaBaru;
}

// Fungsi untuk menambahkan node mahasiswa ke linked list
mhs* addmahasiswa(mhs* head, int nim, const char* nama) {
    mhs* mahasiswaBaru = createmhs(nim, nama);
    mahasiswaBaru->next = head;
    head=mahasiswaBaru;
    return (head);
}

// Fungsi untuk menampilkan daftar mahasiswa dalam linked list
void tampilmahasiswa(mhs* head) {
    mhs* n = head;

    printf("Daftar Mahasiswa:\n");
    while (n != NULL) {
        printf("NIM: %d, Nama: %s\n", n->nim, n->nama);
        n = n->next;
    }
    printf("\n");
}

int main() {
    mhs* head = NULL;
    int n,nim;
    char nama[50];
    printf("Masukan jumlah data mahasiswa : ");scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        printf("\nMahasiswa ke-%d\n", i+1);
        printf("Nama  = ");scanf("%s", &nama);
        printf("NIM   = ");scanf("%d", &nim);
        head = addmahasiswa(head, nim,nama);
    }

    tampilmahasiswa(head);

    return 0;
}
