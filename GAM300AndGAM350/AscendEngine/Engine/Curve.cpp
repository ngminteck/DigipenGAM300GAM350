#include "pch.h"

Curve::Curve()
: _steps(100)
{

}

Curve::~Curve()
{
}

void Curve::clear()
{
	_nodes.clear();
	_way_points.clear();
	_distances.clear();
}

void Curve::add_way_point(const Vec3& point)
{
	_way_points.push_back(point);
	_on_way_point_added();
}



void Curve::add_node(const Vec3& node)
{
	_nodes.push_back(node);

	

	if(_nodes.size()==1)
	{
		_distances.push_back(0);
	}
	else
	{
		int new_node_index=_nodes.size() - 1;

		double segment_distance=(_nodes[new_node_index] - _nodes[new_node_index-1]).Magnitude();
		_distances.push_back(segment_distance + _distances[new_node_index-1]);
	}
}
