#include "Mermaid.h"

Mermaid::Mermaid(int value) : Card(value, mermaid)
{
}

void Mermaid::play(Game&, Player&)
{
    printf("\tNo effect but mermaids are worth more.\n");
}

std::string Mermaid::str()
{
    return "Mermaid(" + std::to_string(_value) + ")";
}
