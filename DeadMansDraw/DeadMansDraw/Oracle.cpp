#include "Oracle.h"

Oracle::Oracle(int value) : Card(value, oracle) {

}

void Oracle::play(Game&, Player&)
{
}

std::string Oracle::str()
{
    return "Oracle(" + std::to_string(value) + ")";
}
