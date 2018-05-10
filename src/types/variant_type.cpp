/*
Copyright © Nico Zink
All rights reserved.
*/

#include <cpp_util/types/variant_type.h>

// Local includes

// Project includes

// System Includes

VariantType::VariantType()
{
	
}

VariantType::~VariantType()
{

}

void* VariantType::null_ptr = nullptr;

VariantType VariantType::Null = VariantType::Create<void*>(VariantType::null_ptr);

bool VariantType::operator ==(const VariantType &b) const
{
	return variant_item == b.variant_item;
}

bool VariantType::operator !=(const VariantType &b) const
{
	return variant_item != b.variant_item;
}
