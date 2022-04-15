// Copyright 2022, Spinochi Andreea
#ifndef COMMAND_FUNCTIONS_H_
#define COMMAND_FUNCTIONS_H_

void shuffle_deck(linked_list_t *list_of_decks, int n);
void merge_decks(linked_list_t *list_of_decks, int n, int m);
void add_deck_to_main_list_to_split(linked_list_t *list_of_decks, void *data,
                                    int n);
void split_deck(linked_list_t *list_of_decks, int n, int m);
void reverse_deck(linked_list_t *list_of_decks, int n);

#endif  // COMMAND_FUNCTIONS_H_
