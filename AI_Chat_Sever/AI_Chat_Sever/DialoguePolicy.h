#pragma once
#include "CharacterState.h"
#include "DialogueSituation.h"
#include "DialogueResult.h"

class DialoguePolicy
{
public:
    bool AllowLLMCall(
        const CharacterState& state,
        const DialogueSituation& situation
    );

    std::string MakeCacheKey(
        const CharacterState& state,
        const DialogueSituation& situation
    );

    DialogueResult GetFallbackDialogue(
        const CharacterState& state
    );
};