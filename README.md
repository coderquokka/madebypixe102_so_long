# so_long
*And thanks for all the fish!*

### Table of Contents

* [Introduction](#introduction)
* [How it Works](#how-it-works)
* [Extras](#extras)
* [Gameplay](#gameplay)
* [Other Maps](#other-maps)
* [Installation](#installation)
* [Technical Issues](#technical-issues)
* [Summary](#summary)

## Introduction
In this project, we'll code a simple 2D game to get familiar with interfaces. In my case, it will be Pacman.

### Game Rules
The game we choose must follow a set of rules. The executable ``so_long`` will receive a map as the only argument, and this map will have a ``.ber`` filetype.

The file also must follow these rules:
- Only ``P`` *(pacman)*, ``1`` *(wall)*, ``0`` *(empty)*, ``C`` *(collectible)*, and ``E`` *(exit)* will be accepted characters in our map (except if you add enemies as bonus)
- The map must be rectangular, i.e. all rows must have the same length
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed, i.e. surrounded by walls

If any of these checks fail, the game must end with ``Error\n`` followed by a custom message.

The goal is for the player(s) to collect all the collectibles on the map before going to an exit in the least possible number of steps

## How it Works
For the graphics part of the project we used a library called ``minilibx``. It's fairly basic and somewhat limited, but was still fun to use in the project



### Part one: reading the map

In this part of the code I checked that the given map was properly opened, that it had a ``.ber`` filetype, and then continued by reading the file one line at a time with ``get_next_line``.
Once that was done I filled a struct ``t_lay`` with some basic map attributes like number of players, exits, collectibles, number of rows and columns, etc. During the reading process I also created a string containin the entire map, whcih was then very useful to create a matrix with ``ft_split`` with ``\n`` as the separator.



### Part 2: starting the game

For this part I took the ``t_lay`` and my map matrix to build my main ``t_game`` struct. This struct includes more detailed information about my game state, such a list of pacmans, a list of ghosts, the number of loop repetitions (frames), and other info. From here I initialized a window with the mlx function and started drawing the static elements of the map (walls, spaces and collectibles) on the window. The mlx library, as other graphic libraries, has an infinite loop where the game events happen. From here I check the state of the game to re-print certain elements of the map or to manage special events, such as when Pacman dies or when ghosts are in panic mode.
The ``mlx`` library has hooks, which essentially link certain events on the computer (keypresses, mouse clicks, etc) with functions we implement. In my case I 'hooked' the end of the game function to pressing the ``x`` button to close a window. Also, I used a key hook to link keypresses with pacman's movements.


### Part 3: game mechanics

When ``esc``/``Q`` is pressed, the game ends. If the arrow keys or the ``W``. ``A``, ``S``, ``D`` keys are pressed, every pacman on the map changes its direction and tries to move in that direction. Also, every so often all pacmans will all try to move in the same direction they're headed. This way the arrow/WASD keys just change pacmans' directions to make them move forward till they hit a wall.
Ghosts behave similarly (they're the first bonus: enemies), but instead of responding the keypress, they use a basic algorithm to find the closest pacman and try to catch it. Whenever a pacman is caught by a ghost, the attribute ``pac_dying`` is set to 1 in the ``t_game`` struct and all pacmans die with a short animation.
Ghosts load in seven different colors, and each new ghost will have a different color. To do this, I had to load every sprite of every color with the mlx library and assign a new color to every new ghost with ``ghost_number % number_of_colors``, thus rotating through the list of colours when there are more ghosts than available colors.

Lastly, if a pacman reaches an exit and there are no collectibles left, it will be deleted from the list of players. If all pacmans reach the exit, the game ends and the final score is displayed.


### Part 4: animations

There are several animations throughout the game (it's the other bonus in the project), from pacman's gobbling animation or ghosts' panic mode to pacman's death animation. They are all animated in a similar way: with linked lists. Every node in the list corresponds to an image of the animation. Every so often a function is called which will move to the next image, and if the last one is found, the node resets to the top of the linked list.

Pacman and ghosts move on the map matrix, which is much smaller than the mlx window. For this reason and to make movement smooth it is interesting to keep a position in the matrix (``pos``) and a position on the window (``win_pos``) for every pacman/ghost, and update the position on the window one pixel at a time untill ``pos * sprite_size == win_pos``.


## Extras

The pacman game I designed has a few extras we weren't asked to implement, but I thought would make the overall game experience better. Here's a list of the most relevant additions:

- Add custom (simple) chasing algorithm using euclidean distances.
- Ability to restart the game by pressing the ``R`` key
- Ability to exit the game by pressing the ``Q`` key
- Ghosts enter panic mode when there's less than a third of the pacdots remaining. During this time the players will be faster and ghosts will flash for the sake of distraction
- The score is displayed in the classic pacman fonts, instead of the (ugly) builtin fonts from ``mlx_string_put()``
- Arrow keys also move the player
- Add decorating pacman logo centered at the bottom
- Add support for both ``linux`` and ``MacOS``
- Implement several players in a single map
- Ability to save a direction for when it's available
- Added over 30 test maps (most of them playable)
- Restrict ending or resetting the game while pacman is dying

## Gameplay

There are a total of 30 maps available. See [MAPS.md](https://github.com/madebypixel02/so_long/tree/master/tests/MAPS.md)

Here are a few sample gameplays from my favorite maps:



https://user-images.githubusercontent.com/40824677/143445307-83c3ff1f-7294-4238-9faa-dc0e0eabb314.mp4

https://user-images.githubusercontent.com/40824677/143445401-1ad6a78e-dd5e-431c-b3f3-eaa386fbf803.mp4

https://user-images.githubusercontent.com/40824677/143445427-6c5f6597-c7cf-4f17-9c10-3aa52c9207a2.mp4

https://user-images.githubusercontent.com/40824677/143445444-5beb9455-d436-4500-a872-ceb262f0904f.mp4


## Other Maps
There are 20+ maps (ported from [Machine-Learning-Pacman](https://github.com/madebypixel02/Machine-Learning-Pacman/tree/master/layouts)) to try your skill/luck.

See [Other Maps](https://github.com/madebypixel02/so_long/tree/master/tests/MAPS.md#other-maps)

## Installation

### Cloning the repositories
```shell
git clone https://github.com/madebypixel02/so_long.git
cd so_long
make
```

### Installing the MLX library

* ``Linux``

If you're not using a MacOS device from 42, you'll need to install the libraries manually. Please refer to the [official github](https://github.com/42Paris/minilibx-linux) for more details. To install it, do the following (requires root access):

```shell
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux/
make
sudo cp mlx.h /usr/include
sudo cp libmlx.a /usr/lib
```

* ``MacOS``

To install the library, you will need to first install a package manager like homebrew (check [here](https://brew.sh/)) to then install the X11 package with ``brew install Xquartz``. After that you must extract the minilibx file called ``minilibx_opengl.tgz``. then install it to your system with the following commands (requires sudo as well):

```shell
cd minilibx_opengl
make
sudo cp mlx.h /usr/local/include
sudo cp libmlx.a /usr/local/lib
sudo reboot
```
Note: A reboot is necessary to ensure that the ``Xquartz`` is working properly. You can test if it is by running a test example with the command ``xeyes``.

### Installing the manuals

If you want quick access to the mlx manuals, it is recommended that you copy the files from the ``man`` folder in [minilibx-linux](https://github.com/42Paris/minilibx-linux) to your system manuals:

* ``Linux``
```shell
sudo cp man/man3/* /usr/share/man/man3/
```
Note: Depending on your Linux configuration, to get the manuals working (e.g. ``man mlx``) you will need to individually gzip all the manual files you just copied, e.g. ``sudo gzip /usr/share/man/man3/mlx.3``.

* ``MacOS``
```shell
sudo cp man/man3/* /usr/X11/share/man/man3
```

### Usage

```
make                        compiles so_long executable
make test MAP={path_to_map} compiles and executes so_long with the specified map
make play                   compiles and executes a small set of maps sequentially
make play2                  compiles and executes a much larger set of maps sequentially
make git                    adds and commits everything, then pushes to upstream branch
make norminette             runs norminette for all files in the project that need to pass it
```

## Technical Issues

Throughout the project, there have been a few roadblocks that needed to be worked around, here's some of them:

- Timing: getting the timing for animations and other stuff right was quite challenging. I ended up just using the number of loop repetitions from ``mlx_loop_hook`` and fiddling with different rates, which also varied a lot between MacOS and Linux.
- Sprites: The minilibx in Linux doesn't handle transparency in sprites the same way MacOS' minilibx does. On Linux the sprites will just have black pixels in the transparent area. I found ways to work this around but it was too much of a hussle.
- Leaks: Minilibx has some leaks that are only detected by ``valgrind``. Using the function ``mlx_destroy_display`` solves that leak, but apparently that function isn't a part of the minilibx in MacOS. For this reason I decided to split the file where that function was called, so that the file compiled in Linux had that extra line for valgrind to be happy.
- Keycodes: yet another difference between MacOS and Linux. The keycodes (``WASD``, ``ESC``, etc) are completely different. I defined those variables straight from the makefile to correct this issue.

## Summary
This has been my favorite project so far, coding my own pacman clone was so much fun, regargless how flawed it might be :)

August 14th, 2021
