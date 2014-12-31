/*
 * Doubly Linked List
 */
#include <stdio.h>
#include <stdlib.h>

#include "include/linkedlist.h"

dlcl_node * dlcl_get_next(dlcl_node *node) {
    if(node == NULL) {
        return NULL;
    } else {
        return node->next;
    }
}

dlcl_node * dlcl_get_prev(dlcl_node *node) {
    if(node == NULL) {
        return NULL;
    } else {
        return node->prev;
    }
}

dlcl_node * dlcl_get_first(dlcl_list list) {
    if(list.count == NULL) {
        return NULL;
    } else {
        return list.head;
    }
}

dlcl_node * dlcl_get_last(dlcl_list list) {
    if(list.count == 0) {
        return NULL;
    } else {
        return list.tail;
    }
}

dlcl_node * dlcl_new_node(void *data) {
    dlcl_node *newNode;

    newNode = (dlcl_node *)malloc(sizeof(dlcl_node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;

    return newNode;
}
        
dlcl_node * dlcl_insert_first(dlcl_list *list, dlcl_node *newNode) {
    return dlcl_insert_before(list, NULL, newNode);
}

dlcl_node * dlcl_insert_before(dlcl_list *list, dlcl_node *node, dlcl_node *newNode) {
    if(list->count++ == 0) {
        // List is empty, insert as first and last
        list->head = newNode->next = newNode->prev = newNode;
    } else {
        // List contains at least one node
        if(node == NULL) {
            // Insert before first Node
            node = list->head;
            // Reassign head to new head
            list->head = newNode;
        }

        // Insert before node
        newNode->prev = node->prev;
        newNode->next = node;
        node->prev = newNode;
    }
    return newNode;
}

dlcl_node * dlcl_insert_last(dlcl_list *list, dlcl_node *newNode) {
    return dlcl_insert_after(list, NULL, newNode);
}

dlcl_node * dlcl_insert_after(dlcl_list *list, dlcl_node *node, dlcl_node *newNode) {
    if(list->count++ == 0) {
        // List is empty, insert as first and last
        list->head = newNode->next = newNode->prev = newNode;
    } else {
        // List contains at least one node
        if(node == NULL) {
            // Insert after last Node
            node = list->head->prev;
        }

        // Insert after node
        newNode->prev = node;
        newNode->next = node->next;
        node->next = newNode;
    }
    return newNode;
}

void dlcl_remove(dlcl_node *node) {
    if(node != NULL) {
        dlcl_node *nextNode = node->next;
        dlcl_node *prevNode = node->prev;

        if(nextNode != NULL) {
            nextNode->prev = prevNode;
        } else {
            node->list->tail = prevNode;
        }
        if(prevNode != NULL) {
            prevNode->next = nextNode;
        } else {
            node->list->head = nextNode;
        }
        node->list->count--;
        free(node);
    }
}

void dlcl_release(dlcl_list *list) {
    if(list != NULL) {
        dlcl_node *node = list->head;
        while(node) {
            dlcl_node *nextNode = node->next;
            free(node);
            node = nextNode;
        }
        list->head = list->tail = NULL;
        list->count = 0;
    }
}

/* TO create an empty node */
void create()
{
    int data;

    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter value to node : ");
    scanf("%d", &data);
    temp->n = data;
    count++;
}

/*  TO insert at beginning */
void insert1()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}

/* To insert at end */
void insert2()
{
    if (h == NULL)
    {
        create();
        h = temp;
        temp1 = h;
    }
    else
    {
        create();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}

/* To insert at any position */
void insert3()
{
    int pos, i = 2;

    printf("\n Enter position to be inserted : ");
    scanf("%d", &pos);
    temp2 = h;

    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Position out of range to insert");
        return;
    }
    if ((h == NULL) && (pos != 1))
    {
        printf("\n Empty list cannot insert other than 1st position");
        return;
    }
    if ((h == NULL) && (pos == 1))
    {
        create();
        h = temp;
        temp1 = h;
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        create();
        temp->prev = temp2;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        temp2->next = temp;
    }
}

/* To delete an element */
void delete()
{
    int i = 1, pos;

    printf("\n Enter position to be deleted : ");
    scanf("%d", &pos);
    temp2 = h;

    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Error : Position out of range to delete");
        return;
    }
    if (h == NULL)
    {
        printf("\n Error : Empty list no elements to delete");
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        if (i == 1)
        {
            if (temp2->next == NULL)
            {
                printf("Node deleted from list");
                free(temp2);
                temp2 = h = NULL;
                return;
            }
        }
        if (temp2->next == NULL)
        {
            temp2->prev->next = NULL;
            free(temp2);
            printf("Node deleted from list");
            return;
        }
        temp2->next->prev = temp2->prev;
        if (i != 1)
            temp2->prev->next = temp2->next;    /* Might not need this statement if i == 1 check */
        if (i == 1)
            h = temp2->next;
        printf("\n Node deleted");
        free(temp2);
    }
    count--;
}

/* Traverse from beginning */
void traversebeg()
{
    temp2 = h;

    if (temp2 == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf("\n Linked list elements from begining : ");

    while (temp2->next != NULL)
    {
        printf(" %d ", temp2->n);
        temp2 = temp2->next;
    }
    printf(" %d ", temp2->n);
}

/* To traverse from end recursively */
void traverseend(int i)
{
    if (temp2 != NULL)
    {
        i = temp2->n;
        temp2 = temp2->next;
        traverseend(i);
        printf(" %d ", i);
    }
}

/* To search for an element in the list */
void search()
{
    int data, count = 0;
    temp2 = h;

    if (temp2 == NULL)
    {
        printf("\n Error : List empty to search for data");
        return;
    }
    printf("\n Enter value to search : ");
    scanf("%d", &data);
    while (temp2 != NULL)
    {
        if (temp2->n == data)
        {
            printf("\n Data found in %d position",count + 1);
            return;
        }
        else
            temp2 = temp2->next;
        count++;
    }
    printf("\n Error : %d not found in list", data);
}

/* To update a node value in the list */
void update()
{
    int data, data1;

    printf("\n Enter node data to be updated : ");
    scanf("%d", &data);
    printf("\n Enter new data : ");
    scanf("%d", &data1);
    temp2 = h;
    if (temp2 == NULL)
    {
        printf("\n Error : List empty no node to update");
        return;
    }
    while (temp2 != NULL)
    {
        if (temp2->n == data)
        {

            temp2->n = data1;
            traversebeg();
            return;
        }
        else
            temp2 = temp2->next;
    }

    printf("\n Error : %d not found in list to update", data);
}

/* To sort the linked list */
void sort()
{
    int i, j, x;

    temp2 = h;
    temp4 = h;

    if (temp2 == NULL)
    {
        printf("\n List empty to sort");
        return;
    }

    for (temp2 = h; temp2 != NULL; temp2 = temp2->next)
    {
        for (temp4 = temp2->next; temp4 != NULL; temp4 = temp4->next)
        {
            if (temp2->n > temp4->n)
            {
                x = temp2->n;
                temp2->n = temp4->n;
                temp4->n = x;
            }
        }
    }
    traversebeg();
}
