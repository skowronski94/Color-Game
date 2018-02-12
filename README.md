# Color-Game
Logic Game implemented in C++ in Qt framework. Described by specification and UML diagrams.

It is a simple window game where the player need to clear area from coloured balls. 
For more details about the application and game itself take a look at specification if you know polish language.
If you are interested in architecture details you can take a look at UML Class and Sequence diagrams.

Short game rules 

1. Start game with button START
2. Click at ball clear an area determined by balls in the same color which are neightbours to themself.
3. Repeat step 2 until there will be 1 or more empty columns. Notice that every click decrement the counter.
4. Click COUNT to count points. Nuber of points is determined by number of empty columns.
5. The game ends when counter equals to 0. It this moment points are counted for the last time.
