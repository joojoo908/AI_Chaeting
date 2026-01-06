from fastapi import FastAPI
from api.dialogue import router as dialogue_router

app = FastAPI(title="AI Dialogue Service")

app.include_router(dialogue_router, prefix="/dialogue")

# 실행:
# uvicorn main:app --host 0.0.0.0 --port 9000