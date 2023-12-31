#pragma once
#include <vector>
#include "IGraph.hpp"


class MatrixGraph: public IGraph{
     public:
	MatrixGraph(int init_size);
	MatrixGraph(const IGraph& graph);
	virtual ~MatrixGraph();
	virtual void AddEdge(int from, int to) override;
	virtual int VerticesCount() const override ;
	virtual std::vector<int> GetNextVertices(int vertex) const override;
	virtual std::vector<int> GetPrevVertices(int vertex) const override;
	private:
	std::vector <std::vector<int>> vertices;
	
};