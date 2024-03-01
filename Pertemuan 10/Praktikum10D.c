#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10

struct item
{
    int key;
    int value;
};

struct hashtable_item
{
    int flag;
    struct item data;
};

struct hashtable_item array[INITIAL_SIZE];
int size = 0;
int max_size = INITIAL_SIZE;

void init_array()
{
    int i;
    for (i = 0; i < max_size; i++)
    {
        array[i].flag = 0;
    }
}

int hashcode(int key)
{
    return (key % max_size);
}

int size_of_hashtable()
{
    return size;
}

int is_full()
{
    return size == max_size;
}

void resize_array()
{
    int old_size = max_size;
    max_size *= 2;

    struct hashtable_item new_array[max_size];
    int i;

    for (i = 0; i < max_size; i++)
    {
        new_array[i].flag = 0;
    }

    // Rehashing existing data
    for (i = 0; i < old_size; i++)
    {
        if (array[i].flag == 1)
        {
            int new_index = hashcode(array[i].data.key);
            int count = 1;
            while (new_array[new_index].flag == 1)
            {
                new_index = (new_index + count * count) % max_size;
                count++;
            }
            new_array[new_index].flag = 1;
            new_array[new_index].data = array[i].data;
        }
    }

    for (i = 0; i < max_size; i++)
    {
        array[i] = new_array[i];
    }
}

void insert(int key, int value)
{
    if (is_full())
    {
        resize_array();
    }

    int index = hashcode(key);
    int i = index;
    int count = 1;

    while (array[i].flag == 1)
    {
        i = (index + count * count) % max_size;
        count++;

        if (count == max_size)
        {
            printf("\nHash table is full, cannot insert any more items \n");
            return;
        }
    }

    array[i].flag = 1;
    array[i].data.key = key;
    array[i].data.value = value;
    size++;
    printf("\nKey (%d) has been inserted \n", key);
}

void remove_element(int key)
{
    int index = hashcode(key);
    int i = index;
    int count = 1;

    while (array[i].flag != 0)
    {
        if (array[i].flag == 1 && array[i].data.key == key)
        {
            array[i].flag = 2;
            size--;
            printf("\nKey (%d) has been removed \n", key);
            return;
        }

        i = (index + count * count) % max_size;
        count++;

        if (count == max_size)
        {
            break;
        }
    }

    printf("\nThis key does not exist \n");
}

void display()
{
    int i;
    for (i = 0; i < max_size; i++)
    {
        if (array[i].flag == 1)
        {
            printf("\nArray[%d] has elements -: \n %d(key) and %d(value) ", i, array[i].data.key, array[i].data.value);
        }
        else
        {
            printf("\nArray[%d] has no elements \n", i);
        }
    }
}

int main()
{
    int choice, key, value, n, c;

    init_array();

    do
    {
        printf("Implementation of Hash Table in C with Quadratic Probing \n\n");
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

    return 0;
}
