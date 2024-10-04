#ifndef GAME_HPP
# define GAME_HPP

# include "../utils.hpp"
# include "Data.hpp"

class Game
{
	public:

		// ⤹ actions.cpp
			void	tube(int buildingId1, int buildingId2);
			void	upgrade(int buildingId1, int buildingId2);
			void	teleport(int buildingIdEntrance, int buildingIdExit);
			void	pod(int podId, initializer_list<int> buildingIds);
			void	destroy(int podId);
			void	wait();
			void	end();

		Data	data;

	protected:

	private:

};

#endif
