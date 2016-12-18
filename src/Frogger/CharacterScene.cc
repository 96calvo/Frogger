/******************************************************************
* Copyright (C) 2016 Jordi Serrano Berbel <jsberbel95@gmail.com> *
* This can not be copied, modified and/or distributed without    *
* express permission of the copyright owner.                     *
******************************************************************/

#include "GUI.hh"
#include "System.hh"
#include "Logger.hh"
#include "CharacterScene.h"

using namespace Logger;

#define CELL_WIDTH 80
#define CELL_HEIGHT 80

SDL_RendererFlip flip = SDL_FLIP_NONE;

CharacterScene::CharacterScene(void){
	m_background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::SALOON };
	mccree = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::MCCREE };
}

CharacterScene::~CharacterScene(void) {
}

void CharacterScene::OnEntry(void) {
}

void CharacterScene::OnExit(void) {
}

void CharacterScene::Update(void) {
	static MouseCoords mouseCoords(0, 0);
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		Println("===============");
		Println("mxp: ", mouseCoords);
		mouseCoords = IM.GetMouseCoords();
	}
	else if (IM.IsMouseUp<MOUSE_BUTTON_LEFT>()) {
		Println("mxn: ", IM.GetMouseCoords());
	}
							// Test InputManager key methods
	if (IM.IsKeyHold<'a'>()) Println("a hold");
	if (IM.IsKeyDown<'0'>()) Println("0 down");
	if (IM.IsKeyHold<KEY_BUTTON_DOWN>()) {
		//Println("down arrow up");
		mccree.transform.y+= TM.GetDeltaTime()*1.3;
	}
	if (IM.IsKeyHold<KEY_BUTTON_UP>()) {
		//Println("up arrow up");
		mccree.transform.y -= TM.GetDeltaTime()*1.3;
	}
	if (IM.IsKeyHold<KEY_BUTTON_LEFT>()) {
		//Println("left arrow up");
		mccree.transform.x -= TM.GetDeltaTime()*1.3;
		flip = SDL_FLIP_NONE;

	}
	if (IM.IsKeyHold<KEY_BUTTON_RIGHT>()) {
		//Println("right arrow up");
		mccree.transform.x += TM.GetDeltaTime()*1.3;
		flip = SDL_FLIP_HORIZONTAL;
	}
}

void CharacterScene::Draw(void) {
	m_background.Draw(); // Render background
	//mccree.Draw(); // Rencer mccree
	R.Rotate(mccree.transform,ObjectID::MCCREE, flip); // IT'S HIGH NOON
	//GUI::DrawTextShaded<FontID::FACTORY>("It's High Noon",
	//{ W.GetWidth() >> 1, int(W.GetHeight()*.1f), 1, 1 },
	//{ 190, 0, 160 }, { 50, 200, 230 }); // Render score that will be different when updated

}
