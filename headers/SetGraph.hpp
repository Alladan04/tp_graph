#pragma once
#include <vector>
#include <unordered_set>
#include "IGraph.hpp"


class SetGraph: public IGraph{
     public:
	SetGraph(int init_size);
	SetGraph(const IGraph& graph);
	virtual ~SetGraph();
	virtual void AddEdge(int from, int to) override;
	virtual int VerticesCount() const override ;
	virtual std::vector<int> GetNextVertices(int vertex) const override;
	virtual std::vector<int> GetPrevVertices(int vertex) const override;
	private:
	std::vector <std::unordered_set<int>> vertices;
	
};