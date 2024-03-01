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
        else{
            printf("Pilihan tidak tersedia");
            return;
        }

        arr[j + 1] = key;
    }
}



void main(){
    int pilihan;
    int data[MAX];
    int size; //ukuran array yang dipakai
    printf("~~~~~~~Insertion Sort~~~~~~~\n");
    fill_data(data,&size);

    printf("\nIngin diurutkan secara ascending atau descending nih ?\n");
    printf("1.ascending\n2.descending\npilihan(1/2) : ");scanf("%d", &pilihan);
    insertionSort(data,size,pilihan);

    if(pilihan==1 || pilihan==2){
        printf("Data setelah diurutkan:\n");
        tampil_data(data,size);
    }
}


