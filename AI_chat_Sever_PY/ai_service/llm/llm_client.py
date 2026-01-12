import httpx
import json
import os

API_KEY = os.getenv("LLM_API_KEY")

async def call_llm(req):
    prompt = f"""
너는 연애 시뮬레이션 게임의 NPC다.

[캐릭터 상태]
- 호감도: {req.state.affection}
- 기분: {req.state.mood}
- 위치: {req.situation.location}

[플레이어의 말]
"{req.user_input}"

플레이어의 말에 자연스럽게 한두 문장으로 응답하라.
"""

    # 아직은 더미 응답
    return {
        "dialogue": f"(플레이어의 말 '{req.user_input}'에 대한 반응)",
        "emotion": req.state.mood,
        "tone": "neutral"
    }