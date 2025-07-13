
   #include "header.h"

int mul(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3, char **argv)
{
    int len1=strlen(argv[1]);
    int len2=strlen(argv[3]);

    //Convert input strings to digit lists
    if(digit_to_list(head1,tail1,argv[1],len1)==FAILURE || digit_to_list(head2,tail2,argv[3],len2))
    return FAILURE;

    int *result=calloc(len1+len2,sizeof(int));
    if(!result)
    return FAILURE;

    Dlist *temp1=*tail1;
    int i=0;
    while(temp1)
    {
        Dlist *temp2=*tail2;
        int j=0,carry=0;

        while(temp2)
        {
           //Multiply digits, add existing result and carry
           int prod=temp1->data * temp2->data + result[i+j] + carry;
           result[i+j]=prod%10; //Store single digit
           carry=prod/10;       //Store carry
           temp2=temp2->prev;
           j++;
        }
        //Add remaining carry if any
        if(carry)
         result[i+j]=result[i+j] + carry;

         temp1=temp1->prev;
         i++;
    }

    //remove zero
    int size=len1+len2;
    while(size>1 && result[size-1]==0)
    size--;

    //array to link list add at end
    for(int k=size-1;k>=0;k--)
    {
       Dlist *new=malloc(sizeof(Dlist));
       if(!new)
       return FAILURE;

       new->data=result[k];
       new->prev=*tail3;
       new->next=NULL;

       if(*tail3)
       (*tail3)->next=new;
       else
       *head3=new;

    *tail3=new;
    }
    free(result);
    //Print the final result
    printf("The Result is: ");
    Dlist *temp=*head3;
    while(temp)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}