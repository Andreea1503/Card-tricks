// Copyright 2022, Spinochi Andreea
#ifndef ADD_H_
#define ADD_H_

linked_list_t* dll_create_list(int data_size);
node_t* dll_create_node();
void add_card_to_deck(linked_list_t *list_of_cards, void *data);
void add_deck_to_main_list(linked_list_t *list_of_decks, void *data);
void add_deck(linked_list_t *list_of_decks, int n);
void add_cards(linked_list_t *list_of_decks, int n, int c);

#endif  // ADD_H_
