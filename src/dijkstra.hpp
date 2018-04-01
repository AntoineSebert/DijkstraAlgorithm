/*
 * @author Antoine "Anthony" Sébert
 * @description An implementation of the Dijkstra algorithm in C++17 as a class
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
#include <numeric>
#include <queue>
#include <string>
#include <utility>

class Dijkstra {
	/* attributes */
		private:
			std::map<unsigned int*, unsigned int*> paths;
			std::priority_queue<unsigned int> nodes;
	/* members */
		public:
			// constructors
				Dijkstra();
				Dijkstra(const Dijkstra& other);
				Dijkstra(Dijkstra&& other) noexcept;
			// destructors
				~Dijkstra() noexcept;
			// operators
				Dijkstra& operator=(const Dijkstra& other);
				Dijkstra& operator=(Dijkstra&& other) noexcept;
		protected:
			void init();
			[[maybe_unused]] int* minDistanceSearch();
			void distancesUpdate();
			pair<unsigned int*, unsigned int*> shOrtestPath();
			void mainAlgorithm();
};