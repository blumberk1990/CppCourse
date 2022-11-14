#include <string>
#include <iostream>
#include <vector>

struct Person
{
  int id;
  std::string name;
};

class PersonFactory
{
    private:
        static u_int personCounter;

    public:
        Person createPerson(const std::string& name) {
            Person person;
            person.name = name;
            person.id = personCounter;
            personCounter++;
            return person;
        }
};

u_int PersonFactory::personCounter = 0;

int main()
{
    std::vector<Person> persons;
    PersonFactory personFacotry;
    
    persons.push_back(personFacotry.createPerson("Tim"));
    persons.push_back(personFacotry.createPerson("Johnny"));
    persons.push_back(personFacotry.createPerson("Stefan"));
    for(auto& person : persons) {
        std::cout << "Personal data: id=<" << person.id 
                  << ">, name=<" << person.name << ">" 
                  << std::endl;
    }
    
}