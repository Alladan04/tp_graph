#include "ListGraph.hpp"
#include "ArcGraph.hpp"
#include "MatrixGraph.hpp"
#include "SetGraph.hpp"

#include <iostream>
#include <vector>
#include <queue>

void dfs_aux(int u, const IGraph &graph, std::vector<bool> &visited, void (*callback)(int v)){
    visited[u] = true;
    callback(u);
    std::vector<int> children = graph.GetNextVertices(u);

    for (int v : children){
        if (!visited[v]){
            dfs_aux(v, graph, visited, callback);
        }
    }
}

void dfs(const IGraph &graph, void (*callback)(int v)){
    int vertices_count = graph.VerticesCount();
    std::vector<bool> visited;
    visited.assign(vertices_count, false);
    for (int i = 0; i < vertices_count; ++i){
        if (!visited[i]){
            dfs_aux(i, graph, visited, callback);
        }
    }
}

void bfs_aux(int u, const IGraph &graph, std::vector<bool> &visited, void (*callback)(int v)){
    std::queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        callback(v);

        std::vector<int> children = graph.GetNextVertices(u);
        for (int w : children){
            if (!visited[w]){
                visited[w] = true;
                q.push(w);
            }
        }
    }
}

void bfs(const IGraph &graph, void (*callback)(int v)){
    int vertices_count = graph.VerticesCount();

    std::vector<bool> visited;

    visited.assign(vertices_count, false);
    for (int i = 0; i < vertices_count; ++i) {
        if (!visited[i]) {
            bfs_aux(i, graph, visited, callback);
        }
    }
}


void cb_func(int num){
     std::cout<<num<<" ";
}
int main(){
     ListGraph list_gr(6);
     list_gr.AddEdge(0, 1);//+ 1,0
     list_gr.AddEdge(1, 2);//+ 2,1
     list_gr.AddEdge(2, 4);//+ 4,2
     list_gr.AddEdge(2, 3);//+3,2
     list_gr.AddEdge(3, 4);//+4,3
     list_gr.AddEdge(2,5);

     std::cout<<"bfs ListGraph"<<std::endl;
     bfs(list_gr, cb_func);
     std::cout<<std::endl;

     MatrixGraph matr_gr(list_gr);
     std::cout<<"bfs MatrixGraph"<<std::endl;
     bfs(matr_gr, cb_func);
     std::cout<<std::endl;

     SetGraph set_gr(matr_gr);
     std::cout<<"bfs SetGraph"<<std::endl;
     bfs(set_gr, cb_func);
     std::cout<<std::endl;

     ArcGraph arc_gr(set_gr);
     std::cout<<"bfs ArcGraph"<<std::endl;
     bfs(arc_gr, cb_func);
     std::cout<<std::endl;

     std::cout<<"dfs ListGraph"<<std::endl;
     dfs(list_gr, cb_func);
     std::cout<<std::endl;
     
     std::cout<<"dfs MatrixGraph"<<std::endl;
     dfs(matr_gr, cb_func);
     std::cout<<std::endl;

     std::cout<<"dfs SetGraph"<<std::endl;
     dfs(set_gr, cb_func);
     std::cout<<std::endl;

     std::cout<<"dfs ArcGraph"<<std::endl;
     dfs(arc_gr, cb_func);
     std::cout<<std::endl;
//выводит вершины с точностью до порядка последних трех вершин

}