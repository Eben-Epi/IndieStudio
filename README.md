Indie Studio

How to launch the game :

- On Linux (with a command prompt):
	Create a directory named build (with command `mkdir build`).
	Go in this directory (with the command `cd build`).
	Execute the command `cmake ..`.
	Then execute the command `make` and wait.
	Go back to the previous directory (with the command `cd ..`).
	Finally execute the command `./build/bomberman`.

- On Windows (with a command prompt):
	Create a directory named build (with command `mkdir build`).
	Go in this directory (with the command `cd build`).
	Execute the command `cmake ..`.
	Then execute the command `make` and wait.
	Go back to the previous directory (with the command `cd ..`).
	Finally execute the command `./build/bomberman`.

- On Windows (without command prompt) :
	Go in the directory `bonus` then the directory `mingw32-exe`.
	Double clic on `bomberman.exe`.

How to play :

	You can choose the number of players and the number of AI.
	The number max of players is 4 and the minimum is 2. For example, you can play with 2 players and 2 AI, but can't play with 3 players and 2 AI.

	Commands for each player are defined when you create a new game.
	There are ultimates that you need to charge to use them.
		Sydney : Became invincible and get a boost of movement speed.
		AlphaOne : Throw a chock wave in column or in rows. It destructs everything on its way.
		Lonie : Stun all enemies for a few seconds, then slow them a lot.
		Gunguy : Thorw bombs on feets of his enemies.

	There are bonuses and penalties that can be dropped when you destruct a brick wall.
	- Bonuses :
		Dark green : 1 more bombs.
		Blue : give kick bombs ability.
		Light blue : Wall Pass.
		Red : increase range of bombs by one.
		Yellow : increase speed.
	- Penalties :
		Skull :
			The skull can be given to another player by touching it.
			Effect random among :
				Ultra Speed: Really high speed,
				Ultra Slow: Really low speed,
				Reverse Control: Control reversed,
				No drop: Cannot drop bombs,
				Auto drop: Automaticaly drop bombs
