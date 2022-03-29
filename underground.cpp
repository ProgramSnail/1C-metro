#include <vector>
#include <string>
#include <fstream>
#include <set>

#include "underground.hpp"

const size_t kInf = 1e9;

struct Station {
	size_t id;
	size_t line_id;
	std::string name;
	std::vector<size_t> changes;
};

struct Line {
	size_t interval;
	std::string name;
	std::vector<size_t> stations;
};

struct Edge {
	size_t end;
	size_t cost;
};

struct EdgeFrom {
	size_t vertex;
	size_t edge;
};

struct Way {
	size_t begin;
	size_t end;
	size_t length;
	std::vector<EdgeFrom> edges;
};

class Graph {
public:
	Graph(std::vector<std::vector<Edge>> edges)
		: v_count_(edges.size()), edges_(std::forward<std::vector<std::vector<Edge>>>(edges)) {}

	Way SearchShortestWay(size_t begin, size_t end) {
		struct VertexId {
			size_t cost;
			size_t id;
		};

		size_t length_answer;
		std::vector<EdgeFrom> way_answer;

		std::vector<size_t> way(v_count_, kInf);
		std::vector<EdgeFrom> edge_from(v_count_);
		std::set<VertexId> current;

		way[begin] = 0;
		current.insert({begin, 0});

		while (current.size() > 0) {
			size_t vertex = current.begin()->id;
			current.erase(current.begin());
			for (size_t i = 0; i < edges_.size(); ++i) {
				size_t way_cost = way[vertex] + edges_[vertex][i].cost;
				size_t to_vertex = edges_[vertex][i].end;

				if (way[to_vertex] > way_cost) {
					current.erase({way[to_vertex], to_vertex});
					way[to_vertex] = way_cost;
					edge_from[vertex] = {vertex, i};
					current.insert({way[to_vertex], to_vertex});
				}
			}
		}

		length_answer = way[end];

		if (length_answer != kInf) {
			while (end != begin) {
				way_answer.push_back(edge_from[end]);
				end = edge_from[end].vertex;
			}
		}

		return {begin, end, length_answer, way_answer};
	}
private:
private:
	size_t v_count_;
	std::vector<std::vector<Edge>> edges_;
};

class GraphBuilder {
	
};

class Underground {
public:
	Underground() {}

	std::vector<size_t> FindShortestWay(size_t time, size_t begin_id, size_t end_id) {
		Graph current_underground = BuildGraph(time);
	}

	void AddStation( station) {
		stations_.push_back(std::forward<Station>(station));
	}
	void AddLine(std::string line_name, std::) {
		lines_.push_back(std::forward<Line>(line));
	}
	void RemoveStation(size_t station_id) {
		stations_.
	}
	
	void RemoveLine(size_t line_id) {
		lines_
	}
private:
	Graph BuildGraph(size_t time) {

	}
private:
	std::vector<Station> stations_;
	std::vector<Line> lines_;
	GraphBuilder builder_;
};
