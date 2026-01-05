#pragma once
#include <string>

struct DialogueSituation
{
    std::string event;     // talk_start, event_branch
    std::string location;
    std::string time;
};