from policy.dialogue_policy import allow_llm_call, make_cache_key, fallback_dialogue
from cache.dialogue_cache import get_cache, set_cache
from llm.llm_client import call_llm

async def generate_dialogue(req):
    key = make_cache_key(req)

    cached = get_cache(key)
    if cached:
        return cached

    if not allow_llm_call(req):
        return fallback_dialogue(req)

    result = await call_llm(req)
    set_cache(key, result)
    return result