#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node *ptrnode;

ptrnode createNode(int nilai){
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
ptrnode insert_tail(ptrnode head, ptrnode *tail, int nilai) {
    ptrnode new_node = createNode(nilai);
    new_node->next = NULL;

    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        *tail = new_node; // Perbarui tail saat memasukkan elemen pertama
    } else {
        new_node->prev = *tail;
        (*tail)->next = new_node;
        *tail = new_node;
    }

    return head;
}

ptrnode remove_last(ptrnode head, ptrnode *tail) {
    if (head == NULL) {
        printf("Daftar kosong, tidak ada yang dapat dihapus\n");
        return head;
    }
    if (*tail == head) {
        free(head);
        *tail = NULL;
        return NULL;
    }
    ptrnode temp = *tail;
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
    free(temp);

    return head;
}

ptrnode tampilnilai(ptrnode head) {
    ptrnode current = head;
    int i=1;
    while (current != NULL) {
        printf("Node ke-%d : %d",i, current->value);
        current = current->next;
        i++;
        printf("\n");
    }
    printf("\n");

    return head;
}

int main(){
    ptrnode head = NULL;
    ptrnode tail = NULL;

    head=insert_tail(head, &tail, 1);
    head=insert_tail(head, &tail, 2);
    head=insert_tail(head, &tail, 3);

    printf("Daftar awal:\n");
    tampilnilai(head);

    insert_tail(head,&tail, 8);
    printf("Daftar setelah insert tail:\n");
    tampilnilai(head);

    head = remove_last(head, &tail);
    printf("Daftar setelah remove:\n");
    tampilnilai(head);


    return 0;

}
