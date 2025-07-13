#include "header.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3, char **argv)
{
    int len1=strlen(argv[1]);
    int len2=strlen(argv[3]);

    if(digit_to_list(head1,tail1,argv[1],len1)==FAILURE || digit_to_list(head2,tail2,argv[3],len2)==FAILURE)
    return FAILURE;

    //check divisible by zero
    Dlist *temp=*head2;
    int zero=1;
    while(temp)
    {
      if(temp->data!=0)
      {
        zero=0;
        break;
      }
      temp=temp->next;
    }
    if(zero)
    {
      printf("Error:divided by zero\n");
      return FAILURE;
    }
    
    //Dividend greater the divisior result is zero
    if(compare_list(head1,tail1,head2,tail2)==SUCCESS)
    {
      printf("The Result is: 0\n");
      return SUCCESS;
    }

    int count=1;
    //Continue until head1 becomes less than head2
    while(compare_list(head1,tail1,head2,tail2)!=SUCCESS)
    {
      //Perform subtraction
      if(sub_list(head1,tail1,head2,tail2,head3,tail3,argv)!=SUCCESS)
      return FAILURE;

      //update head1 with head3 result
      copy_list(head1,tail1,head3,tail3);

      //clear head3 for next substraction
      clear_list(head3,tail3);

      count++;
    }
    printf("The Result is %d\n",count);//This is the quotient
    return SUCCESS;

}
int compare_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2)
{
   Dlist *temp1=*head1;
   Dlist *temp2=*head2;
   
   int len1=0,len2=0;
   //calculate length of the 1st list (head1)
   while(temp1)
   {
     len1++;
     temp1=temp1->next;
   }
   //calculate length of the 2st list (head2)
   while(temp2)
   {
     len2++;
     temp2=temp2->next;
   }

   //length of 1st list smaller than 2nd list (head1<head2)
   if(len1<len2)
   return SUCCESS;
   //length of 1st list greater than 2nd list (head1>head2)
   else if(len1>len2)
   return FAILURE;

   temp1=*head1;
   temp2=*head2;
   //lengths are equal compare digit by digit
   while(temp1 && temp2)
   {
    //1st digit small 
     if(temp1->data < temp2->data)
     return SUCCESS;
     //1st digit greater
     else if(temp1->data > temp2->data)
     return FAILURE;

     //if 1st digit equal then check next digit
     temp1=temp1->next;
     temp2=temp2->next;
   }
   //both numbers are equal 
   return SUCCESS;
}