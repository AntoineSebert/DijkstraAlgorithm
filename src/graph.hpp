﻿/**
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
		template<typename vertex_data>
		class abstract_graph;
		template<typename vertex_data>
		class oriented_graph;
		template<typename vertex_data>
		class unoriented_graph;
		template<typename vertex_data>
		class mixed_orientation_graph;
		template<typename vertex_data, typename edge_weight>
		class weighted_graph;
		template<typename vertex_data>
		class unweighted_graph;
		template<typename vertex_data, typename edge_weight>
		class mixed_weight_graph;
		template<typename vertex_data, typename edge_weight>
		class oriented_weighted_graph;
		template<typename vertex_data>
		class oriented_unweighted_graph;
		template<typename vertex_data, typename edge_weight>
		class oriented_mixed_weight_graph;
		template<typename vertex_data, typename edge_weight>
		class unoriented_weighted_graph;
		template<typename vertex_data>
		class unoriented_unweighted_graph;
		template<typename vertex_data, typename edge_weight>
		class unoriented_mixed_weight_graph;
		template<typename vertex_data, typename edge_weight>
		class mixed_orientation_weighted_graph;
		template<typename vertex_data>
		class mixed_orientation_unweighted_graph;
		template<typename vertex_data, typename edge_weight>
		class mixed_orientation_mixed_weight_graph;
	template<typename vertex_data = unsigned int>
	class abstract_graph {
		// ATTRIBUTES
			template <typename T = unsigned int>
			using abstract_link = std::pair<T, T>;
			// put in a particular header and transform it into a named tuple
			class abstract_vertex {
				vertex_data value;
				abstract_vertex();
				virtual void pureVirtual() = 0;
			};
			std::any container;
			static unsigned int instances;
		// MEMBERS
			// default constructor
				abstract_graph() = delete;
				abstract_graph(underlying_container container_type, uniqueness vertices_uniqueness) {
					if(container_type == LIST)
						container = (vertices_uniqueness == UNIQUE ? std::map<vertex_data, std::set<std::any>> : std::multimap<vertex_data, std::multiset<std::any>>);
					else {
						container = (vertices_uniqueness == UNIQUE ? : );
					}
					++instances;
				}
			// copy constructor
				abstract_graph(const abstract_graph& rhs) : container(rhs.container) {
					++instances;
				}
			// move constructor
				abstract_graph(abstract_graph&& rhs) noexcept : container(rhs.container) {
					rhs.container.reset();
					++instances;
				}
			// destructor
				~abstract_graph() noexcept {
					--instances;
				}
			// operators
				// arithmetic operators
					virtual abstract_graph& operator=(const abstract_graph& rhs) = 0;
					virtual abstract_graph* operator+(const abstract_vertex& rhs) = 0;		// add vertex
					virtual abstract_graph* operator-(const abstract_vertex& rhs) = 0;		// remove vertex if it exist
					virtual abstract_graph* operator+(const abstract_graph& rhs) = 0;		// add vertices and edges
					virtual abstract_graph* operator-(const abstract_graph& rhs) = 0;		// remove vertices and edges if they exist
					/* nonsenses
					virtual abstract_graph* operator+() = delete;
					virtual abstract_graph* operator-() = delete;
					virtual abstract_graph* operator*(const std::any& rhs) = delete;
					virtual abstract_graph* operator/(const std::any& rhs) = delete;
					virtual abstract_graph* operator%(const std::any& rhs) = delete;
					virtual abstract_graph& operator++() = delete;
					virtual abstract_graph* operator++(int) = delete;
					virtual abstract_graph& operator--() = delete;
					virtual abstract_graph* operator--(int) = delete;
					*/
				// bitwise operators
					virtual void operator~() = 0;											// invert links orientation in oriented graphs
					virtual void operator&(const abstract_graph& rhs) = 0;					// intersection
					virtual void operator|(const abstract_graph& rhs) = 0;					// union
					virtual void operator^(const abstract_graph& rhs) = 0;					// difference
					virtual void operator<<(const abstract_graph& rhs) = 0;					// output
					virtual void operator>>(const abstract_vertex& rhs) = 0;					// input
				// comparison/relational operators
					virtual bool operator==(const abstract_graph& rhs) = 0;					// compare vertices and edges
					virtual bool operator!=(const abstract_graph& rhs) = 0;					// compare vertices and edges
					virtual bool operator!=(const abstract_graph& rhs) const = 0;			// compare vertices and edges
					virtual bool operator>(const abstract_graph& rhs) const = 0;			// compare number of vertices
					virtual bool operator<(const abstract_graph& rhs) const = 0;			// compare number of vertices
					virtual bool operator>=(const abstract_graph& rhs) const = 0;			// compare number of vertices
					virtual bool operator<=(const abstract_graph& rhs) const = 0;			// compare number of vertices
					//virtual bool operator<=>(const abstract_graph& rhs) const = 0;		// compare number of vertices (not available yet) ( ͡° ͜ʖ ͡°)
				// compound assignment operators
					virtual abstract_graph& operator+=(const abstract_vertex& rhs) = 0;		// add vertex
					virtual abstract_graph& operator-=(const abstract_vertex& rhs) = 0;		// remove vertex if it exist
					virtual abstract_graph& operator+=(const abstract_graph& rhs) = 0;		// add vertices and edges
					virtual abstract_graph& operator-=(const abstract_graph& rhs) = 0;		// remove vertices and edges if they exist
					/* nonsenses
					virtual abstract_graph& operator*=(abstract_graph rhs) = delete;
					virtual abstract_graph& operator/=(abstract_graph rhs) = delete;
					virtual abstract_graph& operator%=(abstract_graph rhs) = delete;
					*/
					virtual abstract_graph& operator&=(const abstract_graph& rhs) = 0;		// intersection
					virtual abstract_graph& operator|=(const abstract_graph& rhs) = 0;		// union
					virtual abstract_graph& operator^=(const abstract_graph& rhs) = 0;		// difference
					virtual abstract_graph& operator<<=(const abstract_graph& rhs) = 0;		// output
					virtual abstract_graph& operator>>=(const abstract_graph& rhs) = 0;		// input
				// logical operators
					virtual bool operator!() = 0;											// check if empty
					virtual bool operator&&(const abstract_graph& rhs) = 0;					// check if the two graphs are not empty
					virtual bool operator||(const abstract_graph& rhs) = 0;					// check if one of the two graphs is not empty
				// member and pointer operators
					virtual abstract_vertex& operator[](unsigned int index) = 0;				// unsecure element access
					std::any& operator*() = delete;											// nonsense
					abstract_graph& operator&() = delete;									// possible optimization
					virtual std::any& operator->() = 0;										// access underlying container
					const void* operator->*(const abstract_graph& rhs) = delete;			// nonsense
				// other operators
					void operator()(std::any rhs, ...) = delete;							// could not find a good utility of this
					abstract_graph& operator,(const abstract_graph& rhs) = delete;			// nonsense
					//std::any operator"" _literal(abstract_graph) = delete;				// could not find a good utility of this + throw errors

					virtual explicit operator oriented_graph<std::any>() = 0;
					virtual explicit operator unoriented_graph<std::any>() = 0;
					virtual explicit operator mixed_orientation_graph<std::any>() = 0;

					virtual explicit operator weighted_graph<std::any, std::any>() = 0;
					virtual explicit operator unweighted_graph<std::any>() = 0;
					virtual explicit operator mixed_weight_graph<std::any, std::any>() = 0;

					virtual explicit operator oriented_weighted_graph<std::any, std::any>() = 0;
					virtual explicit operator oriented_unweighted_graph<std::any>() = 0;
					virtual explicit operator oriented_mixed_weight_graph<std::any, std::any>() = 0;
					virtual explicit operator unoriented_weighted_graph<std::any, std::any>() = 0;
					virtual explicit operator unoriented_unweighted_graph<std::any>() = 0;
					virtual explicit operator unoriented_mixed_weight_graph<std::any, std::any>() = 0;
					virtual explicit operator mixed_orientation_weighted_graph<std::any, std::any>() = 0;
					virtual explicit operator mixed_orientation_unweighted_graph<std::any>() = 0;
					virtual explicit operator mixed_orientation_mixed_weight_graph<std::any, std::any>() = 0;

					void* operator new(size_t x) = delete;									// possible optimization
					void* operator new[](size_t x) = delete;								// possible optimization
					void operator delete(void *a) = delete;									// possible optimization
					void operator delete[](void *a) = delete;								// possible optimization
			// move assignment operator
				virtual abstract_graph& operator=(abstract_graph&& other) noexcept = 0;
			// iterators
				virtual void begin() const noexcept = 0;
				virtual void cbegin() const noexcept = 0;
				virtual void end() const noexcept = 0;
				virtual void cend() const noexcept = 0;
				virtual void rbegin() const noexcept = 0;
				virtual void crbegin() const noexcept = 0;
				virtual void rend() const noexcept = 0;
				virtual void crend() const noexcept = 0;
			// element access
				virtual void at() = 0;
				// subscript operator already defined in members/operators/member_and_pointer_operators
				virtual void front() = 0;
				virtual void back() = 0;
			// capacity
				virtual void empty() = 0;
				virtual void size() = 0;
				virtual void max_size() = 0;
				virtual void resize() = 0;
				virtual void capacity() = 0;
				virtual void reserve() = 0;
				virtual void shrink_to_fit() = 0;
			// modifiers
				virtual void clear() = 0;
				virtual void insert() = 0;
				virtual void insert_or_assign() = 0;
				virtual void emplace() = 0;
				virtual void emplace_hint() = 0;
				virtual void try_emplace() = 0;
				virtual void erase() = 0;
				virtual void push_front() = 0;
				virtual void emplace_front() = 0;
				virtual void pop_front() = 0;
				virtual void push_back() = 0;
				virtual void emplace_back() = 0;
				virtual void pop_back() = 0;
				virtual void swap() = 0;
				virtual void merge() = 0;
				virtual void extract() = 0;
			// list operations
				virtual void splice() = 0;
				virtual void remove() = 0;
				virtual void remove_if() = 0;
				virtual void reverse() = 0;
				virtual void unique() = 0;
				virtual void sort() = 0;
			// lookup
				virtual void count() = 0;
				virtual void find() = 0;
				virtual void contains() = 0;
				virtual void lower_bound() = 0;
				virtual void upper_bound() = 0;
				virtual void equal_range() = 0;
			// observers
				virtual void key_comp() = 0;
				virtual void value_comp() = 0;
				virtual void hash_function() = 0;
				virtual void key_eq() = 0;
			// allocator
				virtual void get_allocator() = 0;
	};
	// abstract graph orientation
		template<typename vertex_data = unsigned int>
		class oriented_graph : public abstract_graph<vertex_data> {
			// ATTRIBUTES
			// MEMBERS
				public:
					oriented_graph() = delete;
					oriented_graph(underlying_container container_type, uniqueness vertices_uniqueness)
						: abstract_graph(container_type, vertices_uniqueness) {}
					~oriented_graph() {}
				private:
					virtual void pureVirtual() = 0;
		};
		template<typename vertex_data = unsigned int>
		class unoriented_graph : public abstract_graph<vertex_data> {
			// ATTRIBUTES
			// MEMBERS
				unoriented_graph();
				~unoriented_graph();
				virtual void pureVirtual() = 0;
		};
		template<typename vertex_data = unsigned int>
		class mixed_orientation_graph : public oriented_graph<vertex_data>, public unoriented_graph<vertex_data> {
			// ATTRIBUTES
			// MEMBERS
				mixed_orientation_graph();
				~mixed_orientation_graph();
				virtual void pureVirtual() = 0;
		};
	// abstract graph weight
		template<typename vertex_data = unsigned int, typename edge_weight = unsigned int>
		class weighted_graph : public abstract_graph<vertex_data> {
			// ATTRIBUTES
			// MEMBERS
				weighted_graph();
				~weighted_graph();
				virtual void pureVirtual() = 0;
		};
		template<typename vertex_data = unsigned int>
		class unweighted_graph : public abstract_graph<vertex_data> {
			// ATTRIBUTES
			// MEMBERS
				unweighted_graph();
				~unweighted_graph();
				virtual void pureVirtual() = 0;
		};
		template<typename vertex_data = unsigned int, typename edge_weight = unsigned int>
		class mixed_weight_graph : public weighted_graph<typename vertex_data, typename edge_weight>, public unweighted_graph<vertex_data> {
			// ATTRIBUTES
			// MEMBERS
				mixed_weight_graph();
				~mixed_weight_graph();
				virtual void pureVirtual() = 0;
		};
	// graph subtypes
		template<typename vertex_data = unsigned int, typename edge_weight = unsigned int>
		class oriented_weighted_graph : public oriented_graph<vertex_data>, public weighted_graph<vertex_data, edge_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					oriented_weighted_graph() {}
					~oriented_weighted_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename vertex_data = unsigned int>
		class oriented_unweighted_graph : public oriented_graph<vertex_data>, public unweighted_graph<vertex_data> {
			// ATTRIBUTES
			// MEMBERS
				public:
					oriented_unweighted_graph() {}
					~oriented_unweighted_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename vertex_data = unsigned int, typename edge_weight = unsigned int>
		class oriented_mixed_weight_graph : public oriented_graph<vertex_data>, public mixed_weight_graph<vertex_data, edge_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					oriented_mixed_weight_graph() {}
					~oriented_mixed_weight_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename vertex_data = unsigned int, typename edge_weight = unsigned int>
		class unoriented_weighted_graph : public unoriented_graph<vertex_data>, public weighted_graph<vertex_data, edge_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					unoriented_weighted_graph() {}
					~unoriented_weighted_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename vertex_data = unsigned int>
		class unoriented_unweighted_graph : public unoriented_graph<vertex_data>, public unweighted_graph<vertex_data> {
			// ATTRIBUTES
			// MEMBERS
				public:
					unoriented_unweighted_graph() {}
					~unoriented_unweighted_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename vertex_data = unsigned int, typename edge_weight = unsigned int>
		class unoriented_mixed_weight_graph : public unoriented_graph<vertex_data>, public mixed_weight_graph<vertex_data, edge_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					unoriented_mixed_weight_graph() {}
					~unoriented_mixed_weight_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename vertex_data = unsigned int, typename edge_weight = unsigned int>
		class mixed_orientation_weighted_graph : public mixed_orientation_graph<vertex_data>, public weighted_graph<vertex_data, edge_weight> {
			// ATTRIBUTES
			// MEMBERS
				public:
					mixed_orientation_weighted_graph() {}
					~mixed_orientation_weighted_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename vertex_data = unsigned int>
		class mixed_orientation_unweighted_graph : public mixed_orientation_graph<vertex_data>, public unweighted_graph<vertex_data> {
			// ATTRIBUTES
			// MEMBERS
				public:
					mixed_orientation_unweighted_graph() {}
					~mixed_orientation_unweighted_graph() noexcept {}
				private:
					void pureVirtual() {}
		};
		template<typename vertex_data = unsigned int, typename edge_weight = unsigned int>
		class mixed_orientation_mixed_weight_graph : public mixed_orientation_graph<vertex_data>, public mixed_weight_graph<vertex_data, edge_weight> {
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