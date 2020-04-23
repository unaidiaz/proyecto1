#include "objet.h"
#include"ModuleTextures.h"
#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

Objet::Objet(int x, int y) : position(x, y)
{
	spawnPos = position;
}

Objet::~Objet()
{
	if (obcollider != nullptr)
		obcollider->pendingToDelete = true;
	
}

const Collider* Objet::GetCollider() const
{
	return obcollider;
	
}

void Objet::Update()
{
	if (currentAnim != nullptr) {
		currentAnim->Update();
	}
		

	if (obcollider != nullptr) {
		obcollider->SetPos(position.x, position.y);

	}
		
	
}

void Objet::Draw()
{
	if (currentAnim != nullptr)
	{
		App->render->Blit(placatext, position.x, position.y + 110, &(currentAnim->GetCurrentFrame()));
		App->render->Blit(tanquetext, position.x+5, position.y+30, &(currentAnim->GetCurrentFrame()));
		App->render->Blit(bolsotext, position.x+10, position.y+30, &(currentAnim->GetCurrentFrame()));
		App->render->Blit(paraguastext, position.x+5, position.y+30, &(currentAnim->GetCurrentFrame()));
	}
		
}

void Objet::OnCollision(Collider* collider)
{
	destr();
}
void Objet::destr()
{
	pendingToDelete = true;
	if (obcollider != nullptr) {
		obcollider->pendingToDelete = true;
	}
	
}