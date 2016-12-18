
#include "GUI.hh"
#include "System.hh"
#include "Logger.hh"
#include "MenuScene.h"
#include "GameScene.hh"
#include "LevelSelect.h"
using namespace Logger;

#define CELL_WIDTH 80
#define CELL_HEIGHT 80

LevelSelect::LevelSelect(void) {
	m_background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID::BG_00 };
	titulo = { { W.GetWidth() / 6, W.GetHeight() / 8, W.GetWidth() - 200, W.GetHeight() - 700 }, ObjectID::TITULO };
}

LevelSelect::~LevelSelect(void) {
}

void LevelSelect::OnEntry(void) {
}

void LevelSelect::OnExit(void) {
}

void LevelSelect::Update(void) {
	static MouseCoords mouseCoords(0, 0);
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		Println("===============");
		Println("mxp: ", mouseCoords);
		mouseCoords = IM.GetMouseCoords();
	}
	else if (IM.IsMouseUp<MOUSE_BUTTON_LEFT>()) {
		Println("mxn: ", IM.GetMouseCoords());
	}

	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>() && IM.GetMouseCoords().x > 340 && IM.GetMouseCoords().x < 428 && IM.GetMouseCoords().y > 282 && IM.GetMouseCoords().y < 329) {  //Apretar el boto de play
		SM.SetCurScene <GameScene>();
		mouseCoords = IM.GetMouseCoords();
	}

	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>() && IM.GetMouseCoords().x > 315 && IM.GetMouseCoords().x < 455 && IM.GetMouseCoords().y > 435 && IM.GetMouseCoords().y < 480) {  //Apretar el boto de exit
		SM.SetCurScene <GameScene>();
		mouseCoords = IM.GetMouseCoords();
	}

	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>() && IM.GetMouseCoords().x > 341 && IM.GetMouseCoords().x < 591 && IM.GetMouseCoords().y > 427 && IM.GetMouseCoords().y < 637) {  //Apretar el boto de exit
		SM.SetCurScene <GameScene>();
		mouseCoords = IM.GetMouseCoords();
	}


	// Test InputManager key methods
	if (IM.IsKeyHold<'a'>()) Println("a hold");
	if (IM.IsKeyDown<'0'>()) Println("0 down");
	if (IM.IsKeyUp<KEY_BUTTON_DOWN>()) Println("down arrow up");

}

void LevelSelect::Draw(void) {
	m_background.Draw(); // Render background
	titulo.Draw();
	GUI::DrawTextShaded<FontID::ARIAL>("Easy",
	{ W.GetWidth() >> 1, int(W.GetHeight()*.4f), 1, 1 },
	{ 190, 0, 160 }, { 50, 200, 230 }); // Render score that will be different when updated
	GUI::DrawTextShaded<FontID::ARIAL>("Medium",
	{ W.GetWidth() >> 1, int(W.GetHeight()*.6f), 1, 1 },
	{ 190, 0, 160 }, { 50, 200, 230 }); // Render score that will be different when updated
	GUI::DrawTextShaded<FontID::ARIAL>("Hard",
	{ W.GetWidth() >> 1, int(W.GetHeight()*.8f), 1, 1 },
	{ 190, 0, 160 }, { 50, 200, 230 }); // Render score that will be different when updated
}
