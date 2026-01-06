def allow_llm_call(req) -> bool:
    # 대화 시작 이벤트만 허용
    return req.situation.event == "talk_start"

def make_cache_key(req) -> str:
    stage = req.state.affection // 20
    return f"{req.state.character_id}:{stage}:{req.situation.event}:{req.situation.location}"

def fallback_dialogue(req):
    return {
        "dialogue": "...",
        "emotion": "neutral",
        "tone": "flat"
    }