from fastapi import APIRouter
from models.schemas import DialogueRequest, DialogueResponse
from service.dialogue_service import generate_dialogue

router = APIRouter()

@router.post("/", response_model=DialogueResponse)
async def dialogue(req: DialogueRequest):
    return await generate_dialogue(req)