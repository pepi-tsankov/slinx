#ifndef TREE_H
#define TREE_H

#include "Entity.h" // Base class: Entity

class Tree : public Entity
{
public:
	Tree(int coordX, int coordY, int sizeX, int sizeY, int sizeZ);
	~Tree();
};

#endif // TREE_H
