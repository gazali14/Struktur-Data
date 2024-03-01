#include <stdio.h>
#include <string.h>
#define MAX 100	//ukuran maksimum array

struct Mahasiswa
{
  int nim;
  char nama[50];
  int nilai;
};

void fill_data (struct Mahasiswa mhs[], int *size){	//mengisi data
    printf ("Masukkan jumlah mahasiswa (maksimal 100): ");scanf ("%d", size);
    printf ("Input data: \n");
    for (int i = 0; i < *size; i++){
        printf("Mahasiswa ke-%d:\n", i + 1);
        printf("Nama     : "); scanf(" %[^\n]s", mhs[i].nama);
        printf("NIM      : "); scanf("%d", &mhs[i].nim);
        printf("Nilai    : "); scanf("%d", &mhs[i].nilai);
    }
}

void tampil_data (struct Mahasiswa mhs[], int size)
{
    for (int i = 0; i < size; i++)
        printf ("Nama: %s, NIM: %d,  Nilai: %d\n", mhs[i].nama, mhs[i].nim,mhs[i].nilai);
    printf ("\n");
}

void insertionSort(struct Mahasiswa mhs[], int n, int asc_desc, int sort_option)
{
    int i, j;
    struct Mahasiswa key;
    for (i = 1; i < n; i++){
        key = mhs[i];
        j = i - 1;
        switch(sort_option){
            case 1://pengurutan dengan nama
                if (asc_desc == 1){	//pengurutan ascending
                    while (j >= 0 && strcmp (mhs[j].nama, key.nama) > 0){
                        mhs[j + 1] = mhs[j];
                        j = j - 1;
                    }
                }
                else if (asc_desc == 2){ //pengurutan descending
                    while (j >= 0 && strcmp (mhs[j].nama, key.nama) < 0){
                        mhs[j + 1] = mhs[j];
                        j = j - 1;
                    }
                }
                else
                    printf ("Pilihan tidak tersedia");
                mhs[j + 1] = key;

                break;
            case 2: //pengurutan dengan nim
                if (asc_desc == 1){		//pengurutan ascending
                    while (j >= 0 && mhs[j].nim > key.nim){
                        mhs[j + 1] = mhs[j];
                        j = j - 1;
                    }
                }
                else if (asc_desc == 2){	//pengurutan descending
                    while (j >= 0 && mhs[j].nim < key.nim){
                        mhs[j + 1] = mhs[j];
                        j = j - 1;
                    }
                }
                else
	                printf ("Pilihan tidak tersedia");
	           mhs[j + 1] = key;
	           break;
	       case 3://pengurutan dengan nilai
                if (asc_desc == 1){		//pengurutan ascending
                    while (j >= 0 && mhs[j].nilai > key.nilai){
                        mhs[j + 1] = mhs[j];
                        j = j - 1;
                    }
                }
                else if (asc_desc == 2){	//pengurutan descending
                    while (j >= 0 && mhs[j].nilai < key.nilai){
                        mhs[j + 1] = mhs[j];
                        j = j - 1;
                    }
                }
                else
	                printf ("Pilihan tidak tersedia");
	           mhs[j + 1] = key;
	           break;
	       default:
	            printf("pilihan tidak tersedia");
	            break;;
        }
    }
}

void swap (struct Mahasiswa *a, struct Mahasiswa *b)
{
  struct Mahasiswa temp = *a;
  *a = *b;
  *b = temp;
}

void selection_sort (struct Mahasiswa mhs[], int size, int asc_desc,int sort_option)
{
    for (int step = 0; step < size - 1; step++){
        switch(sort_option){
            case 1: //pengurutan dengan nama
                if (asc_desc == 1){	//pengurutan ascending
                    int min_idx = step;
                    for (int i = step + 1; i < size; i++)
                        if (strcmp (mhs[i].nama, mhs[min_idx].nama) < 0)
                            min_idx = i;
                    swap (&mhs[min_idx], &mhs[step]);
                }
                else if (asc_desc == 2){//pengurutan descending
                    int max_idx = step;
                    for (int i = step + 1; i < size; i++)
                        if (strcmp (mhs[i].nama, mhs[max_idx].nama) > 0)
                            max_idx = i;
        	        swap (&mhs[max_idx], &mhs[step]);
                }
                else
                    printf ("Pilihan tidak tersedia");
                break;
            case 2: //pengurutan dengan nim
                if(asc_desc==1){ //pengurutan ascending
                    int min_idx = step;
                    for(int i = step+1; i<size; i++)
                        if(mhs[i].nim<mhs[min_idx].nim)
                            min_idx = i;
                    swap(&mhs[min_idx],&mhs[step]);
                }
                else if(asc_desc==2){//pengurutan descending
                    int max_idx = step;
                    for(int i = step +1;i<size;i++)
                        if(mhs[i].nim > mhs[max_idx].nim)
                            max_idx = i;
                    swap(&mhs[max_idx],&mhs[step]);
                }
                else
                    printf("Pilihan tidak tersedia");
                break;
            case 3: //pengurutan dengan nilai
                if(asc_desc==1){ //pengurutan ascending
                    int min_idx = step;
                    for(int i = step+1; i<size; i++)
                        if(mhs[i].nilai<mhs[min_idx].nilai)
                            min_idx = i;
                    swap(&mhs[min_idx],&mhs[step]);
                }
                else if(asc_desc==2){//pengurutan descending
                    int max_idx = step;
                    for(int i = step +1;i<size;i++)
                        if(mhs[i].nilai > mhs[max_idx].nilai)
                            max_idx = i;
                    swap(&mhs[max_idx],&mhs[step]);
                }
                else
                    printf("Pilihan tidak tersedia");
                break;
            default:
                printf("pilihan tidak tersedia");
                break;
        }
    }
}

