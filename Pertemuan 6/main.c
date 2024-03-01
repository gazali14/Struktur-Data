#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};
typedef struct node *mynode;

mynode CreateNode(int nilai){
    mynode new = (mynode)malloc(sizeof(struct node));
    new->next = NULL;
    new->data = nilai;
    return(new);
}

mynode push(int nilai, mynode head){
    mynode new_node = CreateNode(nilai);
    new_node->next = head;
    head = new_node;
    return(head);
}

mynode pop (mynode head){
    if (head==NULL)
        return NULL;
    mynode temp = head;
    head = temp->next;
    temp-> next = NULL;
    free(temp);
    
    return(head);
}

void display(mynode head){
    mynode temp;
    if (head == NULL){
        printf("Noda kosong");
        return;
    }
    temp = head;
    printf("List dari node:\n");
    while(head != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
}

mynode node_bantuan(int modulus, mynode *node){
    mynode temp;
    temp = (mynode)malloc(sizeof(struct node));
    temp->data = modulus;
    temp->next = *node;
    
    return(temp);
}

void desimal_binary(int n, mynode *head){
    int sisa_bagi;
    for(int i = n ; i > 0 ; i = i/2){
        sisa_bagi = i%2;
        *head = node_bantuan(sisa_bagi, head);
    }
    printf("Hasil konversi Desiaml ke Biner : ");
    mynode temp = *head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
}

void desimal_oktal(int n, mynode *head){
    int sisa_bagi;
    for(int i = n ; i > 0 ; i = i/8){
        sisa_bagi = i%8;
        *head = node_bantuan(sisa_bagi, head);
    }
    printf("Hasil konversi adalah : ");
    mynode temp = *head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
}

int main(){
    mynode head = NULL;
    int bil_desimal, pilihan;
    
    printf("Masukan bilangan desimal : ");scanf("%d",&bil_desimal);
    printf("Menu : \n1. Desimal ke biner \n2. Desimal ke Oktal \n3. exit \nPilihan Anda : ");
    scanf("%d", &pilihan);
    
    switch(pilihan){
        case 1:
            if(bil_desimal==0)
                printf("Hasil konversi adalah : 0");
            else if (bil_desimal < 0){
                int bil_sama = 1;
                while (bil_sama < (bil_desimal * -1))
                {
                    bil_sama *= 2;
                }
                //printf("%d", bil_sama);
    
                desimal_binary(bil_sama - (bil_desimal * -1), &head);
            }
            else{
                desimal_binary(bil_desimal, &head);
                // decToBinary(bil_desimal, &tumpukan);
            }
            break;
        
        case 2:
            desimal_oktal(bil_desimal, &head);
            break;
        
        case 3:
            exit;
            
        default:
            printf("Menu tidak diketahui");
            break;
    }
    
    return 0;
}