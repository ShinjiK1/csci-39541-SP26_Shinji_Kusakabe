Game engine project using GLFW and glad for OpenGL handling. Includes, window creation, image/picture display with shaders that is handled by the renderer and
basic unit class with collision detection and the ability to move units around.

Included is a simple game project made using the engine. The game is basically pong and the player can play using the up and down arrows against a simple cpu/ai that tries to track/follow the ball.
Collision detection is used to handle the balls movement and reverse it when it hits paddles/walls with some built in checks to prevent collisions from being counted twice. Some states are used to
track the game condition and display different images based on it and prevent unintended behaviors. Random number generators are implemented to change the speed and angle of the ball as it bounces between
players to keep gameplay more dynamic as well. The CPU uses a simple algorithm around tracking where the middle of the ball is and trying to follow it.
