//============================================================================
// Name        : cpp_data_structures.cpp
// Author      : Arnaud Schils
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "graph/GraphEdgeList.hpp"

using namespace std;

class TestObject {
public:
	int x;
	std::string s;

	TestObject(){
		x = 2;
		s = "un string";
	}

	TestObject(int x, std::string s){
		this->x = x;
		this->s = s;
	}
};

void test_graph_edge_list(){

	GraphEdgeList<TestObject,TestObject> g;

	//Test vertex insertion
	TestObject o1(1, "1");
	TestObject o2(2, "2");
	TestObject o3(3, "3");
	Vertex<TestObject> v1 = g.insert_vertex(o1);
	Vertex<TestObject> v2 = g.insert_vertex(o2);
	Vertex<TestObject> v3 = g.insert_vertex(o3);

	GraphEdgeList<TestObject,TestObject>::VertexContainer vc = g.vertices();
	int expected_size = 3;
	bool size_ok = vc.size() == expected_size;
	if(!size_ok)
		cout << "vertex insertion test: vertices collection size is "
		<< vc.size() << " instead of " << expected_size << endl;

	//Test edge insertion
	TestObject oe1(1, "e1");
	TestObject oe2(2, "e2");

	Edge<TestObject,TestObject> e1 = g.insert_edge(v1, v2, oe1);
	Edge<TestObject,TestObject> e2 = g.insert_edge(v2, v3, oe2);

	GraphEdgeList<TestObject,TestObject>::EdgeContainer ec = g.edges();
	expected_size = 2;
	size_ok = ec.size() == expected_size;
	if(!size_ok)
		cout << "edge insertion test: edge collection size is " << ec.size() <<
		" instead of " << expected_size << endl;


	//Test vertex removal
	g.remove_vertex(v2);
	ec = g.edges();
	expected_size = 0;
	size_ok = ec.size() == expected_size;
	if(!size_ok)
		cout << "remove vertex test: edge collection size is " << ec.size() <<
		" instead of " << expected_size << endl;
	vc = g.vertices();
	expected_size = 2;
	size_ok = vc.size() == expected_size;
	if(!size_ok)
		cout << "remove vertex test: vertex collection size is " << vc.size() <<
		" instead of " << expected_size << endl;

}


int main() {
	test_graph_edge_list();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
