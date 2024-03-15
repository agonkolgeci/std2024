#include <stdio.h>

#include <stdio.h>
#include <string.h>

#include "acutest.h"
#include "./../lib/objects/objects.h"


void create_car(){
    Car* car = car_create("VW", "POLO", "GE123456");
    TEST_ASSERT_(strcmp(car->brand, "VW") == 0, "Car brand is not VW");
    TEST_ASSERT_(strcmp(car->model, "POLO") == 0, "Car model is not POLO");
    TEST_ASSERT_(strcmp(car->license, "GE123456") == 0, "Car license is not GE123456");
}

void create_customer(){
    Customer* customer = customer_create("John Doe", "Some Street 123");
    TEST_ASSERT_(strcmp(customer->name, "John Doe") == 0, "Customer name is not 'John Doe'");
    TEST_ASSERT_(strcmp(customer->address, "Some Street 123") == 0, "Customer address is not 'Some Street 123'");
}

void create_register(){
    Car* car1 = car_create("VW", "POLO", "GE123456");
    Car* car2 = car_create("VW", "POLO", "GE123457");
    Customer* customer1 = customer_create("John Doe", "Some Street 123");
    Customer* customer2 = customer_create("Jane Doe", "Some Street 321");

    link_car(car1, customer1);
    link_car(car2, customer2);

    Customer** customers = (Customer*[]){customer1, customer2};

    Registry* registry = registry_create(customers, 2);
    TEST_ASSERT_(registry->customers[0] == customer1, "Customer 1 is not in the registry");
    TEST_ASSERT_(registry->customers[1] == customer2, "Customer 2 is not in the registry");

    TEST_ASSERT_(registry->customers[0]->car == car1, "Car 1 is not in the registry");
    TEST_ASSERT_(registry->customers[1]->car == car2, "Car 2 is not in the registry");
}

void create_car_extra(){
    Car* car = car_create("AUDI", "TT", "TI007");
    TEST_ASSERT_(strcmp(car->brand, "AUDI") == 0, "Car brand is not AUDI");
    TEST_ASSERT_(strcmp(car->model, "TT") == 0, "Car model is not TT");
    TEST_ASSERT_(strcmp(car->license, "TI007") == 0, "Car license is not TI007");
}

void create_customer_extra(){
    Customer* customer = customer_create("Jane Doe", "Some Street 321");
    TEST_ASSERT_(strcmp(customer->name, "Jane Doe") == 0, "Customer name is not 'Jane Doe'");
    TEST_ASSERT_(strcmp(customer->address, "Some Street 321") == 0, "Customer address is not 'Some Street 321'");
}

void create_register_extra(){
    Car* car1 = car_create("AUDI", "TT", "TI007");
    Car* car2 = car_create("AUDI", "A4", "TI008");
    Customer* customer1 = customer_create("John Doe", "Some Street 123");
    Customer* customer2 = customer_create("Jane Doe", "Some Street 321");

    link_car(car1, customer1);
    link_car(car2, customer2);

    Customer** customers = (Customer*[]){customer1, customer2};

    Registry* registry = registry_create(customers, 2);
    TEST_ASSERT_(registry->customers[0] == customer1, "Customer 1 is not in the registry");
    TEST_ASSERT_(registry->customers[1] == customer2, "Customer 2 is not in the registry");

    TEST_ASSERT_(registry->customers[0]->car == car1, "Car 1 is not in the registry");
    TEST_ASSERT_(registry->customers[1]->car == car2, "Car 2 is not in the registry");
}

TEST_LIST = {
    { "create_car", create_car },
    { "create_customer", create_customer },
    { "create_register", create_register },
    { "create_car_extra", create_car_extra },
    { "create_customer_extra", create_customer_extra },
    { "create_register_extra", create_register_extra },
    { NULL, NULL }
};
