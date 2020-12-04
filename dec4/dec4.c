#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkKey(char *key)
{
   if (strcmp(key, "byr") == 0)
   {
      return 0;
   }
   else if (strcmp(key, "eyr") == 0)
   {
      return 1;
   }
   else if (strcmp(key, "iyr") == 0)
   {
      return 2;
   }
   else if (strcmp(key, "hgt") == 0)
   {
      return 3;
   }
   else if (strcmp(key, "hcl") == 0)
   {
      return 4;
   }
   else if (strcmp(key, "ecl") == 0)
   {
      return 5;
   }
   else if (strcmp(key, "pid") == 0)
   {
      return 6;
   }
}

int checkValid(int *keys)
{
   for (int i = 0; i < 7; i++)
   {
      if (keys[i]==0)
         return 0;
   }
   return 1;
}

int main()
{
   int argPtr, length, done = 1, validCount = 0;
   int keys[7], i;
   FILE *fp = fopen("input.txt", "r");
   char buffer[256];
   char *key, *value, *temp;


   for (i = 0; i < 7; i++)
   {
      keys[i] = 0;
   }

   while (done)
   {
      temp = fgets(buffer, 256, fp);
      while (temp != NULL)
      {
         if (buffer[0] == '\r' || buffer[0] == '\n')
         {
            // printf("\n");
            break;
         }
         // printf("%s", buffer);

         key = strtok(buffer, ":");
         value = strtok(NULL, " ");

         keys[checkKey(key)] = 1;

         while (key != NULL)
         {
            key = strtok(NULL, ":");
            if (key == NULL)
            {
               break;
            }
            value = strtok(NULL, " ");

            // printf("%s:%s\n", key, value);
            if (strcmp(key, "cid") != 0)
            {
               keys[checkKey(key)] = 1;
            }
         }

         temp = fgets(buffer, sizeof(buffer), fp);
      }
      if (checkValid(keys)==1)
      {
         validCount++;
      }
      for (i = 0; i < 7; i++)
      {
         keys[i] = 0;
      }

      if (temp == NULL)
      {
         done = 0;
      }
   }

   // free(buffer);
   fclose(fp);

   printf("%d\n", validCount);

   return 0;
}