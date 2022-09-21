#include <stdio.h>
#include "list.h"
#include <stdlib.h>

int main() 
{
  printf("Write your Tests for your linked list implementation\n");
  
  list_t *mylist;
  mylist = list_alloc();
  printf("Length should be 0, the length is %d\n", list_length(mylist));
  list_add_to_front(mylist, 1);
  printf("mylist should be 1, it is printed\n");
  list_print(mylist);
  list_add_to_back(mylist, 2);
  printf("mylist should be 1 -> 2, it is printed \n");
  list_print(mylist);
  list_add_to_front(mylist, 1);
  printf("mylist should be 1 -> 1 -> 2, it is printed\n");
  list_print(mylist);
  list_add_to_front(mylist, -2);
  printf("mylist should be -2 -> 1 -> 1 -> 2, it is printed\n");
  list_print(mylist);
  list_add_at_index(mylist, -2, 0);
  printf("List should be -2 -> -2 -> 1 -> 1 -> 2, it is printed\n");
  list_print(mylist);
  list_add_at_index(mylist, 10, 3);
  printf("List should be -2 -> -2 -> 1 -> 10 -> 1 -> 2, it is printed\n");
  list_print(mylist);
  list_remove_from_back(mylist);
  printf("List should be -2 -> -2 -> 1 -> 10 -> 1, it is printed\n");
  list_print(mylist);
  list_remove_from_front(mylist);
  printf("List should be -2 -> 1 -> 10 -> 1, it is printed\n");
  list_print(mylist);
  list_remove_at_index(mylist, 3);
  printf("List should be -2 -> 1 -> 10, it is printed\n");
  list_print(mylist);
  list_is_in(mylist, 10);
  printf("Should return 1\n");
  printf("%d", list_is_in(mylist, 10));
  list_is_in(mylist, 13);
  printf("Should return 0\n");
  printf("%d", list_is_in(mylist, 13));
  list_get_elem_at(mylist, 1);
  printf("Should return 1\n");
  printf("%d", list_is_in(mylist, 1));
  list_get_elem_at(mylist, 30);
  printf("Should return -1\n");
  printf("%d", list_is_in(mylist, 30));
  list_get_index_of(mylist, 5);
  printf("Should return -1\n");
  printf("%d", list_is_in(mylist, -1));
  list_get_index_of(mylist, 10);
  printf("Should return 2\n");
  printf("%d", list_is_in(mylist, 10));



 
}
