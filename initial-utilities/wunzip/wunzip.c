#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>


int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        for (size_t i = 1; i < argc; i++)
        {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL)
            {
                printf("wzip: cannot open file\n");
                exit(1);
            }
            uint32_t count;
            char c;
            while (fread(&count, 4, 1, fp) == 1)
            {
                // printf("%d\n", count);
                fread(&c, 1, 1, fp);
                // printf("%c", c);
                for (size_t i = 0; i < count; i++)
                {
                    printf("%c", c);
                }
                
            }
            fclose(fp);
        }
    }
    else
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
}