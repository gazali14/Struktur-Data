#include <stdio.h>
#include <stdlib.h>

struct item
{
    int key;
    int value;
};

struct hashtable_item
{
    int flag;
    struct item *data;
};

struct hashtable_item *array;
int max = 10;

void init_array()
{
    int i;
    for (i = 0; i < max; i++)
    {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

int hashcode(int key)
{
    return (key % max);
}

int size = 0;

int size_of_hashtable()
{
    return size;
}

void resize_array()
{
    int i;
    int old_max = max;
    max = 2 * old_max;

    struct hashtable_item *new_array = (struct hashtable_item *)malloc(max * sizeof(struct hashtable_item));
    for (i = 0; i < max; i++)
    {
        new_array[i].flag = 0;
        new_array[i].data = NULL;
    }

    // Rehashing existing data
    for (i = 0; i < old_max; i++)
    {
        if (array[i].flag == 1)
        {
            int new_index = hashcode(array[i].data->key);
            while (new_array[new_index].flag == 1)
            {
                new_index = (new_index + 1) % max;
            }
            new_array[new_index].flag = 1;
            new_array[new_index].data = array[i].data;
        }
    }

    free(array);
    array = new_array;
}

void insert(int key, int value)
{
    if (size == max - 2)
    {
        resize_array();
    }

    int index = hashcode(key);
    int i = index;

    struct item *new_item = (struct item *)malloc(sizeof(struct item));
    new_item->key = key;
    new_item->value = value;

    while (array[i].flag == 1 || array[i].flag == 2)
    {
        if (array[i].flag == 2)
        {
            printf("\nCannot insert at index %d as it was previously removed\n", i);
            free(new_item);
            return;
        }

        if (array[i].flag == 1 && array[i].data->key == key)
        {
            printf("\nKey already exists, hence updating its value \n");
            array[i].data->value = value;
            free(new_item);
            return;
        }

        i = (i + 1) % max;

        if (i == index)
        {
            printf("\nHash table is full, cannot insert any more item \n");
            free(new_item);
            return;
        }
    }

    array[i].flag = 1;
    array[i].data = new_item;
    size++;
    printf("\nKey (%d) has been inserted \n", key);
}


void remove_element(int key)
{
    int index = hashcode(key);
    int i = index;

    while (array[i].flag != 0)
    {
        if (array[i].flag == 1 && array[i].data->key == key)
        {
            array[i].flag = 2;
            free(array[i].data);
            array[i].data = NULL;
            size--;
            printf("\nKey (%d) has been removed \n", key);
            return;
        }

        i = (i + 1) % max;

        if (i == index)
        {
            break;
        }
    }

    printf("\nThis key does not exist \n");
}

void display()
{
    int i;
    for (i = 0; i < max; i++)
    {
        struct item *current = (struct item *)array[i].data;
        if (current == NULL)
        {
            printf("\nArray[%d] has no elements \n", i);
        }
        else
        {
            printf("\nArray[%d] has elements -: \n %d(key) and %d(value) ", i, current->key, current->value);
        }
    }
}

int main()
{
    int choice, key, value, n, c;

    array = (struct hashtable_item *)malloc(max * sizeof(struct hashtable_item));
    init_array();

    do
    {
        printf("Implementation of Hash Table in C with Linear Probing \n\n");
        printf("MENU-: \n1. Inserting item in the Hashtable""\n2. Removing item from the Hashtable""\n3. Check the size of Hashtable""\n4. Display Hashtable""\n\nPlease enter your choice-:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Inserting element in Hashtable\n");
            printf("Enter key-:\t");
            scanf("%d", &key);
            printf("Enter value-:\t");
            scanf("%d", &value);
            insert(key, value);
            break;

        case 2:
            printf("Deleting in Hashtable \nEnter the key to delete-:");
            scanf("%d", &key);
            remove_element(key);

            break;

        case 3:
            n = size_of_hashtable();
            printf("Size of Hashtable is-:%d\n", n);

            break;
        case 4:
            display();
            break;
        default:
            printf("Wrong Input\n");
        }
        printf("\nDo you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
    } while (c == 1);

    free(array);
    return 0;
}

