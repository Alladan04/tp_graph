
#include "ArcGraph.hpp"
#include <vector>
//#include <pair>

ArcGraph::ArcGraph(int init_size){
		vertices.resize(init_size);
	};

ArcGraph::ArcGraph(const IGraph& graph){
		int new_size = graph.VerticesCount();
		//vertices.resize(new_size);
		for (int i = 0; i<new_size;++i){
			std::vector<int> next_vertices = graph.GetNextVertices(i);
               for (int j: next_vertices){
				vertices.push_back(std::pair<int,int>(i,j));
			}
               
          }
	};

ArcGraph::~ArcGraph(){

	};
void ArcGraph:: AddEdge(int from, int to) {
		vertices.push_back(std::pair<int, int> (from, to));
	};
int ArcGraph::VerticesCount() const  {
		return vertices.size();
	};
 std::vector<int> ArcGraph:: GetNextVertices(int vertex) const {
		std::vector<int> next_vertices;
		for (std:: pair<int, int> v: vertices){
			if (v.first == vertex){
                    next_vertices.push_back(v.second);
               }
		}
		return next_vertices;
	};
std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
		std::vector <int> prev_vertices;
		for (std::pair<int, int> v: vertices){
               if (v.second == vertex){
                    prev_vertices.push_back(v.first);
               }
          }
		return prev_vertices;
	};