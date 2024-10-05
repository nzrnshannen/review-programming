#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define DEFAULT 50

char* enterStr(); //accepts input
char* concatStrings(char*, char*, int, int); //returns the concatenated string
int strLength(char*); //calculates the string length


int main()
{
    char *str1 = enterStr();
    int str1_len = strLength(str1);

    char *str2 = enterStr();
    int str2_len = strLength(str2);
    
    char *resultStr = concatStrings(str1, str2, str1_len, str2_len);

    printf("First string: %s\n", str1);
    printf("Second string: %s\n", str2);
    printf("\n---\nResult = %s", resultStr);

    free(str1);
    free(str2);
    free(resultStr);

    return 0;
}

char* enterStr()
{
    char str[DEFAULT];
    int len=0;
    char ch;

// or simply use scanf and call strLength() for the length of string
    printf("Enter string: ");
    while((ch=getchar())!='\n')
    {
        str[len] = ch;
        len++;
    }
    str[len] = '\0';

// memory allocation after we get the length of string
    char *retStr = (char*)malloc((sizeof(char) * len) + 1);
    if(retStr!=NULL)
    {
        int i;
        for(i=0; i<len; i++)
        {
            retStr[i] = str[i];
        }
        retStr[i] = '\0';
    }

    printf("\n");
    return retStr;
}

int strLength(char *str)
{
    int len=0;
    char *ptr = str;
    while(*ptr!='\0')
    {
        len++;
        ptr++;
    }
    return len;
}

char* concatStrings(char *s1, char *s2, int len_s1, int len_s2)
{
    char *retStr = (char*)malloc((sizeof(char) * (len_s1 + len_s2)) + 1); // +1 to have some space for null character
    char *ptr = s1;
    int i, j;
    i = j = 0;

    while(*ptr!='\0')
    {
        retStr[i] = s1[i];
        ptr++;
        i++;
    }
    ptr = s2;
    while(*ptr!='\0')
    {
        retStr[i++] = s2[j++];
        ptr++;
    }
    retStr[i] = '\0';

    return retStr;
}