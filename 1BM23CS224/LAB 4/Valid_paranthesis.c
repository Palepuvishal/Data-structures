#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void push(char ele, char stack[], long long *top, long long n) {
    if (*top == n - 1) {
        printf("OVERFLOW\n");
    } else {
        (*top)++;
        stack[*top] = ele;
        printf("%c has been pushed\n", ele);
    }
}

void pop(char stack[], long long *top) {
    if (*top == -1) {
        printf("UNDERFLOW\n");
    } else {
        char popped = stack[*top];
        (*top)--;
        printf("%c has been popped\n", popped);
    }
}

bool isValid(char* s) {
    long long n = strlen(s);
    char stack[n];
    long long top = -1;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
            push(s[i], stack, &top, n);
        } else {
            if (top == -1) {
                return false;
            } else if ((stack[top] == '[' && s[i] == ']') ||
                       (stack[top] == '{' && s[i] == '}') ||
                       (stack[top] == '(' && s[i] == ')')) {
                pop(stack, &top);
            } else {
                return false;
            }
        }
    }
    
    return top == -1;
}

int main() {
    char input[100];
    printf("Enter a string of brackets: ");
    fgets(input, sizeof(input), stdin);
    
    input[strcspn(input, "\n")] = '\0';

    if (isValid(input)) {
        printf("The string has valid parentheses.\n");
    } else {
        printf("The string has invalid parentheses.\n");
    }

    return 0;
}
