#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_FREQUENCY 0
#define MAXCHARS 100
#define ASCIIOFFSET 48

typedef struct freqListType freqList;

struct freqListType {
    int frequency;
    freqList *next;
};

int isInList(freqList *head, int resultfreq);
