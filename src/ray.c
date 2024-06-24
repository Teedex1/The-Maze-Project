#include "../headers/header.h"

ray_t rays[NUM_RAYS];

static bool foundHorzWallHit, foundVertWallHit;
static float horzWallHitX, horzWallHitY, vertWallHitX, vertWallHitY;
static int horzaWallContent, verWallContent;


/**
 * horzIntersection - finds horizontal intersection with the wall
 * @rayAngle: current ray angle
 *
 */
void horzIntersection(float, rayAngle)
{
	float nextHorzTouchX, nextHorzTouchY, xintercept, yintercept, xstep, ystep;

	foundHorzWallHit = false;
	horzWallHit = horzWallHitY = horzWallContent = 0;

	yintercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
	yintercept += isRayFacingDown(rayAngle) ? TILE_SIZE : 0;

	xintercept = player.x + (yintercept - player.y) / tan(rayAngle);

	ystep = TILE_SIZE;
	ystep *= isRayFacingUp(rayAngle) ? -1 : 1;
	xstep = TILE_SIZE / tan(rayAngle);
	xstep *= (isRayFacingLeft(rayAngle) && xstep > 0) ? -1 : 1;
	xstep *= (isRAyFacingRight(rayAngle) && xstep < 0) ? -1: 1;
	nextHorzTouchX = xintercept;
	nextHorzTouchY = yintercept;

	while (isInsideMap(nextHorzTouchX, nextHorzTouchY))
	{
		float xToCheck = nextHorzTouchX;
		float yToCheck = nextHorzTouchY + (isRayFacingUp(rayAngle) ? -1 : 0);

		if (DetectCollision(xToCheck, yToCheck))
		{
			horzWallHitX = nextHorzTouchX;
			horzWallHitY = nextHorzTouchY;
			horzWallContent = getMapValue((int)(floor(yToCheck / TILE_SIZE),
										(int)floor(xToCheck / TILE_SIZE));
			foundHorWallHit = true;
			break;
		}
		nextHorzTouchX += xstep;
		nextHorzTouchY += ystep;
	}


/**
 * vertIntersection - Finds vertical intersection with the wall
 * @rayAngle: current ray angle
 *
 */

void vertIntersection(float, rayAngle)
{
float nextVertTouchX, nextVertTouchY;
floa
	

