#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

public GameModel{


	private:
	ZombieController Zombie_Controller;
	Board board;

	public:
	GameModel();
	void Update();
	void Render();

}

#endif
