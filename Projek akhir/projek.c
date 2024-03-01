/* TUGAS PROJEK AKHIR STRUKTUR DATA (BUKU KONTAK)
Nama    : La Ode Muhammad Gazali
NIM     : 222212696
Kelas   : 2KS2
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <limits.h>

struct person
{
    char nama[35];
    char alamat[50];
    char no_telepon[15];
    char jenis_kelamin[8];
    char email[100];
    int umur;
    char tanggal_lahir[15];
};

void menu();
void got();
void mulai();
void kembali();
void tambah_record();
void daftar_record();
void modifikasi_record();
void hapus_record();
void cari_record();
void urutkan();
void tukar(struct person *a, struct person *b);
void perhitungan();
void pencarian_wildcard();
void pencarian_by_nama();
void pencarian_and();
void pencarian_or();

int main()
{
    //Interface menggunakan bakcground putih dan font color biru
    system("color F1");
    mulai();
    return 0;
}

void kembali()
{
    mulai();
}

void mulai()
{
    menu();
}

void tampilan_header()
{
    system("cls");
    printf("**********************************************\n");
    printf("************  APLIKASI BUKU TELEPON  *********\n");
    printf("**********************************************\n");
}

void tampilan_footer()
{
    printf("\n==============================================\n");
    printf("Tekan tombol apapun untuk melanjutkan...");
    getch();
}

void menu() // Fungsi untuk menampilkan menu utama
{
    tampilan_header();
    printf("\n\t\t MENU UTAMA\n");
    printf("==============================================\n");
    printf("[1]. Tambah Kontak Baru\n");
    printf("[2]. Daftar Kontak\n");
    printf("[3]. Edit Kontak\n");
    printf("[4]. Cari Kontak (berdasarkan Nama, AND, OR)\n");
    printf("[5]. Hapus Kontak\n");
    printf("[6]. Urutkan Kontak\n");
    printf("[7]. Perhitungan (Maks, Min, Rata-rata)\n");
    printf("[8]. Pencarian Wildcard\n");
    printf("[9]. Keluar\n");
    printf("==============================================\n");
    printf("Masukkan pilihan Anda: ");

    switch (getch())
    {
    case '1':
        tambah_record();
        break;
    case '2':
        daftar_record();
        break;
    case '3':
        modifikasi_record();
        break;
    case '4':
        cari_record();
        break;
    case '5':
        hapus_record();
        break;
    case '6':
        urutkan();
        break;
    case '7':
        perhitungan();
        break;
    case '8':
        pencarian_wildcard();
        break;
    case '9':
        exit(0);
        break;
    default:
        system("cls");
        printf("\nInput tidak valid. Masukkan angka 1 hingga 9 saja.\n");
        tampilan_footer();
        menu();
    }
}

void tambah_record() // Fungsi untuk menambahkan record kontak
{
    /*Catatan :
      Dengan fungsi tambah record ini, data kontak yang dimasukkan telah
      otomatis ter-save dan dapat di-load ketika program dijalankan kembali
      sehingga telah mengakomodasi fungsi save dan load sesuai permintaan soal
    */
    system("cls");
    FILE *f;
    struct person p;
    f = fopen("kontak", "ab+");
    printf("================= Tambah Kontak =================");
    printf("\nMasukkan nama                     : ");got(p.nama);
    printf("\nMasukkan alamat                   : ");got(p.alamat);
    printf("\nMasukkan nomor telepon            : ");got(p.no_telepon);
    printf("\nMasukkan jenis kelamin (P/L)      : ");got(p.jenis_kelamin);
    printf("\nMasukkan email                    : ");got(p.email);
    printf("\nMasukkan umur                     : ");scanf("%d", &p.umur);
    printf("Masukkan tanggal lahir (DD/MM/YYYY) : ");got(p.tanggal_lahir);
    fwrite(&p, sizeof(p), 1, f);
    printf("\nRecord tersimpan");
    fclose(f);

    printf("\n\nTekan tombol apapun");
    getch();
    system("cls");
    menu();
}

