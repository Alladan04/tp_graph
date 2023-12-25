#pragma once
#include <vector>
#include "IGraph.hpp"


class ArcGraph: public IGraph{
     public:
	ArcGraph(int init_size);
	ArcGraph(const IGraph& graph);
	virtual ~ArcGraph();
	virtual void AddEdge(int from, int to) override;
	virtual int VerticesCount() const override ;
	virtual std::vector<int> GetNextVertices(int vertex) const override;
	virtual std::vector<int> GetPrevVertices(int vertex) const override;
	private:
	std::vector <std::pair<int, int>> vertices;
	
};