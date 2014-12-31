#include <stdio.h>
#include <stdlib.h>

#include "include/sessions.h"

// Definimos como alocar!
#define SESSIONLIST_NEW() (SessionList *)malloc(sizeof(SessionList))
#define SESSION_NEW() (Session *)malloc(sizeof(Session))


/*
* Crea una session
*/
Session* create_session() {
    Session* newSession;
    // alocamos memoria
    newSession = SESSION_NEW();
    // Iniciamos los campos
    newSession->fd = -1;
    newSession->ip[0] = 0;
    newSession->filename[0] = 0;
    newSession->offset = 0;
    newSession->total = 0;

    return newSession;
}

/*
* Agrega una session al inicio de la lista
*/
SessionList* add_session(SessionList* list, Session* session) {
    SessionList* newSessionList;
    newSessionList = SESSIONLIST_NEW();
    newSessionList->session = session;
    newSessionList->next = list;
    list = newSessionList;
    return list;
}

/*
* Devuelve la session cuyo fd coindide con fd_expected
*/
Session* get_session(SessionList *list , int fd_expected) {
    SessionList* aux;
    aux = list;

    while (aux->session->fd != fd_expected) {
        aux = aux->next;
    }
    return aux->session;
}

/*
* Elimina la session cuyo fd coindide con fd_expected
*/
SessionList* remove_session(SessionList* list , int fd_expected) {
    SessionList* current , *before;
    current = list;
    before = list;
    int current_val;
    Session* s;

    s = current->session;
    current_val = s->fd;
    while ( current_val != fd_expected){
        before = current;
        current = current->next;
        s = current->session;
        current_val = s->fd;
    }
    if (list == current) {
        if ( current->next == NULL ) {
            list = NULL;
        } else {
            list = current->next;
        }
    } else {
        before->next = current->next;
    }
    free (current->session);
    free(current);
    return list;
}
