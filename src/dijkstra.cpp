/*
 * @author Antoine "Anthony" Sébert
 * @description An implementation of the Dijkstra algorithm in C++17 as a class - code
 * @date 01/04/2018
 */

#include "dijkstra.h"

using namespace std;

// public
	// constructors
		Dijkstra::Dijkstra() {}
		Dijkstra::Dijkstra(const Dijkstra& other) : nodes(other.nodes), weights(other.weights), paths(other.paths) {}
		Dijkstra::Dijkstra(Dijkstra&& other) noexcept {
			
		}
	// destructors
		Dijkstra::~Dijkstra() noexcept {
			
		}
	// operators
		Dijkstra& Dijkstra::operator=(const Dijkstra& other) {
			
		}
		Dijkstra& Dijkstra::operator=(Dijkstra&& other) noexcept {
			
		}
// protected:
	void Dijkstra::init() {
			
		}
	[[maybe_unused]] int* Dijkstra::minDistanceSearch() {
			
		}
	void Dijkstra::distancesUpdate() {
			
		}
	std::pair<unsigned int*, unsigned int*> Dijkstra::shOrtestPath() {
			
		}
	void Dijkstra::mainAlgorithm() {
			
		}