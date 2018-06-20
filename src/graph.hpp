/**
* Graph Library
* Copyright (c) 2018, Antoine Sébert antoine.sb@orange.fr, All rights reserved.
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
#include <optional>
#include <set>
#include <utility>
#include <vector>
#include <typeinfo>

namespace graph {
	enum node_uniqueness {
		unique_nodes,
		not_unique_nodes
	};
	enum path_uniqueness {
		unique_paths,
		not_unique_paths
	};
	enum orientation {
		oriented,
		unoriented,
		mixed_orientation
	};
	enum weightness {
		weighted,
		unweighted,
		mixed_weightness
	};
	// node_uniqueness: unique
		// path_uniqueness: unique
			// orientation: oriented
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using NU_u_PU_u_oriented_weighted_graph = std::map<vertex_data, std::map<std::map<std::any, std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using NU_u_PU_u_oriented_unweighted_graph = std::map<vertex_data, std::set<std::map<std::any, std::any>::const_reference>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using NU_u_PU_u_oriented_mixed_weightness_graph = std::map<vertex_data, std::map<std::map<std::any, std::any>::const_reference, std::optional<edge_data>>>;
			// orientation: unoriented
				// weightness: weighted

				// weightness: unweighted

				// weightness: mixed

			// orientation: mixed
				// weightness: weighted

				// weightness: unweighted

				// weightness: mixed

		// path_uniqueness: not_unique
			// orientation: oriented
				// weightness: weighted

				// weightness: unweighted

				// weightness: mixed

			// orientation: unoriented
				// weightness: weighted

				// weightness: unweighted

				// weightness: mixed

			// orientation: mixed
				// weightness: weighted

				// weightness: unweighted

				// weightness: mixed

	// node_uniqueness: not_unique
		// path_uniqueness: unique
			// orientation: oriented
				// weightness: weighted

				// weightness: unweighted

				// weightness: mixed

			// orientation: unoriented
				// weightness: weighted

				// weightness: unweighted

				// weightness: mixed

			// orientation: mixed
				// weightness: weighted

				// weightness: unweighted

				// weightness: mixed

		// path_uniqueness: not_unique
			// orientation: oriented
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using NU_nu_PU_nu_oriented_weighted_graph = std::multimap<vertex_data, std::multimap<std::multimap<std::any, std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using NU_nu_PU_nu_oriented_unweighted_graph = std::multimap<vertex_data, std::multiset<std::multimap<std::any, std::any>::const_reference>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using NU_nu_PU_nu_oriented_mixed_weightness_graph = std::multimap<vertex_data, std::multimap<std::multimap<std::any, std::any>::const_reference, std::optional<edge_data>>>;
			// orientation: unoriented
				// weightness: weighted
					/*
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using NU_nu_PU_nu_unoriented_weighted_graph = std::multimap<vertex_data, std::multimap<std::multimap<std::any, std::any>::const_reference, edge_data>>;
					*/
				// weightness: unweighted

				// weightness: mixed

			// orientation: mixed
				// weightness: weighted

				// weightness: unweighted

				// weightness: mixed

	// node_uniqueness: not_unique, path_uniqueness: not_unique, weightess: weighted, orientation: oriented
	template<class vertex_data = unsigned int, class edge_data = unsigned int>
	using unique_oriented_weighted_graph = std::map<vertex_data, std::multimap<std::map<std::any, std::any>::const_reference, edge_data>>;
	/*
	template<class vertex_index = unsigned int>
	using unoriented_unweighted_graph = std::
*/
	//using unoriented_unweighted_graph = std::multiset<std::multiset<unoriented_unweighted_graph::const_iterator>>;

	template<class vertex_data = unsigned int, class edge_data = unsigned int>
	class abstract_graph {
		// ATTRIBUTES
			// emplacements non contigus en mémoire, itérateurs restent valides en insertion et en suppression
			NU_nu_PU_nu_oriented_weighted_graph<vertex_data, edge_data> container;
			static unsigned int instances;
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
							container.merge(rhs.container);
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
					virtual void operator~() = 0;														// invert links orientation in oriented graphs
					virtual void operator&(const abstract_graph& rhs) = 0;								// intersection
					virtual void operator|(const abstract_graph& rhs) = 0;								// union
					virtual void operator^(const abstract_graph& rhs) = 0;								// difference
				// comparison/relational operators
					// compare vertices and edges
						bool operator==(const abstract_graph& rhs) {
							// check if size of the containers is the same
							if(container.size() != rhs.container.size())
								return false;
							// check if number of keys is the same
							if(std::set<vertex_data> keys_set(container), keys_set_rhs(rhs.container);  keys_set.size() != keys_set_rhs.size())
								return false;
							// check if number of each key is the same
							for(const auto& element : keys_set) {
								if(container.count(element) != rhs.container.count(element))
									return false;
							}
							// iterate through edges
							auto it_rhs = rhs.container.begin();
							for(auto it = container.cbegin(); it != container.end(); ++it) {
								// check if size of the edges containers is the same
								if(it->second.size() != it_rhs->second.size())
									return false;


								// check if number of keys is the same
								if(std::set<vertex_data> keys_set(container), keys_set_rhs(rhs.container);  keys_set.size() != keys_set_rhs.size())
									return false;
								// check if number of each key is the same
								for(const auto& element : keys_set) {
									if(container.count(element) != rhs.container.count(element))
										return false;
								}

								// check if the weight is the same

								++it_rhs;
							}
							return true;
						}
					// compare vertices and edges
						bool operator!=(const abstract_graph& rhs) { return !(this == rhs); }
					// compare number of vertices
					virtual bool operator>(const abstract_graph& rhs) const { return container.size() > rhs.container.size(); }
					// compare number of vertices
					virtual bool operator<(const abstract_graph& rhs) const { return container.size() < rhs.container.size(); }
					// compare number of vertices
					virtual bool operator>=(const abstract_graph& rhs) const { return !(this < rhs); }
					// compare number of vertices
					virtual bool operator<=(const abstract_graph& rhs) const { return !(this > rhs); }
					// compare number of vertices
					//virtual bool operator<=>(const abstract_graph& rhs) const {}						// (C++20) ( ͡° ͜ʖ ͡°)
				// compound assignment operators
					virtual abstract_graph& operator+=(const abstract_graph& rhs) = 0;					// add vertices and edges
					virtual abstract_graph& operator-=(const abstract_graph& rhs) = 0;					// remove vertices and edges if they exist
					virtual abstract_graph& operator&=(const abstract_graph& rhs) = 0;					// intersection
					virtual abstract_graph& operator|=(const abstract_graph& rhs) = 0;					// union
					virtual abstract_graph& operator^=(const abstract_graph& rhs) = 0;					// difference
				// logical operators
					// check if empty
					bool operator!() { return container.empty(); }
					// check if the two graphs are not empty
					bool operator&&(const abstract_graph& rhs) { return !(container.empty() || rhs.container.empty()); }
					// check if one of the two graphs is not empty
					bool operator||(const abstract_graph& rhs) { return !(container.empty() && rhs.container.empty()); }
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
	};
}

#endif