//including required header file
#include "headerA3.h"
#include "personalHeader.h"

/*
    sortID: sorts the pre existing linked lest in acending order
    In: tweet ** head
    Out: NONE
    Post: recieves the head of the linked list from the main, and uses a sorting algorithm to sort the linked list by user id in acending order
*/
void sortID (tweet ** head)
{  
    //if statement to check if the list is empty, and printing to user nothing to sort
    if(*head == NULL)
    {
        printf("The list is empty! Nothing to sort!\n");
        return;
    }

    //declaring required variables  
    int tempId, size, counter;
    char tempUser[51];
    char tempText[141];
    tweet *temp;

    //initalizing required variables
    temp = *head;
    size = 0;
    
    //while-loop until the end of the linked list
    while (temp != NULL)
    {
        //incrementing size counter and traversing to the next node
        size++;
        temp = temp -> next;
    }

    //for-loop for length of size
    for(int i = size; i > 0; i--)
    {
        //initalizing required variables
        temp = *head;         
        counter = 0;

        //while-loop traversing to the end of list, and checking if the next node is not empty
        while (temp->next !=NULL)
        {
            //if statement checking if current id is greater than the next id and swapping everything
            if(temp->id > temp->next->id)
            {
                tempId = temp->id;
                temp->id = temp->next->id;
                temp->next->id = tempId;

                strcpy(tempUser, temp->user);
                strcpy(temp->user, temp->next->user);
                strcpy(temp->next->user, tempUser);

                strcpy(tempText, temp->text);
                strcpy(temp->text, temp->next->text);
                strcpy(temp->next->text, tempText);
            }
            else
            {
                //incrementing counter
                counter++;
            }
            
            //traversing to the next node
            temp = temp->next;
        }
        
        //if statement to check if the array has been sorted and exiting the for-loop
        if(counter == size-1)
        {
            break;
        }
    }

    printf("List Successfully Sorted!\n");
}



