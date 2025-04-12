//Postfix Expression Evaluation in C
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 100
int stack[SIZE];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* exp) {
    int i = 0;
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');  // convert char to int
        } else {
            int val2 = pop();
            int val1 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[] = "23*54*+9-";  // Equivalent to: (2*3)+(5*4)-9
    printf("Postfix Expression: %s\n", exp);
    printf("Result = %d\n", evaluatePostfix(exp));
    return 0;
}
