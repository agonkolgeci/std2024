#include <stdio.h>
#include "../../lib/objects/objects.h"

/*

   This file is for debugging only.

*/

int main() {
    Customer *customer1 = customer_create("Agon", "Agon.Kolgeci@etu.unige.ch");
    Customer *customer2 = customer_create("Antoine", "Antoine.Maendly@etu.unige.ch");
    Customer **customers = (Customer*[]){customer1, customer2};

    Registry *registry = registry_create(customers, 2);
    
    Car *mercedes = car_create("Mercedes-Benz", "GLC", "054 698 546");
    Car *peugeot = car_create("Lamborgini", "Aventador", "786 875 968");
    
    link_car(mercedes, customer1);
    link_car(peugeot, customer2);

    print_registry(registry);

    car_destroy(mercedes);
    car_destroy(peugeot);
    customer_destroy(customer1);
    customer_destroy(customer2);
    registry_destroy(registry);

    return 0;
}
