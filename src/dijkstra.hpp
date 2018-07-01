/*
 * @author Antoine "Anthony" Sébert
 * @description An implementation of the Dijkstra algorithm in C++17 as a class - header
 * @note no need to specialize std::swap, because it uses the move constructor and move assignment operator
 * @note in this implementation, the weights are positives
 * @date 01/04/2018
 * @todo Spécialisation de l'algorithme : arrêter la recherche lorsque l'égalité s(1) = s(fin) est vérifiée, dans le cas où on ne cherche que la distance minimale entre s(deb) et s(fin)
 *	1  S ← empty sequence
 *	2  u ← target
 *	3  while prev[u] is defined:                 // Construct the shortest path with a stack S
 *	4      insert u at the beginning of S        // Push the vertex onto the stack
 *	5      u ← prev[u]                           // Traverse from target to source
 *	6  insert u at the beginning of S            // Push the source onto the stack
 */

#pragma once

#include <any>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <utility>
#include <vector>

#include "../../fiboheap/fiboheap.hpp"

namespace dijkstra_algorithm {
	template<class edge_data> struct graph_test
		: std::set<typename std::map<typename graph_test<edge_data>::const_pointer, edge_data>> {
		using std::map<typename graph_test<edge_data>::const_pointer, edge_data>::map;
	};
}

namespace dijkstra_algorithm {
	template<class edge_data>
	class Dijkstra {
		/* ATTRIBUTES */
			private:
				graph_test<edge_data>* graphContainer;
				graph_test<edge_data>::const_reference;
				//graph_test<edge_data>::const_pointer start, finish;
		/* MEMBERS */
			public:
				// constructors
					Dijkstra(graph_test<edge_data>* data/*, graph_test<edge_data>::const_pointer start, graph_test<edge_data>::const_pointer finish*/) {}
					Dijkstra(const Dijkstra& other) : graphContainer(graphContainer) {}
					Dijkstra(Dijkstra&& other) noexcept : graphContainer(graphContainer) { /* destroy eventual dynamic data */ }
				// destructors
					~Dijkstra() noexcept/* = default*/ {} // maybe not need to redefine
				// operators
					Dijkstra& operator=(const Dijkstra& other) {
						Dijkstra tmp(other);
						*this = std::move(tmp);

						return *this;
					}
					Dijkstra& operator=(Dijkstra&& other) noexcept {
						if(this == &other)
							return *this;

						graphContainer = other.graphContainer;
						/* destroy eventual dynamic data */

						return *this;
					}
			protected:
				void run() {
					/*
					dist[source] ← 0                           // Initialization
					create vertex set Q
					for each vertex v in Graph :
						if v ≠ source
							dist[v] ← INFINITY                 // Unknown distance from source to v
						prev[v] ← UNDEFINED                    // Predecessor of v
						Q.add_with_priority(v, dist[v])
						while Q is not empty:                      // The main loop
							u ← Q.extract_min()                    // Remove and return best vertex
							for each neighbor v of u :              // only v that is still in Q
								alt ← dist[u] + length(u, v)
								if alt < dist[v]
									dist[v] ← alt
									prev[v] ← u
									Q.decrease_priority(v, alt)
					return dist, prev
					*/
				}
	};
}