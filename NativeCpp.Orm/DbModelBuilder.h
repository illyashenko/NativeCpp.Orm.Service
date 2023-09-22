#pragma once
#include "IEntity.h"
#include "std_service.h"
#include "EntityTypeConfiguration.h"
#include "Customers.h"
#include "CustomersAttributes.h"
#include "Jobs.h"

static std::unordered_map<IEntity*, EntityTypeConfiguration> entity_map;

class DbModelBulider
{
public:
	template <class TEntity> EntityTypeConfiguration SetEntity();
};

template<class TEntity>
inline EntityTypeConfiguration DbModelBulider::SetEntity()
{
	return EntityTypeConfiguration();
}

RTTR_REGISTRATION{

	rttr::registration::class_<Customers>("customers")
	.constructor<>()
	.property("Id", &Customers::id)
	.property("Age", &Customers::age)
	.property("FirstName", &Customers::first_name)
	.property("LastName", &Customers::last_name)
	.property("Email", &Customers::email)
	.property("Phone", &Customers::phone)
	.property("Weight", &Customers::weight);

	rttr::registration::class_<Jobs>("jobs")
	.constructor<>()
	.property("Id", &Jobs::id)
	.property("CreateDate", &Jobs::create_date)
	.property("Data", &Jobs::data);

	rttr::registration::class_<CustomersAttributes>("CustomersAttributes")
	.constructor<>()
	.property("Id", &CustomersAttributes::id)
	.property("Customer_Id", &CustomersAttributes::customer_id)
	.property("PostCode", &CustomersAttributes::post_code)
	.property("City", &CustomersAttributes::city)
	.property("Region", &CustomersAttributes::region)
	.property("Address", &CustomersAttributes::address);
}

