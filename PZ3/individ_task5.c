#include "stdio.h"
#include "stdlib.h"

/*
Создать циклический односвязный список, предусмотреть функции
создания списка, добавление элемента. Удаление элемента из
середины списка ( середина - не первый и не последний элемент).
Вывод списка.
*/

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct List {
  Node *head;
} List;

void createList(List *list) { list->head = NULL; }

void addElement(List *list, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;

  if (list->head == NULL) {
    newNode->next = newNode;
    list->head = newNode;
  } else {
    Node *current = list->head;
    while (current->next != list->head) {
      current = current->next;
    }
    newNode->next = list->head;
    current->next = newNode;
    list->head = newNode;
  }
}

void deleteElement(List *list, int data) {
  if (list->head == NULL) {
    printf("List is empty\n");
    return;
  }

  if (list->head->next == list->head) {
    if (list->head->data == data) {
      free(list->head);
      list->head = NULL;
    } else {
      printf("Element not found\n");
    }
    return;
  }

  Node *current = list->head;
  Node *prev = NULL;

  do {
    if (current->data == data) {
      if (current == list->head) {
        printf("Cannot delete first element\n");
        return;
      }

      if (current->next == list->head) {
        printf("Cannot delete last element\n");
        return;
      }

      prev->next = current->next;
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  } while (current != list->head);

  printf("Element not found\n");
}

void printList(List *list) {
  if (list->head == NULL) {
    printf("List is empty\n");
    return;
  }

  Node *current = list->head;
  do {
    printf("%d ", current->data);
    current = current->next;
  } while (current != list->head);
  printf("\n");
}

int main() {
  List list;
  createList(&list);

  addElement(&list, 1);
  addElement(&list, 2);
  addElement(&list, 3);
  addElement(&list, 4);
  addElement(&list, 5);

  printf("List: ");
  printList(&list);

  int number;
  printf("Enter element to delete: \n");
  scanf("%d", &number);
  deleteElement(&list, number);

  printf("Enter element to delete: \n");
  scanf("%d", &number);
  deleteElement(&list, number);

  printf("Enter element to delete: \n");
  scanf("%d", &number);
  deleteElement(&list, number);

  printf("Enter element to delete: \n");
  scanf("%d", &number);
  deleteElement(&list, number);

  printf("List: ");
  printList(&list);

  if (list.head != NULL) {
    Node *current = list.head;
    do {
      Node *next = current->next;
      free(current);
      current = next;
    } while (current != list.head);
  }

  return 0;
}