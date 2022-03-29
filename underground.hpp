#pragma once

#include <unordered_map>

#include "helpers.hpp"
#include "graph.hpp"

namespace underground {

class UndergroundBuilder;

class Underground {
public:
	Underground() {}

	std::vector<helpers::IdType> FindShortestWay(size_t begin_time,
                                        const helpers::IdType& begin,
                                        const helpers::IdType& end);

    // not work properly, now work as FindShortestWay
    std::vector<helpers::IdType> FindWayForReading(size_t begin_time,
                                          const helpers::IdType& begin,
                                          const helpers::IdType& end);

	void AddStation(const helpers::IdType& station,
                    const helpers::IdType& line,
                    ssize_t position = -1,
                    const std::string& name = "",
                    const std::vector<helpers::IdType>& changes = {});

	void AddLine(const helpers::IdType& line,
                 size_t interval,
                 const std::string& name = "");

private:
	helpers::Graph BuildGraph(size_t current_time);

private:
	std::vector<helpers::Station> stations_;
	std::vector<helpers::Line> lines_;
    std::unordered_map<helpers::IdType, size_t> stations_by_id_;
    std::unordered_map<helpers::IdType, size_t> lines_by_id_;
};

}; // namespace underground
