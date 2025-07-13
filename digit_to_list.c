#include "header.h"

//Converts a numeric string into a doubly linked list (one digit per node)
int digit_to_list(Dlist **head, Dlist **tail, char *s, int len)
{
    int i;
   for(i=0;i<len;i++)
   {
     //Validate character is a digit
     if(!(s[i]>='0' && s[i]<='9'))
     return FAILURE;
    //Allocate a new node for the digit
    Dlist *new=malloc(sizeof(Dlist));
    if(!new)
    return FAILURE;//Memory allocation failed

        new->data=s[i]-'0';//Convert character to integer
        new->next = NULL;
        new->prev = *tail;
        //Append node to the end of the list
        if (*tail)
            (*tail)->next = new;
        else
            *head = new;//First node (head)

        *tail = new;//Update tail to new node
    }
    return SUCCESS;
}