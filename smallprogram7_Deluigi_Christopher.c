//Christopher Deluigi
//Dr. Steinberg
//COP3223C Section 1
//Small Program 7
#include<string.h>
#include<stdio.h>

void deblank(char input [], char output[]); //creates user defined functions, with input arguments
void pluralize(char noun[]); //creates user defined functions, with input arguments
void fact(char string[]); //creates user defined functions, with input arguments
char* substring( char word1[], char word2[]); //creates user defined functions, with input arguments

int main()
{
    ///////////////////////////////////
    // Problem 1
    char input[20]; //declares variable in main and pases it
    char output[20];

    printf("Enter a string: "); //sets up print statement and saves user input to input
    fgets (input,sizeof (input), stdin); //reads user input until new line is formed
    deblank(input,output); //calls function and removes any additional spacing 
    printf("Output String with no blanks: %s", output); //prints users input with out spaces and the variable output
    ///////////////////////////////////
    // problem 2
    char noun[20];//declares variable in main and pases it
    printf("Enter string to be pluralize: "); //sets up print statement and saves user input to noun

    fgets(noun,sizeof(noun),stdin);  //reads user input from input until new line is formed
    pluralize(noun); //calls function, displaying the correct pluralized word
    printf("Word pluralize: %s\n",noun); //prints users input pluralized
    ///////////////////////////////////
    // problem 3
    char string[20]; //declares variable in main and pases it
    printf("Enter a string with no spaces: "); //sets up print statement and saves user input to string
    scanf("%s",string);

    fact(string); //calls function with variable string
    ///////////////////////////////////
    // Problem 4
    char word1[20]; //declares variable in main and passes it
    char word2[20];
    char* save_word; // declare pointer variable

    printf("Enter the string: "); //asks the user for input, saved it to string word1
    scanf("%s",word1);

    printf("Enter the substring you would like to look for: "); //asks the user for input, saved it to string word2
    scanf("%s",word2); 

    save_word = substring(word1,word2);//appends the string from destination to source 

    if (*save_word != '\0')
        printf("Substring %s exists!\n",word2); //if pointer isnt equal to null then print statement runs,
    else
        printf("Substring %s doesn't exist!\n",word2); //if it is, substring wont exist

    return 0;
    ///////////////////////////////////
}

void deblank(char input [], char output[])
{
    int count = 0; //declares variable for counting the characters in the input, allowing to then print without the space
    strcpy(output,input); // copies and returns the input and saves it to the output

    for( int c = 0; output[c] != '\0'; c++) //loops runs until entire string output is read, until null
    {
        if (output[c] != ' ')  // checks to see if output has a whitespace, then the amount of spaces it counts is for output[count]. then it will then save the value of where output is in the loop to (output[c])                       
        {                      // and if is a whitespace than it will continue, meaning all the letters after it will move to the left of the text
            output[count] = output[c];
            count++;
        }
    }
    output[count] = '\0'; // sets null to be the last value to be sure only the text with white space os effected


}

void pluralize(char noun[])
{
    int letter_count = strlen(noun); // this is the letter_count of  the string word that was inputed by the user

    if(noun[letter_count - 2] == 'y')  // checks to see if the last letter of the word is y, if it is it will then replace y with i
    {                                  //and then it will add es and add null to the very end of the string to make sure it ends there
        noun[letter_count - 2] = 'i';
        noun[letter_count - 1] = 'e';
        noun[letter_count] = 's';
        noun[letter_count + 1] = '\0';
    }

    else if(noun[letter_count - 2] == 's') // checks to see if the last letter of the word is s, if it is it will then add es to the end of it 
    {                                       //and add null to the very end of the string to make sure it ends there
        noun[letter_count - 1] = 'e';
        noun[letter_count] = 's';
        noun[letter_count + 1] = '\0';
    }

    else if((noun[letter_count -2] == 'h' && noun[letter_count -3] == 'c') ||(noun[letter_count - 2] == 'h' && noun[letter_count -3] == 's'))
    {                  // checks the second to last letter to see if it is s or c
                        //and then it will add es and add null to the very end of the string to make sure it ends there
        noun[letter_count - 1] = 'e';
        noun[letter_count] = 's';
        noun[letter_count + 1] = '\0';
    }

    else     // if nothing matches the criteria then it will auto add s to the end of the word and add null to the very end of the string to make sure it ends there
    {
        noun[letter_count-1] = 's';
        noun[letter_count] = '\0';
    }

}
void fact(char string[])
{
    int letters = 0; //declares variable for each type of character, digits, letters and punctuation
    int digits = 0;
    int punctuation = 0;

    for(int x = 0; string[x] != '\0'; x++) //loop runs to check the whole string
    {
        if((string[x] >= 'A' && string[x] <= 'Z') || (string[x] >= 'a' && string[x] <= 'z') ) //checks to see if the input has any letters, and if it does its adds one to letters, begining at zero
            ++letters;
        else if((string[x] >= '0' && string[x] <= '9')) //checks to see if the input has any numbers, and if it does its adds one to digits, begining at zero
            ++digits;
        else if((string[x] >= '!' && string[x] <= '/') || (string[x] >= ':' && string[x] <= '@') || (string[x] >= '[' && string[x] <= '`')) //checks to see if the input has any punctuation above , and if it does its adds one count per punctuation to punctuations, begining at zero
            ++punctuation ;
    }


    printf("%s has",string); //prints the amount of letters, digits, and punctuation characters the input had
    printf("\n%d letters\n",letters);
    printf("%d digits\n",digits);
    printf("%d punctuation characters\n",punctuation );

}

char* substring(char word1[], char word2[])
{
    int hold;
    int save;
    int first_lette ; //declares variable for counting the characters in different portions of the word

    for(int x = 0; word1[x] !='\0'; ++x) //loop runs though the whole string word 1 array and will check to null
    {
        if(save == 1) // checks to see if save == 1 then there is a substring and first_lette will still hold 
        {             //the first letter of string word1.But if save == 2, that means there is no substring, null value
            break;
        }
        else if (save == 2 && word1[x + 1] == '\0' || word1[x + 1] == '\0')
        {   // checks to see if save == 2 and string 1  == null, if conditions are met and 1 is added to count first_lette
            first_lette = x + 1;
            break;
        }

        if(word1[x] == word2[0]) //checks if the the letter that we're currently on in string word 1 matches the very first letter of string word 2 and runs until the end of the word
        {
            first_lette = x;    // The variable "first" will hold the instance of the first letter in word1, and if suceessful it will keep that value for the first letter, otherwise it will be updated throughout the code.
            hold = x + 1; // saves which letters matched when being ran

            for(int y = 1; y < strlen(word2); ++y) //loop runs and starts at the second letter of word2 till the end
            {
                if(word1[hold] == word2[y]) // checks to see if the current letters in word1 and word2 match up with each other, and if they do another if statement follows...
                {
                    // This will check if the value after the current letter is a null character which will mean that there is a substring within the string, so this will result in z being 1 and will break out the second for lop and the first for loop.
                    if( word2[y + 1] == '\0')
                    {
                        save = 1;
                        break;
                    }
                    hold++; //if statement is false then hold is added 1
                }
                else //checks if a letter is missing from word1 if the if statement above fails
                {
                  save = 2;
                  break;
                }
            }
        }
    }
    return &word1[first_lette]; // returns back to main to then get printed for the terminal
}