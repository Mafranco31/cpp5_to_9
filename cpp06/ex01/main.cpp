#include "Serializer.hpp"
#include <iostream>
#include <string>
#include "data.h"

int main( void ) {
    Data d;

    d.name = "Mathis";
    d.surname = "Francois";
    d.place = "Barcelona";
    d.street = "Via Laietana";
    std::cout << "name: " << d.name << std::endl;
    std::cout << "surname: " << d.surname << std::endl;
    std::cout << "place: " << d.place << std::endl;
    std::cout << "street: " << d.street << std::endl << std::endl;

    Data    *p_data = &d;
    Serializer::deserialize(Serializer::serialize(p_data));
    std::cout << "name: " << p_data->name << std::endl;
    std::cout << "surname: " << p_data->surname << std::endl;
    std::cout << "place: " << p_data->place << std::endl;
    std::cout << "street: " << p_data->street << std::endl << std::endl;

    std::cout << "Adress of d: " << &d << std::endl;
    std::cout << "Adress of p_data serialized: " << Serializer::serialize(p_data) << std::endl;
    std::cout << "Adress converted to int: " << std::hex << Serializer::serialize(p_data) << std::endl;
    std::cout << "Adress of p_data deserialized: " << Serializer::deserialize(Serializer::serialize(p_data)) << std::endl;
}