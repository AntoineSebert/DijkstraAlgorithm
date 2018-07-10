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
#include <exception>
#include <iostream>
#include <list>
#include <map>
#include <optional>
#include <set>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

#define DEBUG(message) std::cout << message << std::endl;

namespace graph {
	// data types are created at compile-time, so I have to hard code them
	// vertex_signifiance: significative
		// vertex_uniqueness: unique
			// edges_uniqueness: unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_VU_u_EU_u_W_w_graph = std::map<vertex_data, std::map<std::map<std::any, std::any>::const_pointer, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_s_VU_u_EU_u_W_uw_graph = std::map<vertex_data, std::set<std::map<std::any, std::any>::const_pointer>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_VU_u_EU_u_W_mw_graph = std::map<vertex_data, std::map<std::map<std::any, std::any>::const_pointer, std::optional<edge_data>>>;
			// edges_uniqueness: not_unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_VU_u_EU_nu_W_w_graph = std::map<vertex_data, std::multimap<std::map<std::any, std::any>::const_pointer, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_s_VU_u_EU_nu_W_uw_graph = std::map<vertex_data, std::multiset<std::map<std::any, std::any>::const_pointer>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_VU_u_EU_nu_W_mw_graph = std::map<vertex_data, std::multimap<std::map<std::any, std::any>::const_pointer, std::optional<edge_data>>>;
		// vertex_uniqueness: not_unique
			// edges_uniqueness: unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_VU_nu_EU_u_W_w_graph = std::multimap<vertex_data, std::map<std::multimap<std::any, std::any>::const_pointer, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_s_VU_nu_EU_u_W_uw_graph = std::multimap<vertex_data, std::set<std::multimap<std::any, std::any>::const_pointer>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_VU_nu_EU_u_W_mw_graph = std::multimap<vertex_data, std::map<std::multimap<std::any, std::any>::const_pointer, std::optional<edge_data>>>;
			// edges_uniqueness: not_unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_VU_nu_EU_nu_W_w_graph = std::multimap<vertex_data, std::multimap<std::multimap<std::any, std::any>::const_pointer, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_s_VU_nu_EU_nu_W_uw_graph = std::multimap<vertex_data, std::multiset<std::multimap<std::any, std::any>::const_pointer>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_s_VU_nu_EU_nu_W_mw_graph = std::multimap<vertex_data, std::multimap<std::multimap<std::any, std::any>::const_pointer, std::optional<edge_data>>>;
	// vertex_signifiance: not_significative
		// vertex_uniqueness: unique
			// edges_uniqueness: unique
				// weightness: weighted
					template<class edge_data = unsigned int>
					using VS_ns_VU_u_EU_u_W_w_graph = std::set<std::map<std::set<std::any>::const_pointer, edge_data>>;
				// weightness: unweighted
					using VS_ns_VU_u_EU_u_W_uw_graph = std::set<std::set<std::set<std::any>::const_pointer>>;
				// weightness: mixed
					template<class edge_data = unsigned int>
					using VS_ns_VU_u_EU_u_W_mw_graph = std::set<std::map<std::set<std::any>::const_pointer, std::optional<edge_data>>>;
			// edges_uniqueness: not_unique
				// weightness: weighted
					template<class edge_data = unsigned int>
					using VS_ns_VU_u_EU_nu_W_w_graph = std::set<std::multimap<std::set<std::any>::const_pointer, edge_data>>;
					// weightness: unweighted
					using VS_ns_VU_u_EU_nu_W_uw_graph = std::set<std::multiset<std::set<std::any>::const_pointer>>;
					// weightness: mixed
					template<class edge_data = unsigned int>
					using VS_ns_VU_u_EU_nu_W_mw_graph = std::set<std::multimap<std::set<std::any>::const_pointer, std::optional<edge_data>>>;
		// vertex_uniqueness: not_unique (if all the nodes are indexed based on their position in the container, is this part really necessary ?)
			// edges_uniqueness: unique
				// weightness: weighted
					template<class edge_data = unsigned int>
					using VS_ns_VU_nu_EU_u_W_w_graph = std::multiset<std::map<std::multiset<std::any>::const_pointer, edge_data>>;
				// weightness: unweighted
					using VS_ns_VU_nu_EU_u_W_uw_graph = std::multiset<std::set<std::multiset<std::any>::const_pointer>>;
				// weightness: mixed
					template<class edge_data = unsigned int>
					using VS_ns_VU_nu_EU_u_W_mw_graph = std::multiset<std::map<std::multiset<std::any>::const_pointer, std::optional<edge_data>>>;
			// edges_uniqueness: not_unique
				// weightness: weighted
					template<class edge_data = unsigned int>
					using VS_ns_VU_nu_EU_nu_W_w_graph = std::multiset<std::multimap<std::multiset<std::any>::const_pointer, edge_data>>;
				// weightness: unweighted
					using VS_ns_VU_nu_EU_nu_W_uw_graph = std::multiset<std::multiset<std::multiset<std::any>::const_pointer>>;
				// weightness: mixed
					template<class edge_data = unsigned int>
					using VS_ns_VU_nu_EU_nu_W_mw_graph = std::multiset<std::multimap<std::multiset<std::any>::const_pointer, std::optional<edge_data>>>;
	// vertex_signifiance: mixed_signifiance
		// vertex_uniqueness: unique
			// edges_uniqueness: unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_VU_u_EU_u_W_w_graph = std::map<std::optional<vertex_data>, std::map<std::map<std::any, std::any>::const_pointer, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_ms_VU_u_EU_u_W_uw_graph = std::map<std::optional<vertex_data>, std::set<std::map<std::any, std::any>::const_pointer>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_VU_u_EU_u_W_mw_graph = std::map<std::optional<vertex_data>, std::map<std::map<std::any, std::any>::const_pointer, std::optional<edge_data>>>;
			// edges_uniqueness: not_unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_VU_u_EU_nu_W_w_graph = std::map<std::optional<vertex_data>, std::multimap<std::map<std::any, std::any>::const_pointer, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_ms_VU_u_EU_nu_W_uw_graph = std::map<std::optional<vertex_data>, std::multiset<std::map<std::any, std::any>::const_pointer>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_VU_u_EU_nu_W_mw_graph = std::map<std::optional<vertex_data>, std::multimap<std::map<std::any, std::any>::const_pointer, std::optional<edge_data>>>;
		// vertex_uniqueness: not_unique
			// edges_uniqueness: unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_VU_nu_EU_u_W_w_graph = std::multimap<std::optional<vertex_data>, std::map<std::multimap<std::any, std::any>::const_pointer, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_ms_VU_nu_EU_u_W_uw_graph = std::multimap<std::optional<vertex_data>, std::set<std::multimap<std::any, std::any>::const_pointer>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_VU_nu_EU_u_W_mw_graph = std::multimap<std::optional<vertex_data>, std::map<std::multimap<std::any, std::any>::const_pointer, std::optional<edge_data>>>;
			// edges_uniqueness: not_unique
				// weightness: weighted
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_VU_nu_EU_nu_W_w_graph = std::multimap<std::optional<vertex_data>, std::multimap<std::multimap<std::any, std::any>::const_pointer, edge_data>>;
				// weightness: unweighted
					template<class vertex_data = unsigned int>
					using VS_ms_VU_nu_EU_nu_W_uw_graph = std::multimap<std::optional<vertex_data>, std::multiset<std::multimap<std::any, std::any>::const_pointer>>;
				// weightness: mixed
					template<class vertex_data = unsigned int, class edge_data = unsigned int>
					using VS_ms_VU_nu_EU_nu_W_mw_graph = std::multimap<std::optional<vertex_data>, std::multimap<std::multimap<std::any, std::any>::const_pointer, std::optional<edge_data>>>;
	enum vertex_uniqueness : unsigned int {
		unique_vertices,
		not_unique_vertices
	};
	enum vertex_signifiance : unsigned int {
		significative,
		not_significative,
		mixed_signifiance
	};
	enum edge_uniqueness : unsigned int {
		unique_edges,
		not_unique_edges
	};
	enum orientation : unsigned int {
		oriented,
		unoriented,
		mixed_orientation
	};
	enum weightness : unsigned int {
		weighted,
		unweighted,
		mixed_weightness
	};
	class graph_incompatibility : public std::exception {
		private:
			std::string message = "The graphs do not have the same properties";
		public:
			graph_incompatibility(
				const std::map<std::string, unsigned int>& properties_1 = std::map<std::string, unsigned int>(),
				const std::map<std::string, unsigned int>& properties_2 = std::map<std::string, unsigned int>()) {

				if(!properties_1.empty() && !properties_2.empty()) {
					message += ": ";
					for(const auto[key, value] : properties_1) {
						if(value != properties_2.at(key))
							message += (key + " ");
					}
					message += "are different";
				}
			}
			virtual const char* what() const throw() { return message.c_str(); }
	};
	// using sets, maps, multisets, multimaps: emplacements non contigus en mémoire, itérateurs restent valides en insertion et en suppression
	template<class vertex_data = unsigned int, class edge_data = unsigned int>
	class abstract_graph {
		// ATTRIBUTES
			private:
				std::any container;
				/* static */ unsigned int instances;
				std::map<std::string, unsigned int> properties;
		// MEMBERS
			public:
				// default constructor
					abstract_graph(
						vertex_signifiance v_s = not_significative, vertex_uniqueness v_u = unique_vertices,
						edge_uniqueness e_u = unique_edges, weightness w = unweighted, orientation o = unoriented) {

						properties = {
							{ "vertex_signifiance", v_s },
							{ "vertex_uniqueness", v_u },
							{ "edge_uniqueness", e_u },
							{ "weightness", w },
							{ "orientation", o }
						};

						switch(v_s) {
							case significative:
								if(v_u == unique_vertices) {
									if(e_u == unique_edges) {
										switch(w) {
											case weighted:
												container = VS_s_VU_u_EU_u_W_w_graph<vertex_data, edge_data>();
												break;
											case unweighted:
												container = VS_s_VU_u_EU_u_W_uw_graph<vertex_data>();
												break;
											case mixed_weightness:
												container = VS_s_VU_u_EU_u_W_mw_graph<vertex_data, edge_data>();
												break;
										}
									}
									else {
										switch(w) {
											case weighted:
												container = VS_s_VU_u_EU_nu_W_w_graph<vertex_data, edge_data>();
												break;
											case unweighted:
												container = VS_s_VU_u_EU_nu_W_uw_graph<vertex_data>();
												break;
											case mixed_weightness:
												container = VS_s_VU_u_EU_nu_W_mw_graph<vertex_data, edge_data>();
												break;
										}
									}
								}
								else {
									if(e_u == unique_edges) {
										switch(w) {
											case weighted:
												container = VS_s_VU_nu_EU_u_W_w_graph<vertex_data, edge_data>();
												break;
											case unweighted:
												container = VS_s_VU_nu_EU_u_W_uw_graph<vertex_data>();
												break;
											case mixed_weightness:
												container = VS_s_VU_nu_EU_u_W_mw_graph<vertex_data, edge_data>();
												break;
										}
									}
									else {
										switch(w) {
											case weighted:
												container = VS_s_VU_nu_EU_nu_W_w_graph<vertex_data, edge_data>();
												break;
											case unweighted:
												container = VS_s_VU_nu_EU_nu_W_uw_graph<vertex_data>();
												break;
											case mixed_weightness:
												container = VS_s_VU_nu_EU_nu_W_mw_graph<vertex_data, edge_data>();
												break;
										}
									}
								}
								break;
							case not_significative:
								if(v_u == unique_vertices) {
									if(e_u == unique_edges) {
										switch(w) {
											case weighted:
												container = VS_ns_VU_u_EU_u_W_w_graph<edge_data>();
												break;
											case unweighted:
												container = VS_ns_VU_u_EU_u_W_uw_graph();
												break;
											case mixed_weightness:
												container = VS_ns_VU_u_EU_u_W_mw_graph<edge_data>();
												break;
										}
									}
									else {
										switch(w) {
											case weighted:
												container = VS_ns_VU_u_EU_nu_W_w_graph<edge_data>();
												break;
											case unweighted:
												container = VS_ns_VU_u_EU_nu_W_uw_graph();
												break;
											case mixed_weightness:
												container = VS_ns_VU_u_EU_nu_W_mw_graph<edge_data>();
												break;
										}
									}
								}
								else {
									if(e_u == unique_edges) {
										switch(w) {
											case weighted:
												container = VS_ns_VU_nu_EU_u_W_w_graph<edge_data>();
												break;
											case unweighted:
												container = VS_ns_VU_nu_EU_u_W_uw_graph();
												break;
											case mixed_weightness:
												container = VS_ns_VU_nu_EU_u_W_mw_graph<edge_data>();
												break;
										}
									}
									else {
										switch(w) {
											case weighted:
												container = VS_ns_VU_nu_EU_nu_W_w_graph<edge_data>();
												break;
											case unweighted:
												container = VS_ns_VU_nu_EU_nu_W_uw_graph();
												break;
											case mixed_weightness:
												container = VS_ns_VU_nu_EU_nu_W_mw_graph<edge_data>();
												break;
										}
									}
								}
								break;
							case mixed_signifiance:
								if(v_u == unique_vertices) {
									if(e_u == unique_edges) {
										switch(w) {
											case weighted:
												container = VS_ms_VU_u_EU_u_W_w_graph<vertex_data, edge_data>();
												break;
											case unweighted:
												container = VS_ms_VU_u_EU_u_W_uw_graph<vertex_data>();
												break;
											case mixed_weightness:
												container = VS_ms_VU_u_EU_u_W_mw_graph<vertex_data, edge_data>();
												break;
										}
									}
									else {
										switch(w) {
											case weighted:
												container = VS_ms_VU_u_EU_nu_W_w_graph<vertex_data, edge_data>();
												break;
											case unweighted:
												container = VS_ms_VU_u_EU_nu_W_uw_graph<vertex_data>();
												break;
											case mixed_weightness:
												container = VS_ms_VU_u_EU_nu_W_mw_graph<vertex_data, edge_data>();
												break;
										}
									}
								}
								else {
									if(e_u == unique_edges) {
										switch(w) {
											case weighted:
												container = VS_ms_VU_nu_EU_u_W_w_graph<vertex_data, edge_data>();
												break;
											case unweighted:
												container = VS_ms_VU_nu_EU_u_W_uw_graph<vertex_data>();
												break;
											case mixed_weightness:
												container = VS_ms_VU_nu_EU_u_W_mw_graph<vertex_data, edge_data>();
												break;
										}
									}
									else {
										switch(w) {
											case weighted:
												container = VS_ms_VU_nu_EU_nu_W_w_graph<vertex_data, edge_data>();
												break;
											case unweighted:
												container = VS_ms_VU_nu_EU_nu_W_uw_graph<vertex_data>();
												break;
											case mixed_weightness:
												container = VS_ms_VU_nu_EU_nu_W_mw_graph<vertex_data, edge_data>();
												break;
										}
									}
								}
								break;
						}

						++instances;
					}
				// copy constructor
					abstract_graph(const abstract_graph& rhs) : container(rhs.container), properties(rhs.properties) { ++instances; }
				// move constructor
					abstract_graph(abstract_graph&& rhs) noexcept {
						container = std::move(rhs.container);
						properties = std::move(rhs.properties);
					}
				// destructor
					~abstract_graph() noexcept { --instances; }
				// operators
					// arithmetic operators
						// basic assignation
							abstract_graph& operator=(const abstract_graph& rhs) {
								container = rhs.container;
								properties = rhs.properties;
								return &this;
							}
						// move assignment operator
							abstract_graph& operator=(abstract_graph&& other) noexcept {
								container = std::move(other.container);
								properties = std::move(rhs.properties);
								return *this;
							}
						// add vertices and edges
							abstract_graph operator+(const abstract_graph& rhs) {
								if(!isCompatible(rhs)) {
									try {
										throw graph_incompatibility(properties, rhs.properties);
									}
									catch(std::exception& e) {
										std::cout << e.what() << std::endl;
									}
								}
								
								auto data = casted_container();
								DEBUG(data);
								//casted_container.merge(rhs.casted_container());
								// check stuff

								return *this;
							}
						// remove vertices and edges if they exist
							abstract_graph* operator-(const abstract_graph& rhs) {
								if(!isCompatible(rhs))
									throw graph_incompatibility(properties, rhs.properties);
								for(vertex_data element : rhs.container)
									container.erase(element);
								// check the edges


								return this;
							}
					// bitwise operators
						// invert links orientation in oriented graphs
							abstract_graph* operator~() {
								if(properties.at("orientation") == oriented) {

								}
								return this;
							}
						// intersection
							void operator&(const abstract_graph& rhs) {}
						// union
							void operator|(const abstract_graph& rhs) {}
						// difference
							void operator^(const abstract_graph& rhs) {}
					// comparison/relational operators
						// compare vertices and edges
							bool operator==(const abstract_graph& rhs) {

								// check properties
								try {
									if(!std::equal(properties.cbegin(), properties.cend(), rhs.properties.cbegin()))
										return false;
								}
								catch(std::bad_alloc e) {
									e.what();
								}

								// maybe replace all the code below
								/*
								try {
								if(!std::equal(container.cbegin(), container.cend(), rhs.container.cbegin()))
								return false;
								}
								catch(std::bad_alloc e) {
								e.what();
								}
								*/

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
							inline bool operator!=(const abstract_graph& rhs) { return !(this == rhs); }
						// compare number of vertices
							inline bool operator>(const abstract_graph& rhs) const { return container.size() > rhs.container.size(); }
						// compare number of vertices
							inline bool operator<(const abstract_graph& rhs) const { return container.size() < rhs.container.size(); }
						// compare number of vertices
							inline bool operator>=(const abstract_graph& rhs) const { return !(this < rhs); }
						// compare number of vertices
							inline bool operator<=(const abstract_graph& rhs) const { return !(this > rhs); }
						// compare number of vertices ( ͡° ͜ʖ ͡°) (C++20)
							//bool operator<=>(const abstract_graph& rhs) const {}
					// compound assignment operators
						// add vertices and edges
							inline abstract_graph& operator+=(const abstract_graph& rhs) { return this + rhs; }
						// remove vertices and edges if they exist
							inline abstract_graph& operator-=(const abstract_graph& rhs) { return this - rhs; }
						// intersection
							inline abstract_graph& operator&=(const abstract_graph& rhs) { return this & rhs; }
						// union
							inline abstract_graph& operator|=(const abstract_graph& rhs) { return this | rhs; }
						// difference
							inline abstract_graph& operator^=(const abstract_graph& rhs) { return this ^ rhs; }
					// logical operators
						// check if empty
							inline bool operator!() { return container.empty(); }
						// check if the two graphs are not empty
							inline bool operator&&(const abstract_graph& rhs) { return !(container.empty() || rhs.container.empty()); }
						// check if one of the two graphs is not empty
							inline bool operator||(const abstract_graph& rhs) { return !(container.empty() && rhs.container.empty()); }
				// graph operations
					// check compatibility of the properties
						bool isCompatible(const abstract_graph& rhs) const { return properties == rhs.properties; }
					// tests whether there is an edge from the vertex x to the vertex y
						bool adjacent(vertex_data vertex_1, vertex_data vertex_2, unsigned int index_1 = 0, unsigned int index_2 = 0) {
							if(properties.at("orientation") == oriented) {
								/*
								container.at(vertex_1).second
									std::max(vertex_1, vertex_2);
								*/
							}
							else {

							}
							return false;
						}
						bool adjacent(unsigned int vertex_1, unsigned int vertex_2) {
							if(properties.at("orientation") == oriented) {
								/*
								container.at(vertex_1).second
									std::max(vertex_1, vertex_2);
								*/
							}
							else {

							}
							return false;
						}
					// adds the vertex x, if it is not there
						std::optional<std::any> add_vertex(const vertex_data& element) {
							if(properties.at(orientation) == oriented) {

							}
							/*
							if(auto result = container.insert(element); result.second)
								return result.first;
							*/
							return {};
						}
						std::optional<std::any> add_vertex(vertex_data&& element) {
							/*
							if(auto result = container.insert(element); result.second)
								return result.first;
							*/
							return {};
						}
					// lists all vertices y such that there is an edge from the vertex x to the vertex y
						std::list<std::any> neightbors(const vertex_data& element) const {

						}
						std::list<std::any> neightbors(vertex_data&& element) const {

						}
						std::list<std::any> neightbors(std::set<std::any>::iterator& element) const {

						}
						std::list<std::any> neightbors(std::map<std::any, std::any>::iterator& element) const {

						}
			/*
			The basic operations provided by a graph data structure G usually include:
				adjacent(x, y): tests whether there is an edge from the vertex x to the vertex y
				remove_vertex(x): removes the vertex x, if it is there
				add_edge(x, y): adds the edge from the vertex x to the vertex y, if it is not there
				remove_edge(x, y): removes the edge from the vertex x to the vertex y, if it is there
				get_vertex_value(x): returns the value associated with the vertex x
				set_vertex_value(x, v): sets the value associated with the vertex x to v

			Structures that associate values to the edges usually also provide:
				get_edge_value(x, y): returns the value associated with the edge (x, y)
				set_edge_value(x, y, v): sets the value associated with the edge (x, y) to v
			*/

			std::any casted_container() {
				switch(properties.at("vertex_signifiance")) {
					case significative:
						if(properties.at("vertex_uniqueness") == unique_vertices) {
							if(properties.at("edge_uniqueness") == unique_edges) {
								switch(properties.at("weightness")) {
									case weighted:
										return &std::any_cast<VS_s_VU_u_EU_u_W_w_graph<vertex_data, edge_data>>(container);
									case unweighted:
										return &std::any_cast<VS_s_VU_u_EU_u_W_uw_graph<vertex_data>>(container);
									case mixed_weightness:
										return &std::any_cast<VS_s_VU_u_EU_u_W_mw_graph<vertex_data, edge_data>>(container);
								}
							}
							else {
								switch(properties.at("weightness")) {
									case weighted:
										return &std::any_cast<VS_s_VU_u_EU_nu_W_w_graph<vertex_data, edge_data>>(container);
									case unweighted:
										return &std::any_cast<VS_s_VU_u_EU_nu_W_uw_graph<vertex_data>>(container);
									case mixed_weightness:
										return &std::any_cast<VS_s_VU_u_EU_nu_W_mw_graph<vertex_data, edge_data>>(container);
								}
							}
						}
						else {
							if(properties.at("edge_uniqueness") == unique_edges) {
								switch(properties.at("weightness")) {
									case weighted:
										return &std::any_cast<VS_s_VU_nu_EU_u_W_w_graph<vertex_data, edge_data>>(container);
									case unweighted:
										return &std::any_cast<VS_s_VU_nu_EU_u_W_uw_graph<vertex_data>>(container);
									case mixed_weightness:
										return &std::any_cast< VS_s_VU_nu_EU_u_W_mw_graph<vertex_data, edge_data>>(container);
								}
							}
							else {
								switch(properties.at("weightness")) {
									case weighted:
										return &std::any_cast<VS_s_VU_nu_EU_nu_W_w_graph<vertex_data, edge_data>>(container);
									case unweighted:
										return &std::any_cast<VS_s_VU_nu_EU_nu_W_uw_graph<vertex_data>>(container);
									case mixed_weightness:
										return &std::any_cast<VS_s_VU_nu_EU_nu_W_mw_graph<vertex_data, edge_data>>(container);
								}
							}
						}
						break;
					case not_significative:
						if(properties.at("vertex_uniqueness") == unique_vertices) {
							if(properties.at("edge_uniqueness") == unique_edges) {
								switch(properties.at("weightness")) {
									case weighted:
										return &std::any_cast<VS_ns_VU_u_EU_u_W_w_graph<edge_data>>(container);
									case unweighted:
										return &std::any_cast<VS_ns_VU_u_EU_u_W_uw_graph>(container);
									case mixed_weightness:
										return &std::any_cast<VS_ns_VU_u_EU_u_W_mw_graph<edge_data>>(container);
								}
							}
							else {
								switch(properties.at("weightness")) {
									case weighted:
										return &std::any_cast<VS_ns_VU_u_EU_nu_W_w_graph<edge_data>>(container);
									case unweighted:
										return &std::any_cast<VS_ns_VU_u_EU_nu_W_uw_graph>(container);
									case mixed_weightness:
										return &std::any_cast<VS_ns_VU_u_EU_nu_W_mw_graph<edge_data>>(container);
								}
							}
						}
						else {
							if(properties.at("edge_uniqueness") == unique_edges) {
								switch(properties.at("weightness")) {
									case weighted:
										return &std::any_cast<VS_ns_VU_nu_EU_u_W_w_graph<edge_data>>(container);
									case unweighted:
										return &std::any_cast<VS_ns_VU_nu_EU_u_W_uw_graph>(container);
									case mixed_weightness:
										return &std::any_cast<VS_ns_VU_nu_EU_u_W_mw_graph<edge_data>>(container);
								}
							}
							else {
								switch(properties.at("weightness")) {
									case weighted:
										return &std::any_cast<VS_ns_VU_nu_EU_nu_W_w_graph<edge_data>>(container);
									case unweighted:
										return &std::any_cast<VS_ns_VU_nu_EU_nu_W_uw_graph>(container);
									case mixed_weightness:
										return &std::any_cast<VS_ns_VU_nu_EU_nu_W_mw_graph<edge_data>>(container);
								}
							}
						}
						break;
					case mixed_signifiance:
						if(properties.at("vertex_uniqueness") == unique_vertices) {
							if(properties.at("edge_uniqueness") == unique_edges) {
								switch(properties.at("weightness")) {
									case weighted:
										return &std::any_cast<VS_ms_VU_u_EU_u_W_w_graph<vertex_data, edge_data>>(container);
									case unweighted:
										return &std::any_cast<VS_ms_VU_u_EU_u_W_uw_graph<vertex_data>>(container);
									case mixed_weightness:
										return &std::any_cast<VS_ms_VU_u_EU_u_W_mw_graph<vertex_data, edge_data>>(container);
								}
							}
							else {
								switch(properties.at("weightness")) {
									case weighted:
										return &std::any_cast<VS_ms_VU_u_EU_nu_W_w_graph<vertex_data, edge_data>>(container);
									case unweighted:
										return &std::any_cast<VS_ms_VU_u_EU_nu_W_uw_graph<vertex_data>>(container);
									case mixed_weightness:
										return &std::any_cast<VS_ms_VU_u_EU_nu_W_mw_graph<vertex_data, edge_data>>(container);
								}
							}
						}
						else {
							if(properties.at("edge_uniqueness") == unique_edges) {
								switch(properties.at("weightness")) {
									case weighted:
										return &std::any_cast<VS_ms_VU_nu_EU_u_W_w_graph<vertex_data, edge_data>>(container);
									case unweighted:
										return &std::any_cast<VS_ms_VU_nu_EU_u_W_uw_graph<vertex_data>>(container);
									case mixed_weightness:
										return &std::any_cast<VS_ms_VU_nu_EU_u_W_mw_graph<vertex_data, edge_data>>(container);
								}
							}
							else {
								switch(properties.at("weightness")) {
									case weighted:
										return &std::any_cast<VS_ms_VU_nu_EU_nu_W_w_graph<vertex_data, edge_data>>(container);
									case unweighted:
										return &std::any_cast<VS_ms_VU_nu_EU_nu_W_uw_graph<vertex_data>>(container);
									case mixed_weightness:
										return &std::any_cast<VS_ms_VU_nu_EU_nu_W_mw_graph<vertex_data, edge_data>>(container);
								}
							}
						}
						break;
				}
			}
	};
}

#endif