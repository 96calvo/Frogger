/******************************************************************
* Copyright (C) 2016 Jordi Serrano Berbel <jsberbel95@gmail.com> *
* This can not be copied, modified and/or distributed without    *
* express permission of the copyright owner.                     *
******************************************************************/

#include "GUI.hh"
#include "System.hh"
#include "Logger.hh"
#include "MenuScene.h"
#include "GameScene.hh"
#include "LevelSelect.h"
using namespace Logger;

#define CELL_WIDTH 80
#define CELL_HEIGHT 80

MenuScene::MenuScene(void){
	m_background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::BG_00 };
	titulo = { { W.GetWidth()/6, W.GetHeight()/8, W.GetWidth()-200, W.GetHeight()-700 }, ObjectID::TITULO };
}

MenuScene::~MenuScene(void) {
}

void MenuScene::OnEntry(void) {
}

void MenuScene::OnExit(void) {
}

void MenuScene::Update(void) {
	static MouseCoords mouseCoords(0, 0);
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		Println("===============");
		Println("mxp: ", mouseCoords);
		mouseCoords = IM.GetMouseCoords();
	}
	else if (IM.IsMouseUp<MOUSE_BUTTON_LEFT>()) {
		Println("mxn: ", IM.GetMouseCoords());
	}

	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>() && IM.GetMouseCoords().x > 346 && IM.GetMouseCoords().x <424  &&  IM.GetMouseCoords().y > 283 && IM.GetMouseCoords().y < 330) {  //Apretar el boto de play
		SM.SetCurScene <LevelSelect> ();
		mouseCoords = IM.GetMouseCoords();
	}

	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>() && IM.GetMouseCoords().x > 313 && IM.GetMouseCoords().x < 455 && IM.GetMouseCoords().y > 438 && IM.GetMouseCoords().y < 482) {  //Apretar el boto de play
		//SM.SetCurScene <LevelSelect>();
		mouseCoords = IM.GetMouseCoords();
	}

	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>() && IM.GetMouseCoords().x > 352 && IM.GetMouseCoords().x < 416 && IM.GetMouseCoords().y > 591 && IM.GetMouseCoords().y < 635) {  //Apretar el boto de exit
		IM.SetQuit();
		mouseCoords = IM.GetMouseCoords();
	}


							// Test InputManager key methods
	if (IM.IsKeyHold<'a'>()) Println("a hold");
	if (IM.IsKeyDown<'0'>()) Println("0 down");
	if (IM.IsKeyUp<KEY_BUTTON_DOWN>()) Println("down arrow up");
	
}

void MenuScene::Draw(void) {
	m_background.Draw(); // Render background
	titulo.Draw();
	GUI::DrawTextShaded<FontID::ARIAL>("Play",
	{ W.GetWidth() >> 1, int(W.GetHeight()*.4f), 1, 1 },
	{ 190, 0, 160 }, { 50, 200, 230 }); // Render score that will be different when updated
	GUI::DrawTextShaded<FontID::ARIAL>("Ranking",
	{ W.GetWidth() >> 1, int(W.GetHeight()*.6f), 1, 1 },
	{ 190, 0, 160 }, { 50, 200, 230 }); // Render score that will be different when updated
	GUI::DrawTextShaded<FontID::ARIAL>("Exit",
	{ W.GetWidth() >> 1, int(W.GetHeight()*.8f), 1, 1 },
	{ 190, 0, 160 }, { 50, 200, 230 }); // Render score that will be different when updated
}
