#include "Animal.h"
Animal::Animal(int coordX, int coordY, int sizeX, int sizeY, int sizeZ) : Entity(coordX, coordY, sizeX, sizeY, sizeZ)
{
    //ctor
}

Animal::~Animal()
{
    //dtor
}
void Animal::Move()
{

}
void Animal::Die()
{
    delete this;
}
