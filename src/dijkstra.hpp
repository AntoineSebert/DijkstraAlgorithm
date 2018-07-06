/*
 * @author Antoine "Anthony" Sébert
 * @description Implementation of the Dijkstra's algorithm in C++17 as a single header library using fibonacci heap and named tuples
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

#if 201703L <= __cplusplus
	#error This library needs at least a C++17 compliant compiler
#endif

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <any>
#include <cassert>
#include <chrono>
#include <iostream>
#include <limits>
#include <map>
#include <optional>
#include <set>
#include <utility>

#include "../../fiboheap/fiboheap.hpp"

namespace std {
	template<class Iter>
	void check_range(Iter first, Iter second) {
		static_cast<void>(first == second); // ill-formed compilation if iterators are not comparable, making it fail
		// throw range_error("invalid iterator range");
		//return first < second;
	}

	pair<optional<any>, chrono::duration<double>> dijkstra(const set<map<set<any>::const_iterator, unsigned int>>& data, set<map<set<any>::const_iterator, unsigned int>>::iterator _Start, set<map<set<any>::const_iterator, unsigned int>>::iterator _Arr) {
		auto start = chrono::system_clock::now();

		check_range(_Start, _Arr);

		//dist[source] = 0								// Initialization
		FibHeap<unsigned int> queue = FibHeap<unsigned int>();
		for(const auto& vertex : data) {
			/*
			if(vertex != *_Start)
				dist[vertex] = INFINITY;									// Unknown distance from source to v
			prev[vertex] = UNDEFINED;										// Predecessor of v
			queue.add_with_priority(vertex, dist[vertex]);
			*/
		}
		while(!queue.empty()) {												// The main loop
			auto u = queue.extract_min();									// Remove and return best vertex
			/*
			for(const auto& vertex : u) {									// only v that is still in Q
				if(alt = dist[u] + length(u, vertex); alt < dist[vertex]) {
					dist[vertex] = alt;
					prev[vertex] = u;
					queue.decrease_priority(vertex, alt);
				}
			}
				*/
		}

		auto end = chrono::system_clock::now();
		chrono::duration<double> elapsed_time = end - start;
		std::cout << "elapsed time: " << elapsed_time.count() << "s\n";

		//return dist, prev
		return pair<optional<any>, chrono::duration<double>>();
	}
}

#endif