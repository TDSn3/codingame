#ifndef DATA_HPP
# define DATA_HPP

# include "../utils.hpp"

class Data
{
	public:

		void	update();
		void	printData();

		int		resources;
		int		num_travel_routes;
		map		<pair<int, int>, int> travel_routes;
		int		num_pods;
		int		num_new_buildings;

	protected:

	private:

};

#endif
