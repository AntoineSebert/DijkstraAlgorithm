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
#include <typeinfo>
#include <vector>

namespace graph {
	template<class vertex_data, class edge_data>
	class abstract_graph {
		// ATTRIBUTES
			std::map<vertex_data, std::set<std::pair<std::map::const_iterator, edge_data>>> container;
			static unsigned int instances;
			typename vertex_data_type = decltype(vertex_data), edge_data_type = decltype(edge_data);
		// MEMBERS
			// default constructor
				abstract_graph() { ++instances; }
			// copy constructor
				abstract_graph(const abstract_graph& rhs) : container(rhs.container) { ++instances; }
			// move constructor
				abstract_graph(abstract_graph&& rhs) noexcept { container = std::move(other.container); }
			// destructor
				~abstract_graph() noexcept { --instances; }
			// operators
				// arithmetic operators
					// basic assignation
						abstract_graph& operator=(const abstract_graph& rhs) { container = rhs.container; }
					// move assignment operator
						abstract_graph& operator=(abstract_graph&& other) noexcept {
							container = std::move(other.container);
							return *this;
						}
					// add vertices and edges
						abstract_graph* operator+(const abstract_graph& rhs) {
							container.insert(rhs.container.begin(), rhs.container.end());
							// check the edges
							return *this;
						}
					// remove vertices and edges if they exist
						abstract_graph* operator-(const abstract_graph& rhs) {
							for(vertex_data element : rhs.container)
								container.erase(element);
							// check the edges
							return *this;
						}
				// bitwise operators
					virtual void operator~() = 0;												// invert links orientation in oriented graphs
					virtual void operator&(const abstract_graph& rhs) = 0;						// intersection
					virtual void operator|(const abstract_graph& rhs) = 0;						// union
					virtual void operator^(const abstract_graph& rhs) = 0;						// difference
					virtual void operator<<(const abstract_graph& rhs) = 0;						// output
					virtual void operator>>(const vertex_data& rhs) = 0;						// input
				// comparison/relational operators
					virtual bool operator==(const abstract_graph& rhs) = 0;						// compare vertices and edges
					virtual bool operator!=(const abstract_graph& rhs) = 0;						// compare vertices and edges
					virtual bool operator!=(const abstract_graph& rhs) const = 0;				// compare vertices and edges
					// compare number of vertices
					virtual bool operator>(const abstract_graph& rhs) const { return container.size() > rhs.container.size(); }
					// compare number of vertices
					virtual bool operator<(const abstract_graph& rhs) const { return container.size() < rhs.container.size(); }
					// compare number of vertices
					virtual bool operator>=(const abstract_graph& rhs) const { return !(this < rhs); }
					// compare number of vertices
					virtual bool operator<=(const abstract_graph& rhs) const { return !(this > rhs); }
					// compare number of vertices
					//virtual bool operator<=>(const abstract_graph& rhs) const {}				// (C++20) ( ͡° ͜ʖ ͡°)
				// compound assignment operators
					virtual abstract_graph& operator+=(const abstract_graph& rhs) = 0;			// add vertices and edges
					virtual abstract_graph& operator-=(const abstract_graph& rhs) = 0;			// remove vertices and edges if they exist
					virtual abstract_graph& operator&=(const abstract_graph& rhs) = 0;			// intersection
					virtual abstract_graph& operator|=(const abstract_graph& rhs) = 0;			// union
					virtual abstract_graph& operator^=(const abstract_graph& rhs) = 0;			// difference
				// logical operators
					virtual bool operator!() = 0;												// check if empty
					virtual bool operator&&(const abstract_graph& rhs) = 0;						// check if the two graphs are not empty
					virtual bool operator||(const abstract_graph& rhs) = 0;						// check if one of the two graphs is not empty
				// member and pointer operators
					virtual vertex_data& operator[](unsigned int index) = 0;					// unsecure element access
					std::any& operator*() = delete;												// nonsense
					abstract_graph& operator&() = delete;										// possible optimization
					virtual std::any& operator->() = 0;											// access underlying container
					const void* operator->*(const abstract_graph& rhs) = delete;				// nonsense
				// other operators
					void operator()(std::any rhs, ...) = delete;								// could not find a good utility of this
					abstract_graph& operator,(const abstract_graph& rhs) = delete;				// nonsense
					//std::any operator"" _literal(abstract_graph) = delete;					// could not find a good utility of this + throw errors

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
			/*
			The basic operations provided by a graph data structure G usually include:
				adjacent(x, y): tests whether there is an edge from the vertex x to the vertex y;
				neighbors(x): lists all vertices y such that there is an edge from the vertex x to the vertex y;
				add_vertex(x): adds the vertex x, if it is not there;
				remove_vertex(x): removes the vertex x, if it is there;
				add_edge(x, y): adds the edge from the vertex x to the vertex y, if it is not there;
				remove_edge(x, y): removes the edge from the vertex x to the vertex y, if it is there;
				get_vertex_value(x): returns the value associated with the vertex x;
				set_vertex_value(x, v): sets the value associated with the vertex x to v.

			Structures that associate values to the edges usually also provide:
				get_edge_value(x, y): returns the value associated with the edge (x, y);
				set_edge_value(x, y, v): sets the value associated with the edge (x, y) to v.
			*/
			// iterators
				auto begin() const noexcept { return container.begin(); }
				auto cbegin() const noexcept { return container.cbegin();  }
				auto end() const noexcept { return container.end();  }
				auto cend() const noexcept { return container.cend(); }
				auto rbegin() const noexcept { return container.rbegin(); }
				auto crbegin() const noexcept { return container.crbegin(); }
				auto rend() const noexcept { return container.rend(); }
				auto crend() const noexcept { return container.crend(); }
			// element access
				const vertex_data& at(const vertex_data& key) const {
					try {
						return container.at(key);
					}
					catch(std::out_of_range e) {
						e.what();
					}
					return nullptr;
				}
				// subscript operator already defined in members/operators/member_and_pointer_operators
			// capacity
				auto empty() { return container.empty(); }
				auto size() { return container.size(); }
				auto max_size() { return container.max_size(); }
			/*
			// modifiers
				virtual void clear() = 0;
				virtual void insert() = 0;
				virtual void insert_or_assign() = 0;
				virtual void emplace() = 0;
				virtual void emplace_hint() = 0;
				virtual void try_emplace() = 0;
				virtual void erase() = 0;
				virtual void swap() = 0;
				virtual void merge() = 0;
				virtual void extract() = 0;
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
			*/
	};
}

#endif