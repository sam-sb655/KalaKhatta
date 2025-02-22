#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    double items[MAX];
} Stack;

// Stack functions
void push(Stack *s, double value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

double pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Function to evaluate a postfix expression
double evaluatePostfix(char *postfix) {
    Stack s;
    s.top = -1;
    int i;

    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // If operand, push onto stack
        if (isdigit(ch)) {
            push(&s, ch - '0'); // Convert character to integer
        }
        // If operator, pop two elements and perform operation
        else {
            double val2 = pop(&s);
            double val1 = pop(&s);
            switch (ch) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    push(&s, val1 / val2); 
                    break;
                case '^': push(&s, pow(val1, val2)); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
        }
    }

    // Final result
    return pop(&s);
}

// Driver code
int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    double result = evaluatePostfix(postfix);
    printf("Result: %.2lf\n", result);

    return 0;
}
