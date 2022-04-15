// Copyright 2022, Spinochi Andreea
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"
#include "add.h"
#include "get.h"
#include "delete.h"
#define MAX_STRING_SIZE 64

// displaying the entire list of decks
void show_all(linked_list_t *list_of_decks)
{
    node_t *decks = list_of_decks->head;

    int i = 0;
    if (list_of_decks->size > 0) {
        do {
            linked_list_t *aux = decks->data;
            node_t *aux_card = aux->head;

            printf("Deck %d:\n", i);
            do {
                card_t *card = aux_card->data;
                // displaying the cards of the decks
                printf("\t%d %s\n", card->value, card->symbol);

                aux_card = aux_card->next;
            } while (aux_card != NULL);

            decks = decks->next;
            i++;
        } while (decks != NULL);
    }
}

// displaying the deck mentioned in the command
void show_deck(linked_list_t *list_of_decks, int n)
{
    int i = 0;

    node_t *aux_deck = list_of_decks->head;

    // parsing the list of decks until we reach the one that was mentioned
    while (i < n) {
        aux_deck = aux_deck->next;
        i++;
    }

    linked_list_t *aux = aux_deck->data;
    node_t *aux_card = aux->head;

    printf("Deck %d:\n", n);
    // displaying the cards of the deck
    while (aux_card != NULL) {
        card_t *card = aux_card->data;
        printf("\t%d %s\n", card->value, card->symbol);

        aux_card = aux_card->next;
    }
}

// displaying the number of deck
void deck_number(linked_list_t *list_of_decks)
{
    printf("The number of decks is %d.\n", list_of_decks->size);
}

// displaying the length of a given deck
void deck_len(linked_list_t *list_of_decks, int n)
{
    int i = 0;
    node_t *aux_deck = list_of_decks->head;

    // checking if the deck is valid
    if (n < 0 || n > list_of_decks->size) {
        printf("The provided index is out of bounds for the deck list.\n");
        return;
    }

    // parsing until we reach the given deck
    while (i < n) {
        aux_deck = aux_deck->next;
        i++;
    }

    linked_list_t *list_of_cards = aux_deck->data;
    printf("The length of deck %d is %d.\n", n, list_of_cards->size);
}
