//including required header file
#include "headerA3.h"
#include "personalHeader.h"

int main(int argc, char *argv[])
{
    //declaring required variables
    bool loop;
    int menuOption, searchSuccess;
    tweet *tweetList;
    tweet *temp;

    //initializing required variables
    tweetList = NULL;
    menuOption = 0;
    loop = true;    

    //while loop to run program until the user wants to exit the program
    while(loop)
    {
        //printing the menu option for the user everytime
        printf("\nEnter one of the following menu options:\n");
        printf("\t1. Create a new tweet\n");
        printf("\t2. Display tweets\n");
        printf("\t3. Search a tweet (by keyword)\n");
        printf("\t4. Find how many words are “stop words” (stop words are explained in a later section)\n");
        printf("\t5. Delete the nth tweet\n");
        printf("\t6. Save tweets to a file\n");
        printf("\t7. Load tweets from a file\n");
        printf("\t8. Sort the given linked list on userid.\n");
        printf("\t9. Exit\n\n");

        //prompting the user for user input on which menu option they want to run, and storing it in menu option
        printf("Choose a menu option: ");
        scanf("%d", &menuOption);
        getchar();
        
        //switch-case statement for the selected user menuOption
        switch(menuOption)
        {
            // Function #1
            case 1:  
                //calling addNodeToList function
                addNodeToList(&tweetList, createTweet(tweetList));
                break;
            
            // Function #2
            case 2:
                //calling displayTweets function
                displayTweets(tweetList);
                break;

            // Function #3
            case 3:
                //calling searchTweetsByKeyword function
                searchSuccess = searchTweetsByKeyword(tweetList);
                
                //if-else statement to print error messages to user
                if(tweetList == NULL)
                {
                    printf("Our database is empty, nothing to search!\n\n");
                }
                else if(searchSuccess == 0)
                {
                    printf("Keyword was not found in any tweet in our database!\n\n");
                }

                break;
            
            // Function #4
            case 4:
                //calling countStopWords function
                countStopWords(tweetList);
                break;

            // Function #5
            case 5:
                //calling deleteTweet function
                deleteTweet(&tweetList);
                break;

            // Function #6
            case 6:
                //calling saveTweetsToFile function
                saveTweetsToFile(tweetList);
                break;

            // Function #7
            case 7:
                //calling loadTweetsFromFile function
                loadTweetsFromFile(&tweetList);
                break;

            // Function #8
            case 8:
                //calling sortID function
                sortID(&tweetList);
                break;

            // Exit program
            case 9:
                //setting loop to false
                loop = false;
                break;
            
            // Default print statement for if the user enters an invalid input
            default:
                printf("Invalid menu option! Please enter options from 1-9!\n");
        }
    }

    //while-loop to free the linked list
    while (tweetList != NULL )
    {
        temp = tweetList;
        tweetList = temp->next;
        free (temp);
    }

    //return 0 for main
    return 0;
}