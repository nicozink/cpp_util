#pragma once

#include <memory>
#include <vector>

namespace
{
	struct VariantItem
	{
		std::shared_ptr<void> variant_ptr;
	};

	template <typename T>
	class VariantStorage
	{
	public:
		static T Get(const VariantItem& variant_item)
		{
			return *std::static_pointer_cast<T>(variant_item.variant_ptr);
		}

		static VariantItem Set(T value)
		{
			VariantItem to_return;
			
			T* item_ptr = new T(value);

			to_return.variant_ptr = std::shared_ptr<T>(item_ptr, [](void* p) {
				delete static_cast<T*>(p);
			});

			return to_return;
		}
	};

	template <typename T>
	class VariantStorage<T*>
	{
	public:
		static T* Get(const VariantItem& variant_item)
		{
			return std::static_pointer_cast<T>(variant_item.variant_ptr);
		}

		static VariantItem Set(T* value)
		{
			VariantItem to_return;

			to_return.variant_ptr = std::shared_ptr<T>(value, [](void* p) {});

			return to_return;
		}
	};

	template <typename T>
	class VariantStorage<T&>
	{
	public:
		static T& Get(const VariantItem& variant_item)
		{
			return *std::static_pointer_cast<T>(variant_item.variant_ptr);
		}

		static VariantItem Set(T& value)
		{
			VariantItem to_return;

			T* item_ptr = &value;

			to_return.variant_ptr = std::shared_ptr<T>(item_ptr, [](void* p) {});

			return to_return;
		}
	};

	template <typename T>
	class VariantStorage<T&&>
	{
	public:
		static VariantItem Set(T&& value)
		{
			VariantItem to_return;

			T* item_ptr = new T(std::move(value));

			to_return.variant_ptr = std::shared_ptr<T>(item_ptr, [](void* p) {});

			return to_return;
		}
	};
}

class VariantType
{
public:

	// Static Methods

	template <typename T>
	static VariantType Create(T item);

	// Static Variables

	static VariantType Null;

	// Constructors

	VariantType();

	~VariantType();

	// Operators

	bool operator ==(const VariantType &b) const;
	bool operator !=(const VariantType &b) const;

	// Public Methods

	template <typename T>
	T get() const;

	template <typename T>
	void set(const T item);

private:

	// Private Static Variables

	static void* null_ptr;

	// Private Variables

	VariantItem variant_item;
};

template <typename T>
VariantType VariantType::Create(T item)
{
	VariantType vt;
	vt.set<T>(item);

	return vt;
}

template <typename T>
T VariantType::get() const
{
	return VariantStorage<T>::Get(variant_item);
}

template <typename T>
void VariantType::set(const T item)
{
	variant_item = VariantStorage<T>::Set(std::move(item));
}
