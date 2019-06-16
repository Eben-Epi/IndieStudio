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

	There is bonuses and maluses that can be dropped when you destruct a brick wall.
	- Bonuses :
		Dark green : more bombs.
		Light green : give kick bombs ability.
		Purple : increase range of bombs
		Yellow : increase speed.
		White : Wall Pass
	- Malus :
		Skull : random malus among :	Ultra Speed,
										Ultra slow,
										Reverse Control,
										No drop,
										Auto drop


