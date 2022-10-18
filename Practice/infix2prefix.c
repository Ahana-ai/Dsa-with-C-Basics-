#include<stdio.h>
#include<string.h>

void infixToPostfix(char*);
int precedence(char);
char reverse(char*);

int precedence(char op) {
    if (op == '+' || op == '-')  return 1;
    else if (op == '*' || op == '/' || op == '%')  return 2;
    else if (op == '^')  return 3;
    else return 0;
}

char reverse(char *arr)
{
    int i = strlen(arr);
    char rev_arr[10];
    while(i != 0)
    {
        rev_arr[i] = arr[i];
        i--;
    }
   
    infixToPostfix(rev_arr);
}

void infixToPostfix(char *infix) {
    char postfix[10] = "";
    int p_index = 0;
    char stack[10];
    int s_top = -1;
    for(int i=0; i<strlen(infix); i++) {
        if(precedence(infix[i]) == 0) {
            postfix[p_index++] = infix[i];
        }
        else {
            if(s_top == -1 || precedence(stack[s_top]) < precedence(infix[i])) {
                stack[++s_top] = infix[i];
            }
            else {
                while(s_top>=0)
                    postfix[p_index++] = stack[s_top--];
                stack[++s_top] = infix[i];
            }
        }
    }
    while(s_top>=0)
        postfix[p_index++] = stack[s_top--];
    int i=strlen(postfix);
    while(postfix[i]!=0) {
        printf("%c", postfix[i--]);
    }
}

void main() {
    char expr[10] = "a+b*c";
     reverse(expr);
}