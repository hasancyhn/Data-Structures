// 20010011091 - Hasan CEYHAN
#include<stdio.h>
#include<string.h>
char stack[100];
int top;

int priority(char a)
{
    if (a=='(')
        return -1;
    else if (a==')')
        return 0;
    else if (a=='+' || a=='-')
        return 1;
    else if (a=='*' || a=='/')
        return 2;
    else if (a=='^')
        return 3;
    else
        return 4;
}

int main()
{
    char a[100];
    printf("Enter the infix expression: \n");
    scanf("%s",a);
    char postfix[strlen(a)];
    top=-1;
    int r=0;
    int i,n=strlen(a);
    for (i=0;i<n;i++)
    {
        if (a[i]=='(')
        {
            push(a[i]);
        }
        else if (a[i]==')')
        {
            while (stack[top]!='(')
            {

                postfix[r]=stack[top];
                r++;
                pop();
            }
        }
        else
        {
            if (priority(a[i])==4)
                {
                    postfix[r]=a[i];
                    r++;
                }
            else
                {
                    if (priority(a[i])>priority(stack[top]) || (a[i]=='^' && stack[top]=='^'))
                    {
                        push(a[i]);
                    }
                    else
                    {
                        while(priority(a[i])<=priority(stack[top]))
                        {
                            postfix[r]=stack[top];
                            r++;
                            pop();
                        }
                        push(a[i]);

                    }
                }
        }

    }
    while(top!=-1)
        {
            if (stack[top]!='(' && stack[top]!=')')
            {
                postfix[r]=stack[top];
                r++;
            }

            pop();
        }
    printf("The postfix expression is: \n");
    for (i=0;i<r;i++)
    {
        printf("%c",postfix[i]);
    }
}



void push(char c)
{
    top++;
    stack[top]=c;
}
void pop()
{
    top--;
}
