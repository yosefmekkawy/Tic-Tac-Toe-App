# Tic-Tac-Toe-C-App
a C++ Console game with the following games : 3x3 Tic Tac Toe - Pyramidic Tic Tac Toe - Connect 4 - 5x5 Tic Tac Toe With an ai player Built With MiniMax Algorithm
<h2>Features</h2>
board game that consists of the following games classes, separated into a header file and implementation files:
1-	GameManager that owns a board and 2 players and runs the game and swap turns. 
2-	Player that represents a generic game player that has a name and can do x, y moves
3-	An abstract game Board with functions to be defined in children for rules of the game.
4-	A RandomPlayer that returns a random x, y move.
This framework is suitable for building multiple board games like X-O and similar ones. It shows the power of OOP in reusing existing code to build new apps with less effort. You are given an example X-O game implementation that includes the following classes:
5-	X_O_Board represents the board of X-O and the rules for that game.
6-	X_O_App is an application that creates a GameManager with X_O_Board and 2 players and runs the X-O game.  

<h2>Games</h2>

1-3x3 Tic-Tac-Toe
The Classic Tic Tac Toe Game with the 3x3 board
Winning: The first player to get three-in-a-row vertically, horizontally, or diagonally wins.

2- Pyramic Tic-Tac-Toe
The game board is shaped like a pyramid. Five squares make the base, then three, then one. Players take turns marking Xs and Os as in traditional tic-tac-toe.
Winning: The first player to get three-in-a-row vertically, horizontally, or diagonally wins.
 
3- Four-in-a-row
You will recognize four-in-a row as a two-dimensional version of the classic game, Connect Four. The game board consists of a 7 x 6 grid. Seven columns of six squares each. Instead of dropping counters as in Connect Four, players mark the grid with Xs and Os as in tic-tac-toe.
Rules: The first player places an X in the bottom square of any column. Taking turns, players make their mark in any column, as long as it is in the lowest square possible.
Winning: The first player to get four-in-a-row vertically, horizontally, or diagonally wins.
 
4- 5 x 5 Tic Tac Toe 
This tic-tac-toe variation is played on a 5 x 5 grid. As in the traditional game, players are Xs or Os.
Rules: Players take turns placing an X or an O in one of the squares until all the squares except one are filled. (Each player has 12 turns for a total of 24 squares.) 
Winning: Count the number of three-in-a-rows each player has. Sequences can be vertically, horizontally, or diagonally. Whoever has the most, wins.

<h2>Player Options</h2>
Each game has the option to play with a friend or a random computer player.
also there is a smart ai player built for the 5x5 game using the minimax algorithm to calculate the optimal move.
