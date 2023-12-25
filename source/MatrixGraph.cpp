#include "MatrixGraph.hpp"
#include"IGraph.hpp"
#include <vector>

MatrixGraph::MatrixGraph(int init_size){
		vertices.resize(init_size);
		for (std::vector<int> item:vertices){
			item.resize(init_size);
		}
	};

MatrixGraph::MatrixGraph(const IGraph& graph){
		int new_size = graph.VerticesCount();
		vertices.resize(new_size);
		for (int i = 0; i<new_size;++i){
			vertices[i].resize(new_size);
			std::vector<int> next_vertices = graph.GetNextVertices(i);
               for (int j: next_vertices){
				vertices[i][j] = 1;
			}
               
          }
	};

MatrixGraph::~MatrixGraph(){
	};
void MatrixGraph:: AddEdge(int from, int to) {
     int max_s = std::max(from, to);//если вдруг подали вершину, которая для этого не встречалась, то увеличиваем нашу таблицу
     if (max_s > vertices.size()){//можно было наверно и просто ошибку выдавать
          vertices.resize(max_s);
          for (std::vector<int> v :vertices){
               v.resize(max_s);
          }
     }
		vertices[from][to] = 1;
	};
int MatrixGraph::VerticesCount() const  {
		return vertices.size();
	};
 std::vector<int> MatrixGraph:: GetNextVertices(int vertex) const {
		std::vector<int> next_vertices;
		for (int i =0; i<vertices.size();++i){
			if (vertices[vertex][i] ==1){
                    next_vertices.push_back(i);
               }
		}
		return next_vertices;
	};
std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
		std::vector <int> prev_vertices;
		for (int from = 0; from<vertices.size(); ++from){
               if (vertices[from][vertex] == 1){
                    prev_vertices.push_back(from);
               }
		}
		return prev_vertices;
	};