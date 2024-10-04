#ifndef DATA_HPP
# define DATA_HPP

# include "../utils.hpp"

class Data
{
	public:

		~Data(void) {
			for (auto &pair : buildings)
				delete pair.second;
			buildings.clear();
		}

		void	update();
		void	printData();

		int		resources;
		int		num_travel_routes;
		map		<pair<int, int>, s_route> travel_routes;
		int		num_pods;
		map		<int, s_pod> pods;
		int		num_new_buildings;
		map		<int, s_building*> buildings;

		float	calculateDistance (int buildingId1, int buildingId2);

	protected:

	private:

};

#endif
