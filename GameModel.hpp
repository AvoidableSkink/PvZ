#ifndef GAMEMODEL_HPP
#define GAMEMODEL_HPP

public GameModel{


	private:
	ZombieController z_cont;
	Board board;

	public:
	GameModel();
	void Update();
	void Render();

}

#endif
