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
#include "sort.h"
#define MAX_STRING_SIZE 64

int main(void) {
    linked_list_t *list_of_decks;
    int n, c, m;
    list_of_decks = dll_create_list(sizeof(linked_list_t));

    while (1) {
        char command[100];
        fgets(command, 100, stdin);

        char *p = strtok(command, " ");
        if (strcmp(p, "ADD_DECK") == 0) {
            if (verify_if_deck_is_valid(p, &n) == 0) {
                continue;
            }
            add_deck(list_of_decks, n);

            printf("The deck was successfully created with %d cards.\n", n);
        } else if (strcmp(p, "ADD_CARDS") == 0) {
            if (verify_if_deck_and_card_is_valid(p, &n, &c) == 0) {
                continue;
            }
            if (check_if_deck_is_valid(list_of_decks, n) == 0) {
                continue;
            }
            add_cards(list_of_decks, n, c);

            printf("The cards were successfully added to deck %d.\n", n);
        } else if (strcmp(p, "SHOW_ALL\n") == 0) {
            if (strtok(NULL, " ") != NULL) {
                printf("Invalid command. Please try again.\n");
                continue;
            }
            show_all(list_of_decks);
        } else if (strcmp(p, "SHOW_DECK") == 0) {
            if (verify_if_deck_is_valid(p, &n) == 0) {
                continue;
            }
            if (check_if_deck_is_valid(list_of_decks, n) == 0) {
                continue;
            }
            show_deck(list_of_decks, n);
        } else if (strcmp(p, "DEL_DECK") == 0) {
            if (verify_if_deck_is_valid(p, &n) == 0) {
                continue;
            }
            if (check_if_deck_is_valid(list_of_decks, n) == 0) {
                continue;
            }
            delete_deck(list_of_decks, n);
            printf("The deck %d was successfully deleted.\n", n);
        } else if (strcmp(p, "DEL_CARD") == 0) {
            if (verify_if_deck_and_card_is_valid(p, &n, &c) == 0) {
                continue;
            }
            int ok = 1;
            if (check_if_deck_is_valid(list_of_decks, n) == 0) {
                ok = 0;
                continue;
            }
            if (check_if_card_is_valid(list_of_decks, n, c) == 0) {
                ok = 0;
                continue;
            }
            delete_card(list_of_decks, n, c, &ok);
            if (ok != 0) {
                printf("The card was successfully deleted from deck %d.\n", n);
            }
        } else if (strcmp(p, "DECK_NUMBER\n") == 0) {
            if (strtok(NULL, " ") != NULL) {
                printf("Invalid command. Please try again.\n");
                continue;
            }
            deck_number(list_of_decks);
        } else if (strcmp(p, "DECK_LEN") == 0) {
            if (verify_if_deck_is_valid(p, &n) == 0) {
                continue;
            }
            if (check_if_deck_is_valid(list_of_decks, n) == 0) {
                continue;
            }
            deck_len(list_of_decks, n);
        } else if (strcmp(p, "SHUFFLE_DECK") == 0) {
            if (verify_if_deck_is_valid(p, &n) == 0) {
                continue;
            }
            if (check_if_deck_is_valid(list_of_decks, n) == 0) {
                continue;
            }
            shuffle_deck(list_of_decks, n);
        } else if (strcmp(p, "MERGE_DECKS") == 0) {
            if (verify_if_deck_and_card_is_valid(p, &n, &m) == 0) {
                continue;
            }
            if (check_if_deck_is_valid(list_of_decks, n) == 0) {
                continue;
            }
            if (check_if_deck_is_valid(list_of_decks, m) == 0) {
                continue;
            }
            merge_decks(list_of_decks, n, m);
        } else if (strcmp(p, "SPLIT_DECK") == 0) {
            if (verify_if_deck_and_card_is_valid(p, &n, &m) == 0) {
                continue;
            }
            if (check_if_deck_is_valid(list_of_decks, n) == 0) {
                continue;
            }
            if (check_if_card_is_valid(list_of_decks, n, m) == 0) {
                continue;
            }
            split_deck(list_of_decks, n, m);
        } else if (strcmp(p, "REVERSE_DECK") == 0) {
            if (verify_if_deck_is_valid(p, &n) == 0) {
                continue;
            }
            if (check_if_deck_is_valid(list_of_decks, n) == 0) {
                continue;
            }
            reverse_deck(list_of_decks, n);
            printf("The deck %d was successfully reversed.\n", n);
            } else if (strcmp(p, "SORT_DECK") == 0) {
            if (verify_if_deck_is_valid(p, &n) == 0) {
                continue;
            }
            if (check_if_deck_is_valid(list_of_decks, n) == 0) {
                continue;
            }
            sort_deck(list_of_decks, n);
            printf("The deck %d was successfully sorted.\n", n);
            } else if (strcmp(p, "EXIT\n") == 0) {
            if (strtok(NULL, " ") != NULL) {
                printf("Invalid command. Please try again.\n");
                continue;
            }
            exit_program(list_of_decks);
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
            return 0;
}
