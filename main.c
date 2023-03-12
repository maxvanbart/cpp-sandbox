//
// Created by maxva on 12-3-2023.
//

#include "faker.h"

#include <stdio.h>


int main() {
    printf("Hello world from C!\n");
    int i = faker(5);
    printf("%d\n", i);


    // Create a random array of integers and parse it to the cumsum
    int myNumbers[] = {25, 50, 75, 100};
    int * r = cumsum(myNumbers);

    // Print the results of the cumsum
    printf("Cumsum results:\n");
    for (int j = 0; j < 4; j++) {
        printf("%d\n", r[j]);
    }


    return 0;
}