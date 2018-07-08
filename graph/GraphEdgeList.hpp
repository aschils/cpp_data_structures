/*
 * GraphEdgeList.hpp
 *
 * Edge list structure data structure for undirected graph.
 *
 *  Created on: 8 juil. 2018
 *      Author: aschils
 */

#ifndef GRAPH_GRAPHEDGELIST_HPP_
#define GRAPH_GRAPHEDGELIST_HPP_

#include "Graph.hpp"

template <typename EdgeElement, typename VertexElement>
class GraphEdgeList : public Graph<EdgeElement, VertexElement> {

protected:
	typename Graph<EdgeElement, VertexElement>::EdgeContainer edges_c;
	typename Graph<EdgeElement, VertexElement>::VertexContainer vertices_c;

public:
	/*
	 * Return an iterable collection of all vertices of the graph
	 */
	typename Graph<EdgeElement, VertexElement>::VertexContainer vertices();

	/*
	 * Return an iterable collection of all edges of the graph
	 */
	typename Graph<EdgeElement, VertexElement>::EdgeContainer edges();

	/*
	 * Return an iterable collection of the edges incident upon vertex v
	 */
	typename Graph<EdgeElement, VertexElement>::EdgeContainer incident_edges(
			Vertex<VertexElement> v);

	/*
	 * Return the end vertex of edge e distinct from vertex v; an error occurs
	 * if e is not incident on v.
	 */
	Vertex<VertexElement> opposite(Vertex<VertexElement> v, Edge<EdgeElement,VertexElement> e);

	/*
	 * Return an array storing the end vertices of edge e
	 */
	std::vector<Vertex<VertexElement> > end_vertices(Edge<EdgeElement,VertexElement> e);

	/*
	 *Test wether vertices v and w are adjacent
	 */
	bool are_adjacent(Vertex<VertexElement> v, Vertex<VertexElement> w);

	/*
	 * Replace element stored at v with x
	 */
	void replace(Vertex<VertexElement> v, VertexElement x);

	/*
	 * Replace the element stored at edge e with x
	 */
	void replace(Edge<EdgeElement,VertexElement> e, EdgeElement x);

	/*
	 * Insert and return a new vertex storing element x
	 */
	Vertex<VertexElement> insert_vertex(VertexElement x);

	/*
	 * Insert and return a new undirected edge with end vertices v and w and
	 * storing element x
	 */
	Edge<EdgeElement,VertexElement> insert_edge(Vertex<VertexElement> v,
			Vertex<VertexElement> w, EdgeElement x);

	/*
	 * Remove vertex v and all its incident edges and return the element stored
	 * at v
	 */
	VertexElement remove_vertex(Vertex<VertexElement> v);

	/*
	 * Remove edge e and return the element stored at e
	 */
	EdgeElement remove_edge(Edge<EdgeElement,VertexElement> e);
};

/*
 * Return an iterable collection of all vertices of the graph
 */
template <typename EdgeElement, typename VertexElement>
typename Graph<EdgeElement, VertexElement>::VertexContainer
GraphEdgeList<EdgeElement, VertexElement>::vertices(){
	return vertices_c;
}

/*
 * Return an iterable collection of all edges of the graph
 */
template <typename EdgeElement, typename VertexElement>
typename Graph<EdgeElement, VertexElement>::EdgeContainer
GraphEdgeList<EdgeElement, VertexElement>::GraphEdgeList::edges(){
	return edges_c;
}

/*
 * Return an iterable collection of the edges incident upon vertex v
 */
template <typename EdgeElement, typename VertexElement>
typename Graph<EdgeElement, VertexElement>::EdgeContainer
GraphEdgeList<EdgeElement, VertexElement>::incident_edges(Vertex<VertexElement> v){
	typename Graph<EdgeElement, VertexElement>::EdgeContainer incident_edges;
	for (typename Graph<EdgeElement, VertexElement>::EdgeContainer::iterator
			it=edges_c.begin();
			it!=edges_c.end(); ++it){
		Vertex<VertexElement> *start_vertex = it->start;
		Vertex<VertexElement> *end_vertex = it->end;

		if(start_vertex == v.position  || end_vertex == v.position)
			incident_edges.push_back(*it);
	}
	return incident_edges;
}

/*
 * Return the end vertex of edge e distinct from vertex v; an error occurs
 * if e is not incident on v.
 */
