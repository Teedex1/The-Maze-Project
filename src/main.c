#include "../headers/header.h"

bool GameRunning = false;
int TicksLastFrame;
player_t player;

/**
 * setup_game - initialize player variable and load wall textures
 *
 */

void setup_game(void)
{
	player.x = SCREEN_WIDTH / 2;
	player.y = SCREEN_HEIGHT / 2;
	player.width = 1;
	player.height = 30;
	player.walkDirection = 0;
	player.walkSpeed = 100;
	player.turnDirection = 0;
	player.turnSpeed = 45 * (PI / 180);
	player.rotationAngle = PI / 2;
	wallTexturesready();
}

/**
 * update_game - update_game delta time, the ticks last frame
 * the player movement and the ray casting
 */
void update_game(void)
{
	float DeltaTime;
	int timeTowait = FRAME_TIME_LENGTH - (SDL_GetTicks() - TicksLastFrame);

	if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
	{
		SDL_Delay(timeToWait);
	}
	DeltaTime = SDL_GetTicks();

	TicksLastFrame = SDL_GetTicks();

	movePlayer(DeltaTime);
	castAllRays();
}

/**
 * render - calls all functions needed for on-screen rendering
 *
 */
void render_game(void)
{
	clearColorBuffer(0xFF000000);

	renderWall();

	renderMap();
	renderRays();
	renderPlayer();

	renderColorBuffer();
}

/**
 * Destroy - free wall textures and destroy window
 *
 */
void destroy_game(void)
{
	freeWallTexures();
	destroyWindow();
}

/**
 * main - main function
 * Return: 0
 */

int main(void)
{
	GameRunning = initializeWindow();

	setup_game();

	while (GameRunning)
	{
		handleInput();
		update_game();
		render_game();
	}
	destroy_game();
	return (0);
}