void daftar_record() // Fungsi untuk menampilkan daftar record kontak
{
    system("cls");
    struct person p;
    FILE *f;
    f = fopen("kontak", "rb");
    if (f == NULL)
    {
        printf("DATA KONTAK BELUM DITAMBAHKAN\n\n");
        printf("\nTekan tombol apapun");
        getch();
        system("cls");
        menu();
    }

    printf("\n\t\t\t\t\t\tDAFTAR KONTAK\n");
    printf("\n===============================================================================================================================\n");
    printf("%-20s%-20s%-20s%-20s%-25s%-10s%-15s\n", "Nama", "Alamat", "Nomor Telepon", "Jenis Kelamin", "Email", "Umur", "Tanggal Lahir");
    printf("===============================================================================================================================\n\n");

    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        printf("%-20s%-20s%-20s%-20s%-25s%-10d%-15s\n", p.nama, p.alamat, p.no_telepon, p.jenis_kelamin, p.email, p.umur, p.tanggal_lahir);
    }

    printf("\n===============================================================================================================================\n");
    fclose(f);
    printf("\nTekan tombol apapun");
    getch();
    system("cls");
    menu();
}


void cari_record() // Fungsi untuk mencari record kontak
{
    system("cls");
    printf("\n\t\t CARI KONTAK\n");
    printf("\n===========================================\n");
    printf("[1]. Cari berdasarkan Nama \n[2]. Cari berdasarkan Nama DAN Umur yang cock (AND) \n[3]. Cari berdasrakan Nama ATAU Umur yang cock (OR)\n");
    printf("=============================================\n");
    printf("Masukkan pilihan Anda : \n");

    switch (getch())
    {
    case '1':
        pencarian_by_nama();
        break;
    case '2':
        pencarian_and();
        break;
    case '3':
        pencarian_or();
        break;
    default:
        system("cls");
        printf("\nMasukkan 1 sampai 3 saja");
    }
}

void pencarian_by_nama() // Fungsi untuk mencari kontak berdasarkan nama
{
    system("cls");
    struct person p;
    FILE *f;
    char nama[100];
    int ditemukan = 0;

    f = fopen("kontak", "rb");
    if (f == NULL)
    {
        printf("\nDATA KONTAK BELUM DITAMBAHKAN \a\a\a\a");
        exit(1);
    }
    printf("\nMasukkan nama yang akan dicari : ");
    got(nama);

    printf("\n\t\t\t\tInformasi Detail %s\n",nama);
    printf("\n===============================================================================================================================\n");
    printf("%-20s%-20s%-20s%-20s%-25s%-10s%-15s\n", "Nama", "Alamat", "Nomor Telepon", "Jenis Kelamin", "Email", "Umur", "Tanggal Lahir");
    printf("===============================================================================================================================\n\n");

    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        if(strcmp(p.nama, nama) == 0){
            printf("%-20s%-20s%-20s%-20s%-25s%-10d%-15s\n", p.nama, p.alamat, p.no_telepon, p.jenis_kelamin, p.email, p.umur, p.tanggal_lahir);
            ditemukan = 1;
            break;
        }
    }

    printf("\n===============================================================================================================================\n");


    if (!ditemukan)
    {
        printf("\nfile tidak ditemukan");
    }

    fclose(f);
    printf("\n Tekan tombol apapun");
    getch();
    system("cls");
    menu();
}

