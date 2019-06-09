# Rush00 (Classic Shoot-Em-Up Style Game)

The goal of this project is to implement a simplistic shoot-em-up-style game in your terminal. For those of you who don’t know what that kind of game is (shame on you, by the way), have a look at Gradius, R-Type, etc...

You will use a ’screen’ made up of a grid of ’squares’, that you can equate to the characters on your terminal, so that the entities of your game are each represented by a character on screen.

Here are the basic requirements :

• Single-player

• Display using the ncurses library

• Horizontal or vertical scrolling (The screen area moves through the world, very much like in R-Type for example)

• Random enemies

• The player can shoot at enemies

• Basic collision handling (If an enemy touches you, you die)

• Game entities occupy one ’square’ of the map only.

• Frame-based timing


It may seem a little daunting, but the basic requirements can be fulfilled by a game even simpler and way uglier than the already pretty simple Space Invaders. So it’s not actually that hard.

There will be plenty of occasions to use the various facilities of C++. For example, representing the various entities of your game (Player ship, enemies, missiles, etc ...) as subclasses of a GameEntity class? Maybe even an interface? 
At any rate, a very large part of the grading will regard intelligent use of objects, inheritance, and so on.

For those of you who have never made a video game, here’s how a very basic game should run:

• Acquire input (Player controls, network, etc ...)

• Update game entities

• Render display

• Repeat until game ends !


Of course, the "Update" phase includes a lot of things, including handling the spawning of enemies, making actions required by player input, moving entities according to their current vector and the time since the last update ... But those are the basics.

When you get down to it, a basic video game is a really simple program. It should not be too hard to do, should it?
When you’re pretty sure you’ve done everything right, you are very welcome to improve on the basic requirements and make an even better game.

Here are some of the features we consider "essential" and that will have to be done before other bonuses are counted:

• Displaying score, time, number of lives, etc... on screen

• Clock-based timing (Use whichever system facility or library you like)

• Entities that can occupy multiple squares

• Enemies can also shoot

• Scenery (Collidable objects or simple background)


And after that, if you still want something to do, here are some ideas of cool bonuses, but keep in mind that we’ll consider them useless if you haven’t done the other stuff before:

• Large and hard-to-beat boss enemies

• Enemies have a scripted behaviour

• Multiplayer, either on the same keyboard or through the network if you’re feeling cocky

• Scripted game worlds, with pre-determined batches of enemies


Keep in mind that, as usual, bonuses will not be graded if the basics are not completed, and a bonus that crashes your program could bring your whole grade down...

To debug Entity Classes run "make debug"
