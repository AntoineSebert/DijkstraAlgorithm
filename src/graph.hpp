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
	// data types are created at compile-time, so I have to hard code them

	// vertex_signifiance: significative
		// node_uniqueness: unique
			// path_uniqueness: unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_NU_u_PU_u_W_w_graph = std::map<vertex_data, std::map<std::map<std::any, std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_sNU_u_PU_u_W_uw_graph = std::map<vertex_data, std::set<std::map<std::any, std::any>::const_reference>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_sNU_u_PU_u_W_mw_graph = std::map<vertex_data, std::map<std::map<std::any, std::any>::const_reference, std::optional<edge_data>>>;
			// path_uniqueness: not_unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_NU_u_PU_nu_W_w_graph = std::map<vertex_data, std::multimap<std::map<std::any, std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_s_NU_u_PU_nu_W_uw_graph = std::map<vertex_data, std::multiset<std::map<std::any, std::any>::const_reference>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_NU_u_PU_nu_W_mw_graph = std::map<vertex_data, std::multimap<std::map<std::any, std::any>::const_reference, std::optional<edge_data>>>;
		// node_uniqueness: not_unique
			// path_uniqueness: unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_NU_nu_PU_u_W_w_graph = std::multimap<vertex_data, std::map<std::multimap<std::any, std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_s_NU_nu_PU_u_W_uw_graph = std::multimap<vertex_data, std::set<std::multimap<std::any, std::any>::const_reference>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_NU_nu_PU_u_W_mw_graph = std::multimap<vertex_data, std::map<std::multimap<std::any, std::any>::const_reference, std::optional<edge_data>>>;
			// path_uniqueness: not_unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_NU_nu_PU_nu_W_w_graph = std::multimap<vertex_data, std::multimap<std::multimap<std::any, std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_s_NU_nu_PU_nu_W_uw_graph = std::multimap<vertex_data, std::multiset<std::multimap<std::any, std::any>::const_reference>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_NU_nu_PU_nu_W_mw_graph = std::multimap<vertex_data, std::multimap<std::multimap<std::any, std::any>::const_reference, std::optional<edge_data>>>;
	// vertex_signifiance: not_significative
		// node_uniqueness: unique
			// path_uniqueness: unique
				// weightness: weighted
					template<class edge_data = unsigned int>
					using VS_ns_NU_u_PU_u_W_w_graph = std::set<std::map<std::set<std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					using VS_ns_NU_u_PU_u_W_uw_graph = std::set<std::set<std::set<std::any>::const_reference>>;
				// weightness: mixed
					template<class edge_data = unsigned int>
					using VS_ns_NU_u_PU_u_W_mw_graph = std::set<std::map<std::set<std::any>::const_reference, std::optional<edge_data>>>;
			// path_uniqueness: not_unique
				// weightness: weighted
					template<class edge_data = unsigned int>
					using VS_ns_NU_u_PU_nu_W_w_graph = std::set<std::multimap<std::set<std::any>::const_reference, edge_data>>;
					// weightness: unweighted
					using VS_ns_NU_u_PU_nu_W_uw_graph = std::set<std::multiset<std::set<std::any>::const_reference>>;
					// weightness: mixed
					template<class edge_data = unsigned int>
					using VS_ns_NU_u_PU_nu_W_mw_graph = std::set<std::multimap<std::set<std::any>::const_reference, std::optional<edge_data>>>;
		// node_uniqueness: not_unique (if all the nodes are indexed based on their position in the container, is this part really necessary ?)
			// path_uniqueness: unique
				// weightness: weighted
					template<class edge_data = unsigned int>
					using VS_ns_NU_nu_PU_u_W_w_graph = std::multiset<std::map<std::multiset<std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					using VS_ns_NU_nu_PU_u_W_uw_graph = std::multiset<std::set<std::multiset<std::any>::const_reference>>;
				// weightness: mixed
					template<class edge_data = unsigned int>
					using VS_ns_NU_nu_PU_u_W_mw_graph = std::multiset<std::map<std::multiset<std::any>::const_reference, std::optional<edge_data>>>;
			// path_uniqueness: not_unique
				// weightness: weighted
					template<class edge_data = unsigned int>
					using VS_ns_NU_nu_PU_nu_W_w_graph = std::multiset<std::multimap<std::multiset<std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					using VS_ns_NU_nu_PU_nu_W_uw_graph = std::multiset<std::multiset<std::multiset<std::any>::const_reference>>;
				// weightness: mixed
					template<class edge_data = unsigned int>
					using VS_ns_NU_nu_PU_nu_W_mw_graph = std::multiset<std::multimap<std::multiset<std::any>::const_reference, std::optional<edge_data>>>;
	// vertex_signifiance: mixed_signifiance
		// node_uniqueness: unique
			// path_uniqueness: unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_NU_u_PU_u_W_w_graph = std::map<std::optional<vertex_data>, std::map<std::map<std::any, std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_ms_NU_u_PU_u_W_uw_graph = std::map<std::optional<vertex_data>, std::set<std::map<std::any, std::any>::const_reference>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_NU_u_PU_u_W_mw_graph = std::map<std::optional<vertex_data>, std::map<std::map<std::any, std::any>::const_reference, std::optional<edge_data>>>;
			// path_uniqueness: not_unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_NU_u_PU_nu_W_w_graph = std::map<std::optional<vertex_data>, std::multimap<std::map<std::any, std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_ms_NU_u_PU_nu_W_uw_graph = std::map<std::optional<vertex_data>, std::multiset<std::map<std::any, std::any>::const_reference>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_NU_u_PU_nu_W_mw_graph = std::map<std::optional<vertex_data>, std::multimap<std::map<std::any, std::any>::const_reference, std::optional<edge_data>>>;
		// node_uniqueness: not_unique
			// path_uniqueness: unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_NU_nu_PU_u_W_w_graph = std::multimap<std::optional<vertex_data>, std::map<std::multimap<std::any, std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_ms_NU_nu_PU_u_W_uw_graph = std::multimap<std::optional<vertex_data>, std::set<std::multimap<std::any, std::any>::const_reference>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_NU_nu_PU_u_W_mw_graph = std::multimap<std::optional<vertex_data>, std::map<std::multimap<std::any, std::any>::const_reference, std::optional<edge_data>>>;
			// path_uniqueness: not_unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_NU_nu_PU_nu_W_w_graph = std::multimap<std::optional<vertex_data>, std::multimap<std::multimap<std::any, std::any>::const_reference, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_ms_NU_nu_PU_nu_W_uw_graph = std::multimap<std::optional<vertex_data>, std::multiset<std::multimap<std::any, std::any>::const_reference>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_NU_nu_PU_nu_W_mw_graph = std::multimap<std::optional<vertex_data>, std::multimap<std::multimap<std::any, std::any>::const_reference, std::optional<edge_data>>>;
	enum vertex_uniqueness {
		unique_vertices,
		not_unique_vertices
	};
	enum vertex_signifiance {
		significative,
		not_significative,
		mixed_signifiance
	};
	enum edge_uniqueness {
		unique_edges,
		not_unique_edges
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
	// using sets, maps, multisets, multimaps: emplacements non contigus en mémoire, itérateurs restent valides en insertion et en suppression
	template<class vertex_data = unsigned int, class edge_data = unsigned int>
	class abstract_graph {
		// ATTRIBUTES
			private:
				std::any container;
				static unsigned int instances;
		// MEMBERS
			public:
				// default constructor
					abstract_graph(
						vertex_uniqueness v_u = unique_vertices, vertex_signifiance v_s = not_significative,
						edge_uniqueness e_u = unique_edges, orientation o = unoriented, weightness w = unweighted) {

						++instances;

					}
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
						// invert links orientation in oriented graphs
							abstract_graph* operator~() { return *this; }
						// intersection
							void operator&(const abstract_graph& rhs) {}
						// union
							void operator|(const abstract_graph& rhs) {}
						// difference
							void operator^(const abstract_graph& rhs) {}
					// comparison/relational operators
						// compare vertices and edges
							bool operator==(const abstract_graph& rhs) {
								// check if size of the containers
								if(container.size() != rhs.container.size())
									return false;
								// check if number of keys
								if(std::set<vertex_data> keys_set(container), keys_set_rhs(rhs.container);  keys_set.size() != keys_set_rhs.size())
									return false;
								// check if number of each key
								for(const auto& element : keys_set) {
									if(container.count(element) != rhs.container.count(element))
										return false;
								}
								// iterate through vertices
								auto it_rhs = rhs.container.begin();
								for(auto it = container.cbegin(); it != container.end(); ++it) {
									// check if size of the edges containers
									if(it->second.size() != it_rhs->second.size())
										return false;
									// check if number of keys
									if(std::set<vertex_data> keys_set(container), keys_set_rhs(rhs.container);  keys_set.size() != keys_set_rhs.size())
										return false;
									// check if number of each key
									for(const auto& element : keys_set) {
										if(container.count(element) != rhs.container.count(element))
											return false;
									}
									// iterate through edges
									auto it2_rhs = it_rhs->second.begin();
									for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
										// check if the weight exists
										if(it2->second xor it2_rhs->second)
											return false;
										// check if the weight is the same
										if(it2->second != it2_rhs->second)
											return false;
										++it2_rhs;
									}

									++it_rhs;
								}
								return true;
							}
						// compare vertices and edges
							bool operator!=(const abstract_graph& rhs) { return !(this == rhs); }
						// compare number of vertices
							bool operator>(const abstract_graph& rhs) const { return container.size() > rhs.container.size(); }
						// compare number of vertices
							bool operator<(const abstract_graph& rhs) const { return container.size() < rhs.container.size(); }
						// compare number of vertices
							bool operator>=(const abstract_graph& rhs) const { return !(this < rhs); }
						// compare number of vertices
							bool operator<=(const abstract_graph& rhs) const { return !(this > rhs); }
						// compare number of vertices ( ͡° ͜ʖ ͡°) (C++20)
							//bool operator<=>(const abstract_graph& rhs) const {}
					// compound assignment operators
						// add vertices and edges
							abstract_graph& operator+=(const abstract_graph& rhs) = 0;
						// remove vertices and edges if they exist
							abstract_graph& operator-=(const abstract_graph& rhs) = 0;
						// intersection
							abstract_graph& operator&=(const abstract_graph& rhs) = 0;
						// union
							abstract_graph& operator|=(const abstract_graph& rhs) = 0;
						// difference
							abstract_graph& operator^=(const abstract_graph& rhs) = 0;
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