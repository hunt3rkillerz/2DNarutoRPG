#include "BattleScreen.h"



BattleScreen::BattleScreen(Ninja *a, Ninja* b)
{
	this->a = a;
	this->b = b;
}


BattleScreen::~BattleScreen()
{
}

void BattleScreen::draw(GraphicsDevice * gDevice)
{
	ID3DXFont *font = nullptr;
	HRESULT hr = D3DXCreateFont(gDevice->device, 40, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE, "Arial", &font);
	if (!SUCCEEDED(hr))
	{
		return;
	}
	RECT r1, r2;
	SetRect(&r1, 50, 50, 600, 200);
	SetRect(&r2, 800, 600, 1000, 800);
	std::string enemy = b->getName() + "\n" + std::to_string(b->getCurHP()) + "/" + std::to_string(b->getHP());
	font->DrawTextA(NULL, enemy.c_str(), -1, &r1, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
	std::string ally = a->getName() + "\n" + std::to_string(a->getCurHP()) + "/" + std::to_string(b->getHP());
	font->DrawTextA(NULL, ally.c_str(), -1, &r2, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
}

