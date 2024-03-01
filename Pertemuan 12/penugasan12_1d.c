#include <stdio.h>
#define MAX 100 //ukuran maksimum array

void fill_data(int data[], int *size){ //mengisi data
    printf("Input ukuran array (max 100): ");scanf("%d", size);
    printf("Input data: \n");
    for(int i=0;i<*size;i++){
        printf("Data ke-%d : ",i+1);scanf("%d",&data[i]);
    }
}

void tampil_data(int data[], int size){
    for(int i=0;i<size;i++)
        printf("%d ",data[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n, int asc_desc){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if(asc_desc==1){ //pengurutan ascending
                if (arr[j] > arr[j+1])
                    swap(&arr[j], &arr[j+1]);
            }
            else if(asc_desc==2){ //pengurutan descending
                if (arr[j] < arr[j+1])
                    swap(&arr[j], &arr[j+1]);
            }
            else{
                printf("Pilihan tidak tersedia");
                return;
            }

        }
    }
}

void main(){
    int pilihan;
    int data[MAX];
    int size; //ukuran array yang dipakai
    printf("~~~~~~~Bubble Sort~~~~~~~\n");
    fill_data(data,&size);

    printf("\nIngin diurutkan secara ascending atau descending nih ?\n");
    printf("1.ascending\n2.descending\npilihan(1/2) : ");scanf("%d", &pilihan);
    bubbleSort(data,size,pilihan);

    if(pilihan==1 || pilihan==2){
        printf("Data setelah diurutkan:\n");
        tampil_data(data,size);
    }

}

