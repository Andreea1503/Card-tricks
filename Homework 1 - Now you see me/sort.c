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
#include "verify_if_valid.h"
#define MAX_STRING_SIZE 64

void sort_deck(linked_list_t *list_of_decks, int n)
{
    node_t *aux = get_nth_node(list_of_decks, n);
    linked_list_t *list_of_cards = aux->data;
    node_t *cards = list_of_cards->head;
    node_t *aux_cards = NULL;
    card_t *card;

    int swapped;

    if (list_of_cards->head == NULL)
        return;
    if (list_of_cards->size > 1) {
        do {
            swapped = 0;
            while (cards->next != aux_cards) {
                card = cards->data;
                node_t *aux = cards->next;
                card_t *aux_card = aux->data;

                // comparing the values
                if (card->value > aux_card->value)
                {
                    node_t *temp_node = cards->data;
                    cards->data = cards->next->data;
                    cards->next->data = temp_node;

                    swapped = 1;
                // if the values are equal, sort based on the symbol
                } else if (card->value == aux_card->value) {
                    if (strcmp(aux_card->symbol, "HEART") == 0 &&
                        strcmp(card->symbol, "HEART") != 0) {
                        node_t *temp_node = cards->data;
                        cards->data = cards->next->data;
                        cards->next->data = temp_node;

                        swapped = 1;
                    } else if (strcmp(aux_card->symbol, "SPADE") == 0 &&
                            strcmp(card->symbol, "HEART") != 0 &&
                            strcmp(card->symbol, "SPADE") != 0) {
                        node_t *temp_node = cards->data;
                        cards->data = cards->next->data;
                        cards->next->data = temp_node;

                        swapped = 1;
                    } else if (strcmp(aux_card->symbol, "DIAMOND") == 0 &&
                            strcmp(card->symbol, "HEART") != 0 &&
                            strcmp(card->symbol, "SPADE") != 0 &&
                            strcmp(card->symbol, "DIAMOND") != 0) {
                        node_t *temp_node = cards->data;
                        cards->data = cards->next->data;
                        cards->next->data = temp_node;

                        swapped = 1;
                    }
                }
                cards = cards->next;
            }
            aux_cards = cards;
            cards = list_of_cards->head;
        } while (swapped);
    }
}
