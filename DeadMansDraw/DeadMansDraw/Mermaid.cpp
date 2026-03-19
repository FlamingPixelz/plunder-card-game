#include "Mermaid.h"

Mermaid::Mermaid(int value) : Card(value, mermaid)
{
}

void Mermaid::play(Game&, Player&)
{
}

std::string Mermaid::str()
{
    return "Mermaid(" + std::to_string(value) + ")";
}
