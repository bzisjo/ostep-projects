#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE (512)

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    else if (argc >= 2)
    {
        char *line_buf = NULL;
        size_t line_buf_size = 0;
        FILE *stream;
        if (argc == 2)
        {
            //stdin
            char buffer[BUFFER_SIZE];
            while (fgets(buffer, BUFFER_SIZE, stdin) != NULL)
            {
                if (strstr(buffer, argv[1]) != NULL)
                {
                    printf("%s", buffer);
                }
            }
        }
        else
        {
            for (size_t i = 2; i < argc; i++)
            {
                stream = fopen(argv[i], "r");
                if (stream == NULL)
                {
                    printf("wgrep: cannot open file\n");
                    free(line_buf);
                    exit(1);
                }

                while (getline(&line_buf, &line_buf_size, stream) != -1)
                {
                    // printf("%s", line_buf);
                    if (strstr(line_buf, argv[1]) != NULL)
                    {
                        printf("%s", line_buf);
                    }
                }
                fclose(stream);
            }
        }

        free(line_buf);
        return 0;
    }
}