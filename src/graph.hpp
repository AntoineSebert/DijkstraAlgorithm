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
	// enums
		enum underlying_container {
			LIST,
			MATRIX
		};
		enum uniqueness {
			UNIQUE,
			NOT_UNIQUE
		};
	template<typename data>
	class abstract_graph {
		// ATTRIBUTES
			template <typename T = unsigned int>
			using abstract_link = std::pair<T, T>;
			// put in a particular header and transform it into a named tuple
			class abstract_node {
				data value;
				abstract_node();
				virtual void pureVirtual() = 0;
			};
			std::any container;
			static unsigned int instances;
			template<typename node_data = unsigned int>
			class oriented_graph;
			template<typename node_data = unsigned int>
			class unoriented_graph;
			template<typename node_data = unsigned int>
			class mixed_orientation_graph;
			template<typename node_data = unsigned int, typename path_weight = unsigned int>
			class weighted_graph;
			template<typename node_data = unsigned int>
			class unweighted_graph;
			template<typename node_data = unsigned int, typename path_weight = unsigned int>
			class mixed_weight_graph;
			template<typename node_data = unsigned int, typename path_weight = unsigned int>
			class oriented_weighted_graph;
			template<typename node_data = unsigned int>
			class oriented_unweighted_graph;
			template<typename node_data = unsigned int, typename path_weight = unsigned int>
			class oriented_mixed_weight_graph;
			template<typename node_data = unsigned int, typename path_weight = unsigned int>
			class unoriented_weighted_graph;
			template<typename node_data = unsigned int>
			class unoriented_unweighted_graph;
			template<typename node_data = unsigned int, typename path_weight = unsigned int>
			class unoriented_mixed_weight_graph;
			template<typename node_data = unsigned int, typename path_weight = unsigned int>
			class mixed_orientation_weighted_graph;
			template<typename node_data = unsigned int>
			class mixed_orientation_unweighted_graph;
			template<typename node_data = unsigned int, typename path_weight = unsigned int>
			class mixed_orientation_mixed_weight_graph;
		// MEMBERS
			virtual void pureVirtual() = 0;
			// default constructor
				abstract_graph();
			// copy constructor
				abstract_graph(const abstract_graph& rhs) : container(rhs.container) {}
			// move constructor
				abstract_graph(abstract_graph&& rhs) noexcept : container(rhs.container) { rhs.container.reset(); }
			// destructor
				~abstract_graph() noexcept = 0;
			// operators
				// arithmetic operators
					abstract_graph& operator=(const abstract_graph& rhs) = 0;
					abstract_graph operator+(const abstract_node& rhs) = 0;					// add node
					abstract_graph operator-(const abstract_node& rhs) = 0;					// remove node if it exist
					abstract_graph operator+(const abstract_graph& rhs) = 0;				// add nodes and paths
					abstract_graph operator-(const abstract_graph& rhs) = 0;				// remove nodes and paths if they exist
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
					void operator~() = 0;													// invert links orientation in oriented graphs
					void operator&(const abstract_graph& rhs) = 0;							// intersection
					void operator|(const abstract_graph& rhs) = 0;							// union
					void operator^(const abstract_graph& rhs) = 0;							// difference
					void operator<<(const abstract_graph& rhs) = 0;							// output
					void operator>>(const abstract_node& rhs) = 0;							// input
				// comparison/relational operators
					bool operator==(const abstract_graph& rhs) = 0;							// compare nodes and paths
					bool operator!=(const abstract_graph& rhs) = 0;							// compare nodes and paths
					bool operator!=(const abstract_graph& rhs) const = 0;					// compare nodes and paths
					bool operator>(const abstract_graph& rhs) const = 0;					// compare number of nodes
					bool operator<(const abstract_graph& rhs) const = 0;					// compare number of nodes
					bool operator>=(const abstract_graph& rhs) const = 0;					// compare number of nodes
					bool operator<=(const abstract_graph& rhs) const = 0;					// compare number of nodes
					//bool operator<=>(const abstract_graph& rhs) const = 0;				// compare number of nodes ( ͡° ͜ʖ ͡°)
				// compound assignment operators
					abstract_graph& operator+=(const abstract_node& rhs) = 0;				// add node
					abstract_graph& operator-=(const abstract_node& rhs) = 0;				// remove node if it exist
					abstract_graph& operator+=(const abstract_graph& rhs) = 0;				// add nodes and paths
					abstract_graph& operator-=(const abstract_graph& rhs) = 0;				// remove nodes and paths if they exist
					/* nonsenses
					abstract_graph& operator*=(abstract_graph rhs) = delete;
					abstract_graph& operator/=(abstract_graph rhs) = delete;
					abstract_graph& operator%=(abstract_graph rhs) = delete;
					*/
					abstract_graph& operator&=(const abstract_graph& rhs) = 0;				// intersection
					abstract_graph& operator|=(const abstract_graph& rhs) = 0;				// union
					abstract_graph& operator^=(const abstract_graph& rhs) = 0;				// difference
					abstract_graph& operator<<=(const abstract_graph& rhs) = 0;				// output
					abstract_graph& operator>>=(const abstract_graph& rhs) = 0;				// input
				// logical operators
					bool operator!() = 0;													// check if empty
					bool operator&&(const abstract_graph& rhs) = 0;							// check if the two graphs are not empty
					bool operator||(const abstract_graph& rhs) = 0;							// check if one of the two graphs are not empty
				// member and pointer operators
					abstract_node& operator[](unsigned int index) = 0;						// unsecure element access
					std::any& operator*() = delete;											// nonsense
					abstract_graph& operator&() = delete;									// possible optimization
					std::any& operator->() = 0;												// access underlying container
					const void* operator->*(const abstract_graph& rhs) = delete;			// nonsense
				// other operators
					void operator()(std::any rhs, ...) = delete;							// could not find a good utility of this
					abstract_graph& operator,(const abstract_graph& rhs) = delete;			// nonsense
					void operator ""_literal(abstract_graph a) = delete;					// could not find a good utility of this
					// implicit conversions
						operator oriented_graph<std::any>() = 0;
						operator unoriented_graph() = 0;
						operator mixed_orientation_graph() = 0;

						operator weighted_graph() = 0;
						operator unweighted_graph() = 0;
						operator mixed_weight_graph() = 0;

						operator oriented_weighted_graph() = 0;
						operator oriented_unweighted_graph() = 0;
						operator oriented_mixed_weight_graph() = 0;
						operator unoriented_weighted_graph() = 0;
						operator unoriented_unweighted_graph() = 0;
						operator unoriented_mixed_weight_graph() = 0;
						operator mixed_orientation_weighted_graph = 0;
						operator mixed_orientation_unweighted_graph() = 0;
						operator mixed_orientation_mixed_weight_graph() = 0;
					// explicit conversions
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
					void* operator new(size_t x) = delete;									// possible optimization
					void* operator new[](size_t x) = delete;								// possible optimization
					void operator delete(void *a) = delete;									// possible optimization
					void operator delete[](void *a) = delete;								// possible optimization
			// move assignment operator
				abstract_graph& operator=(abstract_graph&& other) noexcept = 0;
			// iterators
				void begin() const noexcept = 0;
				void cbegin() const noexcept = 0;
				void end() const noexcept = 0;
				void cend() const noexcept = 0;
				void rbegin() const noexcept = 0;
				void crbegin() const noexcept = 0;
				void rend() const noexcept = 0;
				void crend() const noexcept = 0;
			// element access
				void at() = 0;
				// subscript operator already defined in members/operators/member_and_pointer_operators
				void front() = 0;
				void back() = 0;
			// capacity
				void empty() = 0;
				void size() = 0;
				void max_size() = 0;
				void resize() = 0;
				void capacity() = 0;
				void reserve() = 0;
				void shrink_to_fit() = 0;
			// modifiers
				void clear() = 0;
				void insert() = 0;
				void insert_or_assign() = 0;
				void emplace() = 0;
				void emplace_hint() = 0;
				void try_emplace() = 0;
				void erase() = 0;
				void push_front() = 0;
				void emplace_front() = 0;
				void pop_front() = 0;
				void push_back() = 0;
				void emplace_back() = 0;
				void pop_back() = 0;
				void swap() = 0;
				void merge() = 0;
				void extract() = 0;
			// list operations
				void splice() = 0;
				void remove() = 0;
				void remove_if() = 0;
				void reverse() = 0;
				void unique() = 0;
				void sort() = 0;
			// lookup
				void count() = 0;
				void find() = 0;
				void contains() = 0;
				void lower_bound() = 0;
				void upper_bound() = 0;
				void equal_range() = 0;
			// observers
				void key_comp() = 0;
				void value_comp() = 0;
				void hash_function() = 0;
				void key_eq() = 0;
			// allocator
				void get_allocator() = 0;
	};
	// abstract graph orientation
		template<typename node_data = unsigned int>
		class oriented_graph : public abstract_graph<node_data> {
			// ATTRIBUTES
			// MEMBERS
				oriented_graph();
				virtual void pureVirtual() = 0;
		};
		template<typename node_data = unsigned int>
		class unoriented_graph : public abstract_graph<node_data> {
			// ATTRIBUTES
			// MEMBERS
				unoriented_graph();
				virtual void pureVirtual() = 0;
		};
		template<typename node_data = unsigned int>
		class mixed_orientation_graph : public oriented_graph<node_data>, public unoriented_graph<node_data> {
			// ATTRIBUTES
			// MEMBERS
				mixed_orientation_graph();
				virtual void pureVirtual() = 0;
		};
	// abstract graph weight
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class weighted_graph : public abstract_graph<node_data> {
			// ATTRIBUTES
			// MEMBERS
				weighted_graph();
				virtual void pureVirtual() = 0;
		};
		template<typename node_data = unsigned int>
		class unweighted_graph : public abstract_graph<node_data> {
			// ATTRIBUTES
			// MEMBERS
				unweighted_graph();
				virtual void pureVirtual() = 0;
		};
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class mixed_weight_graph : public weighted_graph<typename node_data = unsigned int, typename path_weight = unsigned int>, public unweighted_graph<node_data> {
			// ATTRIBUTES
			// MEMBERS
				mixed_weight_graph();
				virtual void pureVirtual() = 0;
		};
	// graph subtypes
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class oriented_weighted_graph : public oriented_graph<node_data>, public weighted_graph<node_data, path_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					oriented_weighted_graph() {}
					~oriented_weighted_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int>
		class oriented_unweighted_graph : public oriented_graph<node_data>, public unweighted_graph<node_data> {
			// ATTRIBUTES
			// MEMBERS
				public:
					oriented_unweighted_graph() {}
					~oriented_unweighted_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class oriented_mixed_weight_graph : public oriented_graph<node_data>, public mixed_weight_graph<node_data, path_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					oriented_mixed_weight_graph() {}
					~oriented_mixed_weight_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class unoriented_weighted_graph : public unoriented_graph<node_data>, public weighted_graph<node_data, path_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					unoriented_weighted_graph() {}
					~unoriented_weighted_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int>
		class unoriented_unweighted_graph : public unoriented_graph<node_data>, public unweighted_graph<node_data> {
			// ATTRIBUTES
			// MEMBERS
				public:
					unoriented_unweighted_graph() {}
					~unoriented_unweighted_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class unoriented_mixed_weight_graph : public unoriented_graph<node_data>, public mixed_weight_graph<node_data, path_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					unoriented_mixed_weight_graph() {}
					~unoriented_mixed_weight_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class mixed_orientation_weighted_graph : public mixed_orientation_graph<node_data>, public weighted_graph<node_data, path_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					mixed_orientation_weighted_graph() {}
					~mixed_orientation_weighted_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int>
		class mixed_orientation_unweighted_graph : public mixed_orientation_graph<node_data>, public unweighted_graph<node_data> {
			// ATTRIBUTES
			// MEMBERS
				public:
					mixed_orientation_unweighted_graph() {}
					~mixed_orientation_unweighted_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename node_data = unsigned int, typename path_weight = unsigned int>
		class mixed_orientation_mixed_weight_graph : public mixed_orientation_graph<node_data>, public mixed_weight_graph<node_data, path_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					mixed_orientation_mixed_weight_graph() {}
					~mixed_orientation_mixed_weight_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
}

#endif