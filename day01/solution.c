#include "solution.h"

int isInList(freqList *head, int resultfreq)
{
    int res = 0;

    while (head != NULL) {
        if (head -> frequency == resultfreq)
        {
            res = 1;
            break;
        }
        head = head -> next;
    }

    return res;
}

int main(int argc, char* argv[])
{
    char *filename;
    FILE *infile;

    char line[MAXCHARS];
    char backup[MAXCHARS];
    long value;

    int currentfreq = BASE_FREQUENCY;
    int resultfreq = BASE_FREQUENCY;

    freqList *head = NULL;
    freqList *temp = NULL;
    freqList *tail = NULL;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 0;
    }

    filename = argv[1];

    infile = fopen(filename, "r");

    if (!infile) {
        printf("Unable to open file: %s\n", filename);
        return 0;
    }

    while (infile)
    {
        while (fgets(line, MAXCHARS, infile))
        {
            strtok(line, "\n");
            strcpy(backup, line);

            if (strlen(line) > 1) {
                
                value = strtol(backup, NULL, 10);
                resultfreq = currentfreq + ((int)value);

                if (isInList(head, resultfreq) == 1) {
                    printf("Current frequency %d, change of %s; resulting frequency %d, which has already been seen.\n", currentfreq, line, resultfreq);
                    return 1;
                } else {
                    /* add to list storage */
                    if (head == NULL) {
                        head = (freqList*)malloc(sizeof(freqList));
                        if (head == NULL) {
                            return 0;
                        }
                        head -> next = NULL;
                        head -> frequency = resultfreq;
                        tail = head;
                    } else {
                        temp = (freqList*)malloc(sizeof(freqList));
                        if (temp == NULL) {
                            return 0;
                        }
                        temp -> next = NULL;
                        temp -> frequency = resultfreq;

                        tail -> next = temp;
                        tail = temp;
                    }

                    printf("Current frequency %d, change of %s; resulting frequency %d.\n", currentfreq, line, resultfreq);
                }
                currentfreq = resultfreq;
            }
        }

        fclose(infile);
        
        infile = fopen(filename, "r");

        if (!infile) {
            printf("Unable to open file: %s\n", filename);
            return 0;
        }
    }

    return 1;
}
