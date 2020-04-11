Pranayas Game
(Designed with my Daughter)

### AIM
The Queen is trying to get to the prize. The King is trying to stop her.

If the King bumps into the Queen, the Queen returns to the top of the screen.

If the King bumps into a wall, he is sent to the top of the screen.

*2 player game.*

### On Screen
The Queen 'Q' on the screen.

The King 'K' on the screen.

The prize '$' on the screen.

Wall '#' on the screen.

### Controls
To move King use 

w - up

a - left

s - down

d - right

To move Queen use arrow keys

### Setup
Requires ncurses 

`sudo apt install libncurses5-dev libncursesw5-dev`

`make pranayasgame`

`./pranayasgame`

### BUGS
1. Hardcoded for a terminal of size 50x100 (100 width, 50 height)
2. If both King and Queen are moving you could walk through each other.
3. You can walk off the screen to the right and bottom.
