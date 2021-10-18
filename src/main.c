#include <stdio.h>
#include <stdlib.h>

#include "train_stops.h"

int main(void)
{
    struct train_stop* six_train;
    struct train_stop* grand_central;
    struct train_stop* hunter_college;
    struct train_stop* st_110;

    six_train = create_stop("Brooklyn Bridge", "JZ45");
    six_train = insert_stop(six_train, create_stop("Bleeker St", "BDFM"));
    six_train = insert_stop(six_train, create_stop("14 St-Union Sq", "LNQRW45"));
    six_train = insert_stop(six_train, create_stop("23 St", ""));
    six_train = insert_stop(six_train, grand_central = create_stop("42 St Grand Central", "457S"));
    six_train = insert_stop(six_train, create_stop("59 St", "45NRW"));
    six_train = insert_stop(six_train, hunter_college = create_stop("68 St Hunter College", ""));
    six_train = insert_stop(six_train, create_stop("77 St", ""));
    six_train = insert_stop(six_train, st_110 = create_stop("110 St", ""));
    six_train = insert_stop(six_train, create_stop("125 St", "45"));

    print_line(six_train);

    free_stop(grand_central);
    free_stop(hunter_college);
    free_stop(st_110);

    printf("New ");
    print_line(six_train);

    free_line(six_train);
}