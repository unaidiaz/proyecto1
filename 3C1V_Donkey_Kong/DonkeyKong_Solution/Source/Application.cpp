#include "Application.h"

#include "Module.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "SceneIntro.h"
#include "HowHigh.h"
#include "HowHigh2.h"
#include "HowHigh3.h"
#include "SceneLevel1.h"
#include "SceneLevel3.h"
#include "SceneLevel4.h"
#include "ModuleCollisions.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEnemies.h"
#include "ModuleAudio.h"
#include"ModuleObjet.h"
#include "ModuleFonts.h"

Application::Application()
{
	// The order in which the modules are added is very important.
	// It will define the order in which Pre/Update/Post will be called
	// Render should always be last, as our last action should be updating the screen
	modules[0] = window = new ModuleWindow(true);
	modules[1] = input = new ModuleInput(true);
	modules[2] = textures = new ModuleTextures(true);
	modules[3] = audio = new ModuleAudio(true);
	modules[4] = sceneIntro = new SceneIntro(true);
	modules[5] = howhigh = new HowHigh(false);
	modules[6] = scene1 = new SceneLevel1(false);
	modules[7] = howhigh2 = new HowHigh2(false);
	modules[8] = scene3 = new SceneLevel3(false);
	modules[9] = howhigh3 = new HowHigh3(false);
	modules[10] = scene4 = new SceneLevel4(false);
	modules[11] = player = new ModulePlayer(false);
	modules[12] = enemies = new ModuleEnemies(false);
	modules[13] = objet = new ModuleObjet(false);
	modules[14] = collisions = new ModuleCollisions(true);
	modules[15] = fade = new ModuleFadeToBlack(true);
	modules[16] = fonts = new ModuleFonts(true);
	modules[17] = render = new ModuleRender(true);

}

Application::~Application()
{
	for (int i = 0; i < NUM_MODULES; ++i)
	{
		//Important: when deleting a pointer, set it to nullptr afterwards
		//It allows us for null check in other parts of the code
		delete modules[i];
		modules[i] = nullptr;
	}
}

bool Application::Init()
{
	bool ret = true;

	// All modules (active and disabled) will be initialized
	for (int i = 0; i < NUM_MODULES && ret; ++i)
	{
		ret = modules[i]->Init();
	}
	// Only active modules will be 'started'
	for (int i = 0; i < NUM_MODULES && ret; ++i)
	{
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;
	}
	return ret;
}

update_status Application::Update()
{
	update_status ret = update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : update_status::UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == update_status::UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : update_status::UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret; --i)
		ret = modules[i]->IsEnabled() ? modules[i]->CleanUp() : true;

	return ret;
}
