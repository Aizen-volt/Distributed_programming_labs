#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char* data;
  struct Node* next;
  struct Node* prev;
};

void waitForKey() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    continue;
  }
}

void clearScreen() {
  printf("\e[1;1H\e[2J");
}

void printMenu() {
  clearScreen();
  printf("1. Show all elements\n2. Add element\n3. Remove element at index\n[CTRL+d] EXIT\nInput: ");
}

void freeList(struct Node** head_ref) {
  struct Node* current = *head_ref;
  struct Node* next;

  while (current != NULL) {
    next = current->next;
    //free(current->data);
    //free(current);
    current = next;
  }

  *head_ref = NULL;
}

void showAllElements(struct Node* head) {
  clearScreen();
  struct Node* current = head;
  while (current != NULL) {
    printf("%s", current->data);
    current = current->next;
  }
  printf("Press any key to continue...\n");
  waitForKey();
}

void addElement(struct Node** head_ref, char* element) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    freeList(head_ref);
    exit(1);
  }
  newNode->data = element;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (*head_ref == NULL || strcmp(element, (*head_ref)->data) > 0) {
    newNode->next = *head_ref;
    if (*head_ref != NULL) {
      (*head_ref)->prev = newNode;
    }
    *head_ref = newNode;
  }
  else {
    struct Node* current = *head_ref;
    while (current->next != NULL && strcmp(element, current->next->data) < 0) {
      current = current->next;
    }
    newNode->next = current->next;
    if (current->next != NULL) {
      newNode->prev = current;
      current->next->prev = newNode;
    }
    current->next = newNode;
  }
}

void removeElement(struct Node** head_ref, int index) {
  if (index < 0) {
    return;
  }

  if (*head_ref == NULL) {
    return;
  }

  struct Node* temp = *head_ref;

  if (index == 0) {
    *head_ref = temp->next;
    free(temp->data); 
    free(temp); 
    return;
  }

  for (int i = 0; temp != NULL && i < index - 1; i++) {
    temp = temp->next;
  }

  if (temp == NULL || temp->next == NULL) {
    return;
  }

  struct Node* next = temp->next->next;

  free(temp->next->data);
  free(temp->next);

  temp->next = next;
}

void handleInput(char* input, struct Node** head_ref) {
  if (strcmp(input, "1\n") == 0) {
    showAllElements(*head_ref);
  }
  else if (strcmp(input, "2\n") == 0) {
    char* element = NULL;
    size_t len;
    printf("Enter element: ");
    getline(&element, &len, stdin);
    addElement(head_ref, element);
  }
  else if (strcmp(input, "3\n") == 0) {
    int index;
    scanf("%d", &index);
    removeElement(head_ref, index);
  }
}

int main() {
  struct Node* head = NULL;

  char* input = NULL;
  size_t len = 0;
  ssize_t read;

  printMenu();
  while ((read = getline(&input, &len, stdin)) != -1) {
    handleInput(input, &head);
    printMenu();
  }
  clearScreen();

  freeList(&head);
  free(input);

  return 0;
}
