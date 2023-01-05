//including required header file
#include "headerA3.h"
#include "personalHeader.h"

/*
    deleteTweet: prompts user to delete a tweet 
    In: tweet ** tweetList
    Out: NONE
    Post: takes in the head of the list as input and traverses through the list to find stop words and returns the count
*/
void deleteTweet(tweet ** tweetList)
{
    //if statement checking to see if the list is empty
    if(*tweetList == NULL)
    {
        printf("The list is empty! There are no tweets to delete!\n");
        return;
    }

    //declaring required variables
    tweet * temp;
    tweet * before;
    tweet * after;
    int numTweets, delete, traverse;
    bool invalidInput, tweetDeleted;

    //initializing required variables
    numTweets = 0;
    traverse = 0;
    invalidInput = true;
    temp = *tweetList;

    //while-loop until end of list and incrementing counter for number of tweets
    while (temp != NULL)
    {
        numTweets++;
        temp = temp -> next;
    }

    //printing the number of tweets to the user
    printf("Currently there are %d tweets.\n", numTweets);

    //while-loop to validate input of which tweet the user wants to delete
    while(invalidInput)
    {
        //prompting user to enter the tweet they wish to delete
        printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", numTweets);
        scanf("%d", &delete);

        //if-else statement to check if the tweet number entered is valid, and if not prompting user to enter again
        if(delete < 1 || delete > numTweets)
        {
            printf("Invalid tweet number! Please try again!\n\n");
        }
        else
        {
            invalidInput = false;
        }
    }

    //setting temp to head of the list, and while-loop until the end of the list
    temp = *tweetList;
    while (temp != NULL)
    {
        //assuming the tweet has not yet been deleted, and maintaing the next node in after
        tweetDeleted = false;
        after = temp->next;

        //if statement to check if this is the tweet the user wanted to delete
        if(delete-1 == traverse)
        {
            //if-else statement to check whether the tweet they want to delete is the head or not
            if(temp == *tweetList)
            {
                //decrementing the number of tweets and printting to the user
                numTweets--;
                printf("Tweet %d deleted. There are now %d tweets left.\n\n", temp->id, numTweets);

                //setting the new head to the next node, and freeing the previous node, and setting tweetDeleted to true
                *tweetList = (*tweetList)->next;
                free(temp);
                tweetDeleted = true;  
            }
            else
            {
                //decrementing the number of tweets and printting to the user
                numTweets--;
                printf("Tweet %d deleted. There are now %d tweets left.\n\n", temp->id, numTweets);

                //linking the previous node to the after node and freeing the current node, and setting tweetDeleted to true
                before->next = after;
                free(temp);
                tweetDeleted = true;                  
            }
        }
        
        //incrementing traversem and setting before node to temp
        traverse++;
        before = temp;

        //checking to see if the tweet was deleted or not, and travesing to the next node correspondingly
        if(tweetDeleted == false)
        {
            temp = temp -> next;
        }
        else
        {
            temp = after;  
        }
    }        
}