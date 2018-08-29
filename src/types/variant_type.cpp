/*
Copyright © Nico Zink
All rights reserved.
*/

#include <cpp_util/types/variant_type.h>

// Local includes

// Project includes

// System Includes

namespace
{
	VariantType CreateNull()
	{
		VariantType variant_type;
		variant_type.set<void>(nullptr);

		return variant_type;
	}
}

VariantType::VariantType()
{
	
}

VariantType::~VariantType()
{

}

void* VariantType::null_ptr = nullptr;

VariantType VariantType::Null = CreateNull();

bool VariantType::operator ==(const VariantType &b) const
{
	return variant_ptr == b.variant_ptr;
}

bool VariantType::operator !=(const VariantType &b) const
{
	return variant_ptr != b.variant_ptr;
}
