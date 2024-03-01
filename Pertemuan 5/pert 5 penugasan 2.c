#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node* mynode;

mynode createNode(int nilai){
    mynode temp;
    temp = (mynode)malloc(sizeof(struct node));;
    temp->data = nilai;
    temp->next = NULL;
    temp->prev = NULL;
}

void insert_head(mynode* head, int data) {
    mynode newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

mynode insert_tail(mynode head, mynode *tail, int data) {
    mynode new_node = createNode(data);
    new_node->next = NULL;

    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        *tail = new_node;
// Perbarui tail saat memasukkan elemen pertama
    } else {
        new_node->prev = *tail;
        (*tail)->next = new_node;
        *tail = new_node;
    }

    return head;
}


mynode tampilnilai(mynode head) {
    mynode current = head;
    int i=1;
    while (current != NULL) {
        printf("Node ke-%d : %d",i, current->data);
        current = current->next;
        i++;
        printf("\n");
    }
    printf("\n");

    return head;
}

int main(){
    int data,n;
    mynode head = NULL;
    mynode tail = NULL;

    printf("Masukan jumlah data : ");scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        printf("Masukkan data node ke-%d = ", i + 1);
        scanf("%d", &data);
        head = insert_tail(head, &tail, data);
    }

    printf("Daftar awal:\n");
    tampilnilai(head);

    printf("Masukan data untuk first node : ");scanf("%d", &data);
    insert_head(&head, data);

    printf("Daftar setelah insert head:\n");
    tampilnilai(head);
    return 0;

}
