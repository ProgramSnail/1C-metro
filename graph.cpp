#include <set>

#include "graph.hpp"

namespace underground {

namespace helpers {

Graph::Graph(const std::vector<size_t>& verticles,
             const std::vector<std::vector<Edge>>& edges)
		: verticles_(verticles), edges_(edges) {
    for (size_t i = 0; i < verticles_.size(); ++i) {
        id_to_position_[verticles_[i]] = i;
    }
}

std::vector<IdType> Graph::FindWayWithId(IdType begin, IdType end) {
    std::vector<IdType> answer;
    Way way = FindWay(id_to_position_[begin], id_to_position_[end]);
    return answer;
}

Way Graph::FindWay(size_t begin, size_t end) {
    struct VertexId {
        size_t cost;
        size_t id;
    };

    size_t length_answer;
    std::vector<EdgeFrom> way_answer;

    std::vector<size_t> way(verticles_.size(), constants::kInf);
    std::vector<EdgeFrom> edge_from(verticles_.size());
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

    if (length_answer != constants::kInf) {
        while (end != begin) {
            way_answer.push_back(edge_from[end]);
            end = edge_from[end].vertex;
        }
    }

    return {begin, end, length_answer, way_answer};
}

}; //namespace helpers

}; // namespace underground
