#include"Dialog.h"

Dialog::Dialog(System& system, Hero* hero, bool* isLoadSource)
{
	init(system, hero, isLoadSource);
	//Это еще двигать в зависимости от размеров экрана
	dialog = {
	L"Добро пожаловать в мою кузницу! Ты не умер и это фантастика!",
	L"Я - кузнец Сварог, мастерю оружие и помогаю путникам, которые попадают\nсюда.",
	L"О, так ты еще не понял! Ты, мой друг, в башне Снов. Чудненькое местечко,\n куда не попадают просто так.",
	L"Вот те раз! Думаешь это так просто? Взял и вышел? Неет, ты на самом деле\n спишь, и это тебе все сниться.",
	L"Да, и самое ужасное, что ты не проснешься, пока не дойдешь до конца, а если\n умрешь здесь, больше не сможешь проснуться",
	L"Да, жизнь штука тяжелая, никогда не знаешь, что с тобой произойдет. А, и еще\n никто не проходил через эту башню полностью",
	L"Та видишь ли, на самом верху живет очень сильный злой маг, победить которого\nне удавалось никому. А чтобы у путников был хоть какой то шанс, я тут стою\nи приторговываю оружем и полезными вещичками. Так что давай, собирайся как\nследует,  в свой последний бой."
	};

	next = [&]()
	{
		//Короче мы тут возвращаемся к выбору действия.
		/*
		* Короче вот смотри.
		* 
		* Выбор:
		* 1. Кто я
		* 2. Где я
		* ...
		* И потом мы к примеру выбрали позицию, прочитали, а после нажали кнопку далее и нас вернуло к выбору действий. 
		* Надеюсь ты меня понял
		*/
		isBtnClick = false;
	};
	hello = [&]()
	{
		//К примеру Hello начинает с текста 0
	};
	whereIam = [&]()
	{
		//Тут с 3
	};
	wantExit = [&]()
	{

	};
	scaredDream = [&]()
	{

	};
	negation = [&]()
	{

	};
	why = [&]
	{

	};
}

void Dialog::update()
{
	if (event->type == sf::Event::MouseMoved)
	{
		/*Отслеживаем движение мыши*/
	}
}

void Dialog::render()
{
}

void Dialog::draw()
{
}

void Dialog::hud()
{
	handle->draw(sh_area);
	if (isBtnClick)
	{
		handle->draw(select[0]->getRect());
		handle->draw(ans);
		handle->draw(select_Text[0]);
	}
	else {
		for (int i = 0; i < select_Text.size(); i++)
		{
			handle->draw(select[i]->getRect());
			handle->draw(select_Text[i]);
		}
	}
}

void Dialog::createSource()
{

	area = new sf::Texture;
	st_button = new sf::Texture[2];
	select_Text.resize(2);
	loadTexture("resources//Image//Textures//RandomEventButton.png", &st_button[0]);
	loadTexture("resources//Image//Textures//HoverButton0.png", &st_button[1]);
	loadTexture("resources//Image//Textures//dialog.png", area);
	sh_area.setPosition(420, 653);
	sh_area.setSize(sf::Vector2f(1046, 436));
	sh_area.setTexture(area);
	//495 720 ->930 295
	setText(dialog[1], ans, normallFont, 478, 720, white, 24);
	/*Кнопка продолжить*/
	setText(L"Продолжить", select_Text[0], normallFont, 478, 720, white, 24);
	insertButton(0, select, 478, 720, 100, 100, &st_button[0], &st_button[1]);

	isBtnClick = true;

}

void Dialog::removeSource()
{
}
