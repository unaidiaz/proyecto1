#include "SceneLevel1.h"
#include "ModuleObjet.h"
#include "stdio.h"
#include <time.h>
#include "Application.h"
#include "ModuleInput.h"
#include "Globals.h"
#include "Module.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleCollisions.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "Animation.h"
#include "ModuleFonts.h"
#include "SDL/include/SDL_scancode.h"
#include "ModuleFadeToBlack.h"

SceneLevel1::SceneLevel1(bool startEnabled) : Module(startEnabled)
{

}

SceneLevel1::~SceneLevel1()
{

}

// Load assets
bool SceneLevel1::Start()
{
	srand(time(NULL));

	LOG("Loading background assets");
	App->player->hammerMode = false;
	bool ret = true;
	App->player->lvl = 1;
	App->player->canLateralMov = false;
	App->player->Posicion.x = 125;
	App->player->Posicion.y = 690;
	App->enemies->Enable();
	App->player->Enable();
	App->objet->Enable();
	App->audio->PlayMusic("Assets/2. Stage 1 START.ogg");
	kong = App->textures->Load("Assets/perso.png");
	testTexture = App->textures->Load("Assets/lvl1.png");
	princesa = App->textures->Load("Assets/perso.png");
	highscore = App->textures->Load("Assets/carteles y mensajes.png");
	oneup = App->textures->Load("Assets/carteles y mensajes.png");
	bonus = App->textures->Load("Assets/carteles y mensajes.png");
	lvl = App->textures->Load("Assets/lvl1_.png");
	four = App->textures->Load("Assets/carteles y mensajes.png");
	barriles_4 = App->textures->Load("Assets/objetosestaticos.png");
	littlemario = App->textures->Load("Assets/letras.png");	
	vida3 = App->textures->Load("Assets/3vidas.png");
	cont = 0;
	//547
	App->collisions->AddCollider({ 87 * 3 - 15, 23 * 3 + 72,49 * 3 ,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ -15, 153 + 72, 432,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 143 * 3 - 12, 52 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 159 * 3 - 12, 53 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 175 * 3 - 12, 54 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 191 * 3 - 12, 55 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 207 * 3 - 12,76 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 191 * 3 - 12, 77 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 175 * 3 - 12,78 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 159 * 3 - 12,79 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 143 * 3 - 12, 80 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 127 * 3 - 12, 81 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 111 * 3 - 12, 82 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 95 * 3 - 12, 83 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 79 * 3 - 12, 84 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 63 * 3 - 12, 85 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 47 * 3 - 12, 86 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 31 * 3 - 12, 87 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 15 * 3 - 12, 88 * 3 + 72, 48, 3 }, Collider::Type::plataforma);

	App->collisions->AddCollider({ 207 * 3 - 15,143 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 191 * 3 - 15, 144 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 175 * 3 - 15,145 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 159 * 3 - 15,146 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 143 * 3 - 15, 147 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 127 * 3 - 15, 148 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 111 * 3 - 15, 149 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 95 * 3 - 15, 150 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 79 * 3 - 15, 151 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 63 * 3 - 15, 152 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 47 * 3 - 15, 153 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 31 * 3 - 15, 154 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 15 * 3 - 15, 155 * 3 + 72, 48, 3 }, Collider::Type::plataforma);

	App->collisions->AddCollider({ 191 * 3 - 15,121 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 175 * 3 - 15,120 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 159 * 3 - 15,119 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 143 * 3 - 15,118 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 127 * 3 - 15,117 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 111 * 3 - 15,116 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 95 * 3 - 15,115 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 79 * 3 - 15,114 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 63 * 3 - 15,113 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 47 * 3 - 15,112 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 31 * 3 - 15,111 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 15 * 3 - 15,110 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ -1 * 3 - 15,109 * 3 + 72, 48, 3 }, Collider::Type::plataforma);

	App->collisions->AddCollider({ 191 * 3 - 12,187 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 175 * 3 - 12,186 * 3 + 72, 50, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 159 * 3 - 12,185 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 143 * 3 - 12,184 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 127 * 3 - 12,183 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 111 * 3 - 12,182 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 95 * 3 - 12,181 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 79 * 3 - 12,180 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 63 * 3 - 12,179 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 47 * 3 - 12,178 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 31 * 3 - 12,177 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 15 * 3 - 12,176 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ -1 * 3 - 12,175 * 3 + 72, 48, 3 }, Collider::Type::plataforma);

	App->collisions->AddCollider({ 207 * 3 - 15,209 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 191 * 3 - 15, 210 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 175 * 3 - 15,211 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 159 * 3 - 15,212 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 143 * 3 - 15, 213 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 127 * 3 - 15, 214 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 111 * 3 - 15, 215 * 3 + 72, 48, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ -1 * 3 - 15, 216 * 3 + 72, 336, 3 }, Collider::Type::plataforma);

	////////////////////////////////////////////////////////////////////////////////////////

	App->collisions->AddCollider({ 380, 23 * 3 + 73, 5,75 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 188 * 3 - 15, 54 * 3 + 73, 5,70 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 36 * 3 - 15, 154 * 3 + 72, 5, 70 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 36 * 3 - 15, 87 * 3 + 72, 5, 70 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 188 * 3 - 15, 120 * 3 + 72, 5, 70 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 100 * 3 - 15, 150 * 3 + 72, 5, 90 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 116 * 3 - 15,116 * 3 + 72, 5, 90 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 76 * 3 - 15, 85 * 3 + 72, 5, 75 }, Collider::Type::escalera);
	App->collisions->AddCollider({ 188 * 3 - 15, 186 * 3 + 72, 5, 70 }, Collider::Type::escalera);


	App->collisions->AddCollider({ 188 * 3 - 15, 54 * 3 + 145, 5,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 188 * 3 - 15, 186 * 3 + 145, 5, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 188 * 3 - 15, 120 * 3 + 145, 5, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 36 * 3 - 15, 154 * 3 + 143, 5, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 36 * 3 - 15, 87 * 3 + 145, 5, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 380, 23 * 3 + 156, 5,3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 100 * 3 - 15, 150 * 3 + 166, 5, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 116 * 3 - 15,116 * 3 + 168, 5, 3 }, Collider::Type::plataforma);
	App->collisions->AddCollider({ 76 * 3 - 15, 85 * 3 + 156, 5, 3 }, Collider::Type::plataforma);



	App->collisions->AddCollider({ 330, 50, 70, 70 }, Collider::Type::Victoria);


	App->objet->AddObjet(Objet_Type::barril_fuego, 50, 645);
	App->objet->AddObjet(Objet_Type::martillo, 500, 550);
	App->objet->AddObjet(Objet_Type::martillo, 50, 260);

	int direccion, x;
	App->enemies->AddEnemy(Enemy_Type::KONG, 50, 158, 0);
	for (int i = 0; i < 2; i++) {
		direccion = rand() % 2;
		if (direccion == 0) {
			direccion = -1;
		}
		switch (i)
		{
		case 0:
			//App->enemies->AddEnemy(Enemy_Type::LLAMA, 153, 400, direccion);
			break;
		case 1:
			//App->enemies->AddEnemy(Enemy_Type::LLAMA, 500, 420, direccion);
			break;
		}
	}
	//App->objet->AddObjet(Objet_Type::tanque, 200, 575);
	//App->objet->AddObjet(Objet_Type::bolso, 610, 287);
	//App->objet->AddObjet(Objet_Type::paraguas, -10, 365);

	char lookupTable_r[] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ.-" };
	char lookupTable_b[] = { "0123456789" };
	char lookupTable_az[] = { "0123456789" };
	rojas = App->fonts->Load("Assets/letras_rojas.png", lookupTable_r, 1);
	blancas = App->fonts->Load("Assets/letras_blancas.png", lookupTable_b, 1);
	azules = App->fonts->Load("Assets/letras_azules.png", lookupTable_az, 1);



	return ret;
}


