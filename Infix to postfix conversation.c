//AIM:- To perform Infix to Postfix conversion in DSA using C programming

#include<stdio.h>
#include<stdlib.h>

int TOP=-1,MAX;
char *STACK;
void PUSH(char item)
{
     if(TOP==MAX-1)
     {
          printf("Stack Overflow");
     }
     else
     {
          TOP=TOP+1;
          STACK[TOP]=item;
     }
}

char POP()
{
    if(TOP==-1)
    {
         printf("Stack Underflow/Empty\n:");
         return '\0';
    }
    else
    {
         char item=STACK[TOP];
         TOP=TOP-1;
         return item;
    }
}

char PEEK()
{
    if(TOP==-1)
    {
        //printf("Stack Underflow/Empty\n:);
        return '\0';
    }
    else
    {
        return STACK[TOP];
    }
}

int GetPrecedence(char op)
{
      switch(op)
      {
         case '+':
         case '-':
             return 1;   //Lowest Precedence
         case '*':
         case '/':
             return 2;
         case '^':
            return 3;    //Highest Precedence
        default:
            return 0;    //Consider it as an operand
      }
}

int main()
{
     printf("Enter the size of the infix expression:");
     scanf("%d",&MAX);

     STACK = (char*)malloc(MAX*sizeof(char));
     char infix[MAX];
     char postfix[MAX];
     printf("Enter the infix string of size %d:",MAX);
     scanf("%s",infix);

     int TokenPrecedence,j=0,i=0;
     char c,temp;

      //Reading one token at a time

      while((c=infix[i])!='\0')
      //for(int i=0;i<MAX;i++)
   {
          //c=infix[i]
          TokenPrecedence = GetPrecedence(c);  //Current token at a time

          if(TokenPrecedence>0)   //Current token is operator
          {
               while(TokenPrecedence<=GetPrecedence(PEEK()))   //Current Token<=StackTop Token
               {
                     postfix[j++]=POP();
               }
               PUSH(c);
          }
          else  //Current token is operand '(' or ')'
          {
               switch(c)
                {
                    case '(':
                         PUSH(c);
                         break;
                    case ')':
                         while (PEEK()!="("])
                         { 
                             postfix[j++]=POP();
                         }
                        POP();
                        break;
                    default:
                        postfix[j++]=c;
                        break;   
               }
          }
          i++;
   }

   //Pop all remaining tokens from stack
   while (PEEK()!='\0')
   {
        char c = POP();
        postfix[j++]=c;
   }
   postfix[j]='\0';
   printf("Postfix notation is: %s",postfix);
   return 0;
}