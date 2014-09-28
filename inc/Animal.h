#ifndef ANIMAL_H
#define ANIMAL_H

#include "Entity.h"
#include "IMoveable.h"
#include "IDie.h"

class Animal : public Entity, public IMoveable
{
    public:
        Animal(int coordX, int coordY, int sizeX, int sizeY, int sizeZ);
        ~Animal();
        void Move();
        void Die();
    protected:
    private:
        int speed = 1; // the speed of the thing measured by sth, idk
};

#endif // ANIMAL_H