void SceneLevel1::DebugDrawGamepadInfo()
{
	GamePad& pad = App->input->pads[0];

	sprintf_s(_scoreText, 150, "pad 0 %s, press 1/2/3 for rumble", (pad.enabled) ? "plugged" : "not detected");
	App->fonts->BlitText(5, 10, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "buttons %s %s %s %s %s %s %s %s %s %s %s",
		(pad.a) ? "a" : "",
		(pad.b) ? "b" : "",
		(pad.x) ? "x" : "",
		(pad.y) ? "y" : "",
		(pad.start) ? "start" : "",
		(pad.back) ? "back" : "",
		(pad.guide) ? "guide" : "",
		(pad.l1) ? "lb" : "",
		(pad.r1) ? "rb" : "",
		(pad.l3) ? "l3" : "",
		(pad.r3) ? "r3" : ""
	);
	App->fonts->BlitText(5, 20, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "dpad %s %s %s %s",
		(pad.up) ? "up" : "",
		(pad.down) ? "down" : "",
		(pad.left) ? "left" : "",
		(pad.right) ? "right" : ""
	);
	App->fonts->BlitText(5, 30, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "left trigger  %0.2f", pad.l2);
	App->fonts->BlitText(5, 40, blancas, _scoreText);
	sprintf_s(_scoreText, 150, "right trigger %0.2f", pad.r2);
	App->fonts->BlitText(5, 50, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "left thumb    %.2fx, %0.2fy", pad.l_x, pad.l_y);
	App->fonts->BlitText(5, 60, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "   deadzone   %0.2f", pad.l_dz);
	App->fonts->BlitText(5, 70, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "right thumb   %.2fx, %0.2fy", pad.r_x, pad.r_y);
	App->fonts->BlitText(5, 80, blancas, _scoreText);

	sprintf_s(_scoreText, 150, "   deadzone   %0.2f", pad.r_dz);
	App->fonts->BlitText(5, 90, blancas, _scoreText);
}

