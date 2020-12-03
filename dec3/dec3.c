#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("input.txt", "r");
    char map[323][31];
    char temp;
    int treesHit = 0;
    int i, j;

    for (i = 0; i < 323; i++)
    {
        for (j = 0; j <= 31; j++)
        {
            temp = fgetc(fp);

            if (j == 0 && (temp == '\r' || temp == '\n'))
            {
                temp = fgetc(fp);
            }
            // printf("%c", temp);
            // if (feof(fp))
            // {
            //     break;
            // }
            if (temp != '\n' && temp != '\r')
            {
                map[i][j] = temp;
                // printf("%c", map[i][j]);
            }
            // else
            // {
            //     printf("\\n");
            // }
        }
        // printf("\n");
    }
    fclose(fp);

    j = 0;
    for(i = 1; i < 323; i++)
    {
        j = (j+3)%31;
        if (map[i][j] == '#')
        {
            map[i][j] = 'X';
            treesHit++;
        }
        else
        {
            map[i][j] = 'O';
        }
    }
    for (i = 0; i < 323; i++)
    {
        for (j = 0; j < 31; j++)
        {

            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    printf("hit %d trees\n", treesHit);

    return 0;
}