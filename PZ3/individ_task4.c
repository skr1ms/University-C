#include "stdio.h"
#include "stdlib.h"

/*
Создать циклический двусвязный список, предусмотреть функции
создания списка, добавление элемента. Удаление элемента из
середины списка ( середина - не первый и не последний элемент).
Вывод списка
*/

typedef struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct List {
  Node *head;
  Node *tail;
} List;

void createList(List *list) {
  list->head = NULL;
  list->tail = NULL;
}

void addElement(List *list, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;

  if (list->head == NULL) {
    newNode->next = newNode;
    newNode->prev = newNode;
    list->head = newNode;
    list->tail = newNode;
  } else {
    newNode->next = list->head;
    newNode->prev = list->tail;
    list->tail->next = newNode;
    list->head->prev = newNode;
    list->tail = newNode;
  }
}

void deleteElement(List *list, int data) {
  if (list->head == NULL) {
    printf("List is empty\n");
    return;
  }

  if (list->head == list->tail) {
    if (list->head->data == data) {
      free(list->head);
      list->head = NULL;
      list->tail = NULL;
    } else {
      printf("Element not found\n");
    }
    return;
  }

  Node *current = list->head;
  do {
    if (current->data == data) {
      if (current == list->head) {
        printf("Cannot delete first element\n");
        return;
      }
      if (current == list->tail) {
        printf("Cannot delete last element\n");
        return;
      }

      current->prev->next = current->next;
      current->next->prev = current->prev;
      free(current);
      return;
    }
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