#include "DialogueCache.h"

std::unordered_map<std::string, DialogueResult> DialogueCache::cache;

bool DialogueCache::Exists(const std::string& key)
{
    return cache.find(key) != cache.end();
}

DialogueResult DialogueCache::Get(const std::string& key)
{
    return cache[key];
}

void DialogueCache::Store(const std::string& key, const DialogueResult& result)
{
    cache[key] = result;
}
