#include <stdio.h>
#define MAX 100 //ukuran maksimum array

void fill_data(int data[], int *size){ //mengisi data
    printf("Input ukuran array (max 100): ");scanf("%d", size);
    printf("Input data: \n");
    for(int i=0;i<*size;i++){
        printf("Data ke-%d : ",i+1); scanf("%d",&data[i]);
    }
}

void tampil_data(int data[], int size){
    for(int i=0;i<size;i++)
        printf("%d ",data[i]);
    printf("\n");
}

void insertionSort(int arr[], int n, int asc_desc)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        if(asc_desc==1){//pengurutan ascending
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        else if(asc_desc==2){//pengurutan descending
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        else
            printf("Pilihan tidak tersedia");
        arr[j + 1] = key;
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int data[], int size,int asc_desc){
    for(int step = 0; step < size - 1; step++){
        if(asc_desc==1){ //pengurutan ascending
            int min_idx = step;
            for(int i = step +1;i<size;i++)
                if(data[i]<data[min_idx])
                    min_idx = i;
            swap(&data[min_idx],&data[step]);
        }
        else if(asc_desc==2){//pengurutan descending
            int max_idx = step;
            for(int i = step +1;i<size;i++)
                if(data[i]>data[max_idx])
                    max_idx = i;
            swap(&data[max_idx],&data[step]);
        }
        else
            printf("Pilihan tidak tersedia");
    }
}

void bubbleSort(int arr[], int n, int asc_desc){
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if(asc_desc==1){ //pengurutan ascending
                if (arr[j] > arr[j+1])
                    swap(&arr[j], &arr[j+1]);
            }
            else if(asc_desc==2){ //pengurutan descending
                if (arr[j] < arr[j+1])
                    swap(&arr[j], &arr[j+1]);
            }
            else
                printf("Pilihan tidak tersedia");
}

void merge(int arr[], int l, int m, int r, int asc_desc){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if(asc_desc==1){//pengurutan ascending
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        else if (asc_desc==2){//pengurutan descending
           if (L[i] >= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        else
            printf("Pilihan tidak tersedia");
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r,int asc_desc){
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m,asc_desc);
        mergeSort(arr, m + 1, r, asc_desc);
        merge(arr, l, m, r, asc_desc);
    }
}

void main(){
    int pilihan,asc_desc;
    int data[MAX];
    int size; //ukuran array yang dipakai
    printf("~~~~~~~~~~Sorting~~~~~~~~~~\n");
    printf("Metode Sorting Yang Tersedia\n");
    printf("1.Insertion Sort\n2.Selection Sort\n3.Merge Sort\n4.Bubble Sort\n");
    printf("Pilih metode sorting (1/2/3/4) : ");scanf("%d", &pilihan);

    printf("\nPilih pengurutan Ascendng(1) atau Descending(2) --> (1/2) : ");scanf("%d", &asc_desc);
    printf("\n");

    fill_data(data,&size);

    switch(pilihan){
        case 1:
            printf("->Menjalankan sorting dengan metode Insertion Sort\n");
            if(asc_desc==1){
                printf("->Pilihan pengurutan Ascendng");
            }
            else if(asc_desc==2){
                printf("->Pilihan pengurutan Descending");
            }
            insertionSort(data,size,asc_desc);
            break;
        case 2:
            printf("->Menjalankan sorting dengan metode Selection Sort\n");
            if(asc_desc==1){
                printf("->Pilihan pengurutan Ascendng");
            }
            else if(asc_desc==2){
                printf("->Pilihan pengurutan Descending");
            }
            selection_sort(data,size,asc_desc);
            break;
        case 3:
            printf("->Menjalankan sorting dengan metode Merge Sort\n");
            if(asc_desc==1){
                printf("->Pilihan pengurutan Ascendng");
            }
            else if(asc_desc==2){
                printf("->Pilihan pengurutan Descending");
            }
            mergeSort(data,0,size-1,asc_desc);
            break;
        case 4:
            printf("->Menjalankan sorting dengan metode Bubble Sort\n");
            if(asc_desc==1){
                printf("->Pilihan pengurutan Ascendng");
            }
            else if(asc_desc==2){
                printf("->Pilihan pengurutan Descending");
            }
            bubbleSort(data,size,asc_desc);
            break;
        default:
            printf("->Pilihan metode tidak tersedia");
            break;
    }


    printf("\n->Data setelah diurutkan: ");
    tampil_data(data,size);
}
