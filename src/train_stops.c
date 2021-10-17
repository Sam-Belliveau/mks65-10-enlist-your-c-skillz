#include "./train_stops.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct train_stop* create_stop(const char* name, const char trains[])
{
    struct train_stop* stop = malloc(sizeof(struct train_stop));

    strncpy(stop->name, name, TRAIN_STOP_NAME_SIZE);
    strncpy(stop->trains, trains, TRAIN_STOP_MAX_TRAINS);
    stop->next_stop = NULL;
    stop->previous_stop = NULL;

    #ifdef DEBUG_TRAINS
    printf("[DEBUG] CREATED STOP {");
    print_stop(stop);
    printf("}\n");
    #endif

    return stop;
}

void print_stop(struct train_stop* stop)
{
    char* trains = stop->trains;

    printf("%s", stop->name);
    
    if(stop->trains[0])
    {
        printf(" [%c", trains[0]);
        while(*++trains) printf(", %c", *trains);
        printf("]");
    }

    else printf(" [NO TRANSFERS]");
}

void print_line(struct train_stop* stop)
{
    printf("Train Line: {\n");
    
    while(stop) 
    {
        printf("\t");
        print_stop(stop);
        printf("\n");
        stop = stop->next_stop;
    }

    printf("}\n");
}

struct train_stop* insert_stop(struct train_stop* line, struct train_stop* stop)
{
    stop->next_stop = line;
    line->previous_stop = stop;
    return stop;
}

void free_line(struct train_stop* line)
{
    if(line)
    {
        free_line(line->next_stop);

        #ifdef DEBUG_TRAINS
        printf("[DEBUG] FREED STOP {");
        print_stop(line);
        printf("}\n");
        #endif

        if(line->previous_stop) line->previous_stop->next_stop = NULL;
        free(line);
    }

}