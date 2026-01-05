#pragma once
#include <unordered_map>
#include <string>
#include "DialogueResult.h"

class DialogueCache
{
public:
    bool Exists(const std::string& key);
    DialogueResult Get(const std::string& key);
    void Store(const std::string& key, const DialogueResult& result);

private:
    static std::unordered_map<std::string, DialogueResult> cache;
};