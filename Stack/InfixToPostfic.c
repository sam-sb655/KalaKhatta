#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    char items[MAX];
} Stack;

// Stack functions
void push(Stack *s, char ch) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = ch;
}

char pop(Stack *s) {
    if (s->top == -1)
        return '\0';
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    if (s->top == -1)
        return '\0';
    return s->items[s->top];
}

// Function to return precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Function to check if character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    s.top = -1;
    int i, j = 0;
    
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand, add to postfix expression
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If left parenthesis, push to stack
        else if (ch == '(') {
            push(&s, ch);
        }
        // If right parenthesis, pop and output until left parenthesis is found
        else if (ch == ')') {
            while (peek(&s) != '(')
                postfix[j++] = pop(&s);
            pop(&s); // Remove '(' from stack
        }
        // If operator
        else if (isOperator(ch)) {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(ch))
                postfix[j++] = pop(&s);
            push(&s, ch);
        }
    }

    // Pop remaining operators
    while (s.top != -1)
        postfix[j++] = pop(&s);

    postfix[j] = '\0'; // Null-terminate string
}

// Driver code
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
