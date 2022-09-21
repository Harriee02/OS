// list/list.c
//
// Implementation for linked list.
//
// <Author>
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list_t *list_alloc() {
  list_t *ll = malloc(sizeof(list_t));
  return ll;
}

void list_free(list_t *ll){
	if (ll->head == NULL) {return;}
  node_t* node = ll->head;
  node_t* to_free = NULL;
  while (node != NULL) {
    to_free = node;
    node = to_free->next;
    free(to_free);
  }
  ll->head = NULL;
  free(ll);
}

void list_print(list_t *ll) {
  if (ll->head == NULL) {return;}
  node_t* node = ll->head;
  while (node->next != NULL) {
    printf("%d -> ", node->value);
    node = node->next;
  }
  printf("%d\n", node->value);
}

int list_length(list_t* ll){
	if (ll->head == NULL) {return 0;}
	node_t* node = ll->head;
	int length = 0;
	while (node != NULL){
		length ++;
		node = node->next;
	}
	return length;
}

void list_add_to_back(list_t *l, elem value){
	node_t* new_node = malloc(sizeof(node_t));
	new_node->value = value;
	if (l->head == NULL) {
		l->head = new_node;
		return;
	}
	node_t* node = l->head;
	while (node->next != NULL){
		node = node->next;
	}
	node->next = new_node;
}

void list_add_to_front(list_t *l, elem value){
	node_t* new_node = malloc(sizeof(node_t));
	new_node->value = value;
	if (l->head == NULL){
		l->head = new_node;
		return;
	}
	new_node->next = l->head;
	l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index){
	if (index == 0){
		list_add_to_front(l, value);
		return;
	}
	if (index > (list_length(l)-1) ){
		list_add_to_back(l, value);
		return;
	}
	node_t* new_node = malloc(sizeof(node_t));
	new_node->value = value;
	node_t* curr = l->head;
	int counter = 0;
	while (curr != NULL){
		if (index == counter + 1){
			node_t* remaining = curr->next;
			curr->next = new_node;
			new_node->next = remaining;
			break;
		}
		counter++;
		curr = curr->next;
	}
}

elem list_remove_from_back(list_t *l){
	if (l->head == NULL) {
		return -1;
	}
	if (l->head->next == NULL){
		elem return_elem = l->head->value;
		free(l);
		return return_elem;
	}
	node_t* curr = l->head;
	while (curr->next->next != NULL){
		curr = curr->next;
	}
	elem return_elem = curr->next->value;
	free(curr->next);
	curr->next = NULL;
	return return_elem;
}

elem list_remove_from_front(list_t *l){
	if (l->head == NULL) {
		return -1;
	}
	node_t* node = l->head;
	elem return_elem = node->value;
	l->head = node->next;
	free(node);
	return return_elem;
}

elem list_remove_at_index(list_t *l, int index){
	if (l->head == NULL || index >= list_length(l)) {
		return -1;
	}
	if (index == 0){
		return list_remove_from_front(l);
	}
	if(index == list_length(l)- 1) {
    return list_remove_from_back(l);
  }
	node_t* curr = l->head;
	elem return_elem = 0;
	int counter = 0;
	while (curr->next != NULL){
		if (counter + 1 == index){
			node_t* node = curr->next;
			return_elem = curr->next->value;
			curr->next = curr->next->next;
			free(node);
			return return_elem;
		}
		counter ++;
	}
}

bool list_is_in(list_t *l, elem value) {
  return list_get_index_of(l, value) != -1; 
}

elem list_get_elem_at(list_t *l, int index){
	if (l->head == NULL) {
		return -1;
		}
	node_t* curr = l->head;
	int counter = 0;
	while (curr != NULL){
		if (counter == index){
			return curr->value;
		}
		counter++;
		curr = curr->next;
	}
	return -1;
}

int list_get_index_of(list_t *l, elem value){
	if (l->head == NULL) {
		return -1;
		}
	node_t* curr = l->head;
	int counter = 0;
	while (curr != NULL){
		if (curr->value == value){
			return counter;
		}
		counter ++;
		curr = curr->next;
	}
	return -1;
}


