//including required header file
#include "headerA3.h"
#include "personalHeader.h"

/*
    searchTweetsByKeyword: takes in a keyword input from the user and searchs the entire linked list to see if the keyword is found in any tweets
    In: tweet * tweetList
    Out: int
    Post: takes in the head of the list as input and traverses through the list to find the user keyword
*/
int searchTweetsByKeyword(tweet * tweetList)
{
    //declaring all required variables
    tweet *temp;
    bool oneMatch;
    int counter, returnVal;    
    char *token;
    char tempTweet[141];
    char keyWord[141];
    
    //initializing required variables
    temp = tweetList;
    returnVal = 0;

    //checking to see if the list is empty and returning 0, to indicated search is false
    if(tweetList == NULL)
    {
        return returnVal;
    }

    //prompting user to enter key word to search and storing it into keyWord
    printf("Enter a keyword to search: ");
    fgets(keyWord, 151, stdin);
    keyWord[strlen(keyWord)-1] = '\0';

    //while-loop till the end of the linked list
    while(temp != NULL)
    {
        //copying the tweet into a temp variable to ensure the original tweet does not get modified
        strcpy(tempTweet, temp->text);

        //tokenizing the tweet with space delimiters
        token = strtok(tempTweet, " ");
        
        //initialzing required variables
        counter = 0;
        oneMatch = false;

        //while-loop until the end of token
        while(token != NULL)
        {
            //for-loop for length of token
            for(int i = 0; i < strlen(token); i++)
            {
                //if-else statement to check if each character of the keyWord match each character in the tweet
                if(tolower(keyWord[counter]) == tolower(token[i]))
                {
                    //incrementing counter variable
                    counter++;

                    //if statement to check if counter is length of the keyWord to indicate its a match
                    if(counter == strlen(keyWord))
                    {
                        //printing that match is found, and setting required variables to exit the while loop
                        printf("Match found for ‘%s’: %s wrote: %s\n", keyWord, temp->user, temp->text);
                        oneMatch = true;  
                        returnVal = 1;                      
                        break;
                    }
                }
                else
                {
                    //resetting counter to 0 if the keyWord is not found
                    counter = 0;
                }
            }            

            //ensuring the while loop breaks after finding one match of the keyword in the tweet
            if(oneMatch)
            {
                break;
            }
            
            //getting the next word in the tweet
            token = strtok(NULL, " "); 
        }

        //traversing to the next node
        temp = temp->next;
    }
    
    //returning returnVal which either stored 0 (match not found) or 1 (match found)
    return returnVal;
}