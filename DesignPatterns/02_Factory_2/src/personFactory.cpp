#include "personFactory.hpp"

Person PersonFactory::createPerson(const std::string& name)
{
     return {personCounter++, name};
}