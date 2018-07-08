/*
 * Vertex.hpp
 *
 *  Created on: 7 juil. 2018
 *      Author: aschils
 */

#ifndef GRAPH_VERTEX_HPP_
#define GRAPH_VERTEX_HPP_

template <typename VertexElement>
class Vertex {

public:
	Vertex<VertexElement> *position;
	VertexElement x;

	Vertex(){}

	Vertex(VertexElement x){
		this->x = x;
	}
};

#endif /* GRAPH_VERTEX_HPP_ */
