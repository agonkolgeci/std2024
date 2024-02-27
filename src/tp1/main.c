#include <stdio.h>
#include "../../lib/objects/objects.h"

int main()
{
    Car *mercedes = car_create("MB", "GLC", "GPL");

    printf("Model of mercedes: %s", mercedes->model);

    // TEST

    return 0;
}
