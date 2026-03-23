#include "Map.h"

Map::Map(int value) : Card(value, map) {

}

void Map::play(Game&, Player&)
{
}

std::string Map::str()
{
    return "Map(" + std::to_string(value) + ")";
}
