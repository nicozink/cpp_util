#pragma once

#include <memory>
#include <vector>

class VariantType
{
public:
	template <typename T>
	static VariantType Create(T& item);

	static VariantType Null;

	VariantType();

	~VariantType();

	bool operator ==(const VariantType &b) const;
	bool operator !=(const VariantType &b) const;

	template <typename T>
	T& get() const;

	template <typename T>
	void set(const T& item);

private:

	static void* null_ptr;

	std::shared_ptr<void> variant_item;
};

template <typename T>
VariantType VariantType::Create(T& item)
{
	VariantType vt;
	vt.set<T>(item);

	return vt;
}

template <typename T>
T& VariantType::get() const
{
	return *std::static_pointer_cast<T>(variant_item);
}

template <typename T>
void VariantType::set(const T& item)
{
	T* item_ptr = new T(item);

	variant_item = std::shared_ptr<T>(item_ptr, [](void* p) {
		delete static_cast<T*>(p);
	});
}
