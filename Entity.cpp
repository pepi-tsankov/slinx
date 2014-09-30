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
	return this->sizeX;
}
int Entity::SizeY()
{
	return this->sizeY;
}
int Entity::SizeZ()
{
	return this->sizeZ;
}
/* WHAT THE FUCK!? */
/*Error: no such member function found in Entity.h
/*int Entity::ASD()
{

}
int Entity::setCoordX()
{
	this.coordX = value;
}
int Entity::setCoordY()
{
	this.coordY = value;
}
int Entity::setSizeX()
{
	this.sizeX = value;
}
int Entity::setSizeY()
{
	this.sizeY = value;
}
int Entity::setSizeZ()
{
	this.sizeZ = value;
}*/


