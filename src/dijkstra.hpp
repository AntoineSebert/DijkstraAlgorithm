#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <algorithm>
#include <cassert>
#include <filesystem>
#include <functional>
#include <limits>
#include <map>
#include <memory>
#include <optional>
#include <set>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include "boost/heap/fibonacci_heap.hpp"

/*
 * @author Antoine Sébert
 * @description Implementation of Dijkstra's algorithm in C++17 as a single header library using a fibonacci heap.
 */
namespace dijkstra {
	using namespace std;
	using namespace boost::heap;
	namespace fs = std::filesystem;

	/*
	* The orientation of a graph. Has an impact on edge insertion and deletion.
	*/
	enum class Orientation : uint8_t {
		ORIENTED,
		UNORIENTED,
	};

	/*
	* A simple Graph class.
	* - Orientation : The graph is either oriented or not.
	*	In reality all egdes are oriented, but the add_edge() and add_node() methods uses oriented edges to simulate unorientation.
	* - Weights : The graph can contain weighted edges, unweighted edges, or a mix of both, depending on the arguments passed to add_edge() and add_node().
	*	Under the hood all 
	* 
	* @param	W	An integral type for the edge weights, that supports numeric_limits<>::max(), addition and comparison.
	*/
	template <typename W = uint_fast32_t, class = enable_if_t<is_integral_v<W>>>
	class Graph {
		public:
			/*
			* A simple Node class, essentially a wrapper around edges.
			*/
			struct Node {
				map<string, W> neighbors = {};
			};

			/*
			* The comparator for the items in the fibonacci heap.
			*/
			struct comparator {
				inline bool operator() (const pair<string, W>& lhs, const pair<string, W>& rhs) const {
					return get<1>(lhs) > get<1>(rhs);
				}
			};
		private:
			map<string, Node> nodes;
			Orientation _or;

		public:
			/*
			* Constructor.
			* 
			* @param	_or	the edge orientation
			*/
			Graph(Orientation _or = Orientation::UNORIENTED) noexcept : nodes({}), _or(_or) {}

			/* NODES */

			/*
			* Returns the underlying node container.
			* 
			* @return	a map of strings to nodes
			*/
			inline const map<string, Node>& get_nodes() const noexcept {
				return nodes;
			}

			/*
			* Check if a node exists.
			*
			* @param	label	the label
			* @return	true if the node exists, or false otherwise
			*/
			inline bool contains(string label) const noexcept {
				return nodes.find(label) != nodes.end();
			}

			/*
			* Check if the graph is empty.
			*
			* @return	true if the node container is empty, or false otherwise
			*/
			inline bool empty() const noexcept {
				return nodes.empty();
			}

			/*
			* Adds a node. Idempotent.
			* 
			* @param	label	the label
			*/
			void add_node(string label) {
				if (!contains(label))
					nodes[label] = {};
			}

			/*
			* Adds a node and the weighted egdes between neighbors. All non-existing neighbors will be created on the fly.
			*
			* @param	label	the label
			* @param	neighbors	the edges
			* 
			* @return	this
			*/
			Graph add_node(string label, const map<string, W>& neighbors) {
				add_node(label);

				for (const auto& [neighbor, weight] : neighbors)
					add_edge(label, neighbor, weight);

				if (_or == Orientation::UNORIENTED)
					for (const auto& [neighbor, weight] : neighbors)
						add_edge(neighbor, label, weight);

				return this;
			}

			/*
			* Adds a node and the weighted egdes between neighbors. All non-existing neighbors will be created on the fly. All edge weights are defaulted to 0 (can emulate unweighted graphs).
			*
			* @param	label	the label
			* @param	neighbors	the edges
			* 
			* @return	this
			*/
			Graph add_node(string label, const set<string>& neighbors) {
				auto _neighbors = map<string, W>();

				for (const auto& _label : neighbors)
					_neighbors[_label] = 0;

				return add_node(label, neighbors);
			}

			/*
			* Removes a node and any edge pointing to it.
			*
			* @param	label	the label
			*/
			void remove_node(string label) {
				nodes.erase(label);

				for (auto& [_, node] : nodes)
					node.neighbors.erase(label);
			}

			/* EDGES */

			/*
			* Returns the orientation.
			*/
			inline Orientation get_orientation() const noexcept {
				return _or;
			}

