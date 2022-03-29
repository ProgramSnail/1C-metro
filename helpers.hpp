#pragma once

#include <vector>
#include <string>

namespace underground {

namespace constants {
  const size_t kInf = 1e9;
};

namespace helpers {

using IdType = size_t;

struct Station {
    IdType id;
	size_t line;
	std::string name;
	std::vector<size_t> changes;
};

struct StationInfo {
    IdType id;
    std::string name;
    std::vector<IdType> changes;
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

}; // namespace helpers

}; // namespace underground
