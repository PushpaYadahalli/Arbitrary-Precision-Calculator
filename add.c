#include "header.h"

int add(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3, char **argv)
{
    int length1=strlen(argv[1]);
    int length2=strlen(argv[3]);

    //Convert input strings to digit lists
    if(digit_to_list(head1,tail1,argv[1],length1)==FAILURE || digit_to_list(head2,tail2,argv[3],length2)==FAILURE)
    return FAILURE;
    //Pointers to traverse the lists from least significant digit
    Dlist *temp1=*tail1;
    Dlist *temp2=*tail2;

    int sum=0;
    int carry=0;

    while(temp1!=NULL || temp2!=NULL || carry!=0)
    {
        int num1 = temp1 ? temp1->data : 0;
        int num2 = temp2 ? temp2->data : 0;

        //Calculate sum and carry
        sum=num1+num2+carry;
        //Carry for the next iteration
        carry=sum/10;
        //Digit to store in the current node
        sum=sum%10;
        //add first
        Dlist *new=malloc(sizeof(Dlist));
        if(!new)
        return FAILURE;

        new->data=sum;
        new->prev=NULL;
        new->next=*head3;

        if(*head3)
        (*head3)->prev=new;
        else
        *tail3=new;

        *head3=new;
    
       //Move temp pointers backward
       if(temp1)
       temp1=temp1->prev;
       if(temp2)
       temp2=temp2->prev;       
    }
       //print result
       Dlist *temp3=*head3;
       printf("The result is: ");
      while(temp3!=NULL)
      {
        printf("%d ",temp3->data);
        temp3=temp3->next;
      }
      printf("\n");
      return SUCCESS;  
}