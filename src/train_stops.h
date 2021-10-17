#ifndef SAMS_TRAIN_STOP_HEADER_FILE
#define SAMS_TRAIN_STOP_HEADER_FILE 1

#define TRAIN_STOP_NAME_SIZE 128
#define TRAIN_STOP_MAX_TRAINS 64

struct train_stop
{
    char trains[TRAIN_STOP_MAX_TRAINS];
    char name[TRAIN_STOP_NAME_SIZE];
    struct train_stop* next_stop;
    struct train_stop* previous_stop;
};

struct train_stop* create_stop(const char*, const char[]);

void print_stop(struct train_stop*);
void print_line(struct train_stop*);

struct train_stop* insert_stop(struct train_stop*, struct train_stop*);

void free_line(struct train_stop*);

#endif