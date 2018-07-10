/*
 * @author Antoine "Anthony" Sébert
 * @description Implementation of Dijkstra's algorithm in C++17 as a single header library using a fibonacci heap and named tuples
 * @note in this implementation, the weights are positives
 * @date 01/04/2018
 * @todo Spécialisation de l'algorithme : arrêter la recherche lorsque l'égalité s(1) = s(fin) est vérifiée, dans le cas où on ne cherche que la distance minimale entre s(deb) et s(fin)
 *	1  S ← empty sequence
 *	2  u ← target
 *	3  while prev[u] is defined:                 // Construct the shortest path with a stack S
 *	4      insert u at the beginning of S        // Push the vertex onto the stack
 *	5      u ← prev[u]                           // Traverse from target to source
 *	6  insert u at the beginning of S            // Push the source onto the stack
 *	https://www.cl.cam.ac.uk/teaching/1112/AlgorithII/1987-FredmanTar-fibonacci.pdf
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
#include <unordered_set>
#include <utility>

#include "../../fiboheap/fiboheap.hpp"

namespace std {
	template<typename T>
	using graph = set<map<unsigned int, T>>;

	template<typename T>
	using graph_iterator = typename graph<T>::iterator;

	template<typename T>
	using graph_const_iterator = typename graph<T>::const_iterator;
}

namespace std {
	template <class T, class = void>
	struct is_iterator : false_type {};
	template <class T>
	struct is_iterator<T, void_t<typename iterator_traits<T>::iterator_category>> : true_type { };

	template<typename Iter>
	bool check_range(const Iter first, const Iter second) {
		static_cast<void>(first == second); // ill-formed compilation if iterators are not comparable, making it fail
		return is_iterator<Iter>();
	}

	template<typename T = unsigned int>
	pair<optional<any>, chrono::duration<double>> dijkstra(const graph<typename T>& data, graph_iterator<typename T> Source, graph_iterator<typename T> Arr) {
		if(data.empty() == false)
			return pair<optional<any>, chrono::duration<double>>();

		// Initialization
		check_range(Source, Arr);

		auto start = chrono::system_clock::now();

		FibHeap<graph_iterator<T>> queue = FibHeap<graph_iterator<T>>();
		vector<T> distances(data.size(), numeric_limits<unsigned int>::max());
		//distances.at(distance(Source, data.begin())) = 0;
		cout << distance(Source, data.begin()) << ':' << distances.size() << endl;
		unordered_set<optional<unsigned int>> path;

		assert(data.size() == distances.size());

		unsigned int i = 0;
		for(const auto& element : data) {
			//typeid(element).name();
			//queue.push(element, distances.at(i));
			++i;
		}


		while(!queue.empty()) {												// The main loop
			auto u = queue.extract_min();									// Remove and return best vertex
			//for(const auto& vertex : (data.begin() + u->payload)) {								// only v that is still in Q
				/*
				if(unsigned int alt = dist[u] + length(u, vertex); alt < dist[vertex]) {
					dist[vertex] = alt;
					prev[vertex] = u;
					queue.decrease_priority(vertex, alt);
				}
				*/
			//}
		}

		auto end = chrono::system_clock::now();
		chrono::duration<double> elapsed_time = end - start;
		cout << "elapsed time: " << elapsed_time.count() << "s" << endl;

		//return dist, prev
		return pair<optional<any>, chrono::duration<double>>();
	}
}

#endif