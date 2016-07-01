#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ENTER 10
#define true 1
#define false 0

/* Struct to save one element */
struct node {
   char letter;
   struct node *prev;
   struct node *next;
};

/* Struct to save the hole deque */
struct deque {
   struct node *front;
   struct node *back;
   int counter;
};
typedef struct deque *q;

struct deque *create() {
   struct deque *q;

   q = (struct deque *)malloc(sizeof(struct deque));

   q->front = q->back = 0;
   q->counter = 0;

   return q;
}

/* Push a new letter in front of deque. */
void push_front(struct deque *q, char letter) {
   struct node *new_element;

   new_element = (struct node *)malloc(sizeof(struct node));
   assert(new_element);

   new_element->letter = letter;

   /* Because I will be the front, nobody is in front of me*/
   new_element->next = 0;

   if(q->back == 0) {
      /* If the deque was empty, I become de back */
      q->back = new_element;
   } else {
      q->front->next = new_element;
      new_element->prev = q->front;
   }
   /* I become the new front */
   q->front = new_element;
   q->counter++;

   return;
}

/* Push a new letter onto top of deque */
void push_back(struct deque *q, char letter) {
   struct node *new_element;

   new_element = (struct node *)malloc(sizeof(struct node));
   assert(new_element);

   new_element->letter = letter;

   /* Because I will be the back, nobody is behind me */
   new_element->prev = 0;

   if(q->front == 0) {
      /* If the deque was empty, I become the front */
      q->front = new_element;
   } else {
      /* Otherwise I get in line after the old back */
      q->back->prev = new_element;
      new_element->next = q->back;
   }
   /* I become the new back */
   q->back = new_element;
   q->counter++;

   return;
}

/* Returns the first letter*/
char front(struct deque *q) {
   char i;
   i = q->front->letter;

   return i;
}

/* Returns the last letter*/
char back(struct deque *q) {
   char i;
   i = q->back->letter;

   return i;
}

/* Returns the size of the deque */
int size(struct deque *q) {
   if(q->counter == 0) printf("The Deque is empty!!!\n");

   return q->counter;
}

/* Returns 1 if the Deque is empty or 0 if it itsn't */
int empty(const struct deque *q) {
   if (q->counter == 0) return 1;
   else return 0;
}

/* Free the first deque's element.*/
void pop_front(struct deque *q) {
   struct node *head;

   /* Patch out first element */
   head = q->front;
   q->front = head->prev;
   free(head);
   q->counter--;

   return;
}

void pop_back(struct deque *q) {
   struct node *last;

   /* Patch out last element */
   last = q->back;
   q->back = last->next;
   free(last);
   q->counter--;

   return;
}

/* Remove all deque's elements */
void clear(struct deque *q) {
   while(!empty(q))
      pop_front(q);
}

/* Remove all deque's elements and free it */
void destroy(struct deque *q) {
   int i, n = q->counter;

   for(i = 0; i < n; i++)
      pop_front(q);

   free(q);
}

/* Recursive function to print the elements*/
void print_elements(struct deque *q, struct node *i) {

   if(empty(q)) {
      printf("The Deque is empty!\n");
      return;
   }
   if(i == q->back) {
      printf("%c", q->back->letter);
      return;
   }
   printf("%c", i->letter);
   print_elements(q, i->prev);
}

/* Print contents of deque on a single line, front first */
void print(struct deque *q) {
   struct node *i;

   if(empty(q)) {
      printf("The Deque is empty!\n");
   } else {
      i = q->front;
      print_elements(q, i);
      printf("\n");
   }
   return;
}

/* Read the string given until the enter. */
char *readLine() {
	char c;
	char *string = NULL;
	int counter = 0;

	do {
		c = fgetc(stdin);

		string=(char *)realloc(string,sizeof(char)*(counter+1));
		string[counter++] = c;
	} while (c != ENTER);
	string[counter-1] = '\0';

	return string;
}

struct deque *readStruct() {
   char c;
   struct deque *q = create();

	do {
		c = fgetc(stdin);
      push_back(q,c);
	} while (c != ENTER);
   pop_back(q);

   return q;
}

/* Create a struct with the letter of the given string
sorting alphabetically to form the biggest word. */
void last_word(char *string) {
   long long int len, i;
   struct deque *word = create();

   len = strlen(string);

   /* The first letter is the first word in the game. */
   push_front(word,string[0]);

   /* Build the struct to form the biggest word. */
   for(i = 1; i < len; i++) {
      if(string[i] >= word->front->letter)
         push_front(word,string[i]);
      else
         push_back(word, string[i]);
   }
   print(word);

   return;
}

int is_possible(struct deque *A, struct deque *B) {
   if(empty(A) && empty(B)) {
      return true;
   }
   char aux = back(A);
   /* Verify the last letter of B */
   if (back(A) == back(B)) {
      pop_back(A);
      pop_back(B);

      if(is_possible(A,B))
         return true;

      push_back(A,aux);
      push_back(B,aux);
   }

   /* Verify the first letter of B */
   if(back(A) == front(B)) {
      pop_back(A);
      pop_front(B);

      if(is_possible(A,B))
         return true;
   }

   /* If both options returned false */
   return false;
}

int main(int argc, char *argv[]) {
   int op;
   char *string;
   struct deque *A, *B;
   scanf("%d\n", &op);

   /* Choose the problem */
   switch(op) {
      case 1:
         string = readLine();
         last_word(string);
         free(string);
         break;
      case 2:
         A = readStruct();
         B = readStruct();

         if(is_possible(A,B)) printf("S\n");
         else printf("N\n");

         destroy(A);
         destroy(B);
         break;
      default:
         printf("Unknown Operator\n");
   }
   return 0;
}
