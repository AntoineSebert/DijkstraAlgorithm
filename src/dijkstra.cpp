/*
 * @author Antoine "Anthony" Sébert
 * @description An implementation of the Dijkstra algorithm in C++17 as a class - code
 * @date 01/04/2018
 */

#include "dijkstra.hpp"

using namespace std;

// public
	// constructors
		Dijkstra::Dijkstra() {}
		Dijkstra::Dijkstra(const Dijkstra& other) : nodes(other.nodes), weights(other.weights), paths(other.paths) {}
		Dijkstra::Dijkstra(Dijkstra&& other) noexcept : nodes(other.nodes), weights(other.weights), paths(other.paths) { /* destroy eventual dynamic data */ }
	// destructors
		Dijkstra::~Dijkstra() noexcept { /* destroy eventual dynamic data */ }
	// operators
		Dijkstra& Dijkstra::operator=(const Dijkstra& other) {
			Dijkstra tmp(other);
			*this = move(tmp);

			return *this;
		}
		Dijkstra& Dijkstra::operator=(Dijkstra&& other) noexcept {
			if(this == &other)
				return *this;

			nodes = other.nodes;
			weights = other.weights;
			paths = other.paths;
			 /* destroy eventual dynamic data */

			return *this;
		}
// protected:
	void Dijkstra::init() {
		/*
		Initialisation(G,s(deb))
		1 pour chaque point s de G faire
		2    d[s] := infini             // on initialise les sommets autres que s(deb) à infini
		3 fin pour
		4 d[sdeb] := 0                  // la distance au sommet de départ s(deb) est nulle
		*/
	}
	[[maybe_unused]] int* Dijkstra::findMinDistance() {
		/*
		1 mini := infini
		2 sommet := -1
		3 pour chaque sommet s de Q
		4    si d[s] < mini
		5    alors 
		6        mini := d[s]
		7        sommet := s
		8 renvoyer sommet
		*/
	}
	void Dijkstra::distancesUpdate() {
		/*
		1 si d[s2] > d[s1] + Poids(s1,s2)      // Si la distance de sdeb à s2 est plus grande que
		2                                      // celle de sdeb à S1 plus celle de S1 à S2
		3    alors 
		4        d[s2] := d[s1] + Poids(s1,s2) // On prend ce nouveau chemin qui est plus court
		5        prédécesseur[s2] := s1        // En notant par où on passe
		*/
	}
	std::pair<unsigned int*, unsigned int*> Dijkstra::shortestPath() {
		/*
		1 A = suite vide
		2 s := sfin
		3 tant que s != sdeb faire
		4   A = A + s                 // on ajoute s à la suite A
		5   s = prédécesseur[s]       // on continue de suivre le chemin
		6 fin tant que
		*/
	}
	void Dijkstra::mainAlgorithm() {
		/*
		Initialisation(G,sdeb)
		2 Q := ensemble de tous les nœuds
		3 tant que Q n'est pas un ensemble vide faire
		4       s1 := Trouve_min(Q)
		5       Q := Q privé de s1
		6       pour chaque nœud s2 voisin de s1 faire
		7           maj_distances(s1,s2)
		8       fin pour
		9 fin tant que
		*/
	}