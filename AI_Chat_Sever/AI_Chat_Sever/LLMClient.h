#pragma once
#include "CharacterState.h"
#include "DialogueSituation.h"
#include "DialogueResult.h"

class LLMClient
{
public:
    DialogueResult GenerateDialogue(
        const CharacterState& state,
        const DialogueSituation& situation
    );
};