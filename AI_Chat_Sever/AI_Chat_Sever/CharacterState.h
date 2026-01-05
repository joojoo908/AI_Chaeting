
#pragma once
#include <string>

struct Personality
{
    float tsundere = 0.f;
    float kindness = 0.f;
    float jealousy = 0.f;
};

struct Relationship
{
    int affection = 0;
    int trust = 0;
};

struct CharacterState
{
    std::string characterId;    
    Personality personality;
    Relationship relationship;
    std::string mood;
};