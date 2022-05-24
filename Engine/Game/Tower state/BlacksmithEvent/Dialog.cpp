#include"Dialog.h"

Dialog::Dialog(System& system, Hero* hero, bool* isLoadSource)
{
	init(system, hero, isLoadSource);
	//Это еще двигать в зависимости от размеров экрана
	dialog =
	{
	L"\nДобро пожаловать в мою кузницу! Ты не умер и это фантастика!",
	L"Я - кузнец Сварог, мастерю оружие и помогаю путникам, которые попадают\nсюда.",
	L"О, так ты еще не понял! Ты, мой друг, в башне Снов. Чудненькое местечко,\n куда не попадают просто так.",
	L"Вот те раз! Думаешь это так просто? Взял и вышел? Неет, ты на самом деле\n спишь, и это тебе все сниться.",
	L"Да, и самое ужасное, что ты не проснешься, пока не дойдешь до конца, а если\n умрешь здесь, больше не сможешь проснуться",
	L"Да, жизнь штука тяжелая, никогда не знаешь, что с тобой произойдет. А, и еще\n никто не проходил через эту башню полностью",
	L"Та видишь ли, на самом верху живет очень сильный злой маг, победить которого\nне удавалось никому. А чтобы у путников был хоть какой то шанс, я тут стою\nи приторговываю оружем и полезными вещичками. Так что давай, собирайся как\nследует,  в свой последний бой."
	};

	enoughTalk = [&]()
	{

		throw ID_MENU_B;
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
		setText(dialog[1], ans, normallFont, 478, 720, white, 24);
		//К примеру Hello начинает с текста 0
	};
	whereIam = [&]()
	{
		setText(dialog[2], ans, normallFont, 478, 720, white, 24);
		//Тут с 3
	};
	wantExit = [&]()
	{
		setText(dialog[3], ans, normallFont, 478, 720, white, 24);
	};
	scaredDream = [&]()
	{
		setText(dialog[4], ans, normallFont, 478, 720, white, 24);
	};
	negation = [&]()
	{
		setText(dialog[5], ans, normallFont, 478, 720, white, 24);
	};
	why = [&]
	{
		setText(dialog[6], ans, normallFont, 478, 720, white, 24);
	};
}

void Dialog::update()
{
	if (event->type == sf::Event::MouseMoved)
	{
		sf::Vector2f cursor = mouse->getCoordinate();
		for (auto& ui : select)
		{
			ui->setIdle();
			if (ui->containsCursor(cursor))
			{
				ui->setHover();
			}
		}
	}
	else if (event->type == sf::Event::MouseButtonPressed)
	{
		if (event->key.code == sf::Mouse::Left)
		{
			sf::Vector2f cursor = mouse->getCoordinate();
			for (auto& ui : select)
			{
				if (ui->containsCursor(cursor))
				{
					ui->startClick();
					return;
				}


			}
		}
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
		handle->draw(ans);
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
	select_Text.resize(7);
	loadTexture("resources//Image//Textures//RandomEventButton.png", &st_button[0]);
	loadTexture("resources//Image//Textures//HoverButton0.png", &st_button[1]);
	loadTexture("resources//Image//Textures//dialog.png", area);
	sh_area.setPosition(420, 653);
	sh_area.setSize(sf::Vector2f(1046, 436));
	sh_area.setTexture(area);
	//495 720 ->930 295
	setText(dialog[0], ans, normallFont, 478, 720, white, 24);
	/*Кнопка продолжить*/
	
	setText(L"Хватит \nразговоров!", select_Text[0], normallFont, 1246, 957, white, 14);
	insertButton(0, select, 1246, 957, 89, 46, &st_button[0], &st_button[1]);
	select[0]->setOnClick(enoughTalk);

	setText(L"Привет!\nКто ты?", select_Text[1], normallFont, 1113, 957, white, 14);
	insertButton(1, select, 1113, 957, 89, 46, &st_button[0], &st_button[1]);
	select[1]->setOnClick(hello);

	setText(L"Где я?", select_Text[2], normallFont, 584, 957, white, 14);
	insertButton(2, select,584, 957, 89, 46, &st_button[0], &st_button[1]);
	select[2]->setOnClick(whereIam);

	setText(L"Я хочу\nотсюда уйти", select_Text[3], normallFont, 717, 957, white, 14);
	insertButton(3, select, 708, 957, 89, 46, &st_button[0], &st_button[1]);
	select[3]->setOnClick(wantExit);

	setText(L"Кошмарный\nсон", select_Text[4], normallFont, 832, 957, white, 14);
	insertButton(4, select, 832, 957, 89, 46, &st_button[0], &st_button[1]);
	select[4]->setOnClick(scaredDream);

	setText(L"Нет,\nтак быть\nне должно!", select_Text[5], normallFont,991, 957, white, 14);
	insertButton(5, select, 991, 957, 89, 46, &st_button[0], &st_button[1]);
	select[5]->setOnClick(negation);

	setText(L"Почему?", select_Text[6], normallFont, 911, 907, white, 14);
	insertButton(6, select, 911, 907, 89, 46, &st_button[0], &st_button[1]);
	select[6]->setOnClick(why);
	
	isBtnClick = true;

}

void Dialog::removeSource()
{
	deleteArrayObject(st_button);
	deleteArrayObject(area);

}
