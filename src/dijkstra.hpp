/*
 * @author Antoine "Anthony" Sébert
 * @description An implementation of the Dijkstra algorithm in C++17 as a class - header
 * @note no need to specialize std::swap, because it uses the move constructor and move assignment operator
 * @note in this implementation, the weights are positives
 * @date 01/04/2018
 * @todo Spécialisation de l'algorithme : arrêter la recherche lorsque l'égalité s(1) = s(fin) est vérifiée, dans le cas où on ne cherche que la distance minimale entre s(deb) et s(fin)
 */

#pragma once

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

// node index + node weight
typedef std::pair<unsigned int, unsigned int> node;
typedef std::pair<std::weak_ptr<node>, std::weak_ptr<node>> link;

class Dijkstra {
	/* attributes */
		private:
			std::shared_ptr<node> beginningNode;
			std::priority_queue<std::shared_ptr<node>, std::set<std::shared_ptr<node>>/*, comparison*/> nodes;
			// unique paths, pointing to nodes, bound to their weight
			std::map<link, unsigned int/*, comparison*/> paths; // assert(link.first < link.second)
	/* members */
		public:
			// constructors
				Dijkstra()/* = delete*/; // delete default constructor ?
				Dijkstra(const Dijkstra& other);
				Dijkstra(Dijkstra&& other) noexcept;
			// destructors
				~Dijkstra() noexcept/* = default*/; // maybe not need to redefine
			// operators
				Dijkstra& operator=(const Dijkstra& other);
				Dijkstra& operator=(Dijkstra&& other) noexcept;
		protected:
			void init();
			[[maybe_unused]] unsigned int* findMinDistance(); // the priority_queue does the job for us
			void distancesUpdate();
			std::pair<unsigned int*, unsigned int*> shortestPath();
			void mainAlgorithm();
};