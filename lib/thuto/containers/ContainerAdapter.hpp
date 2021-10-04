#pragma once

namespace thuto
{

// Todo : check Adapter has a member container and check container looks like a container
template <typename Adapter, typename Container>
class ContainerAdapter
{
	public:
		using value_type = Container::value_type;
		using pointer = Container::pointer;
		using const_pointer = Container::const_pointer;
		using reference = Container::reference;
		using const_reference = Container::const_reference;

		using const_iterator = Container::const_iterator;
		using iterator = Container::iterator;
		using const_reverse_iterator = Container::const_reverse_iterator;
		using reverse_iterator = Container::reverse_iterator;
		using size_type = Container::size_type;
		using difference_type = Container::difference_type;

		constexpr Adapter* self() { return static_cast<Adapter*>(this); }
		constexpr const Adapter* self() const { return static_cast<const Adapter*>(this); }

		constexpr Container& get_container() { return self()->_container; }
		constexpr  const Container& get_container() const { return self()->_container; }

		constexpr iterator begin() { return self()->_container.begin(); }
		constexpr iterator end() { return self()->_container.end(); }

		constexpr const_iterator cbegin() const { return self()->_container.cbegin(); }
		constexpr const_iterator cend() const { return self()->_container.cend(); }

		constexpr reverse_iterator rbegin() { return self()->_container.rbegin(); }
		constexpr reverse_iterator rend() { return self()->_container.rend(); }

		constexpr const_reverse_iterator crbegin() const { return self()->_container.crbegin(); }
		constexpr const_reverse_iterator crend() const { return self()->_container.crend(); }
};

} // namespace thuto