update_status SceneLevel1::Update()
{
	cont++;
	if (cont % 120 == 0)
	{
		
		if (cont % 1200 == 0) {
			App->enemies->AddEnemy(Enemy_Type::barrilazul, 178, 217, 1);
		}
		else {
			App->enemies->AddEnemy(Enemy_Type::barril, 178, 217, 1);
		}
		

	}
	if (cont == 200)
	{
		App->audio->PlayMusic("Assets/3. Stage 1 BGM.ogg");
		App->player->canLateralMov = true;
	}
	if (App->input->keys[SDL_SCANCODE_F6] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->sceneIntro, 90);
	}
	if (App->input->keys[SDL_SCANCODE_F7] == KEY_STATE::KEY_DOWN)
	{
		App->player->_win = true;
	}
	if (App->input->keys[SDL_SCANCODE_F8] == KEY_STATE::KEY_DOWN)
	{
		App->player->_lose = true;
	}
	if (App->input->keys[SDL_SCANCODE_F9] == KEY_STATE::KEY_DOWN) {
		if (App->player->godmode == false) {
			App->player->godmode = true;
			App->collisions->debug = true;
		}
		else {
			App->collisions->debug = false;
			App->player->godmode = false;
		}
	}
	temp++;
	if (temp % 120 == 0 && App->player->_win == false)
	{
		_bonus = _bonus - 100;
	}
	if (_score >= _highscore)
	{
		_highscore = _score;
	}
	if (_bonus <= 0000)
	{
		_bonus = 0000;
	}
	if (temp == 4800)
	{
		App->audio->PlayMusic("Assets/11. Hurry Up!.ogg", 0.4f);
	}
	if (App->player->_win == true)
	{
		App->objet->CleanUp();
		App->enemies->CleanUp();
		_score += _bonus;
		_bonus = NULL;
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status SceneLevel1::PostUpdate()
{
	// Draw everything --------------------------------------
	// TODO 10: Blit our test texture to check  functionality
	App->render->Blit(testTexture, 0, 100, nullptr);
	//Blit(mario, 50, 50, nullptr);
	
	SDL_Rect princesa_ = { 0,428,14,23 };
	App->render->Blit(princesa, 270, 100, &princesa_);
	SDL_Rect highscore_ = { 63,36,80,8 };
	App->render->Blit(highscore, 225, 0, &highscore_);
	SDL_Rect oneup_ = { 16,36,27,8 };
	App->render->Blit(oneup, 70, 0, &oneup_);
	SDL_Rect bonus_ = { 0,74,44,20 };
	App->render->Blit(bonus, 510, 110, &bonus_);
	SDL_Rect lvl_ = { 0,0,29,8 };
	App->render->Blit(lvl, 510, 70, &lvl_);
	SDL_Rect littlemario_ = { 530,51,8,10 };
	App->render->Blit(littlemario, 10, 70, &littlemario_);
	SDL_Rect barriles__4 = { 0,18,20,(51 - 18) };
	App->render->Blit(barriles_4, 0, 155, &barriles__4);

	SDL_Rect rect_1vida = { 2, -1, 8, 9 };
	SDL_Rect rect_2vidas = { 2, -1, 17, 9 };
	SDL_Rect rect_3vidas = { 2, -1, 27, 9 };
	if (App->player->vidas == 3)
	{
		App->render->Blit(vida3, 30, 60, &rect_3vidas);
	}
	if (App->player->vidas == 2)
	{
		App->render->Blit(vida3, 40, 60, &rect_2vidas);
	}
	if (App->player->vidas == 1)
	{
		App->render->Blit(vida3, 40, 60, &rect_1vida);
	}

	if (App->player->_win == true)
	{
		App->fade->FadeToBlack((Module*)App->scene1, (Module*)App->howhigh2, 180);
		cont_music++;
		if (cont_music == 1)
		{
			App->audio->PlayMusic("Assets/4. Stage 1 CLEAR.ogg");
		}
	}
	if (App->player->_lose == true)
	{
		if (App->player->vidas <= 0)
		{
			App->fade->FadeToBlack((Module*)App->scene1, (Module*)App->sceneIntro, 90);
		}
		else if (App->player->vidas > 0)
		{
			App->fade->FadeToBlack((Module*)App->scene1, (Module*)App->howhigh, 180);
		}
	}
	sprintf_s(_scoreText, 10, "%6d", _score);
	sprintf_s(_highscoreText, 10, "%6d", _highscore);
	sprintf_s(_bonusText, 10, "%4d", _bonus);

	// TODO 3: Blit the text of the score in at the bottom of the screen
	App->fonts->BlitText(29, 27, blancas, _scoreText);
	App->fonts->BlitText(270, 27, blancas, _highscoreText);
	App->fonts->BlitText(527, 134, azules, _bonusText);

	return update_status::UPDATE_CONTINUE;
}

bool SceneLevel1::CleanUp()
{
	App->player->highscore = _highscore;
	temp = 0;	
	App->fonts->UnLoad(rojas);
	App->fonts->UnLoad(blancas);
	App->fonts->UnLoad(azules);
	App->textures->Unload(kong);
	App->textures->Unload(testTexture);
	App->textures->Unload(princesa);
	App->textures->Unload(highscore);
	App->textures->Unload(oneup);
	App->textures->Unload(bonus);
	App->textures->Unload(lvl);
	App->textures->Unload(four);
	App->textures->Unload(littlemario);
	App->textures->CleanUp();
	App->player->cont_muerte = 0;
	App->player->cont_win = 0;
	App->player->Disable();
	App->enemies->Disable();
	App->objet->Disable();

	App->player->_lose = false;
	App->player->_win = false;
	App->player->canLateralMov = true;
	App->player->contToFade = 0;
	App->player->Posicion.x = 125;
	App->player->Posicion.y = 690;
	_score = 000000;
	_bonus = 5000;
	
	App->collisions->CleanUp();
	//App->audio->CleanUp();
	
	return true;
}

