#include "stdio.h"
#include "stdlib.h"

/* Выполнено сразу 2 задания 2 и 3
Создать двусвязный список, предусмотреть функции создания
списка, добавление элемента. Удаление элемента из конца списка (
середина - не первый и не последний элемент). Вывод списка.

Создать двусвязный список, предусмотреть функции создания
списка, добавление элемента. Удаление элемента из начала списка (
середина - не первый и не последний элемент). Вывод списка из
начала в конец. Вывод списка из конца в начало.
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
  newNode->next = NULL;
  newNode->prev = list->tail;
  if (list->tail != NULL) {
    list->tail->next = newNode;
  }
  list->tail = newNode;
  if (list->head == NULL) {
    list->head = newNode;
  }
}

void deleteElement(List *list, int data) {
  Node *temp = list->head;
  while (temp != NULL && temp->data != data) {
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Element not found\n");
    return;
  }

  if (temp->prev == NULL) {
    list->head = temp->next;
  } else {
    temp->prev->next = temp->next;
  }

  if (temp->next == NULL) {
    list->tail = temp->prev;
  } else {
    temp->next->prev = temp->prev;
  }

  free(temp);
}

void popFront(List *list) {
  if (list->head == NULL) {
    printf("List is empty\n");
    return;
  }

  Node *temp = list->head;
  list->head = temp->next;

  if (list->head == NULL) {
    list->tail = NULL;
  } else {
    list->head->prev = NULL;
  }

  free(temp);
}

void popBack(List *list) {
  if (list->tail == NULL) {
    printf("List is empty\n");
    return;
  }

  Node *temp = list->tail;

  list->tail = temp->prev;

  if (list->tail == NULL) {
    list->head = NULL;
  } else {
    list->tail->next = NULL;
  }

  free(temp);
}

void printList(List *list) {
  Node *temp = list->head;
  do {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != NULL);
  printf("\n");
}

void printListReverse(List *list) {
  Node *temp = list->tail;
  do {
    printf("%d ", temp->data);
    temp = temp->prev;
  } while (temp != NULL);
  printf("\n");
}

int main() {
  List list;
  createList(&list);

  printf("List: ");
  addElement(&list, 1);
  addElement(&list, 2);
  addElement(&list, 3);
  addElement(&list, 4);
  addElement(&list, 5);
  addElement(&list, 6);
  addElement(&list, 7);
  addElement(&list, 8);
  addElement(&list, 9);
  addElement(&list, 10);
  printList(&list);

  printf("Pop back: ");
  popBack(&list);
  popBack(&list);
  popBack(&list);
  printList(&list);

  int number;
  printf("Enter element to delete: \n");
  scanf("%d", &number);
  deleteElement(&list, number);

  printf("List (forward): ");
  printList(&list);
  
  printf("List (reverse): ");
  printListReverse(&list);

  Node *current = list.head;
  while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
  }

  return 0;
}