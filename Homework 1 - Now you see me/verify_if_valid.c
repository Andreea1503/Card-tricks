// Copyright 2022, Spinochi Andreea
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"
#include "add.h"
#include "get.h"
#include "delete.h"
#include "show.h"
#include "command_functions.h"
#include "exit.h"
#define MAX_STRING_SIZE 64

int check_if_deck_is_valid(linked_list_t *list_of_decks, int n)
{
    if (n < 0 || n > list_of_decks->size - 1 || list_of_decks->size == 0) {
        printf("The provided index is out of bounds for the deck list.\n");
        return 0;
    }
    return 1;
}

int check_if_card_is_valid(linked_list_t *list_of_decks, int n, int c)
{
    node_t *aux_deck = get_nth_node(list_of_decks, n);

    linked_list_t *card = aux_deck->data;

    if (c < 0 || c > card->size - 1) {
        printf("The provided index is out of bounds for deck %d.\n", n);
        return 0;
    }
    return 1;
}

int verify_if_deck_is_valid(char *p, int *n)
{
    p = strtok(NULL, " ");
    if (p == NULL) {
        printf("Invalid command. Please try again.\n");
        return 0;
    }

    *n = atoi(p);
    if (strtok(NULL, " ") != NULL) {
        printf("Invalid command. Please try again.\n");
        return 0;
    }

    return 1;
}

int verify_if_deck_and_card_is_valid(char *p, int *n, int *c)
{
    p = strtok(NULL, " ");
    if (p == NULL) {
        printf("Invalid command. Please try again.\n");
        return 0;
    }

    *n = atoi(p);
    p = strtok(NULL, " ");
    if (p == NULL) {
        printf("Invalid command. Please try again.\n");
        return 0;
    }

    *c = atoi(p);
    if (strtok(NULL, " ") != NULL) {
        printf("Invalid command. Please try again.\n");
        return 0;
    }

    return 1;
}
