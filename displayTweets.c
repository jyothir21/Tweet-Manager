//including required header file
#include "headerA3.h"
#include "personalHeader.h"

/*
    displayTweets: displays the entire linked list to the user
    In: tweet * tweetList
    Out: NONE
    Post: displays each individual node one by one for the entire linked list to the user
*/
void displayTweets(tweet * tweetList)
{    
    //if statement to check if the list is empty
    if(tweetList == NULL)
    {
        printf("The list is empty! Nothing to display!\n");
        return;
    }

    //declaring and initializing a temp to the head
    tweet *temp;
    temp = tweetList;

    printf("\n\n********************************************* \n");
    
    //while-loop until the end of the linked list
    while (temp != NULL)
    {
        //printing the list to the user, and traversing through the list
        printf("ID %d: Created by %s: %s\n", temp->id, temp->user, temp->text);
        temp = temp -> next;
    }

    printf("********************************************* \n");
}
