#include "RandomEvent.h"


void RandomEvent::EventChest()
{
	text.resize(2);
	max = 1;
	t_btn.resize(3);
	setText(L" Я отворил дверь в одну из комнат. Комната была богато убрана,\n\
со стен свисали портьеры, а пол устлан коврами.\n\
В середине комнаты стоял большой красивый сундук.\n\
Я подошел и увидел гравировку A.B.B.A..\n\
Кажется это был  фамильный герб владельцев башни...", text[0], normallFont, 553, 799, white, n);
	setText(L"Что ж посмотрим, какие драгоценности здесь есть.\n", text[1], normallFont, 553, 799, white, n);
	setText(L"Продолжить\n", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"Открыть\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"Открыть\n", t_btn[2], normallFont, 1024, 959, white, n);

}
void RandomEvent::EventMimik()
{
	text.resize(2);
	t_btn.resize(3);
	max = 1;
	setText(L"Комната в которую я вошел, была роскошной, вся в позолоте\n\
и мебели, ручной работы. Очень дорого и вызывающе.\n\
В центре комнате был пьедестал, на котором возвышался\n\
огромный сундук. Он был весь в драгоценных камнях и\n\
притягивал внимание.Он будто манил к себе и хотел чтобы...", text[0], normallFont, 553, 799, white, n);
	setText(L"его открыли. Я протянул руку к крышке и неожиданно\n\
огромный язык обвил мою руку.Я решил ...", text[1], normallFont, 553, 799, white, n);


	setText(L"Продолжить", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"Отдернуть руку\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"Открыть крышку\n", t_btn[2], normallFont, 1024, 959, white, n);
}
void RandomEvent::EventSacredAltar()
{
	max = 1;
	text.resize(2);
	t_btn.resize(3);
	setText(L"Я стоял в грязном темном коридоре, уставший и раненый.\n\
Посмотрев вокруг себя, я увидел недалеко приоткрытую\n\
дверь. Из просвета исходил голубой цвет. Я подошел и заглянул \n\
внутрь. В комнате находилась скульптура плачущей женщины, из\n\
глаз которой капали слезы...\n", text[0], normallFont, 553, 799, white, n);
	setText(L"Они стекали к ее ногам, у которых стоял кубок, наполненый чем-то.\n\
Атмосфера комнаты не выглядела зловеще, а была скорее\n\
сострадающей. Я подошел к кубку и...\n", text[1], normallFont, 553, 799, white, n);
	setText(L"Продолжить\n", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"Вылил\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"Бросил в стену\n", t_btn[2], normallFont, 1024, 959, white, n);

}
void RandomEvent::EventBloodyAltar()
{
	text.resize(3);
	max = 0;
	t_btn.resize(3);
	setText(L"Чето делает\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"Выпил\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"Вылил\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventTrap()
{
	text.resize(3);
	max = 0;
	t_btn.resize(3);
			  
	setText(L"Лестница на следующий этаж двигается! И как мне пройти дальше?\n\
Придется прыгать по ступенькам и надеяться, что я\n\
не свалюсь на пики точеные. Но я вижу еще неподалеку\n\
выход на балкон, если попробовать забраться по камням\n\
на следующий этаж...\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"Пойти по ступенькам\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"Выйти на балкон\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventStone()
{
	text.resize(2);
	max = 1;
	t_btn.resize(3);
	setText(L" Я шел по полуразрушенному коридору, везде были кучи\n\
камней, досок и костей. Кажется это местечко опасное.\n\
То и дело слышался шорох крыс и от них сыпалась с \n\
потолка пыль. Неожиданно огромная крыса прыгнула на\n\
балку надо мной и от ее веса, балка хрустнула и упала...", text[0], normallFont, 553, 799, white, n);
	setText(L"на меня.Я ... Балка пролетела в нескольких сантиметраз\n\
от меня и врезалась в большой булыжник, который был сзади\n\
меня, булыжник  придавил меня.\n ", text[1], normallFont, 553, 799, white, n);
	setText(L"Продолжить", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"Сделал шаг назад\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"Сделал шаг вперед\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventBoiler()
{
	text.resize(1);
	max = 0;
	t_btn.resize(3);

	setText(L" Откуда такой ужасный запах? Около лестницы стоял\n\
большой булькающий котел. В нем была вязкая зеленая\n\
жидкость, от которой исходил неприятный запах.Рядом\n\
лежал половник. Я решил ...\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"Попробовать\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"Пойти дальше\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventTitle()
{
	text.resize(2);
	max = 1;
	t_btn.resize(2); 
	setText(L"	Я осмотрелся и увидел на стенах еле заметные надписи:\n\
There's not a soul out there No one to hear my prayer\n\
Кажется кто то просил о помощи. \n\
Откуда такой ужасный запах ? Около лестницы стоял\n\
Gimme gimme gimme a man after midnight  Won't...", text[0], normallFont, 553, 799, white, n);
	setText(L"somebody help me chase the shadows away.\n\
Неужели монстры здесь такие умные, что умеют писать?\n", text[1], normallFont, 553, 799, white, n);
	setText(L"Продолжить\n", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"Идти дальше\n", t_btn[1], normallFont, 646, 959, white, n);
}

void RandomEvent::EventViewTower()
{
	text.resize(1);
	setText(L"Почему в башнях всегда проблемы со светом?\n\
Я хочу узнать обстановку снаружи, в какой местности я\n\
нахожусь и сколько сейчас времени. О кажется впереди\n\
туннеля есть какой-то свет... Ха ха это всего лишь\n\
окошко, замечательно, могло быть и хуже.\n\
Я выглянул из маленького окошка в конце\n\
длинного коридора.Вид, который мне открылся,\n\
был завораживающим.\nНа небе розоватая луна,\n\
освещала развалины башни, равнину и темный\n\
лес.Больше ничего не было.Как так получилось,\n\
что башня одна единственная постройка на такое\n\
огромное расстояние? \nЛес выглядел зловеще,\n\
но через его макушки проглядывали первые лучи\n\
солнца. Надо спешить, уже светает.\n ", text[0], normallFont, 553, 799, white, n);
	
}

RandomEvent::RandomEvent(System& system, Hero* hero, bool*isLoadSource)
{
	init(system, hero, isLoadSource);
	white = sf::Color::White;
	countHistory = 0;
	next = [&]()
	{
		if (countHistory < text.size())
		{
			countHistory++;
			if (max == countHistory)
			{
				btn_enabled = true;
			}
		}
		else
		{
			std::cout << "NEXT";
			throw ID_NEXT;
		}
	};
}

void RandomEvent::update()
{
	if (event->type == sf::Event::MouseMoved)
	{
		sf::Vector2f coordinate = mouse->getCoordinate();
		if (btn_enabled)
		{
			for (auto& ui : action_btn)
			{
				ui->setIdle();
				if (ui->containsCursor(coordinate))
				{
					ui->setHover();
				}
			}
		}
		else
		{
			next_btn[0]->setIdle();
			if (next_btn[0]->containsCursor(coordinate))
			{
				next_btn[0]->setHover();
			}
		}
	}
	if (event->type == sf::Event::MouseButtonReleased)
	{
		sf::Vector2f coordinate = mouse->getCoordinate();
		if (btn_enabled)
		{
			for (auto& ui : action_btn)
			{
				if (ui->containsCursor(coordinate))
				{
					ui->startClick();
					next();
				}
			}
		}
		else
		{
			if (next_btn[0]->containsCursor(coordinate))
			{
				next();
			}
		}

	}
}

void RandomEvent::render()
{
}

void RandomEvent::draw()
{
}

void RandomEvent::hud()
{
	handle->draw(shape);
	if (btn_enabled)
	{
		for (auto& ui : action_btn)
		{
			handle->draw(ui->getRect());
		}
	}
	else
	{
		handle->draw(next_btn[0]->getRect());
	}
	handle->draw(text[countHistory]);
	if (btn_enabled)
	{
		for (int i = 1; i < t_btn.size(); i++)
		{
			handle->draw(t_btn[i]);
		}
	}
	else
	{
		handle->draw(t_btn[0]);
	}

	handle->draw(history);
}

void RandomEvent::createSource()
{
	isDelete = false;
	*isLoadSource = true;
	std::mt19937 mersenne{ reinterpret_cast<unsigned>(this) };

	std::uniform_int_distribution<int> num(0, 3);
	texture = new sf::Texture[3];
	loadTexture("resources//Image//Textures//RandomFrame.png", &texture[0]);
	loadTexture("resources//Image//Textures//RandomEventButton.png", &texture[1]);
	loadTexture("resources//Image//Textures//HoverButton0.png", &texture[2]);
	insertButton(0, next_btn, 556, 949, 323, 49, &texture[1], &texture[2]);
	insertButton(0, action_btn, 556, 949, 323, 49, &texture[1], &texture[2]);
	insertButton(1, action_btn, 992, 949, 323, 49, &texture[1], &texture[2]);
	shape.setTexture(&texture[0], true);
	shape.setSize(sf::Vector2f(texture[0].getSize().x, texture[0].getSize().y));
	shape.setPosition(486.f, 719.f);
	int test = 5;
	switch (test)
	{
	case 0:
	{
		EventChest();
	}break;
	case 1:
	{
		EventMimik();
	}break;
	case 2:
	{
		EventSacredAltar();
	}break;
	case 3:
	{
		EventBloodyAltar();
	}break;
	case 4:
	{
		EventTrap();
	}break;
	case 5:
	{
		EventStone();
	}break;
	case 6:
	{
		EventBoiler();
	}break;
	case 7:
	{
		EventTitle();
	}break;
	case 8:
	{
		EventViewTower();
	}break;
	}
	if (max == countHistory)
	{
		btn_enabled = true;
	}
}

void RandomEvent::removeSource()
{
	isDelete = true;
	deleteArrayObject(texture);
	for (auto& ui : action_btn)
	{
		deleteObject(ui);
	}
	for (auto& ui : next_btn)
	{
		deleteObject(ui);
	}
}

RandomEvent::~RandomEvent()
{
	if (isDelete) return;
	this->removeSource();
}
