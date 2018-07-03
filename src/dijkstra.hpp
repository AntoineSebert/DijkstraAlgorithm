/*
 * @author Antoine "Anthony" Sébert
 * @description An implementation of the Dijkstra's algorithm in C++17 as a single header library
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

#if 201703L <= __cplusplus
	#error This library needs at least a C++17 compliant compiler
#endif

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <any>
#include <algorithm>
#include <cassert>
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

namespace std {
	template<class Iter>
	void check_range(Iter first, Iter second) {
		static_cast<void>(first == second); // ill-formed compilation if iterators are not comparable, making it fail
		// throw range_error("invalid iterator range");
		//return first < second;
	}

	any dijkstra(set<map<set<any>::const_iterator, int>>::iterator _Start, set<map<set<any>::const_iterator, int>>::iterator _Arr) {
		check_range(_Start, _Arr);

		FibHeap<int> queue = FibHeap<int>();

		//cout << typeid(*_Start).name() << endl;
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

		return any();
	}
}

#endif