#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <models/src/Person.h>
#include "PersonBuilder.h"
#include "PersonPersonalBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonEmploymentBuilder.h"


int main() 
{
    Person person = Person::build()
                        .is()
                            .withName("Jan").withSurname("Dzikun")
                        .lives()
                            .at("Polanki").withPostCode("88-888").in("Miedzyrzecze")
                        .works()
                            .at("Jupiland").asA("Consultant").earning(500.55);
    std::cout << person << std::endl;
    return 0;
}