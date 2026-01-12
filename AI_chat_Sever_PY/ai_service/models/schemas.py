from pydantic import BaseModel

class CharacterState(BaseModel):
    character_id: str
    affection: int
    trust: int
    mood: str

class Situation(BaseModel):
    event: str
    location: str
    time: str

class DialogueRequest(BaseModel):
    state: CharacterState
    situation: Situation
    user_input: str

class DialogueResponse(BaseModel):
    dialogue: str
    emotion: str
    tone: str