#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getPriority(char letter)
{
    //i noted that the priorities were corresponding to the alphabet order
    if (('a' <= letter) && (letter <= 'z'))
    {
        return letter - 'a' + 1;
    }
    else if (('A' <= letter) && (letter <= 'Z'))
    {
        return 26 + (letter - 'A' + 1);
    }

    return -1; //if not a letter
}

int main()
{
    char item1[200], item2[200], item3[200];
    FILE* fptr = fopen("input.txt", "r");

    int sum = 0;

    while (1) {
        char c = fgetc(fptr); //to check for EOF

        if (c == EOF) { break; }
        else {
            char temp[200];

            fscanf(fptr, "%s\n%s\n%s\n", item1,item2,item3);

            //we removed the first character with the fgetc so we need to reput it on the first string:

            //need to do the following because strcat only takes two strings (two char arrays with a terminating \0 character
            temp[0] = c;
            temp[1] = '\0';
            strcat(temp, item1);
            strcpy(item1, temp);

            //3 for loops to compare all characters in 3 strings
            for (int i = 0 ; i < strlen(item1) ; i++) {

                for (int j = 0 ; j < strlen(item2) ; j++) {

                    for (int k = 0 ; k < strlen(item3) ; k++) {

                        //if a similar char is found in 3 strings
                        if ((item1[i] == item2[j]) && (item2[j] == item3[k])) {

                            sum += getPriority(item1[i]); //we had the priority

                            i = strlen(item1); //break the first loop
                            j = strlen(item2); //break the second loop
                            break; //break the third loop
                        }
                    }
                }
            }
        }



    }

    printf("%s%d\n", "Final sum is : ", sum);
    fclose(fptr);
    return 0;
}
