#include "stdio.h"
#include "stdlib.h"

/*
Создать стек на односвязном списке, предусмотреть функции
создания списка, добавление элемента. Удаление элемента из
середины списка ( середина - не первый и не последний элемент).
Вывод списка
*/

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *top;
} Stack;

void createStack(Stack *stack) { stack->top = NULL; }

void push(Stack *stack, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
}

void deleteMiddleElement(Stack *stack, int number) {
  if (stack->top == NULL) {
    printf("Stack is empty\n");
    return;
  }
  
  int count = 0;
  Node *temp = stack->top;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  
  if (count < 3) {
    printf("Cannot delete from middle - stack has less than 3 elements\n");
    return;
  }
  
  temp = stack->top;
  Node *prev = NULL;
  int currentPos = 0;
  
  while (temp != NULL && temp->data != number) {
    prev = temp;
    temp = temp->next;
    currentPos++;
  }
  
  if (temp == NULL) {
    printf("Element not found\n");
    return;
  }
  
  if (currentPos == 0) {
    printf("Cannot delete first element (top of stack)\n");
    return;
  }
  
  if (currentPos == count - 1) {
    printf("Cannot delete last element (bottom of stack)\n");
    return;
  }
  
  prev->next = temp->next;
  free(temp);
  printf("Element %d deleted from middle position %d\n", number, currentPos);
}

void printStack(Stack *stack) {
  Node *temp = stack->top;
  do {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != NULL);
  printf("\n");
}

int main() {
  Stack stack;

  createStack(&stack);

  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);
  push(&stack, 4);
  push(&stack, 5);
  push(&stack, 6);
  printf("Stack: ");
  printStack(&stack);

  int number;
  printf("Enter element to delete: \n");
  scanf("%d", &number);
  printf("Delete element %d from middle: \n", number);
  deleteMiddleElement(&stack, number);

  printf("Stack: ");
  printStack(&stack);

  Node *current = stack.top;
  while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
  }
  
  return 0;
}