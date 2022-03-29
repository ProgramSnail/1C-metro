#pragma once

#include <unordered_map>

#include "helpers.hpp"

namespace underground {

namespace helpers {

class Graph {
public:
	Graph(const std::vector<IdType>& verticles,
          const std::vector<std::vector<Edge>>& edges);

	std::vector<IdType> FindWayWithId(IdType begin, IdType end);
private:
    Way FindWay(size_t begin, size_t end);
private:
	std::vector<IdType> verticles_;
	std::vector<std::vector<Edge>> edges_;
    std::unordered_map<IdType, size_t> id_to_position_;
};

}; // namespace helpers

}; // namespace underground
