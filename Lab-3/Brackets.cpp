#include <iostream>
#include <string.h>

using namespace std;


struct Stack
{
    char top;
    char cap;
    char* array;
};


struct Stack* createStack(char cap)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

    if (!stack) return NULL;

    stack->top = -1;
    stack->cap = cap;
    stack->array = (char*) malloc(stack->cap * sizeof(char));

    if (!stack->array) return NULL;

    return stack;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}

char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}

int pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return 0;
}

void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}

void evaluateBrackets(char* exp)
{
    struct Stack* stack = createStack(strlen(exp));
    
    if (!stack) return ;

    for (int i = 0; exp[i]; ++i)
    {

        if(exp[i]!='('||exp[i]!='{'||exp[i]!='['||exp[i]!='<'||exp[i]!='|'||exp[i]!='}'||exp[i]==')'||exp[i]=='>'||exp[i]==']')
        {
            cout<<"NO\n";
            return;
        }

        if (exp[i]=='('||exp[i]=='{'||exp[i]=='['||exp[i]=='<')
            {
                push(stack, exp[i]);
            }

        else if (exp[i]=='|')
            { 
                char chad = peek(stack);
                if (chad=='|')
                    pop(stack);
                else 
                    push(stack, exp[i]);    
            }

        else 
        {
            char val = peek(stack);
            
            if (exp[i] == ')' && val=='(')
            {
                pop(stack);               
            }
            else if (exp[i] == '}' && val=='{')
            {
                pop(stack);               
            }
            else if (exp[i] == ']' && val=='[')
            {
                pop(stack);               
            }
            else if (exp[i] == '>' && val=='<')
            {
                pop(stack);               
            }
            else 
            {
                cout<<"NO\n";
                return ;
            }
        }
    }
    cout<<"YES\n";
    return ;
}

int main()
{
    int a;
    cin>>a;

    
    for (int i=0; i<a; i++)
    {
        char brac[10000];
        char ch;
        cin>>brac;               
        evaluateBrackets(brac);
    }   
    return 0;
}