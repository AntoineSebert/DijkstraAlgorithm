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
 * @description Implementation of Dijkstra's algorithm in C++17 as a single
 * header library using a fibonacci heap
 */
namespace dijkstra {
	using namespace std;
	using namespace boost::heap;
	namespace fs = std::filesystem;

	enum class Direction : uint8_t {
		DIRECTED,
		UNDIRECTED,
	};

	template <typename W, class = enable_if_t<is_integral_v<W>>>
	class Graph {
		public:
			struct Node {
				map<string, W> neighbors = {};
			};
			struct comparator {
				bool operator() (const pair<string, W>& lhs, const pair<string, W>& rhs) const {
					return get<1>(lhs) > get<1>(rhs);
				}
			};
		private:
			map<string, Node> nodes;
			Direction dir;

		public:
			Graph(Direction _dir = Direction::UNDIRECTED) noexcept : nodes({}), dir(_dir) {}

			Direction get_direction() const noexcept {
				return dir;
			}

			const map<string, Node>& get_nodes() const noexcept {
				return nodes;
			}

			void add_node(string label) {
				if (!contains(label))
					nodes[label] = {};
			}

			Graph add_node(string label, const map<string, W>& neighbors) {
				add_node(label);

				for (const auto& [neighbor, weight] : neighbors)
					add_edge(label, neighbor, weight);

				if (dir == Direction::UNDIRECTED)
					for (const auto& [neighbor, weight] : neighbors)
						add_edge(neighbor, label, weight);
			}

			void remove_node(string label) {
				nodes.erase(label);

				for (auto& [_, node] : nodes)
					node.neighbors.erase(label);
			}

			void add_edge(string label0, string label1, W weight = W(0)) {
				add_node(label0);
				add_node(label1);

				nodes.at(label0).neighbors[label1] = weight;

				if (dir == Direction::UNDIRECTED)
					nodes.at(label1).neighbors[label0] = weight;
			}

			bool remove_edge(string label0, string label1) {
				if (has_neighbor(label0, label1)) {
					nodes.at(label0).neighbors.erase(label1);

					if (dir == Direction::UNDIRECTED && has_neighbor(label1, label0))
						nodes.at(label1).neighbors.erase(label0);

					return true;
				}
				
				return false;
			}

			inline bool contains(string label) const {
				return nodes.find(label) != nodes.end();
			}

			bool empty() const {
				return nodes.empty();
			}

			bool has_neighbor(string label0, string label1) const {
				return contains(label0) && contains(label1)
					&& nodes.at(label0).neighbors.find(label1) != nodes.at(label0).neighbors.end();
			}

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
			W get_distance(fibonacci_heap<pair<string, W>, compare<comparator>>& heap, string label) const {
				return find_if(heap.begin(), heap.end(), [&](const auto& e) { return get<0>(e) == label; })->second;
			}
			void assertions(string src, string dst) const {
				assert(("The graph is empty", !empty()));
				assert(("The source node is not in the graph", contains(src)));
				assert(("The destination node is not in the graph", contains(dst)));
				assert(("The source and destinatino are the same", dst != src));
			}

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