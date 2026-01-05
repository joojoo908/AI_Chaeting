#include "LLMClient.h"

DialogueResult LLMClient::GenerateDialogue(
    const CharacterState& state,
    const DialogueSituation&)
{
    // TODO: 실제 LLM API 연동
    return {
        "……왜 불렀어. 갑자기.",
        state.mood,
        "cold"
    };
}