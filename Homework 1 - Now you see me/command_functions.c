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
#define MAX_STRING_SIZE 64

void shuffle_deck(linked_list_t *list_of_decks, int n)
{
    node_t *aux_deck = get_nth_node(list_of_decks, n);
    int count;

    linked_list_t *list_of_cards = aux_deck->data;

    if (list_of_cards->size > 1) {
        list_of_cards = aux_deck->data;
        // the index to which the cards are moved to the end of the deck
        count = list_of_cards->size / 2;

        node_t *aux_card = list_of_cards->head;
        card_t *card = aux_card->data;
        int j = 0;

        while (j < count) {
            // add a card to the end of the deck and delete the first one
            add_card_to_deck(list_of_cards, card);
            delete_card(list_of_decks, n, 0, 0);

            j++;
            aux_card = get_nth_card(list_of_cards, 0);
            card = aux_card->data;
        }
    }
    printf("The deck %d was successfully shuffled.\n", n);
}

void merge_decks(linked_list_t *list_of_decks, int n, int m)
{
    node_t *deck_1 = get_nth_node(list_of_decks, n);
    node_t *deck_2 = get_nth_node(list_of_decks, m);

    linked_list_t *deck = dll_create_list(sizeof(card_t));

    linked_list_t *aux1 = deck_1->data;
    linked_list_t *aux2 = deck_2->data;

    node_t *curr1;
    card_t *card1;

    node_t *curr2;
    card_t *card2;

    int min;

    // get the minimum size of the two decks
    if (aux1->size < aux2->size) {
        min = aux1->size;
    } else {
        min = aux2->size;
    }

    int i = 0;

    // parsing until we reach the mininum length
    while (i < min) {
        curr1 = get_nth_card(aux1, i);
        if (curr1->data != NULL) {
            card1 = curr1->data;
        }

        curr2 = get_nth_card(aux2, i);
        if (curr2->data != NULL) {
            card2 = curr2->data;
        }

        add_card_to_deck(deck, card1);
        add_card_to_deck(deck, card2);

        i++;
    }

    // the minimum length was reached and we still have cards to place
    // in the merged deck
    if (aux1->size > min) {
        while (i < aux1->size) {
            curr1 = get_nth_card(aux1, i);

            if (curr1->data != NULL) {
                card1 = curr1->data;
            }

            add_card_to_deck(deck, card1);
            i++;
        }
    } else if (aux2->size > min) {
        while (i < aux2->size) {
            curr2 = get_nth_card(aux2, i);

            if (curr2->data != NULL) {
                card2 = curr2->data;
            }

            add_card_to_deck(deck, card2);
            i++;
        }
    }
    // adding the merged deck to the main list
    add_deck_to_main_list(list_of_decks, deck);

    // deleting the initial decks
    if (n < m) {
        delete_deck(list_of_decks, n);
        delete_deck(list_of_decks, m-1);
    } else {
        delete_deck(list_of_decks, m);
        delete_deck(list_of_decks, n - 1);
    }
    free(deck);

    printf("The deck %d and the deck %d were successfully merged.\n", n, m);
}

// adding the split decks to the main list
void add_deck_to_main_list_to_split(linked_list_t *list_of_decks, void *data,
                                    int n)
{
    node_t *deck = dll_create_node();
    node_t *curr;

    deck->data = calloc(1, sizeof(linked_list_t));
	memcpy(deck->data, data, sizeof(linked_list_t));

    if (list_of_decks->size == 0) {
        list_of_decks->head = deck;
        list_of_decks->size++;
    } else if (n == list_of_decks->size - 1) {
        curr = get_nth_node(list_of_decks, n);
        deck->prev = curr;
        curr->next = deck;
        list_of_decks->size++;
    } else {
        curr = get_nth_node(list_of_decks, n);
        deck->next = curr->next;
        deck->prev = curr;
        curr->next->prev = deck;
        curr->next = deck;
        list_of_decks->size++;
    }
}

void split_deck(linked_list_t *list_of_decks, int n, int m)
{
    linked_list_t *deck_1 = dll_create_list(sizeof(card_t));
    linked_list_t *deck_2 = dll_create_list(sizeof(card_t));

    int i = 0;
    // the card index where the split begins should be at least 1
    if (m != 0) {
        node_t *aux_deck = get_nth_node(list_of_decks, n);

        linked_list_t *card = aux_deck->data;
        node_t *aux_card;
        card_t *aux;

        // creating the first splitted deck
        while (i < m) {
            aux_card = get_nth_card(card, i);

            if (aux_card->data != NULL) {
                aux = aux_card->data;
            }
            add_card_to_deck(deck_1, aux);
            i++;
        }

        // creating the second splitted deck
        while (i < card->size) {
            aux_card = get_nth_card(card, i);

            if (aux_card->data != NULL) {
                aux = aux_card->data;
            }
            add_card_to_deck(deck_2, aux);
            i++;
    }

    add_deck_to_main_list_to_split(list_of_decks, deck_1, n);
    delete_deck(list_of_decks, n);
    add_deck_to_main_list_to_split(list_of_decks, deck_2, n);
    }
    free(deck_1);
    free(deck_2);
    printf("The deck %d was successfully split by index %d.\n", n, m);
}

void reverse_deck(linked_list_t *list_of_decks, int n)
{
    node_t *curr = get_nth_node(list_of_decks, n);

    linked_list_t *card = curr->data;

    node_t *temp = NULL;
    node_t *current = card->head;

    // swaping the nodes
    if (card->size > 1) {
        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        // check that the list has more than one card
        if (temp != NULL)
            card->head = temp->prev;
    }
}
