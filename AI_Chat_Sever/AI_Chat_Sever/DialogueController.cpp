#include "DialogueController.h"
#include "DialogueService.h"
#include "CharacterState.h"
#include "DialogueSituation.h"

using namespace drogon;

void DialogueController::requestDialogue(
    const HttpRequestPtr& req,
    std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto json = req->getJsonObject();
    if (!json)
    {
        callback(HttpResponse::newHttpJsonResponse({ {"error", "invalid json"} }));
        return;
    }

    CharacterState state;
    state.characterId = (*json)["character_id"].asString();
    state.relationship.affection = (*json)["affection"].asInt();
    state.relationship.trust = (*json)["trust"].asInt();
    state.mood = (*json)["mood"].asString();

    DialogueSituation situation;
    situation.event = (*json)["event"].asString();
    situation.location = (*json)["location"].asString();
    situation.time = (*json)["time"].asString();

    DialogueService service;
    DialogueResult result = service.GenerateDialogue(state, situation);

    Json::Value res;
    res["dialogue"] = result.dialogue;
    res["emotion"] = result.emotion;
    res["tone"] = result.tone;

    callback(HttpResponse::newHttpJsonResponse(res));
}