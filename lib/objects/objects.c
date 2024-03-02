#include "objects.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Car *car_create(char *brand, char *model, char *license) {
    Car *car = malloc(sizeof(Car));
    if(car == NULL) {
        return NULL;
    }

    car->brand = brand;
    car->model = model;
    car->license = license;

    return car;
}

Customer *customer_create(char *name, char *address) {
    Customer *customer = malloc(sizeof(Customer));
    if(customer == NULL) {
        return NULL;
    }

    customer->name = name;
    customer->address = address;

    return customer;
}


Registry *registry_create(Customer **customers, int size) {
    Registry *registry = malloc(sizeof(Registry));
    if(registry == NULL) {
        return NULL;
    }

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

        printf("------------------------------\n");
        printf("ID Client: #%d\n", i);
        printf("Nom du client: %s\n", customer->name);
        printf("Adresse du client: %s\n", customer->address);
        printf("Voiture du client: Marque: %s | Modèle: %s | Licence: %s\n", customer->car->brand, customer->car->model, customer->car->license);
        printf("------------------------------");
    }
}