void pencarian_and() // Fungsi untuk mencari kontak dengan kondisi AND
{
    struct person p;
    FILE *f;
    char nama[100];
    int umur;

    f = fopen("kontak", "rb");
    if (f == NULL)
    {
        printf("\nDATA KONTAK BELUM DITAMBAHKAN \a\a\a\a");
        exit(1);
    }

    printf("\nMasukkan nama yang akan dicari: ");got(nama);
    printf("\nMasukkan umur yang akan dicari: ");scanf("%d", &umur);

    system("cls");
    printf("\n\t\t\t\t\tHasil Pencarian (AND)\n");
    printf("\n===============================================================================================================================\n");
    printf("%-20s%-20s%-20s%-20s%-25s%-10s%-15s\n", "Nama", "Alamat", "Nomor Telepon", "Jenis Kelamin", "Email", "Umur", "Tanggal Lahir");
    printf("===============================================================================================================================\n\n");

    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        //Mencocokan nama dan umur
        if (strstr(p.nama, nama) != NULL && p.umur == umur){
            printf("%-20s%-20s%-20s%-20s%-25s%-10d%-15s\n", p.nama, p.alamat, p.no_telepon, p.jenis_kelamin, p.email, p.umur, p.tanggal_lahir);
        }
    }

    printf("\n===============================================================================================================================\n");

    fclose(f);

    printf("\n Tekan tombol apapun");
    getch();
    system("cls");
    menu();
}

void pencarian_or() // Fungsi untuk mencari kontak dengan kondisi OR
{
    struct person p;
    FILE *f;
    char nama[100];
    int umur;

    f = fopen("kontak", "rb");
    if (f == NULL)
    {
        printf("\nDATA KONTAK BELUM DITAMBAHKAN \a\a\a\a");
        exit(1);
    }

    printf("\nMasukkan nama yang akan dicari: ");got(nama);
    printf("\nMasukkan umur yang akan dicari: ");scanf("%d", &umur);

    system("cls");
    printf("\n\t\t\t\t\tHasil Pencarian (OR)\n");
    printf("\n===============================================================================================================================\n");
    printf("%-20s%-20s%-20s%-20s%-25s%-10s%-15s\n", "Nama", "Alamat", "Nomor Telepon", "Jenis Kelamin", "Email", "Umur", "Tanggal Lahir");
    printf("===============================================================================================================================\n\n");

    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        //Mencocokan nama dan umur
        if (strstr(p.nama, nama) != NULL || p.umur == umur){
            printf("%-20s%-20s%-20s%-20s%-25s%-10d%-15s\n", p.nama, p.alamat, p.no_telepon, p.jenis_kelamin, p.email, p.umur, p.tanggal_lahir);
        }
    }

    printf("\n===============================================================================================================================\n");

    fclose(f);

    printf("\n Tekan tombol apapun");
    getch();
    system("cls");
    menu();
}


void hapus_record() // Fungsi untuk menghapus record kontak
{
    struct person p;
    FILE *f, *ft;
    int flag = 0;
    char nama[100];

    f = fopen("kontak", "rb");
    if (f == NULL) {
        printf("DATA KONTAK BELUM DITAMBAHKAN.");
        exit(1);
    } else {
        ft = fopen("temp", "ab+");
        if (ft == NULL) {
            printf("kesalahan membuka file");
        } else {
            printf("\nMasukan nama kontak :");
            got(nama);

            while (fread(&p, sizeof(p), 1, f) == 1) {
                if (strcmp(p.nama, nama) != 0)
                    fwrite(&p, sizeof(p), 1, ft);
                else
                    flag = 1;
            }
            fclose(f);
            fclose(ft);

            if (flag != 1) {
                printf("\nTIDAK ADA DATA KONTAK YANG AKAN DIHAPUS.");
            } else {
                f = fopen("kontak", "wb"); // Membersihkan file kontak
                fclose(f);

                f = fopen("kontak", "ab+");
                ft = fopen("temp", "rb");

                while (fread(&p, sizeof(p), 1, ft) == 1) {
                    fwrite(&p, sizeof(p), 1, f);
                }

                fclose(f);
                fclose(ft);

                remove("temp");
                printf("\nKONTAK BERHASIL DIHAPUS.");
            }
        }
    }

    printf("\n Tekan tombol apapun");
    getch();
    system("cls");
    menu();
}

