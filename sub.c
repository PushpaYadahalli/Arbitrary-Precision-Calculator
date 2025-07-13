#include "header.h"
int sub(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3, char **argv)
{
    int sign=0;//To track if the result is negative
    int length1=strlen(argv[1]);
    int length2=strlen(argv[3]);
    if(length1>length2)
    {
        digit_to_list(head1,tail1,argv[1],length1);
        digit_to_list(head2,tail2,argv[3],length2);
    }
    else if(length1<length2)
    {
        digit_to_list(head1,tail1,argv[3],length2);
        digit_to_list(head2,tail2,argv[1],length1);
        sign=1; //the result is negative
    }
    else
    {
        int res=strcmp(argv[1],argv[3]);
        if(res==0)
        {
            //If both numbers are equal
            printf("the Result is 0\n");
            return SUCCESS;
        }
        else if(res>0)
        {
            digit_to_list(head1,tail1,argv[1],length1);
            digit_to_list(head2,tail2,argv[3],length2);            
        }
        else
        {
            digit_to_list(head1,tail1,argv[3],length2);
            digit_to_list(head2,tail2,argv[1],length1);
            sign=1;
        }
    }
    Dlist *temp1=*tail1;
    Dlist *temp2=*tail2;

    int borrow=0,diff=0;
  while(temp1!=NULL||temp2!=NULL||borrow!=0)
  {
    int num1 = temp1 ? temp1->data : 0;
    int num2 = temp2 ? temp2->data : 0;
    
    if(borrow)
    {
        num1--;
        borrow=0;
    }

    if(num1<num2)
    {
        num1=num1+10;
        borrow=1;
    }
    diff=num1-num2;
    // Insert the result digit at the beginning of result list
    Dlist *new=malloc(sizeof(Dlist));
    if(!new)
    return FAILURE;
    new->data=diff;
    new->prev=NULL;
    new->next=*head3;

    if(*head3)
    (*head3)->prev=new;
    else
    *tail3=new;

   *head3=new;

   if(temp1)
   temp1=temp1->prev;
   if(temp2)
   temp2=temp2->prev;   
  }
  //leading zeros from result
 Dlist *temp3=*head3;
 while(temp3&&temp3->data==0)
 {
    Dlist *toDelete=temp3;
    temp3=temp3->next;
    free(toDelete);
 }
 *head3=temp3;
    if(temp3) 
    temp3->prev=NULL;
    else 
    {
        //Result is completely zero
        *tail3=NULL;
        printf("The Result is: 0\n");
        return SUCCESS;
    }
    //Print the result
    printf("The Result is: ");
    if(sign) 
    printf("-");
    while(temp3) {
        printf("%d", temp3->data);
        temp3=temp3->next;
    }
    printf("\n");

    return SUCCESS;
}