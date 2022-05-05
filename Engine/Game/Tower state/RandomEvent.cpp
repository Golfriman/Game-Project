#include "RandomEvent.h"


void RandomEvent::createAltarEvent()
{
	//Текстура 
	texture = new sf::Texture[4];
	//Загрузка текстуры
	loadTexture("resources//Image//Textures//...", &texture[0]);
	//Размер массива текста
	text.resize(1);
	//Установить текст
	setText(L"Привет\n", text[0], normallFont, 0, 0, white, 12);
	//Установить кнопку
	insertButton(0, buttons, 0, 0, 0, 0, &texture[0]);
}

RandomEvent::RandomEvent(System& system, Hero* hero, bool*isLoadSource)
{
	init(system, hero, isLoadSource);
	white = sf::Color::White;
}

void RandomEvent::update()
{
	
}

void RandomEvent::render()
{
}

void RandomEvent::draw()
{
}

void RandomEvent::hud()
{
	for (auto& ui : buttons)
	{
		handle->draw(ui->getRect());
	}
	for (auto& uiText : text)
	{
		handle->draw(uiText);
	}
}

void RandomEvent::createSource()
{
	*isLoadSource = true;
	std::mt19937 mersenne{ reinterpret_cast<unsigned>(this) };
	std::uniform_int_distribution<int> num(0, 40);
	switch (num(mersenne))
	{
	case 0:
	{
		createAltarEvent();
		break;
	}
	}
}

void RandomEvent::removeSource()
{
}

RandomEvent::~RandomEvent()
{
}
