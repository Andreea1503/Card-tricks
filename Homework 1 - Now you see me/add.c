// Copyright 2022, Spinochi Andreea
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"
#define MAX_STRING_SIZE 64

linked_list_t*
dll_create_list(int data_size)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    list->size = 0;
    list->data_size = data_size;
    list->head = NULL;

    return list;
}

node_t* dll_create_node()
{
    node_t *node = malloc(sizeof(node_t));

    node->prev = NULL;
    node->next = NULL;

    return node;
}

void add_card_to_deck(linked_list_t *list_of_cards, void *data)
{
    node_t *card = dll_create_node();

    // auxiliary node to parse the deck
    node_t *curr = list_of_cards->head;

    // allocation for a single card
    card->data = calloc(1, sizeof(card_t));
	memcpy(card->data, data, sizeof(card_t));

    // inserting the card if the deck is empty
    if (list_of_cards->head == 0) {
        list_of_cards->head = card;
        list_of_cards->size++;
    // inserting the card if the deck is not empty
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        card->prev = curr;
        curr->next = card;
        list_of_cards->size++;
    }
}

// add deck to main list
void add_deck_to_main_list(linked_list_t *list_of_decks, void *data)
{
    node_t *deck = dll_create_node();
    node_t *curr = list_of_decks->head;

    deck->data = calloc(1, sizeof(linked_list_t));
	memcpy(deck->data, data, sizeof(linked_list_t));

    if (list_of_decks->size == 0) {
        list_of_decks->head = deck;
        list_of_decks->size++;
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        deck->prev = curr;
        curr->next = deck;
        list_of_decks->size++;
    }
}

// add the data of the cards to a deck
void add_deck(linked_list_t *list_of_decks, int n)
{
    linked_list_t *decks = dll_create_list(sizeof(card_t));
    card_t *card = malloc(sizeof(card_t));

    int i = 0;
    int number;
    char *p;

    while (i < n) {
        char buffer[256];
        fgets(buffer, 256, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        p = strtok(buffer, " ");

        if (p != NULL) {
            number = atoi(p);
        }

        // verifying if the card is valid
        if (p != NULL) {
            if (number < 1 || number > 14) {
                printf("The provided card is not a valid one.\n");
                continue;
            }
        } else if (n > list_of_decks->size || n < 0){
            printf("The provided index is out of bounds for deck %d.\n", n);
            continue;
        } else if (p == NULL) {
            printf("Invalid command. Please try again.\n");
            free(card);
            return;
        }

         // verifying if the card is valid
        p = strtok(NULL, " ");
        if (p != NULL) {
            if (strcmp(p, "HEART") != 0 && strcmp(p, "DIAMOND") != 0 &&
                strcmp(p, "SPADE") != 0 && strcmp(p, "CLUB") != 0) {
                printf("The provided card is not a valid one.\n");
                continue;
            }
        } else {
            printf("Invalid command. Please try again.\n");
            free(card);
            return;
        }

        // updating the card data
        card->value = number;
        memcpy(card->symbol, p, 100);

        add_card_to_deck(decks, card);
        i++;
    }
    add_deck_to_main_list(list_of_decks, decks);

    free(decks);
    free(card);
}

// function for ADD_CARDS command
void add_cards(linked_list_t *list_of_decks, int n, int c)
{
    node_t *aux_deck = list_of_decks->head;
    int i = 0;

    while (i < n) {
        aux_deck = aux_deck->next;
        i++;
    }

    linked_list_t *aux = aux_deck->data;
    card_t *card = malloc(sizeof(card_t));

    i = 0;
    char *p;
    int number;

    while (i < c) {
        char buffer[256];
        fgets(buffer, 256, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        p = strtok(buffer, " ");

        // verifying if the card is valid
        if (atoi(p) != 0) {
            number = atoi(p);
        } else {
            printf("The provided card is not a valid one.\n");
            continue;
        }

        if (p != NULL) {
            if (number < 1 || number > 14) {
                printf("The provided card is not a valid one.\n");
                continue;
            }
        } else if (n > list_of_decks->size) {
            printf("The provided index is out of bounds for deck %d.\n", n);
            continue;
        } else if (p == NULL) {
            printf("Invalid command. Please try again.\n");
            free(card);
            return;
        }

        // verifying if the card is valid
        p = strtok(NULL, " ");
        if (p != NULL) {
            if (strcmp(p, "HEART") != 0 && strcmp(p, "DIAMOND") != 0 &&
                strcmp(p, "SPADE") != 0 && strcmp(p, "CLUB") != 0) {
                printf("The provided card is not a valid one.\n");
                continue;
            }
        } else {
            printf("Invalid command. Please try again.\n");
            free(card);
            return;
        }

        // updating the values of a card
        card->value = number;
        memcpy(card->symbol, p, 100);

        add_card_to_deck(aux, card);
        i++;
    }
    free(card);
}