void bubbleSort(struct Mahasiswa mhs[], int n, int asc_desc, int sort_option){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            switch(sort_option){
                case 1://pengurutan dengan nama
                    if(asc_desc==1){ //pengurutan ascending
                        if (strcmp(mhs[j].nama,mhs[j+1].nama)>0)
                            swap(&mhs[j], &mhs[j+1]);
                    }
                    else if(asc_desc==2){ //pengurutan descending
                        if (strcmp(mhs[j].nama,mhs[j+1].nama)<0)
                            swap(&mhs[j], &mhs[j+1]);

                    }
                    else
                        printf("Pilihan tidak tersedia");
                    break;
                case 2: //pengurutan dengan nim
                    if(asc_desc==1){ //pengurutan ascending
                        if (mhs[j].nim > mhs[j+1].nim)
                            swap(&mhs[j], &mhs[j+1]);
                    }
                    else if(asc_desc==2){ //pengurutan descending
                        if (mhs[j].nim < mhs[j+1].nim)
                            swap(&mhs[j], &mhs[j+1]);
                    }
                    else
                        printf("Pilihan tidak tersedia");
                    break;
                case 3://pengurutan dengan nilai
                    if(asc_desc==1){ //pengurutan ascending
                        if (mhs[j].nilai > mhs[j+1].nilai)
                            swap(&mhs[j], &mhs[j+1]);
                    }
                    else if(asc_desc==2){ //pengurutan descending
                        if (mhs[j].nilai < mhs[j+1].nilai)
                            swap(&mhs[j], &mhs[j+1]);
                    }
                    else
                        printf("Pilihan tidak tersedia");
                    break;
                default:
                    printf("Pilihan tidak tersedia");
                    break;
            }
        }
    }
}

void merge(struct Mahasiswa mhs[], int l, int m, int r,int asc_desc, int sort_option) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    struct Mahasiswa L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = mhs[l + i];
    for (j = 0; j < n2; j++)
        R[j] = mhs[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        switch (sort_option) {
            case 1: // pengurutan dengan nama
                if(asc_desc==1){
                    if (strcmp(L[i].nama, R[j].nama) <= 0) {
                        mhs[k] = L[i];
                        i++;
                    } else {
                        mhs[k] = R[j];
                        j++;
                    }
                }
                else if(asc_desc==2){
                    if (strcmp(L[i].nama, R[j].nama) >= 0) {
                        mhs[k] = L[i];
                        i++;
                    } else {
                        mhs[k] = R[j];
                        j++;
                    }
                }
                else{
                    printf("Pilihan tidak tersedia");
                }
                break;
            case 2: // pengurutan dengan nilai
                if(asc_desc==1){
                    if (L[i].nim <= R[j].nim) {
                        mhs[k] = L[i];
                        i++;
                    } else {
                        mhs[k] = R[j];
                        j++;
                    }
                }
                else if(asc_desc==2){
                    if (L[i].nim >= R[j].nim) {
                        mhs[k] = L[i];
                        i++;
                    } else {
                        mhs[k] = R[j];
                        j++;
                    }
                }
                else
                    printf("Pilihan tidak tersedia");
                break;
            case 3: // pengurutan dengan nilai
                if(asc_desc==1){
                    if (L[i].nilai <= R[j].nilai) {
                        mhs[k] = L[i];
                        i++;
                    } else {
                        mhs[k] = R[j];
                        j++;
                    }
                }
                else if(asc_desc==2){
                    if (L[i].nilai >= R[j].nilai) {
                        mhs[k] = L[i];
                        i++;
                    } else {
                        mhs[k] = R[j];
                        j++;
                    }
                }
                else
                    printf("Pilihan tidak tersedia\n");
                break;
            default:
                printf("Pilihan tidak tersedia\n");
                return;
        }
        k++;
    }

    while (i < n1) {
        mhs[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        mhs[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Mahasiswa mhs[], int l, int r,int asc_desc, int sort_option) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(mhs, l, m,asc_desc, sort_option);
        mergeSort(mhs, m + 1, r,asc_desc, sort_option);
        merge(mhs, l, m, r,asc_desc, sort_option);
    }
}

