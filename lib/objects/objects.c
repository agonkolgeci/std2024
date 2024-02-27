#include "objects.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Car *car_create(char *brand, char *model, char *license) {
    Car *car = malloc(sizeof(Car));

    car->brand = brand;
    car->model = model;
    car->license = license;

    return car;
}

Customer *customer_create(char *name, char *address) {
    Customer *customer = malloc(sizeof(Customer));

    customer->name = name;
    customer->address = address;

    return customer;
}


Registry *registry_create(Customer **customers, int size) {
    Registry *registry = malloc(sizeof(Registry));

    registry->customers = customers;
    registry->size = size;

    return registry;
}


void car_destroy(Car *car) {
    free(car);
}

void customer_destroy(Customer *customer) {
    free(customer);
}

void registry_destroy(Registry *registry) {
    free(registry);
}

void link_car(Car *car, Customer *customer) {
    customer->car = car;
}

void print_registry(Registry *registry) {
    for(int i = 0; i < registry->size; i++) {
        Customer *customer = registry->customers[i];

        printf("------------------------------");
        printf("ID Client: #%s", i);
        printf("Nom du client: %s", customer->name);
        printf("Adresse du client: %s", customer->address);
        printf("Voiture du client: Marque: %s | Modèle: %s | Licence: %s", customer->car->brand, customer->car->model, customer->car->license);
        printf("------------------------------");
    }
}