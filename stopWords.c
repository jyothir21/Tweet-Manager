//including required header file
#include "headerA3.h"
#include "personalHeader.h"

/*
    countStopWords: searchs all tweets in database and returns the number of stop words found in n number of tweets
    In: tweet * tweetList
    Out: NONE
    Post: takes in the head of the list as input and traverses through the list to find stop words and returns the count
*/
void countStopWords(tweet * tweetList)
{
    //declaring required variables and arrays
    tweet *temp;
    int tweetCounter, stopWordCounter;
    char *token;
    char tempTweet[141];
    char stopWords[25][10] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its","of","on","that","the","to","was","were","will","with"};
    
    //initializing required variables
    temp = tweetList;
    tweetCounter = 0;
    stopWordCounter = 0;

    //while-loop until the end of the list
    while(temp != NULL)
    {
        //copying the tweet into a temp variable so we do not modify the origninal tweet
        strcpy(tempTweet, temp->text);

        //tokenizing the tweet by using space delimiters
        token = strtok(tempTweet, " ");

        //while-loop until the end of the word
        while(token != NULL)
        {           
            //for-loop for the number of stop words in the array 
            for(int i = 0; i < 25; i++)
            {
                //checking to see if any of the words are stop words
                if(strcmp(token, stopWords[i]) == 0)
                {
                    //incrementing the stopword counter
                    stopWordCounter++;                    
                    continue;
                }
            }

            //getting the next word in the tweet
            token = strtok(NULL, " ");
        }

        //incrementing the tweet counter, and moving on to the next node
        tweetCounter++;
        temp = temp->next;
    }

    //printing the number of stop words found across n number of tweets
    printf("Across %d tweets, %d stop words were found.\n", tweetCounter, stopWordCounter);
}