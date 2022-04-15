// Copyright 2022, Spinochi Andreea
#ifndef VERIFY_IF_VALID_H_
#define VERIFY_IF_VALID_H_

int check_if_deck_is_valid(linked_list_t *list_of_decks, int n);
int check_if_card_is_valid(linked_list_t *list_of_decks, int n, int c);
int verify_if_deck_is_valid(char *p, int *n);
int verify_if_deck_and_card_is_valid(char *p, int *n, int *c);

#endif  // VERIFY_IF_VALID_H_