void modifikasi_record() // Fungsi untuk modifikasi record kontak
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  nama[50];

	f=fopen("kontak","rb+");
	if(f==NULL){
		printf("DATA KONTAK BELUM DITAMBAHKAN.");
		exit(1);
	}else{
	    system("cls");
		printf("\nMASUKKAN NAMA KONTAK YANG AKAN DIMODIFIKASI:\n");got(nama);
        while(fread(&p,sizeof(p),1,f)==1){
            if(strcmp(nama,p.nama)==0){

                printf("\nMasukkan nama                     : ");got(s.nama);
                printf("\nMasukkan alamat                   : ");got(s.alamat);
                printf("\nMasukkan nomor telepon            : ");got(s.no_telepon);
                printf("\nMasukkan jenis kelamin (P/L)      : ");got(s.jenis_kelamin);
                printf("\nMasukkan email                    : ");got(s.email);
                printf("\nMasukkan umur                     : ");scanf("%d", &s.umur);
                printf("Masukkan tanggal lahir (DD/MM/YYYY) : ");got(s.tanggal_lahir);

                fseek(f,-sizeof(p),SEEK_CUR);
                fwrite(&s,sizeof(p),1,f);
                flag=1;
                break;
            }
            fflush(stdin);
        }
        if(flag==1){
            printf("\nData anda telah dimodifikasi");
        }
        else{
            printf(" \nData tidak ditemukan");
        }
        fclose(f);
	}
	printf("\n Tekan tombol apapun");
	getch();
    system("cls");
	menu();
}

void urutkan() // Fungsi untuk mongurutkan record kontak
{
    struct person p[100], temp;
    int i, j, n;
    FILE *f;

    f = fopen("kontak", "rb");
    if (f == NULL) {
        printf("\nDATA KONTAK BELUM DITAMBAHKAN :");
        exit(1);
    }

    // Membaca data dari file ke dalam array p
    n = 0;
    while (fread(&p[n], sizeof(struct person), 1, f) == 1) {
        n++;
    }
    fclose(f);

    // Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(p[j].nama, p[j + 1].nama) > 0) {
                tukar(&p[j], &p[j + 1]);
            }
        }
    }

    // Menyimpan data yang telah diurutkan kembali ke dalam file
    f = fopen("kontak", "wb");
    if (f == NULL) {
        printf("\nDATA KONTAK BELUM DITAMBAHKAN");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        fwrite(&p[i], sizeof(struct person), 1, f);
    }
    fclose(f);

    printf("\nData telah diurutkan berdasarkan nama.");
    printf("\n Tekan tombol apapun");
    getch();
    system("cls");
	menu();
}

