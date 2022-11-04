#include "PersonBuilder.h"
#include "PersonPersonalBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonEmploymentBuilder.h"

PersonBuilderBase::operator Person() 
{
    return std::move(person);
}

PersonPersonalBuilder PersonBuilderBase::is() const
{
    return PersonPersonalBuilder{ person };
}

PersonAddressBuilder PersonBuilderBase::lives() const
{
    return PersonAddressBuilder{ person };
}

PersonEmploymentBuilder PersonBuilderBase::works() const
{
    return PersonEmploymentBuilder{ person };
}