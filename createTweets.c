//including required header file
#include "headerA3.h"
#include "personalHeader.h"

/*
    createTweet: creates a new node and returns it the node created
    In: tweet * tweetList
    Out: tweet *
    Post: creates a new node with all the fields filled in by the user and returns the new node created
*/
tweet * createTweet(tweet * tweetList)
{
    //declaring all required variables
    tweet *newNode;
    tweet *temp;
    bool unique;
    bool invalidInput;
    int asciiSum;
    char temp1[1000];
    char temp2[1000];
    
    //initializing and allocating memory for required variables
    newNode = malloc(sizeof(tweet));
    invalidInput = true;
    asciiSum = 0;
    
    //while=loop to validate input from user
    while(invalidInput)
    {
        //prompting user to enter username
        printf("Enter a username: ");
        fgets(temp1, 1000, stdin);       
        temp1[strlen(temp1)-1] = '\0';         

        //prompting user to enter tweet
        printf("Enter the user's tweet: ");
        fgets(temp2, 1000, stdin);      
        temp2[strlen(temp2)-1] = '\0';          

        //if statement validating if the username and user tweet follow the conditions stated, and if all are satisfied then it will exit the loop
        if(strlen(temp1) == 0 || strlen(temp2) == 0)
        {
            printf("Please enter valid characters in the field!\n\n");
        }
        else if(strlen(temp1) > 51)
        {
            printf("Size of username exceeds maximum length! Please enter a user name less than 52 characters!\n\n");            
        }
        else if(strlen(temp2) > 141)
        {
            printf("Size of tweet exceeds maximum length! Please enter a tweet less than 142 characters!\n\n");            
        }
        else
        {
            invalidInput = false;
        }
    }
    
    //copying the users input from temp variables into the node
    strcpy(newNode->user, temp1);  
    strcpy(newNode->text, temp2);    

    //for-loop for the length of user name, and adding the ASCII value of each letter
    for(int i = 0; i < strlen(newNode->user); i++)
    {
        asciiSum += newNode->user[i];
    }   

    //adding the asciiSum with length of user tweet
    newNode->id = asciiSum + strlen(newNode->text);
    
    //setting unique variable to false, to check if the user id generated already exists, and using a while loop to generate a new value
    unique = false;
    while(unique == false)
    {        
        //assuming the generated user id is unique, and setting temp to the head
        unique = true;
        temp = tweetList;

        //while-loop until the end of the list 
        while (temp != NULL)
        {            
            //if statement checking if the user id already exists in the linked list
            if(temp->id == newNode->id)
            {
                //generating a new value and adding it onto the already generated id, and setting unique to false to recheck if that number exists in the linked list
                srand(time(NULL));
                newNode->id += ((rand() % 999) + 1);
                unique = false;
            }

            //moving onto the next node of the linked list
            temp = temp -> next;
        }
    }

    //setting newNode-Next to null
    newNode->next = NULL; 

    //printing the user id to the user
    printf("\nYour computer-generated userid is %d\n\n", newNode->id);

    //returning the newNode 
    return newNode;
}

/*
    addNodeToList: adding the newly generated node to the linked list
    In: tweet ** tweetList, tweet * node
    Out: NONE
    Post: adding the newly generated node to the linked list
*/
void addNodeToList(tweet ** tweetList, tweet * node){
    //if statement to check if the linked list is empty, or not empty
    if(*tweetList == NULL)
    {
        //setting the head to the new node generated
        *tweetList = node;         
    }
    else if(tweetList!=NULL)
    {
        //creating a temp and storing the head value
        tweet * temp = *tweetList;
        
        //while loop to go to the end of the linked list
        while(temp->next != NULL)
        {
            //traversing through the list
            temp = temp -> next;
        }

        //adding the new node to the end of the list
        temp->next = node;
    }        
}


