#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
В первой программе описать динамическую структуру, которая
содержит указатель на статическую структуру Book( с любыми
тремя полями на выбор студента). Создать две динамические
структуры, заполнить их информацией о книгах, связать между
собой и вывести информацию из обоих структур только через
первую из них.
*/

typedef struct Book {
  char title[100];
  char author[100];
  int year;
} Book;

typedef struct Library {
  Book *book;
  struct Library *next;
} Library;

int main() {
  Library library1;
  Library library2;

  library1.book = (Book *)malloc(sizeof(Book));
  library2.book = (Book *)malloc(sizeof(Book));

  strcpy(library1.book->title, "Classroom of the Elite");
  strcpy(library1.book->author, "Syougo Kinugasa");
  library1.book->year = 2015;

  strcpy(library2.book->title, "The Promised Neverland");
  strcpy(library2.book->author, "Kaiu Shirai");
  library2.book->year = 2016;

  library1.next = &library2;
  library2.next = NULL;

  Library *current = &library1;
  int count = 1;
  while (current != NULL) {
    printf("Library %d: %s, %s, %d\n", count, current->book->title,
           current->book->author, current->book->year);
    current = current->next;
    count++;
  }

  free(library1.book);
  free(library2.book);

  return 0;
}
