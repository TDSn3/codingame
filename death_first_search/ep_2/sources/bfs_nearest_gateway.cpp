
#include "../includes/header.hpp"

pair<int, int>	bfs_nearest_gateway(Data &data, int origin, int max_dist)
{
	queue<std::pair<int, int> >	bfs_queue;
	vector<bool>				visited(data.vertices.size(), false);
	int							neighbor;

	bfs_queue.push(pair<int, int>(origin, 0));
	visited[origin] = true;
	while (!bfs_queue.empty())
	{
		int index = bfs_queue.front().first;
		int dist = bfs_queue.front().second;

		bfs_queue.pop();
		if (dist < max_dist)
		{
			for (size_t j = 0; j < data.vertices[index].edges.size(); j++)
			{
				neighbor = data.vertices[index].edges[j].second->index;
				if (data.vertices[index].edges[j].first && !visited[neighbor])
				{
					bfs_queue.push(pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;

					if (data.vertices[neighbor].gateway)
						return (pair<int, int>(index, neighbor));
				}
			}
		}
	}
	return (pair<int, int>(-1, -1));
}
