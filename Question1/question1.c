#include <stdio.h>
#include <stdlib.h>

typedef enum {
    ADD,
    SUB,
    MUL,
    DIV,
    FIBO_VAL
} Operation;

typedef struct Node {
    Operation op;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* makeFunc(Operation op, int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->op = op;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int calculate(Node *node, int fibo[]) {
    if (node->op == ADD) {
        return calculate(node->left, fibo) + calculate(node->right, fibo);
    } else if (node->op == SUB) {
        return calculate(node->left, fibo) - calculate(node->right, fibo);
    } else if (node->op == MUL) {
        return calculate(node->left, fibo) * calculate(node->right, fibo);
    } else if (node->op == DIV) {
        int right_value = calculate(node->right, fibo);
        if (right_value == 0) {
            printf("Error: Division by zero!\n");
            exit(1);
        }
        return calculate(node->left, fibo) / right_value;
    } else if (node->op == FIBO_VAL) {
        return fibo[node->value];
    } else {
        printf("Unknown operation\n");
        exit(1);
    }
}

void calc(Node *node, int fibo[]) {
    if (node->op != FIBO_VAL) {
        switch (node->op) {
            case ADD:
                printf("add : %d\n", calculate(node, fibo));
                break;
            case SUB:
                printf("sub : %d\n", calculate(node, fibo));
                break;
            case MUL:
                printf("mul : %d\n", calculate(node, fibo));
                break;
            case DIV:
                printf("div : %d\n", calculate(node, fibo));
                break;
            default:
                printf("Unknown operation\n");
                break;
        }
    }
}

void generateFibonacci(int n, int fibo[]) {
    fibo[0] = 0;
    fibo[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}

int main() {
    int n = 10;
    int fibo[n + 3];  // Adjusted size
    
    generateFibonacci(n + 2, fibo);  // Generate up to n + 2 Fibonacci numbers
    
    Node *add = makeFunc(ADD, 0);
    add->left = makeFunc(SUB, 0);
    add->left->left = makeFunc(MUL, 0);
    add->left->left->left = makeFunc(ADD, 0);
    add->left->left->left->left = makeFunc(DIV, 0);
    add->left->left->left->left->left = makeFunc(FIBO_VAL, 9);
    add->left->left->left->left->right = makeFunc(FIBO_VAL, 6);
    
    Node *mul = makeFunc(MUL, 0);
    mul->left = makeFunc(FIBO_VAL, 5);  // Use Fibonacci value
    mul->right = makeFunc(FIBO_VAL, 4); // Use Fibonacci value
    
    Node *sub = makeFunc(SUB, 0);
    sub->left = mul;
    sub->right = add;
    
    Node *fiboNode = makeFunc(SUB, 0);
    fiboNode->left = sub;
    fiboNode->right = NULL;
    
    calc(fiboNode, fibo);
    
    return 0;
}
