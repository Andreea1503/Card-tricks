// Copyright 2022, Spinochi Andreea
#ifndef STRUCTS_H_
#define STRUCTS_H_

typedef struct card_t {
	int value;
	char symbol[100];
} card_t;

typedef struct node_t
{
    void *data;
	struct node_t *prev, *next;
} node_t;

typedef struct linked_list_t
{
	node_t *head;
	int data_size;
	int size;
} linked_list_t;

#endif  // STRUCTS_H_
