#include <stdio.h>
#define MAX 100 //ukuran maksimum array

void fill_data(int data[], int *size){ //mengisi data
    printf("Input ukuran array (max 100): ");scanf("%d", size);
    printf("Input data: \n");
    for(int i=0;i<*size;i++){
        printf("data ke-%d : ",i+1); scanf("%d",&data[i]);
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
        else{
            printf("Pilihan tidak tersedia");
            return;;
        }

    }
}

void main(){
    int pilihan;
    int data[MAX];
    int size; //ukuran array yang dipakai
    printf("~~~~~~~selection Sort~~~~~~~\n");
    fill_data(data,&size);


    printf("\nIngin diurutkan secara ascending atau descending nih ?\n");
    printf("1.ascending\n2.descending\npilihan(1/2) : ");scanf("%d", &pilihan);
    selection_sort(data,size,pilihan);

    if(pilihan==1 || pilihan==2){
        printf("Data setelah diurutkan:\n");
        tampil_data(data,size);
    }
}


