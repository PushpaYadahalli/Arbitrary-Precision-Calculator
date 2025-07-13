#include "header.h"
int sub_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3, char **argv)
{
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
     //Insert the result digit at the beginning of result list
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
    *tail3=NULL;

 return SUCCESS;
}
//Copies the content of head3/tail3 into head1/tail1 
void copy_list(Dlist **head1,Dlist **tail1,Dlist **head3,Dlist **tail3)
{
   //free the current head1 list
   clear_list(head1,tail1);
   
   Dlist *temp=*head3;
   while(temp!=NULL)
   {
     Dlist *new=malloc(sizeof(Dlist));

     new->data=temp->data;
     new->prev=*tail1;
     new->next=NULL;

     if(*tail1)
     (*tail1)->next=new;
     else
     *head1=new;

     *tail1=new;
     temp=temp->next;
   }
}
//Frees the entire linked list starting from head1
void clear_list(Dlist **head1,Dlist **tail1)
{
    Dlist *temp;
    while(*head1!=NULL)
    {
        temp=*head1;
        *head1=(*head1)->next;
        free(temp);
    }
    *tail1=NULL;
}