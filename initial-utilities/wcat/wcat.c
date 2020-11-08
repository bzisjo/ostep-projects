#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE (512)

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        for (int i = 0; i < argc - 1; i++)
        {
            FILE *fp = fopen(argv[i + 1], "r");
            if (fp == NULL)
            {
                printf("wcat: cannot open file\n");
                exit(1);
            }

            char buffer[BUFFER_SIZE];
            while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
            {
                printf("%s", buffer);
            }

            fclose(fp);
        }
        return 0;
    }
    else if (argc == 1)
    {
        return 0;
    }
    else
    {
        printf("Not enough arguments");
        exit(1);
    }
}