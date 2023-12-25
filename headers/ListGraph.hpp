#pragma once
#include <vector>
#include "IGraph.hpp"


class ListGraph: public IGraph{
     public:
	ListGraph(int init_size);
	ListGraph(const IGraph& graph);
	virtual ~ListGraph();
	virtual void AddEdge(int from, int to) override;
	virtual int VerticesCount() const override ;
	virtual std::vector<int> GetNextVertices(int vertex) const override;
	virtual std::vector<int> GetPrevVertices(int vertex) const override;
	private:
	std::vector <std::vector<int>> vertices;
	
};