#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
Создать динамическую структуру, согласно списку задач. Номер
индивидуальной задачи вычисляется: остаток от деления на 5
Вашего номера по списку в журнале группы плюс один.
(Пример: номер в журнале 23, значит 23:5=4(ост 3). Значит номер
задачи 3+1=4. Студент решает четвертую задачу)
*/

typedef struct Task {
  int number;
  char description[100];
} Task;

typedef struct TaskList {
  Task *tasks;
  int count;
  int capacity;
} TaskList;

void createTaskList(TaskList *list, int capacity) {
  list->tasks = (Task *)malloc(capacity * sizeof(Task));
  list->count = 0;
  list->capacity = capacity;
}

void addTask(TaskList *list, int number, const char *description) {
  if (list->count < list->capacity) {
    list->tasks[list->count].number = number;
    strcpy(list->tasks[list->count].description, description);
    list->count++;
  } else {
    printf("Task list is full!\n");
  }
}

void printTaskList(TaskList *list) {
  for (int i = 0; i < list->count; i++) {
    printf("Task %d: %s\n", list->tasks[i].number, list->tasks[i].description);
  }
}

int main() {
  TaskList taskList;
  createTaskList(&taskList, 5);

  int number;
  printf("Enter your journal number: ");
  scanf("%d", &number);
  int taskNumber = number % 5 + 1;

  addTask(&taskList, taskNumber, "Dynamic structure implementation");
  addTask(&taskList, 2, "Memory management");
  addTask(&taskList, 3, "Data structures");

  printTaskList(&taskList);

  printf("Your task number: %d\n", taskNumber);

  free(taskList.tasks);
  return 0;
}