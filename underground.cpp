#include "underground.hpp"

namespace underground {


std::vector<helpers::IdType> Underground::FindShortestWay(size_t begin_time,
												 const helpers::IdType& begin,
												 const helpers::IdType& end) {
	helpers::Graph current_underground = BuildGraph(begin_time);
	return current_underground.FindWayWithId(begin, end);
}

// not work properly, now work as FindShortestWay
std::vector<helpers::IdType> Underground::FindWayForReading(size_t begin_time,
															const helpers::IdType& begin,
															const helpers::IdType& end) {
	helpers::Graph current_underground = BuildGraph(begin_time);
	return current_underground.FindWayWithId(begin, end);
}

void Underground::AddStation(const helpers::IdType& station,
							 const helpers::IdType& line,
							 ssize_t position,
							 const std::string& name,
							 const std::vector<helpers::IdType>& changes) {
	size_t line_n = lines_by_id_[line];

	std::vector<size_t> changes_n(changes.size());
	for (size_t i = 0; i < changes.size(); ++i) {
		changes_n[i] = stations_by_id_[changes[i]];
	}

	stations_by_id_[station] = stations_.size();

	stations_.push_back({station, line_n, name, changes_n});

	if (position == -1) {
		lines_[line_n].stations.push_back(station);
	} else {
		lines_[line_n].stations.insert((size_t)position +
									   lines_[line_n].stations.begin(),
									   stations_.size());
	}
}

void Underground::AddLine(const helpers::IdType& line,
						  size_t interval,
						  const std::string& name) {
	lines_.push_back({});
}

helpers::Graph Underground::BuildGraph(size_t current_time) {
	std::vector<helpers::IdType> verticles;
	std::vector<std::vector<helpers::Edge>> edges;

	// realisation

	return helpers::Graph(verticles, edges);
}

}; // namespace underground
