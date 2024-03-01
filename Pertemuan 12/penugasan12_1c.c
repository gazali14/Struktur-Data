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
        else{
            printf("Pilihan tidak tersedia");
            return;
        }

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
    int pilihan;
    int data[MAX];
    int size; //ukuran array yang dipakai
    printf("~~~~~~~Merge Sort~~~~~~~\n");
    fill_data(data,&size);

    printf("\nIngin diurutkan secara ascending atau descending nih ?\n");
    printf("1.ascending\n2.descending\npilihan(1/2) : ");scanf("%d", &pilihan);
    mergeSort(data,0,size-1,pilihan);

    if(pilihan==1 || pilihan==2){
        printf("Data setelah diurutkan:\n");
        tampil_data(data,size);
    }
}


