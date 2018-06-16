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

#ifndef weight
#define weight std::shared_ptr<unsigned int>
#endif

// node index + node weight
typedef std::pair<unsigned int, unsigned int> node;
typedef std::pair<std::weak_ptr<node>, std::weak_ptr<node>> link;

namespace dijkstra_algorithm {
	void* AbstractNode;
	class AbstractGraphContainer {
		virtual ~AbstractGraphContainer() noexcept = 0;
	};
	class AbstractWeightContainer {
		virtual ~AbstractWeightContainer() noexcept = 0;
	};
	class Dijkstra {
		/* ATTRIBUTES */
			private:
				std::shared_ptr<node> firstNode;
				/*
				 * Collection of unique nodes (based on their index), iterable and direct access through key value
				*/
				std::set<std::shared_ptr<node>/*, comparison*/> nodes;
				std::priority_queue<weight, std::vector<weight>/*, comparison*/> weights;
				std::map<link, weight/*, comparison*/> paths; // assert(link.first < link.second)
				AbstractGraphContainer* graphContainer; // adjacency list
		/* MEMBERS */
			public:
				// constructors
					Dijkstra()/* = delete*/ {} // delete default constructor ?
					Dijkstra(const Dijkstra& other) : nodes(other.nodes), paths(other.paths) {}
					Dijkstra(Dijkstra&& other) noexcept : nodes(other.nodes), paths(other.paths) { /* destroy eventual dynamic data */ }
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

						nodes = other.nodes;
						paths = other.paths;
						/* destroy eventual dynamic data */

						return *this;
					}
			protected:
				/*
				Initialisation(G,s(deb))
				1 pour chaque point s de G faire
				2 	d[s] := infini	// on initialise les sommets autres que s(deb) à infini
				3 fin pour
				4 d[sdeb] := 0	// la distance au sommet de départ s(deb) est nulle
				*/
				void init() {
					/*
					for(auto const& [key, val] : nodes)
						val.get() = numeric_limits<int>::max();
					*/
					firstNode->second = 0;
				}
				/*
				1 mini := infini
				2 sommet := -1
				3 pour chaque sommet s de Q
				4 	si d[s] < mini
				5 		mini := d[s]
				6 		sommet := s
				7 renvoyer sommet
				*/
				// the priority_queue does the job for us
				[[maybe_unused]] unsigned int* findMinDistance() { }
				/*
				1 si d[s2] > d[s1] + Poids(s1,s2)	// Si la distance de sdeb à s2 est plus grande que celle de sdeb à S1 plus celle de S1 à S2
				2 	d[s2] := d[s1] + Poids(s1,s2)	// On prend ce nouveau chemin qui est plus court
				3s 	prédécesseur[s2] := s1	// En notant par où on passe
				*/
				void distancesUpdate() { }
				/*
				1 A = suite vide
				2 s := sfin
				3 tant que s != sdeb faire
				4 	A = A + s	// on ajoute s à la suite A
				5 	s = prédécesseur[s]	// on continue de suivre le chemin
				6 fin tant que
				*/
				std::pair<unsigned int*, unsigned int*> shortestPath() { }
				/*
				Initialisation(G,sdeb)
				2 Q := ensemble de tous les nœuds
				3 tant que Q n'est pas un ensemble vide faire
				4 	s1 := Trouve_min(Q)
				5 	Q := Q privé de s1
				6 	pour chaque nœud s2 voisin de s1 faire
				7 		maj_distances(s1,s2)
				8 	fin pour
				9 fin tant que
				*/
				void mainAlgorithm() {
					init();
					while(nodes.size()) {

					}
				}
	};
}