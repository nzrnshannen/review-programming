/*
    A program to check whether the given character is a vowel or not
*/

#include<stdio.h>
#include<ctype.h>
/*
    I used <ctype.h> in order to use the tolower()
    Syntax: tolower(<char>);

    Q: How does tolower() works?
    Instead of doing the standard (character == 'F' || character == 'f'),
    You can just do  (tolower(character) == 'f') 
    It converts the character in lowercase!
*/

void vowelConsonantCheck(char);

int main()
{
    char inputChar;
    printf("Enter a character: ");
    scanf(" %c", &inputChar);

    vowelConsonantCheck(inputChar);
    return 0;
}

void vowelConsonantCheck(char character)
{
    if(tolower(character) == 'a' || tolower(character) == 'e' || tolower(character) == 'i' || tolower(character) == 'o' || tolower(character) == 'u')
    {
        printf("\nThe character %c is a vowel.", character);
    }
    else
    {
        printf("\nThe character %c is a consonant.", character);
    }
}