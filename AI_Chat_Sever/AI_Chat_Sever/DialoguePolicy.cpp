#include "DialoguePolicy.h"

bool DialoguePolicy::AllowLLMCall(
    const CharacterState&,
    const DialogueSituation& situation)
{
    // 이벤트 시작 시만 허용
    return situation.event == "talk_start";
}

std::string DialoguePolicy::MakeCacheKey(
    const CharacterState& state,
    const DialogueSituation& situation)
{
    return state.characterId + "_" +
        std::to_string(state.relationship.affection / 20) + "_" +
        situation.event + "_" +
        situation.location;
}

DialogueResult DialoguePolicy::GetFallbackDialogue(
    const CharacterState&)
{
    return {
        "...",
        "neutral",
        "flat"
    };
}