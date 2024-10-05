#include<stdio.h>
#include<stdlib.h>

char *copyStr(char*, int);
int calculateStrLen(char *);

int main()
{
    char test[] = "Hello, World!";
    int len = calculateStrLen(test);
    char *newStr = copyStr(test, len);
    printf("Result = %s",  newStr);

    free(newStr);

    return 0;
}

int calculateStrLen(char *str)
{
    char *ptr = str;
    int len = 0;
    while(*ptr!='\0')
    {
        len++;
        ptr++;
    }

    return len;
}

char *copyStr(char *str, int len)
{
    char *retval = (char*)malloc((sizeof(char) * len)+ 1); //save some space for the null terminator
    if(retval!=NULL)
    {
        int i=0;
        for(i=0; i<len; i++)
        {
            if((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            {
                retval[i] = (str[i] >= 65 && str[i]<= 90) ? str[i] + 32 : str[i] - 32;
            }
            else
            {
                retval[i] = str[i];
            }
            
        }
        retval[i] = '\0';
    }

    return retval;
}