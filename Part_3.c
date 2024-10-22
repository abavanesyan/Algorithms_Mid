#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node * next;
    int value;
};


void insert(struct Node ** head, int value, int index) {
    struct Node * loc = *head;
    struct Node * newloc = 0;
    int i = 0;
    while (0 != loc->next && i < index - 1)
    {
        loc = loc->next;
        i++;
    }
    if (i == index - 1)
    {
        newloc = malloc(sizeof(struct Node));
        newloc->next = loc->next;
        loc->next = newloc;
        newloc->value = value;
    } else if (0 == index) {
        newloc = malloc(sizeof(struct Node));
        newloc->next = *head;
        *head = newloc;
        newloc->value = value;
        
    } else {
        printf("(insert) item in that index doesn't exist\n");
    }

    return;
}

void append(struct Node ** head, int value) {
    if (0 == *head) {
        *head = malloc(sizeof(struct Node));
        (*head)->next = 0;
        (*head)->value = value;
    }else { 
        struct Node * loc = *head;
        struct Node * newloc = 0;
        while (0 != loc->next)
        {
            loc = loc->next;
        }
        newloc = malloc(sizeof(struct Node));
        newloc->next = 0;
        newloc->value = value;
        loc->next = newloc;
    }

    return;
}

void delete(struct Node ** head, int index) {
    struct Node * loc = *head;
    struct Node * temp = 0;
    int i = 0;
    while (0 != loc->next && i < index - 1)
    {
        loc = loc->next;
        i++;
    }
    if (i == index - 1)
    {
        temp = loc->next;
        loc->next = (loc->next)->next;
        free(temp);
    } else if (0 == index) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        
    } else {
        printf("(delete) item in that index doesn't exist\n");
    }

    return;
}

int get(struct Node ** head, int index) {
    struct Node * loc = *head;
    int i = 0;
    while (0 != loc->next && i < index)
    {
        loc = loc->next;
        i++;
    }
    if (i == index)
    {
        return loc->value;
    } else {
        printf("if it returns 0 it means that item in that index doesn't exist\n");
        return 0;
    }

}

int main() {
    struct Node * listHead = 0;

    append(&listHead, 4);
    append(&listHead, 88);
    append(&listHead, 9);
    append(&listHead, 567);
    insert(&listHead, 7, 2);
    delete(&listHead, 1);
    delete(&listHead, 3);
    int x = get(&listHead, 2);
    printf("%d\n", x);
    delete(&listHead, 0);
    append(&listHead, 5887);
    insert(&listHead, 89, 0);

    struct Node * ptr = listHead;
    struct Node * temp = 0;

// freeing is done while printing the linked-list
    printf("all items in list\n");
    while (ptr != 0)
    {
        printf("%d ", ptr->value);
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    printf("\n");
    
    return 0;
}