#ifndef GRAPH.HPP
#define GRAPH.HPP
#endif

#include <map>
#include <utility>
#include <set>
#include <vector>

namespace graph {
	enum underlying_Container {
		LIST,
		MATRIX
	};
	enum uniqueness {
		UNIQUE,
		NOT_UNIQUE
	};
	template<typename data>
	class AbstractGraph {
		// ATTRIBUTES
			void* container;
		// MEMBERS
			// default constructor
				AbstractGraph() = 0;
			// copy constructor
				AbstractGraph(const AbstractGraph& other) = 0;
			// move constructor1
				AbstractGraph(AbstractGraph&& other) noexcept : data(other.data) = 0;
			// destructor2
				~AbstractGraph() noexcept = 0;
			// operators
				// arithmetic operators
					AbstractGraph& operator=(const AbstractGraph& other) = 0;
					R K::operator+(S b) = 0;
					R K::operator-(S b) = 0;
					R K::operator+() = 0;
					R K::operator-() = 0;
					R K::operator*(S b) = 0;
					R K::operator/(S b) = 0;
					R K::operator%(S b) = 0;
					R K::operator++() = 0;
					R K::operator++(int) = 0;
					R K::operator--() = 0;
					R K::operator--(int) = 0;
				// bitwise operators
					R K::operator~() = 0;
					R K::operator&(S b) = 0;
					R K::operator|(S b) = 0;
					R K::operator^(S b) = 0;
					R K::operator<<(S b) = 0;
					R K::operator>>(S b) = 0;
				// comparison/relational operators
					bool K::operator==(const S& b) = 0;
					bool K::operator!=(const S& b) = 0;
					bool K::operator!=(const S& b) const = 0;
					bool K::operator>(const S& b) const = 0;
					bool K::operator<(const S& b) const = 0;
					bool K::operator>=(const S& b) const = 0;
					bool K::operator<=(const S& b) const = 0;
					bool K::operator<=>(const S& b) const = 0;
				// compound assignment operators
					R& K::operator+=(S b) = 0;
					R& K::operator-=(S b) = 0;
					R& K::operator*=(S b) = 0;
					R& K::operator/=(S b) = 0;
					R& K::operator%=(S b) = 0;
					R& K::operator&=(S b) = 0;
					R& K::operator|=(S b) = 0;
					R& K::operator^=(S b) = 0;
					R& K::operator<<=(S b) = 0;
					R& K::operator>>=(S b) = 0;
				// logical operators
					bool K::operator!() = 0;
					bool K::operator&&(S b) = 0;
					bool K::operator||(S b) = 0;
				// member and pointer operators
					R& K::operator[](S b) = 0;
					R& K::operator*() = 0;
					R& K::operator&() = 0;
					R& K::operator->() = 0;
					R& K::operator->*(S b) = 0;
				// other operators
					R K::operator()(S a, T b, ...) = 0;
					R& K::operator,(S b) = 0;
					R operator ""_b(T a) = 0;
					explicit K::operator R() = 0;
					void* K::operator new(size_t x) = 0;
					void* K::operator new[](size_t x) = 0;
					void K::operator delete(void *a) = 0;
					void K::operator delete[](void *a) = 0;
			// move assignment operator
				AbstractGraph& operator=(AbstractGraph&& other) noexcept = 0;
			// iterators
				auto begin() const noexcept = 0;
				auto cbegin() const noexcept = 0;
				auto end() const noexcept = 0;
				auto cend() const noexcept = 0;
				auto rbegin() const noexcept = 0;
				auto crbegin() const noexcept = 0;
				auto rend() const noexcept = 0;
				auto crend() const noexcept = 0;
			// element access
				auto at() = 0;
				auto operator[] = 0;
				auto front() = 0;
				auto back() = 0;
			// capacity
				auto empty() = 0;
				auto size() = 0;
				auto max_size() = 0;
				auto resize() = 0;
				auto capacity() = 0;
				auto reserve() = 0;
				auto shrink_to_fit() = 0;
			// modifiers
				auto clear() = 0;
				auto insert() = 0;
				auto insert_or_assign() = 0;
				auto emplace() = 0;
				auto emplace_hint() = 0;
				auto try_emplace() = 0;
				auto erase() = 0;
				auto push_front() = 0;
				auto emplace_front() = 0;
				auto pop_front() = 0;
				auto push_back() = 0;
				auto emplace_back() = 0;
				auto pop_back() = 0;
				auto swap() = 0;
				auto merge() = 0;
				auto extract() = 0;
			// list operations
				auto splice() = 0;
				auto remove() = 0;
				auto remove_if() = 0;
				auto reverse() = 0;
				auto unique() = 0;
				auto sort() = 0;
			// lookup
				auto count() = 0;
				auto find() = 0;
				auto contains() = 0;
				auto lower_bound() = 0;
				auto upper_bound() = 0;
				auto equal_range() = 0;
			// observers
				auto key_comp() = 0;
				auto value_comp() = 0;
				auto hash_function() = 0;
				auto key_eq() = 0;
			// allocator
				auto get_allocator() = 0;
	};
	template<typename data>
	class OrientedGraph : public AbstractGraph<data> {


	};
	template<typename data>
	class UnorientedGraph : public AbstractGraph<data> {

	};
	template<typename data>
	class MixedGraph : public OrientedGraph<data, weight>, UnorientedGraph<data, weight> {

	};
	template<typename data, typename weight>
	class WeightedOrientedGraph : public OrientedGraph<data, weight> {

	};
	template<typename data, typename weight>
	class WeightedUnorientedGraph : public UnorientedGraph<data, weight> {

	};
	template<typename data, typename weight>
	class WeightedMixedGraph : public WeightedOrientedGraph<data, weight>, WeightedUnorientedGraph<data, weight> {

	};
}