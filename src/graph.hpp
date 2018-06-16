/**
* Graph Library
* Copyright (c) 2014, Antoine Sébert antoine.sb@orange.fr, All rights reserved.
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 3.0 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library.
*/

#ifndef GRAPH.HPP
#define GRAPH.HPP

#include <any>
#include <map>
#include <utility>
#include <set>
#include <vector>

namespace graph {
	enum underlying_Container {
		LIST,
		MATRIX
	};
	enum uniqueness {
		UNIQUE,
		NOT_UNIQUE
	};
	template<typename data>
	class AbstractGraph {
		// put in a particular header
		class AbstractNode {
			data value;
			AbstractNode() = 0;
		};
		// ATTRIBUTES
			std::any container<std::any>;
			typename type;
		// MEMBERS
			// default constructor
				AbstractGraph() = 0;
			// copy constructor
				AbstractGraph(const AbstractGraph& other) = 0;
			// move constructor
				AbstractGraph(AbstractGraph&& other) noexcept = 0;
			// destructor
				~AbstractGraph() noexcept = 0;
			// operators
				// arithmetic operators
					AbstractGraph& operator=(const AbstractGraph& other) = 0;
					auto operator+(AbstractNode b) = 0;		// add node or path
					auto operator-(AbstractNode b) = 0;		// remove node of path if they exists (and if graph has uniques node labels ?)
					auto operator+(AbstractGraph b) = 0;	// add nodes and paths
					auto operator-(AbstractGraph b) = 0;	// add nodes and paths if they exists (and if graph has uniques node labels ?)
					auto operator+() = delete;				// graph is not an arithmetic type
					auto operator-() = delete;				// graph is not an arithmetic type
					auto operator*(S b) = delete;			// nonsense
					auto operator/(S b) = delete;			// nonsense
					auto operator%(S b) = delete;			// nonsense
					auto operator++() = delete;				// nonsense
					auto operator++(int) = delete;			// nonsense
					auto operator--() = delete;				// nonsense
					auto operator--(int) = delete;			// nonsense
				// bitwise operators
					auto operator~() = 0;
					auto operator&(S b) = 0;
					auto operator|(S b) = 0;
					auto operator^(S b) = 0;
					auto operator<<(S b) = 0;
					auto operator>>(S b) = 0;
				// comparison/relational operators
					bool operator==(const AbstractGraph& b) = 0;
					bool operator!=(const AbstractGraph& b) = 0;
					bool operator!=(const AbstractGraph& b) const = 0;
					bool operator>(const AbstractGraph& b) const = 0;
					bool operator<(const AbstractGraph& b) const = 0;
					bool operator>=(const AbstractGraph& b) const = 0;
					bool operator<=(const AbstractGraph& b) const = 0;
					bool operator<=>(const AbstractGraph& b) const = 0;
				// compound assignment operators
					R& operator+=(S b) = 0;
					R& operator-=(S b) = 0;
					R& operator*=(S b) = 0;
					R& operator/=(S b) = 0;
					R& operator%=(S b) = 0;
					R& operator&=(S b) = 0;
					R& operator|=(S b) = 0;
					R& operator^=(S b) = 0;
					R& operator<<=(S b) = 0;
					R& operator>>=(S b) = 0;
				// logical operators
					bool operator!() = 0;
					bool operator&&(S b) = 0;
					bool operator||(S b) = 0;
				// member and pointer operators
					R& operator[](S b) = 0;
					R& operator*() = 0;
					R& operator&() = 0;
					R& operator->() = 0;
					R& operator->*(S b) = 0;
				// other operators
					auto operator()(S a, T b, ...) = 0;
					R& operator,(S b) = 0;
					auto operator ""_b(T a) = 0;
					explicit operator R() = 0;
					void* operator new(size_t x) = 0;
					void* operator new[](size_t x) = 0;
					void operator delete(void *a) = 0;
					void operator delete[](void *a) = 0;
			// move assignment operator
				AbstractGraph& operator=(AbstractGraph&& other) noexcept = 0;
			// iterators
				auto begin() const noexcept = 0;
				auto cbegin() const noexcept = 0;
				auto end() const noexcept = 0;
				auto cend() const noexcept = 0;
				auto rbegin() const noexcept = 0;
				auto crbegin() const noexcept = 0;
				auto rend() const noexcept = 0;
				auto crend() const noexcept = 0;
			// element access
				auto at() = 0;
				auto operator[] = 0;
				auto front() = 0;
				auto back() = 0;
			// capacity
				auto empty() = 0;
				auto size() = 0;
				auto max_size() = 0;
				auto resize() = 0;
				auto capacity() = 0;
				auto reserve() = 0;
				auto shrink_to_fit() = 0;
			// modifiers
				auto clear() = 0;
				auto insert() = 0;
				auto insert_or_assign() = 0;
				auto emplace() = 0;
				auto emplace_hint() = 0;
				auto try_emplace() = 0;
				auto erase() = 0;
				auto push_front() = 0;
				auto emplace_front() = 0;
				auto pop_front() = 0;
				auto push_back() = 0;
				auto emplace_back() = 0;
				auto pop_back() = 0;
				auto swap() = 0;
				auto merge() = 0;
				auto extract() = 0;
			// list operations
				auto splice() = 0;
				auto remove() = 0;
				auto remove_if() = 0;
				auto reverse() = 0;
				auto unique() = 0;
				auto sort() = 0;
			// lookup
				auto count() = 0;
				auto find() = 0;
				auto contains() = 0;
				auto lower_bound() = 0;
				auto upper_bound() = 0;
				auto equal_range() = 0;
			// observers
				auto key_comp() = 0;
				auto value_comp() = 0;
				auto hash_function() = 0;
				auto key_eq() = 0;
			// allocator
				auto get_allocator() = 0;
	};
	template<typename data>
	class OrientedGraph : public AbstractGraph<data> {


	};
	template<typename data>
	class UnorientedGraph : public AbstractGraph<data> {

	};
	template<typename data>
	class MixedGraph : public OrientedGraph<data, weight>, UnorientedGraph<data, weight> {

	};
	template<typename data, typename weight>
	class WeightedOrientedGraph : public OrientedGraph<data, weight> {

	};
	template<typename data, typename weight>
	class WeightedUnorientedGraph : public UnorientedGraph<data, weight> {

	};
	template<typename data, typename weight>
	class WeightedMixedGraph : public WeightedOrientedGraph<data, weight>, WeightedUnorientedGraph<data, weight> {

	};
}

#endif