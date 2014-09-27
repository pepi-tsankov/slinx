#include "Entity.h";
#include <vector>
#include <iostream>
//constructor
Entity::Entity(int coordX, int coordY, int sizeX, int sizeY, int sizeZ)
{
	this->coordX = coordX;
	this->coordY = coordY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeZ = sizeZ;
}
//destructor
Entity::~Entity()
{
}
//fields
int Entity::CoordX()
{
	return this->coordX;
}
int Entity::CoordY()
{
	return this->coordY;
}
int Entity::SizeX()
{
	return sizeX;
}
int Entity::SizeY()
{
	return sizeY;
}
int Entity::SizeZ()
{
	return sizeZ;
}


