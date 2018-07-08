/*
 * Graph.hpp
 *
 * Undirected Graph interface.
 *
 *  Created on: 7 juil. 2018
 *      Author: aschils
 */

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <list>
#include <vector>
#include "Edge.hpp"
#include "Vertex.hpp"

template <typename EdgeElement, typename VertexElement>
class Graph {

public:
	typedef std::list<Edge<EdgeElement,VertexElement> > EdgeContainer;
	typedef std::list<Vertex<VertexElement> > VertexContainer;

public:
	/*
	 * Return an iterable collection of all vertices of the graph
	 */
	virtual VertexContainer vertices() = 0;

	/*
	 * Return an iterable collection of all edges of the graph
	 */
	virtual EdgeContainer edges() = 0;

	/*
	 * Return an iterable collection of the edges incident upon vertex v
	 */
	virtual EdgeContainer incident_edges(Vertex<VertexElement> v) = 0;

	/*
	 * Return the end vertex of edge e distinct from vertex v; an error occurs
	 * if e is not incident on v.
	 */
	virtual Vertex<VertexElement> opposite(Vertex<VertexElement> v,
			Edge<EdgeElement,VertexElement> e) = 0;

	/*
	 * Return an array storing the end vertices of edge e
	 */
	virtual std::vector<Vertex<VertexElement> > end_vertices(
			Edge<EdgeElement,VertexElement> e) = 0;

	/*
	 *Test wether vertices v and w are adjacent
	 */
	virtual bool are_adjacent(Vertex<VertexElement> v,
			Vertex<VertexElement> w) = 0;

	/*
	 * Replace element stored at v with x
	 */
	virtual void replace(Vertex<VertexElement> v, VertexElement x) = 0;

	/*
	 * Replace the element stored at edge e with x
	 */
	virtual void replace(Edge<EdgeElement,VertexElement> e, EdgeElement x) = 0;

	/*
	 * Insert and return a new vertex storing element x
	 */
	virtual Vertex<VertexElement> insert_vertex(VertexElement x) = 0;

	/*
	 * Insert and return a new undirected edge with end vertices v and w and
	 * storing element x
	 */
	virtual Edge<EdgeElement,VertexElement> insert_edge(Vertex<VertexElement> v,
			Vertex<VertexElement> w, EdgeElement x) = 0;

	/*
	 * Remove vertex v and all its incident edges and return the element stored
	 * at v
	 */
	virtual VertexElement remove_vertex(Vertex<VertexElement> v) = 0;

	/*
	 * Remove edge e and return the element stored at e
	 */
	virtual EdgeElement remove_edge(Edge<EdgeElement,VertexElement> e) = 0;
};


#endif /* GRAPH_HPP_ */
