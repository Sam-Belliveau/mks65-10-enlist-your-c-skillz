#include <stdio.h>
#include <stdlib.h>

#include "train_stops.h"

int main(void)
{
    struct train_stop* six_train;
    struct train_stop* hunter_college;

    six_train = create_stop("Brooklyn Bridge", "JZ45");
    six_train = insert_stop(six_train, create_stop("Canal St", "JNQRW"));
    six_train = insert_stop(six_train, create_stop("Spring St", ""));
    six_train = insert_stop(six_train, create_stop("Bleeker St", "BDFM"));
    six_train = insert_stop(six_train, create_stop("Astor Pl", ""));
    six_train = insert_stop(six_train, create_stop("14 St-Union Sq", "LNQRW45"));
    six_train = insert_stop(six_train, create_stop("23 St", ""));
    six_train = insert_stop(six_train, create_stop("28 St", ""));
    six_train = insert_stop(six_train, create_stop("33 St", ""));
    six_train = insert_stop(six_train, create_stop("42 St Grand Central", "457S"));
    six_train = insert_stop(six_train, create_stop("51 St", "EM"));
    six_train = insert_stop(six_train, create_stop("59 St", "45NRW"));
    six_train = insert_stop(six_train, create_stop("68 St Hunter College", ""));
    hunter_college = six_train;
    six_train = insert_stop(six_train, create_stop("77 St", ""));
    six_train = insert_stop(six_train, create_stop("86 St", "45"));
    six_train = insert_stop(six_train, create_stop("96 St", ""));
    six_train = insert_stop(six_train, create_stop("103 St", ""));
    six_train = insert_stop(six_train, create_stop("110 St", ""));
    six_train = insert_stop(six_train, create_stop("116 St", ""));
    six_train = insert_stop(six_train, create_stop("125 St", "45"));

    print_line(six_train);

    printf("\nFreeing Hunter College!\n\n");
    free_line(hunter_college);

    printf("New ");
    print_line(six_train);

    free_line(six_train);
}