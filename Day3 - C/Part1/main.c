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
    char str[200], item1[200], item2[200];
    int sum = 0;
    FILE* fptr = fopen("input.txt", "r");

    while(fscanf(fptr, "%s\n", str) == 1)
    {
        //reset the strings
        memset(item1, 0, sizeof(item1));
        memset(item2, 0, sizeof(item2));


        int first_item_start = 0;
        int second_item_start = strlen(str)/2;

        int first_item_stop = second_item_start;
        int second_item_stop = strlen(str);

        //copy the first half into item 1 and the second half into item2 using this method : strncpy(dest, src + beginIndex, endIndex - beginIndex);
        strncpy(item1, str + first_item_start, first_item_stop - first_item_start);
        strncpy(item2, str + second_item_start, second_item_stop - second_item_start);

        /*
        printf("%s\n", str);
        printf("%s\n", item1);
        printf("%s\n", item2);
        */

        for (int i = 0 ; i < strlen(item1) ; i++)
        {
            for (int j = 0 ; j < strlen(item2) ; j++)
            {
                //if same part found
                if (item1[i] == item2[j])
                {
                    //add the priority of the corresponding part to the total sum
                    sum += getPriority(item1[i]);
                    i = strlen(item1); //break first loop
                    break; //break second loop
                }
            }
        }
    }

    fclose(fptr);
    printf("%s%d\n", "Final sum is : ", sum);

    return 0;
}
