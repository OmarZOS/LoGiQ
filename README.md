# LoGiQ
One of Omar ZAIDI's ambitious ideas reflected an SFML C++ based game, a simple party game..


### Installing :
    cd LoGiQ/
    make install

### Playing :
    
    make test

### Gameplay :

Each of the four players has a fixed character color and a random set of colors for each of the directions.

- The circle in the middle gets the color of the player (red,green,blue,yellow).
- Press [SPACE] to start the current round.
  
An arrow shall appear, with the same color as one of the surrounding triangles.  

- Press [SPACE] again if you want to suicide.
- According to the arrow's orientation, use the following logic
  - If it has the upper triangle color, follow it.
  - If it has the right triangle color, follow its right side.
  - If it has the left triangle color, follow its left side.
  - If it has the bottom triangle color, follow the opposite side of it.
- The (Bell/Buzzer) sound will tell you about the correctness.
- The player's score is increased depending on the **speed** of answering if he had a **correct** answer.


When every player has had played a round, the player with the least score is kicked.

### Screenshots :

##### Turn left : 


![turn left](Screenshots/Screenshot%20from%202021-11-28%2000-40-17.png)

##### Kicking a player :

![Kicked blue](Screenshots/Screenshot%20from%202021-11-28%2000-40-40.png)

![Kicked red](Screenshots/Screenshot%20from%202021-11-28%2000-40-47.png)

### About :
This was my first OOP project during my studies. I made it from scratch in 3
days, every single instruction of it using Ubuntu's gedit editor and automated
the build process using make which I took the initiative of learning on my own.
It was assigned to make a game of our choice, I have chosen to realise the
idea that I was thinking since about a year before, It was inspired by the
famous dice game at the time "Ludo", I thought that people had fun of some
random game, I wanted to make a much more challenging game, a decent game
where you can win because of a better skill of adaptation, reflexion and speed.
