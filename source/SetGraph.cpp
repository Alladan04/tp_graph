#include "SetGraph.hpp"
#include <unordered_set>

SetGraph::SetGraph(int init_size){
		vertices.resize(init_size);
	};

SetGraph::SetGraph(const IGraph& graph){
		int new_size = graph.VerticesCount();
		vertices.resize(new_size);
		for (int i = 0; i<new_size;++i){
			std::vector<int> next_vertices = graph.GetNextVertices(i);
               for (int j: next_vertices){
				vertices[i].insert(j);
			}
               
          }
	};

SetGraph::~SetGraph(){

	};
void SetGraph:: AddEdge(int from, int to) {
		vertices[from].insert(to);
	};
int SetGraph::VerticesCount() const  {
		return vertices.size();
	};
 std::vector<int> SetGraph:: GetNextVertices(int vertex) const {
		std::vector<int> next_vertices;
		for (int v: vertices[vertex]){
			next_vertices.push_back(v);
		}
		return next_vertices;
	};
std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
		std::vector <int> prev_vertices;
		for (int from = 0; from<vertices.size(); ++from){
			for (int to: vertices[from]){
				if (to==vertex)
				prev_vertices.push_back(from);
			}
		}
		return prev_vertices;
	};