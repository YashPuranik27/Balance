#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void push(char stack[], char chosenChar, int* topStack) {
  stack[*topStack] = chosenChar;
  *topStack += 1;
  if (chosenChar == '0'){
    printf("\n Error");
  }
}
int errors(int x){
  switch(x){
    case 1:
          printf("\n Error");
  }
  return -1;
}
char pop(char stack[], int *topStack){
  if (*topStack == 0){
      return 0;
  }
  else{
    *topStack -= 1;
    char popped_char = stack[*topStack];
    return popped_char;
  }
}
int braceCheck(char currentChar, char popped_chosenChar, char braces){
  if(currentChar == ')' && popped_chosenChar == '('){
        return 0;
  }
  if(currentChar == '}' && popped_chosenChar == '{'){
        return 0;
  }
  if(currentChar == '[' && popped_chosenChar == ']'){
        return 0;
  }
  if(currentChar == '<' && popped_chosenChar == '>'){
        return 0;
  }
  if(currentChar == '(' && popped_chosenChar == ')'){
        return 0;
  }
  if(currentChar == '{' && popped_chosenChar == '}'){
        return 0;
  }
  if(currentChar == ']' && popped_chosenChar == '['){
        return 0;
  }
  if(currentChar == '>' && popped_chosenChar == '<'){
        return 0;
  }
  else{
    return -1;
  }
}
char oppositeSymbol(char brace){
  if(brace == '('){
    return ')';
  }
  if(brace == '{'){
    return '}';
  }
  if(brace == '['){
    return ']';
  }
  if(brace == '<'){
    return '>';
  }
  if(brace == ')'){
    return '(';
  }
  if(brace == '}'){
    return '{';
  }
  if(brace == ']'){
    return '[';
  }
  if(brace == '>'){
    return '<';
  }
  printf("\n Error in input");
  return -1;
}
char peek(char stack[], int *topStack){
  char ans;
  ans = stack[*topStack - 1];
  return ans;
  if(ans == 0){
    errors(1);
  }
}

int balanceCheck(const char *str){
  int size;
  size = strlen(str);
  char stack[size];
  int topStack = 0;
  int *stackPointer = &topStack;
  int itr = 0;
  char checker = '\0';
  while(str[itr] != 0) {
    char currentChar = str[itr];
    if(currentChar == '(' || currentChar == '{' || currentChar == '[' || currentChar == '<'){
          push(stack, currentChar, stackPointer);
    }
    else if (currentChar == ')' || currentChar == '}' || currentChar == ']' || currentChar == '>') {
            char poppedElement = peek(stack, stackPointer);
            if (!braceCheck(currentChar, poppedElement, checker)) {
                printf("%d: %c", itr, currentChar);
                printf("\n Error");
                return -1;
              }
                pop(stack, stackPointer);
            }
            itr = itr + 1;
          }
          if (topStack == 0) {
              return 1;
            }
            while (topStack != 0) {
        char stackElem = pop(stack, stackPointer);
        printf("%c", oppositeSymbol(stackElem));
        }
        return -1;
}
int main(int argc, char **argv) {
    if(argc == 1){
        printf("\n Error. Input needed");
        return -1;
    }
    char *checkString = argv[1];
    int answer;
    answer = balanceCheck(checkString);
    return answer;
}
