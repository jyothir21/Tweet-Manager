*************************************README******************************************

==================================
Name: Jyothir Krishnan
Username: jkrishna
Student Number: 1177917

Course Code: CIS*2500
Assignment Name: Tweet Manager
Date of Last Revision: 04/02/2022
==================================

_____________________________________________________________________________________
Introduction:
    - This program is a menu-driven program which mimics the real life twitter 
      platform using the basic concepts of linked lists. The user will be able to 
      perform basic operations on tweets such as ceate tweets, display tweets, search 
      tweets based on a keyword or mention, save and load tweets from a local file, 
      calculate the number of stop words are present across all of the tweets, and 
      sort the tweets based on user id.
_____________________________________________________________________________________
Compiling Program:
    - get the provided makefile into the folder containing all the sourcefiles
    - type in 'make' into the command line, to create the exectuable
    - type './a3' into the command line, to run the program

    NOTE: Please have personalHeader.h in the folder while compiling to avoid errors
_____________________________________________________________________________________
Files Required:
    - These files are required in order to run this program:
        1. mainA3.c 
        2. createTweets.c 
        3. displayTweets.c 
        4. searchTweets.c 
        5. stopWords.c 
        6. deleteNthTweet.c 
        7. saveTweetsToFile.c 
        8. loadTweetsFromFile.c 
        9. sortID.c 
        10. headerA3.h 
        11. personalHeader.h 
        12. makefile
_____________________________________________________________________________________
Functionality:
    mainA3.c
    - main file which calls all functions to create the foundation of the function

    createTweets.c
    - function which creates a new node with username, userid, and tweet which gets 
      returned by the function

    displayTweets.c
    - function displays the entire linked list to the command line

    searchTweetsByKeyword.c
    - function that prompts user for a keyword to search within the tweets of the 
      linked list and returns the search results

    countStopWords.c
    - function which counts the number of stop words found across all the tweets in 
      the linked list, the stop words are chosen from the specifications of the 
      assignment

    deleteTweet.c 
    - fuction that deletes tweets for the users discretion 

    saveTweetsToFile.c 
    - function that save the current linked list into a file of the users choice

    loadTweetsFromFile.c 
    - function that loads data from a file of the users choice

    sortID.c 
    - function that sorts the tweets based on the user id

    --HELPER FUNCTION--
        addNodeToList()
        - adds a newly created node to linked list
        - NOTE: this function can be found in createTweets.c    
_____________________________________________________________________________________
Limitations:
    - This pogram in incapable of performing saveToFile and then readFromFile
      consecutivly as they follow different formats, but this was created as a part 
      of the assignment requirements
    - Sorting algorithm only works in acending order and only with user id
_____________________________________________________________________________________
                                **Version 1.0.0**

