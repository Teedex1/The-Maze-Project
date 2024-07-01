#include "../headers/header.h"

/**
 * distanceBetweenPoints - find horizontal intersection with the wall
 * @x1: x coordinate of the strating point
 * @y1: y coordinate of the starting point
 * @x2: x coordinate of the end point
 * @y2: y coordinate of the end point
 * Return: the distance between two points
 */

float distanceBetweenPoints(float x1, float y1, floatx2, float y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}

/**
 * isRayFacingDown - check if the ray is facing down
 * @angle: current ray angle
 * Return: true or false
 */

bool isRayFacingDown(float angle)
{
	return (angle > 0 && angle < PI);
}

/**
 * isRayFacingUp - check id the ray is facing up
 * @angle: current ray angle
 * Return: true or false
 */

bool isRayFacingUp(float angle)
{
	return (!isRayFacingDown(angle));
}

/**
 * isRayFacingRight - check if the ray us afacing to the right
 * @angle: current ray angle
 * Return: true or false
 */

bool isRayFacingRight(float angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

/**
 * isRayFacingLeft - check if the ray is facing to te left
 * @angle: current ray angle
 * Return: true or false
 */

bool isRayFacingLeft(float angle)
{
	return (!isRayFacingRight(angle));
}

