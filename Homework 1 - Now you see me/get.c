// Copyright 2022, Spinochi Andreea
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"
#include "add.h"
#include "delete.h"
#define MAX_STRING_SIZE 64

// get a pointer for a deck at a given position
node_t*
get_nth_node(linked_list_t *list_of_decks, int n)
{
    node_t *list_aux = list_of_decks->head;
    int i = 0;

    if (n == 0) {
        return list_aux;
    } else if (n == list_of_decks->size - 1) {
        i = 0;

        while (i < n) {
            list_aux = list_aux->next;
            i++;
        }

        return list_aux;
    } else {
        i = 0;

        while (i < n) {
            list_aux = list_aux->next;
            i++;
        }

        return list_aux;
    }
}

// get a pointer for a card at a given position
node_t*
get_nth_card(linked_list_t *list_of_cards, int n)
{
    node_t *list_aux = list_of_cards->head;
    int i = 0;

    if (n == 0) {
        return list_aux;
    } else if (n == list_of_cards->size - 1) {
        i = 0;

        while (i < n) {
            list_aux = list_aux->next;
            i++;
        }

        return list_aux;
    } else {
        i = 0;

        while (i < n) {
            list_aux = list_aux->next;
            i++;
        }

        return list_aux;
    }
}

