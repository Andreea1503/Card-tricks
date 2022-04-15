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
#define MAX_STRING_SIZE 64

void exit_program(linked_list_t *list_of_decks)
{
    int i = 0;

    while (i < list_of_decks->size) {
        delete_deck(list_of_decks, 0);
    }
    free(list_of_decks);
    exit(0);
}