void main (){
    int pilihan, asc_desc, sort_option;
    struct Mahasiswa mhs[MAX];
    int size;	//ukuran array yang dipakai

    printf ("=====Metode Sorting Yang Tersedia=====\n");
    printf("1.Insertion Sort\n2.Selection Sort\n3.Merge Sort\n4.Bubble Sort\n");
    printf ("Pilih metode sorting (1/2/3/4) : ");scanf ("%d", &pilihan);

    printf ("\n=====Sorting Option=====\n");
    printf("1.Sort by nama\n2.Sort by nim\n3.Sort by nilai\nPilihan : ");scanf ("%d", &sort_option);

    printf ("\nPilih pengurutan Ascendng(1) atau Descending(2) --> (1/2) : ");scanf ("%d", &asc_desc);
    fill_data (mhs, &size);

    switch (pilihan){
        case 1:
            printf ("\n->Menjalankan sorting dengan metode Insertion Sort\n");
            printf ("Menjalankan sorting dengan metode Selection Sort\n");
            if(sort_option==1){
                if (asc_desc == 1){
                    printf ("->Pilihan pengurutan Sort by name (Ascendng)");
                }
                else if (asc_desc == 2){
                    printf ("->Pilihan pengurutan Sort by name (Descending)");
                }
            }
            else if(sort_option==2){
                if (asc_desc == 1){
                    printf ("->Pilihan pengurutan Sort by nim (Ascendng)");
                }
                else if (asc_desc == 2){
                    printf ("->Pilihan pengurutan Sort by nim (Descending)");
                }
            }
            else if(sort_option==3){
                if (asc_desc == 1){
                    printf ("->Pilihan pengurutan Sort by nilai (Ascendng)");
                }
                else if (asc_desc == 2){
                    printf ("->Pilihan pengurutan Sort by nilai (Descending)");
                }
            }
            insertionSort (mhs, size, asc_desc, sort_option);
            break;
        case 2:
            printf ("\n->Menjalankan sorting dengan metode Selection Sort\n");
            if(sort_option==1){
                if (asc_desc == 1){
                    printf ("->Pilihan pengurutan Sort by name (Ascendng)");
                }
                else if (asc_desc == 2){
                    printf ("->Pilihan pengurutan Sort by name (Descending)");
                }
            }
            else if(sort_option==2){
                if (asc_desc == 1){
                    printf ("->Pilihan pengurutan Sort by nim (Ascendng)");
                }
                else if (asc_desc == 2){
                    printf ("->Pilihan pengurutan Sort by nim (Descending)");
                }
            }
            else if(sort_option==3){
                if (asc_desc == 1){
                    printf ("->Pilihan pengurutan Sort by nilai (Ascendng)");
                }
                else if (asc_desc == 2){
                    printf ("->Pilihan pengurutan Sort by nilai (Descending)");
                }
            }
    	    selection_sort (mhs, size, asc_desc, sort_option);
    	    break;
        case 3:
            printf ("\n->Menjalankan sorting dengan metode Merge Sort\n");
            if(sort_option==1){
                if (asc_desc == 1){
                    printf ("->Pilihan pengurutan Sort by name (Ascendng)");
                }
                else if (asc_desc == 2){
                    printf ("->Pilihan pengurutan Sort by name (Descending)");
                }
            }
            else if(sort_option==2){
                if (asc_desc == 1){
                    printf ("->Pilihan pengurutan Sort by nim (Ascendng)");
                }
                else if (asc_desc == 2){
                    printf ("->Pilihan pengurutan Sort by nim (Descending)");
                }
            }
            else if(sort_option==3){
                if (asc_desc == 1){
                    printf ("->Pilihan pengurutan Sort by nilai (Ascendng)");
                }
                else if (asc_desc == 2){
                    printf ("->Pilihan pengurutan Sort by nilai (Descending)");
                }
            }

            mergeSort (mhs, 0, size - 1, asc_desc, sort_option);
            break;
        case 4:
            printf ("\n->Menjalankan sorting dengan metode Bubble Sort\n");
            if(sort_option==1){
                if (asc_desc == 1){
                    printf ("->Pilihan pengurutan Sort by name (Ascendng)");
                }
                else if (asc_desc == 2){
                    printf ("->Pilihan pengurutan Sort by name (Descending)");
                }
            }
            else if(sort_option==2){
                if (asc_desc == 1){
                    printf ("->Pilihan pengurutan Sort by nim (Ascendng)");
                }
                else if (asc_desc == 2){
                    printf ("->Pilihan pengurutan Sort by nim (Descending)");
                }
            }
            else if(sort_option==3){
                if (asc_desc == 1){
                    printf ("->Pilihan pengurutan Sort by nilai (Ascendng)");
                }
                else if (asc_desc == 2){
                    printf ("->Pilihan pengurutan Sort by nilai (Descending)");
                }
            }

            bubbleSort (mhs, size, asc_desc, sort_option);
            break;
        default:
            printf ("Pilihan metode tidak tersedia");
            break;
        }

    printf ("\n->Data setelah diurutkan: \n");
    tampil_data (mhs, size);
}