			/*
			* Adds an edge, whose weight is optional and defaults to 0.
			* If the graph is oriented, the order in wich the node labels are specified is significant; non-existing nodes will be created on the fly.
			*
			* @param	label0	the label of the first node
			* @param	label1	the label of the second node
			* @note	Self-edges are authorised
			*/
			void add_edge(string label0, string label1, W weight = W(0)) {
				add_node(label0);
				add_node(label1);

				nodes.at(label0).neighbors[label1] = weight;

				if (_or == Orientation::UNORIENTED)
					nodes.at(label1).neighbors[label0] = weight;
			}

			/*
			* Removes an edge.
			*
			* @param	label0	the label of the first node
			* @param	label1	the label of the second node
			* @return	true if the edge exists and has been removed, or false otherwise
			*/
			bool remove_edge(string label0, string label1) {
				if (has_neighbor(label0, label1)) {
					nodes.at(label0).neighbors.erase(label1);

					if (_or == Orientation::UNORIENTED && has_neighbor(label1, label0))
						nodes.at(label1).neighbors.erase(label0);

					return true;
				}
				else
					return false;
			}

			/*
			* Checks if two nodes are neighbors
			*
			* @param	label0	the label of the first node
			* @param	label1	the label of the second node
			* @return	true if the two nodes exist and an edge between the nodes exist, or false otherwise
			*/
			bool has_neighbor(string label0, string label1) const {
				return contains(label0) && contains(label1)
					&& nodes.at(label0).neighbors.find(label1) != nodes.at(label0).neighbors.end();
			}

			/* DIJKSTRA'S ALGORITHM */

			/*
			* Finds the shortest path between two nodes, asserting it exists.
			*
			* @param	src	the label of the source node
			* @param	dst	the label of the destination node
			* @return	a path that starts with src and ends with dst
			* @cite	@article{dijkstra1959note, title={A note on two problems in connexion with graphs}, author={Dijkstra, Edsger W and others}, journal={Numerische mathematik}, volume={1}, number={1}, pages={269--271}, year={1959}}
			*/
			fs::path find(string src, string dst) const {
				assertions(src, dst);

				auto preds = map<string, string>();
				auto heap = fibonacci_heap<pair<string, W>, compare<comparator>>();
				auto handles = map<string, decltype(heap)::handle_type>();

				for (auto& [label, _] : nodes)
					handles[label] = heap.push(make_pair(label, label == src ? 0 : numeric_limits<W>::max()));

				while (!heap.empty()) {
					auto& [nearest, distance] = heap.top();

					if (nearest == dst)
						break;

					for (auto& [neighbor, weight] : nodes.at(nearest).neighbors)
						if (handles.find(neighbor) != handles.end())
							if (W alt = distance + weight; alt < get_distance(heap, neighbor)) {
								preds[neighbor] = nearest;
								heap.update(handles.at(neighbor), make_pair(neighbor, alt));
							}

					handles.erase(nearest);
					heap.pop();
				}

				return preds_to_path(preds, src, dst);
			}

		private:
			/*
			* Looks up the distance associated to a label in a heap.
			*
			* @param	heap	the heap
			* @param	label	the label
			* @return	the distance of the node if it exists, or numeric_limits<W>::max() otherwise
			*/
			inline W get_distance(fibonacci_heap<pair<string, W>, compare<comparator>>& heap, string label) const {
				auto it = find_if(heap.begin(), heap.end(), [&](const auto& e) { return get<0>(e) == label; });

				return it != heap.end() ? it->second : numeric_limits<W>::max();
			}

			/*
			* Performs quick assertions to ensure the search for the shortest path can start (but not if it will succeed).
			*
			* @param	src	the label of the source node
			* @param	dst	the label of the destination node
			*/
			inline void assertions(string src, string dst) const {
				assert(("The graph is empty", !empty()));
				assert(("The source node is not in the graph", contains(src)));
				assert(("The destination node is not in the graph", contains(dst)));
				assert(("The source and destination are the same", dst != src));
			}

			/*
			* Transforms the predecessors into a path.
			*
			* @param	preds	the map of node predecessors
			* @param	src	the label of the source node
			* @param	dst	the label of the destination node
			* @return	a path from src to dst
			*/
			fs::path preds_to_path(const map<string, string>& preds, string src, string dst) const {
				vector<string> reverse_path = { dst };
				while (reverse_path.back() != src)
					reverse_path.push_back(preds.at(reverse_path.back()));

				auto _path = fs::path();
				for (auto it = reverse_path.rbegin(); it != reverse_path.rend(); it++)
					_path /= *it;

				return _path;
			}
	};
};

#endif