/*
 * Edge.hpp
 *
 *  Created on: 7 juil. 2018
 *      Author: aschils
 */

#ifndef GRAPH_EDGE_HPP_
#define GRAPH_EDGE_HPP_

#include "Vertex.hpp"

template <typename EdgeElement, typename VertexElement>
class Edge {

public:
	Edge<EdgeElement, VertexElement> *position;
	EdgeElement x;
	Vertex<VertexElement> *start, *end;

	Edge(EdgeElement x, Vertex<VertexElement> *start,
			Vertex<VertexElement> *end){
		this->x = x;
		this->start = start;
		this->end = end;
	}
};


#endif /* GRAPH_EDGE_HPP_ */
