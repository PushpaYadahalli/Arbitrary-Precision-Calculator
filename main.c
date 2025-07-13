#include "header.h"

int main(int argc,char *argv[])
{
   //initialize header and tail to null
   Dlist *head1=NULL;
   Dlist *tail1=NULL;

   Dlist *head2=NULL;
   Dlist *tail2=NULL;

   Dlist *head3=NULL;
   Dlist *tail3=NULL;

   if(argc!=4)
   {
    printf("Invalide arguments\n");
    printf("Usage:./a.out operand1 operator operand2\n");
    return FAILURE;
   }

   switch(argv[2][0])
   {
    case '+':
            if(add(&head1, &tail1, &head2, &tail2, &head3, &tail3, argv)==SUCCESS)
            {
              printf("Successfully performed addition\n");
            }
            else
            {
              printf("Failed to performed addition\n");
            }
            break;
    case '-':
            if(sub(&head1, &tail1, &head2, &tail2, &head3, &tail3, argv)==SUCCESS)
            {
              printf("Successfully performed Substraction\n");
            }
            else
            {
              printf("Failed to performed Substraction\n");
            }
            break;
    case 'x':
            if(mul(&head1, &tail1, &head2, &tail2, &head3, &tail3, argv)==SUCCESS)
            {
              printf("Successfully performed Multiplication\n");
            }
            else
            {
              printf("Failed to performed Multiplication\n");
            }
            break;
    case '/':
            if(division(&head1, &tail1, &head2, &tail2, &head3, &tail3, argv)==SUCCESS)
            {
              printf("Successfully performed Division\n");
            }
            else
            {
              printf("Failed to performed Division\n");
            }
            break;
    default:
           printf("Invalide operator\n");
           break;
   }
return 0;
}