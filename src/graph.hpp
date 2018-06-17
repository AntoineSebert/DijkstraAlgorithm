/**
* Graph Library
* Copyright (c) 2014, Antoine Sébert antoine.sb@orange.fr, All rights reserved.
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 3.0 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library.
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <any>
#include <map>
#include <utility>
#include <set>
#include <vector>

namespace graph {
	enum underlying_container {
		LIST,
		MATRIX
	};
	enum uniqueness {
		UNIQUE,
		NOT_UNIQUE
	};
	template <typename T = unsigned int>
	using abstract_link = std::pair<T, T>;
	template<typename data>
	class abstract_graph {
		// ATTRIBUTES
			// put in a particular header and transform it into a named tuple
			class abstract_node {
				data value;
				abstract_node();
				virtual void pureVirtual() = 0;
			};
			std::any container;
			static unsigned int instances;
		// MEMBERS
			virtual void pureVirtual() = 0;
			// default constructor
				abstract_graph();
			// copy constructor
				abstract_graph(const abstract_graph& rhs) : container(rhs.container) {}
			// move constructor
				abstract_graph(abstract_graph&& rhs) noexcept = 0;
			// destructor
				~abstract_graph() noexcept = 0;
			// operators
				// arithmetic operators
					abstract_graph& operator=(const abstract_graph& rhs) = 0;
					abstract_graph operator+(const abstract_node& rhs) = 0;				// add node
					abstract_graph operator-(const abstract_node& rhs) = 0;				// remove node if it exist
					abstract_graph operator+(const abstract_graph& rhs) = 0;			// add nodes and paths
					abstract_graph operator-(const abstract_graph& rhs) = 0;			// remove nodes and paths if they exist
					/* nonsenses
					abstract_graph operator+() = delete;
					abstract_graph operator-() = delete;
					abstract_graph operator*(const std::any& rhs) = delete;
					abstract_graph operator/(const std::any& rhs) = delete;
					abstract_graph operator%(const std::any& rhs) = delete;
					abstract_graph& operator++() = delete;
					abstract_graph operator++(int) = delete;
					abstract_graph& operator--() = delete;
					abstract_graph operator--(int) = delete;
					*/
				// bitwise operators
					auto operator~() = 0;												// invert links orientation in oriented graphs
					auto operator&(const abstract_graph& rhs) = 0;						// intersection
					auto operator|(const abstract_graph& rhs) = 0;						// union
					auto operator^(const abstract_graph& rhs) = 0;						// difference
					auto operator<<(const abstract_graph& rhs) = 0;						// output
					auto operator>>(const abstract_node& rhs) = 0;						// input
				// comparison/relational operators
					bool operator==(const abstract_graph& rhs) = 0;						// compare nodes and paths
					bool operator!=(const abstract_graph& rhs) = 0;						// compare nodes and paths
					bool operator!=(const abstract_graph& rhs) const = 0;				// compare nodes and paths
					bool operator>(const abstract_graph& rhs) const = 0;				// compare number of nodes
					bool operator<(const abstract_graph& rhs) const = 0;				// compare number of nodes
					bool operator>=(const abstract_graph& rhs) const = 0;				// compare number of nodes
					bool operator<=(const abstract_graph& rhs) const = 0;				// compare number of nodes
					bool operator<=>(const abstract_graph& rhs) const = 0;				// compare number of nodes ( ͡° ͜ʖ ͡°)
				// compound assignment operators
					abstract_graph& operator+=(const abstract_node& rhs) = 0;			// add node
					abstract_graph& operator-=(const abstract_node& rhs) = 0;			// remove node if it exist
					abstract_graph& operator+=(const abstract_graph& rhs) = 0;			// add nodes and paths
					abstract_graph& operator-=(const abstract_graph& rhs) = 0;			// remove nodes and paths if they exist
					/* nonsenses
					abstract_graph& operator*=(abstract_graph rhs) = delete;
					abstract_graph& operator/=(abstract_graph rhs) = delete;
					abstract_graph& operator%=(abstract_graph rhs) = delete;
					*/
					abstract_graph& operator&=(const abstract_graph& rhs) = 0;			// intersection
					abstract_graph& operator|=(const abstract_graph& rhs) = 0;			// union
					abstract_graph& operator^=(const abstract_graph& rhs) = 0;			// difference
					abstract_graph& operator<<=(const abstract_graph& rhs) = 0;			// output
					abstract_graph& operator>>=(const abstract_graph& rhs) = 0;			// input
				// logical operators
					bool operator!() = 0;												// check if empty
					bool operator&&(const abstract_graph& rhs) = 0;						// check if the two graphs are not empty
					bool operator||(const abstract_graph& rhs) = 0;						// check if one of the two graphs are not empty
				// member and pointer operators
					abstract_node& operator[](unsigned int index) = 0;
					std::any& operator*() = delete;										// nonsense
					abstract_graph& operator&() = delete;								// possible optimization
					R& operator->() = 0;												// access underlying container
					R& operator->*(std::any rhs) = delete;								// nonsense
				// other operators
					auto operator()(std::any a, std::any rhs, ...) = delete;			// could not find a good utility of this
					abstract_graph& operator,(const abstract_graph& rhs) = delete;		// nonsense
					auto operator ""_b(T a) = 0;
					explicit operator oriented_graph() = 0;
					explicit operator unoriented_graph() = 0;
					explicit operator mixed_orientation_graph() = 0;

					explicit operator weighted_graph() = 0;
					explicit operator unweighted_graph() = 0;
					explicit operator mixed_weight_graph() = 0;

					explicit operator oriented_weighted_graph() = 0;
					explicit operator oriented_unweighted_graph() = 0;
					explicit operator oriented_mixed_weight_graph() = 0;
					explicit operator unoriented_weighted_graph() = 0;
					explicit operator unoriented_unweighted_graph() = 0;
					explicit operator unoriented_mixed_weight_graph() = 0;
					explicit operator mixed_orientation_weighted_graph = 0;
					explicit operator mixed_orientation_unweighted_graph() = 0;
					explicit operator mixed_orientation_mixed_weight_graph() = 0;
					void* operator new(size_t x) = delete;							// possible optimization
					void* operator new[](size_t x) = delete;						// possible optimization
					void operator delete(void *a) = delete;							// possible optimization
					void operator delete[](void *a) = delete;						// possible optimization
			// move assignment operator
				abstract_graph& operator=(abstract_graph&& other) noexcept = 0;
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
	// abstract graph orientation
		template<typename node_data = unsigned int>
		class oriented_graph : public abstract_graph<node_data> {
			// ATTRIBUTES
		// MEMBERS
			virtual oriented_graph() = 0;
		};
		template<typename node_data = unsigned int>
		class unoriented_graph : public abstract_graph<node_data> {
			// ATTRIBUTES
		// MEMBERS
			virtual unoriented_graph() = 0;
		};
		template<typename node_data = unsigned int>
		class mixed_orientation_graph : public oriented_graph<node_data>, public unoriented_graph<node_data> {
			// ATTRIBUTES
		// MEMBERS
			virtual mixed_orientation_graph() = 0;
		};
	// abstract graph weight
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class weighted_graph : public abstract_graph<node_data> {
			// ATTRIBUTES
		// MEMBERS
			virtual weighted_graph() = 0;
		};
		template<typename node_data = unsigned int>
		class unweighted_graph : public abstract_graph<node_data> {
			// ATTRIBUTES
		// MEMBERS
			virtual unweighted_graph() = 0;
		};
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class mixed_weight_graph : public weighted_graph<typename node_data, typename path_weight = unsigned int>, public unweighted_graph<node_data> {
			// ATTRIBUTES
		// MEMBERS
			virtual mixed_weight_graph() = 0;
		};
	// graph subtypes
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class oriented_weighted_graph : public oriented_graph<node_data>, public weighted_graph<node_data, path_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					oriented_weighted_graph() {}
					~oriented_weighted_graph() {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int>
		class oriented_unweighted_graph : public oriented_graph<node_data>, public unweighted_graph<node_data> {
			// ATTRIBUTES
			// MEMBERS
				public:
					oriented_unweighted_graph() {}
					~oriented_unweighted_graph() {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class oriented_mixed_weight_graph : public oriented_graph<node_data>, public mixed_weight_graph<node_data, path_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					oriented_mixed_weight_graph() {}
					~oriented_mixed_weight_graph() {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class unoriented_weighted_graph : public unoriented_graph<node_data>, public weighted_graph<node_data, path_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					unoriented_weighted_graph() {}
					~unoriented_weighted_graph() {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int>
		class unoriented_unweighted_graph : public unoriented_graph<node_data>, public unweighted_graph<node_data> {
			// ATTRIBUTES
			// MEMBERS
				public:
					unoriented_unweighted_graph() {}
					~unoriented_unweighted_graph() {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class unoriented_mixed_weight_graph : public unoriented_graph<node_data>, public mixed_weight_graph<node_data, path_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					unoriented_mixed_weight_graph() {}
					~unoriented_mixed_weight_graph() {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class mixed_orientation_weighted_graph : public mixed_orientation_graph<node_data>, public weighted_graph<node_data, path_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					mixed_orientation_weighted_graph() {}
					~mixed_orientation_weighted_graph() {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int>
		class mixed_orientation_unweighted_graph : public mixed_orientation_graph<node_data>, public unweighted_graph<node_data> {
			// ATTRIBUTES
			// MEMBERS
				public:
					mixed_orientation_unweighted_graph() {}
					~mixed_orientation_unweighted_graph() {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class mixed_orientation_mixed_weight_graph : public mixed_orientation_graph<node_data>, public mixed_weight_graph<node_data, path_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					mixed_orientation_mixed_weight_graph() {}
					~mixed_orientation_mixed_weight_graph() {}
				private:
					void pureVirtual() {}
		};
}

#endif