template <typename EdgeElement, typename VertexElement>
Vertex<VertexElement> GraphEdgeList<EdgeElement, VertexElement>::opposite(
		Vertex<VertexElement> v, Edge<EdgeElement, VertexElement> e){

	bool e_is_start = v.position == e.start;
	bool e_is_end = v.position == e.end;

	if(!e_is_start && !e_is_end)
		throw std::runtime_error("opposite: Edge e is not incident on vertex v.");

	if(e_is_start)
		return *(e.end);
	else
		return *(e.start);
}

/*
 * Return an array storing the end vertices of edge e
 */
template <typename EdgeElement, typename VertexElement>
std::vector<Vertex<VertexElement> >
GraphEdgeList<EdgeElement, VertexElement>::end_vertices(
		Edge<EdgeElement, VertexElement> e){
	std::vector<Vertex<VertexElement> > a;
	a[0] = *e.start;
	a[1] = *e.end;
	return a;
}

/*
 *Test wether vertices v and w are adjacent
 */
template <typename EdgeElement, typename VertexElement>
bool GraphEdgeList<EdgeElement, VertexElement>::are_adjacent(
		Vertex<VertexElement> v, Vertex<VertexElement> w){
	typename Graph<EdgeElement, VertexElement>::EdgeContainer v_incident_edges =
			incident_edges(v);
	typename Graph<EdgeElement, VertexElement>::EdgeContainer::iterator it;
	for (it = v_incident_edges.begin(); it != v_incident_edges.end(); ++it){
		if(it->start == w.position || it->end == w.position)
			return true;
	}
	return false;
}

/*
 * Replace element stored at v with x
 */
template <typename EdgeElement, typename VertexElement>
void GraphEdgeList<EdgeElement, VertexElement>::replace(
		Vertex<VertexElement> v, VertexElement x){
	v.position->x = x;
}

/*
 * Replace the element stored at edge e with x
 */
template <typename EdgeElement, typename VertexElement>
void GraphEdgeList<EdgeElement, VertexElement>::replace(
		Edge<EdgeElement, VertexElement> e, EdgeElement x){
	e.position->x = x;
}

/*
 * Insert and return a new vertex storing element x
 */
template <typename EdgeElement, typename VertexElement>
Vertex<VertexElement> GraphEdgeList<EdgeElement, VertexElement>::insert_vertex(
		VertexElement x){
	Vertex <VertexElement> v;
	v.x = x;
	vertices_c.push_back(v);
	v.position = &vertices_c.back();
	vertices_c.back().position = v.position;

	return v;
}

/*
 * Insert and return a new undirected edge with end vertices v and w and
 * storing element x
 */
template <typename EdgeElement, typename VertexElement>
Edge<EdgeElement, VertexElement>
GraphEdgeList<EdgeElement, VertexElement>::insert_edge(Vertex<VertexElement> v,
		Vertex<VertexElement> w, EdgeElement x){
	Edge<EdgeElement, VertexElement> e(x, v.position, w.position);
	edges_c.push_back(e);
	e.position = &edges_c.back();
	edges_c.back().position = e.position;
	return e;
}

/*
 * Remove vertex v and all its incident edges and return the element stored
 * at v
 */
template <typename EdgeElement, typename VertexElement>
VertexElement GraphEdgeList<EdgeElement, VertexElement>::remove_vertex(
		Vertex<VertexElement> v){

	typename Graph<EdgeElement, VertexElement>::EdgeContainer::iterator it_e;
	it_e = edges_c.begin();

	while(it_e != edges_c.end()){
		if(it_e->start == v.position || it_e->end == v.position)
			edges_c.erase(it_e++);
		else
			it_e++;
	}

	typename Graph<EdgeElement, VertexElement>::VertexContainer::iterator it;

	it = vertices_c.begin();
	while(it != vertices_c.end()){
		if(it->position == v.position){
			vertices_c.erase(it);
			return v.x;
		}
		it++;
	}

	throw std::runtime_error("remove_vertex: No vertex v in the graph.");
}

/*
 * Remove edge e and return the element stored at e
 */
template <typename EdgeElement, typename VertexElement>
EdgeElement GraphEdgeList<EdgeElement, VertexElement>::remove_edge(
		Edge<EdgeElement, VertexElement> e){

	typename Graph<EdgeElement, VertexElement>::EdgeContainer::iterator it;
	it = edges_c.begin();

	while(it != edges_c.end()){
		if(it->position == e.position){
			edges_c.erase(it);
			return e.x;
		}
	}
	throw std::runtime_error("remove_edge: No edge e in the graph.");
}

#endif /* GRAPH_GRAPHEDGELIST_HPP_ */
