#pragma once
#include <drogon/HttpController.h>

class DialogueController : public drogon::HttpController<DialogueController>
{
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(DialogueController::requestDialogue, "/dialogue", Post);
    METHOD_LIST_END

        void requestDialogue(
            const drogon::HttpRequestPtr& req,
            std::function<void(const drogon::HttpResponsePtr&)>&& callback
        );
};