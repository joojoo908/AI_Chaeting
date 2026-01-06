import httpx
import json
import os

API_KEY = os.getenv("LLM_API_KEY")

async def call_llm(req):
    prompt = f"""
You are an NPC in a dating simulation.

Affection: {req.state.affection}
Mood: {req.state.mood}
Location: {req.situation.location}

Respond in 2~3 sentences.
Return JSON:
{{"dialogue":"...","emotion":"...","tone":"..."}}
"""

    async with httpx.AsyncClient(timeout=10) as client:
        response = await client.post(
            "https://api.llm.com/v1/chat",
            headers={"Authorization": f"Bearer {API_KEY}"},
            json={
                "model": "gpt-4.1",
                "messages": [{"role": "user", "content": prompt}],
                "max_tokens": 200
            }
        )

    content = response.json()["choices"][0]["message"]["content"]
    return json.loads(content)