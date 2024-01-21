#include "figures.h"

bool CheckCollisionCubes(Vector3 cube1, Vector3 cube2)
{
    if (cube1.x == cube2.x &&
        cube1.y == cube2.y &&
        cube1.z == cube2.z)
        return true;
    else
        return false;
}
