#include <iostream>

#include <Owl/Types.hpp>
#include "owl_tests.hpp"  // TODO Separate concerts and write it as a static lib

int main() {
    

    // Outputting data with the template function written on the testing class
    OwlTesting::Tester::show_collection_elements<Owl::Http::HttpMethod>(
        Owl::Http::get_methods, 
        "Available HTTP METHODS as constant enum types in the Framework"
    );

    return 0;
}