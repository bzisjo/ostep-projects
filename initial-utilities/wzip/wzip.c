#include <stdio.h>
#include <stdlib.h>
// #include <netinet/in.h>

#define BUFFER_SIZE (512)

int zip(char curr, uint32_t count)
{
    // count = htonl(count);
    fwrite(&count, 4, 1, stdout);
    fwrite(&curr, 1, 1, stdout);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        
        char curr = '\0';
        char next = '\0';
        uint32_t count = 0;
        for (size_t i = 1; i < argc; i++)
        {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL)
            {
                printf("wzip: cannot open file\n");
                exit(1);
            }

            char *line_buf = NULL;
            size_t line_buf_size = 0;
            ssize_t nread;
            while ( (nread = getline(&line_buf, &line_buf_size, fp)) != -1 )
            {

                for (size_t i = 0; i < nread; i++)
                {
                    next = line_buf[i];
                    if (curr == '\0')
                    {
                        curr = next;
                        count++;
                    }
                    else if (curr == next)
                    {
                        count++;
                    }
                    else
                    {
                        zip(curr, count);
                        count = 1;
                        curr = next;
                    }
                }
            }
            
            free(line_buf);
            fclose(fp);
        }
        zip(curr, count);
    }
    else
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
}