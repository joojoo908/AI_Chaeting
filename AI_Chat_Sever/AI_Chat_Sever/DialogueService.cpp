#include "DialogueService.h"
#include "DialoguePolicy.h"
#include "DialogueCache.h"
#include "LLMClient.h"

DialogueResult DialogueService::GenerateDialogue(
    const CharacterState& state,
    const DialogueSituation& situation)
{
    DialoguePolicy policy;
    DialogueCache cache;

    std::string key = policy.MakeCacheKey(state, situation);

    if (cache.Exists(key))
        return cache.Get(key);

    if (!policy.AllowLLMCall(state, situation))
        return policy.GetFallbackDialogue(state);

    LLMClient llm;
    DialogueResult result = llm.GenerateDialogue(state, situation);

    cache.Store(key, result);
    return result;
}