// Fungsi untuk menukar dua elemen dalam array person
void tukar(struct person *a, struct person *b)
{
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void got(char *nama)
{
    int i = 0;
    char c, ch;

    do {
        c = getch();

        if (c != 8 && c != 13) {
            *(nama + i) = c;
            putch(c);
            i++;
        } else if (c == 8 && i > 0) {
            i--;
            printf("\b \b");  // Hapus karakter sebelumnya dari tampilan
        }

    } while (c != 13);

    *(nama + i) = '\0';
}


// Fungsi untuk menemukan nilai maksimum dari atribut numerik
void CariUmurMaks() {
    FILE *f;
    struct person p;
    int UmurMaks = INT_MIN;
    char nama [35];

    f = fopen("kontak", "rb");  // Membuka file dalam mode baca
    if (f == NULL) {
        printf("DATA KONTAK BELUM DITAMBAHKAN");
        exit(1);
    }

    while (fread(&p, sizeof(p), 1, f) == 1) {
        if (p.umur > UmurMaks) {
            UmurMaks = p.umur;
            strcpy(nama,p.nama);
        }
    }

    fclose(f);

    printf("Usia Maksimum: %d (%s)\n", UmurMaks,nama);

    printf("\n Tekan tombol apapun");
	getch();
    system("cls");
	menu();
}

// Fungsi untuk menemukan nilai minimum dari atribut numerik
void CariUmurMin() {
    FILE *f;
    struct person p;
    int UmurMin = INT_MAX;
    char nama [35];

    f = fopen("kontak", "rb");  // Membuka file dalam mode baca
    if (f == NULL) {
        printf("DATA KONTAK BELUM DITAMBAHKAN");
        exit(1);
    }

    while (fread(&p, sizeof(p), 1, f) == 1) {
        if (p.umur < UmurMin) {
            UmurMin = p.umur;
            strcpy(nama,p.nama);
        }
    }

    fclose(f);

    printf("Usia Minimum: %d (%s)\n", UmurMin,nama);

    printf("\n Tekan tombol apapun");
	getch();
    system("cls");
	menu();
}

// Fungsi untuk menemukan nilai rata-rata dari atribut numerik
void CariUmurRata2() {
    FILE *f;
    struct person p;
    int TotalUmur = 0;
    int count = 0;

    f = fopen("kontak", "rb");  // Membuka file dalam mode baca
    if (f == NULL) {
        printf("DATA KONTAK BELUM DITAMBAHKAN");
        exit(1);
    }

    while (fread(&p, sizeof(p), 1, f) == 1) {
        TotalUmur += p.umur;
        count++;
    }

    fclose(f);

    if (count == 0) {
        printf("Usia Rata-rata: 0.0 (Tidak ada rekaman)\n");
    } else {
        float rataUsia = (float)TotalUmur/count;
        printf("Usia Rata-rata: %.2f\n", rataUsia);
    }

    printf("\n Tekan tombol apapun");
	getch();
    system("cls");
	menu();
}

void perhitungan()
{
    int UmurMaks, UmurMin;
    float UmurRata2;

    system("cls");
    printf("\n\t PERHITUNGAN\n");
    printf("\n============================\n");
    printf("[1].Usia Maksimum \n[2].Usia Minimum \n[3].Usia Rata-rata");
    printf("\n============================\n");
    printf("Masukkan pilihan anda : \n");

    switch(getch())
    {
        case '1':
            CariUmurMaks();
            break;
        case '2':
            CariUmurMin();
            break;
        case '3':
            CariUmurRata2();
            break;
        default:
            system("cls");
            printf("\nMasukkan angka 1 sampai 3 saja");
    }
}

void pencarian_wildcard()
{
    struct person p;
    FILE *f;
    char wildcard[15];

    system("cls");
    printf("\nMasukkan pola wildcard No Telepon: ");
    got(wildcard);

    f = fopen("kontak", "rb");
    if (f == NULL) {
        printf("\nDATA KONTAK BELUM DITAMBAHKAN \a\a\a\a");
        exit(1);
    }

    printf("\n\t\t\t\t\tHasil Pencarian\n");
    printf("\n===============================================================================================================================\n");
    printf("%-20s%-20s%-20s%-20s%-25s%-10s%-15s\n", "Nama", "Alamat", "Nomor Telepon", "Jenis Kelamin", "Email", "Umur", "Tanggal Lahir");
    printf("===============================================================================================================================\n\n");

    while (fread(&p, sizeof(p), 1, f) == 1)
    {
        // Menggunakan strstr untuk mencocokkan wildcard dengan nomor telepon
        if (strstr(p.no_telepon, wildcard) != NULL){
            printf("%-20s%-20s%-20s%-20s%-25s%-10d%-15s\n", p.nama, p.alamat, p.no_telepon, p.jenis_kelamin, p.email, p.umur, p.tanggal_lahir);
        }
    }

    printf("\n===============================================================================================================================\n");

    fclose(f);

    printf("\n Tekan tombol apapun");
    getch();
    system("cls");
    menu();
}
