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
    /*switch(this.direction)
    {
        case "straight":
            if(this.cameraAngle == 0)
            {
                this.CoordX() += this.speed;
            }
            else
            {
                this.CoordY() += this.speed;
            }
    }*/
}
void Animal::Die()
{
    delete this;
}
