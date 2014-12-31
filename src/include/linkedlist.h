/**
 * @file linkedlist.h
 * @author Ariel Salvo
 * @date 31 Dec 2014
 * @brief Doubly Linked Circular List
 *
 * Defines structure, types and interface to a Doubly Linked Circular List
 * @see http://www.sanfoundry.com/c-program-doubly-linked-list/
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct dlcl_node {
    void *data;
    struct dlcl_node *next;
    struct dlcl_node *prev;
} dlcl_node;

typedef struct dlcl_list {
    dlcl_node *head;
    unsigned long count;
} dlcl_list;

#endif /*LINKEDLIST_H_ */
