// Copyright 2022, Spinochi Andreea
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"
#include "add.h"
#include "get.h"
#define MAX_STRING_SIZE 64

// function that deletes the deck mentioned in the command
void delete_deck(linked_list_t *list_of_decks, int n)
{
    node_t *aux_deck = list_of_decks->head;
    node_t *curr = list_of_decks->head;
    int i = 0;

    // parsing the list of decks until we reach the one that was mentioned
    while (i < n) {
        aux_deck = aux_deck->next;
        i++;
    }

    linked_list_t *aux1 = aux_deck->data;

    node_t *aux_card = aux1->head;
    node_t *aux_card2 = aux1->head;
    i = 0;

    // deleting the cards of the mentioned deck
    while (i < aux1->size) {
        aux_card2 = aux_card;
        aux1->size--;
        aux_card = aux_card->next;

        free(aux_card2->data);
        free(aux_card2);
    }

    // check if the list has more than one deck
    if (list_of_decks->size > 1) {
        if (n == 0) {
            aux_deck = list_of_decks->head;
            node_t *aux_deck2 = list_of_decks->head;
            list_of_decks->head = aux_deck2->next;

            aux_deck2->prev = NULL;
            aux_deck->next = NULL;
            aux_deck->prev = NULL;

            aux1 = aux_deck->data;

            free(aux_deck2);
            free(aux1);
            list_of_decks->size--;

        } else if (n == list_of_decks->size - 1) {
            curr = list_of_decks->head;
            i = 0;
            while (curr->next != NULL) {
                curr = curr->next;
                i++;
            }
            curr->prev->next = NULL;
            curr->prev = NULL;

            free(aux_deck->data);
            free(aux_deck);

            list_of_decks->size--;
        } else {
            curr = list_of_decks->head;
            i = 0;
            while (i < n) {
                curr = curr->next;
                i++;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            free(aux_deck->data);
            free(aux_deck);
            list_of_decks->size--;
        }
    // if the list of decks is now empty we deallocate the resources
    } else {
        list_of_decks->head = NULL;

        free(aux_deck->data);
        free(aux_deck);
        list_of_decks->size--;
    }
}

// deleting the card at a given position
void delete_card(linked_list_t *list_of_decks, int n, int c, int *ok)
{
    node_t *aux_deck = get_nth_node(list_of_decks, n);

    linked_list_t *list_of_cards = aux_deck->data;

    // verifying if the position is valid
    if (list_of_cards->size - 1 < c) {
        printf("The provided index is out of bounds for deck %d.\n", n);
        *ok = 0;
        return;
    } else {
        node_t *aux_card = list_of_cards->head;
        node_t *curr = list_of_cards->head;
        int i = 0;

        // parsing the cards until we reach the given one
        while (i < c) {
            aux_card = aux_card->next;
            i++;
        }

        if (list_of_cards->size > 1) {
            if (c == 0) {
                aux_card = list_of_cards->head;
                node_t *aux = list_of_cards->head;
                aux = aux->next;

                aux->prev = NULL;
                aux_card->next = NULL;

                list_of_cards->head = aux;

                list_of_cards->size--;

            } else if (c == list_of_cards->size - 1) {
                curr = list_of_cards->head;
                i = 0;

                while (i < c) {
                    curr = curr->next;
                    i++;
                }

                curr->prev->next = NULL;
                curr->prev = NULL;

                list_of_cards->size--;
            } else {
                curr = list_of_cards->head;
                i = 0;

                while (i < c) {
                    curr = curr->next;
                    i++;
                }

                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;

                list_of_cards->size--;
            }
        } else {
            list_of_cards->size--;
        }

        free(aux_card->data);
        free(aux_card);

        // if the deck is empty, the resources are deallocated
        if (list_of_cards->size == 0) {
            delete_deck(list_of_decks, n);
        }
    }
}
