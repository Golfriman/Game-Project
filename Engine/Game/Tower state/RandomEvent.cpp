#include "RandomEvent.h"


void RandomEvent::EventEffectSurprise()
{
	text.resize(2);
	setText(L"Привет\n", text[0], normallFont, 553, 799, white, n);
	setText(L"Продолжить\n", text[1], normallFont, 646, 959, white, n);
}
void RandomEvent::EventChest()
{
	text.resize(2);
	setText(L" Я отворил дверь в одну из комнат. Комната была богато убрана,\n\
со стен свисали портьеры, а пол устлан коврами.\n\
В середине комнаты стоял большой красивый сундук.\n\
Я подошел и увидел гравировку A.B.B.A..\n\
Кажется это был  фамильный герб владельцев башни. \n\
Что ж посмотрим, какие драгоценности здесь есть.\n", text[0], normallFont, 553, 799, white, n);
	setText(L"Открыть\n", text[1], normallFont, 646, 959, white, n);

}
void RandomEvent::EventMimik()
{
	text.resize(3);
	t_btn.resize(3);
	setText(L"Комната в которую я вошел, была роскошной, вся в позолоте и мебели, ручной работы.\n\
Очень дорого и вызывающе. В центре комнате был пьедестал,  на котором возвышался огромный сундук.\n\
Он был весь в драгоценных камнях и притягивал внимание. Он будто манил к себе и хотел чтобы\n\
его открыли.\nЯ протянул руку к крышке и неожиданно огромный язык обвил мою руку. Я решил ...\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"Отдернуть руку\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"Открыть крышку\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventSacredAltar()
{
	max = 1;
	text.resize(2);
	t_btn.resize(3);
	setText(L"\tЯ стоял в грязном темном коридоре, уставший и раненый.\n\
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
	t_btn.resize(3);
	setText(L"Лестница на следующий этаж двигается! И как мне пройти дальше?\n\
Придется прыгать по ступенькам и надеяться, что я не свалюсь на пики точеные.\n\
Но я вижу еще неподалеку выход на балкон, если попробовать забраться по камням\n\
на следующий этаж...\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"Пойти по ступенькам\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"Выйти на балкон\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventStone()
{
	text.resize(3);
	t_btn.resize(3);
	setText(L" Я шел по полуразрушенному коридору, везде были кучи камней, досок и костей.\n\
Кажется это местечко опасное. То и дело слышался шорох крыс и от них сыпалась с потолка пыль.\n\
Неожиданно огромная крыса прыгнула на балку надо мной и от ее веса, балка хрустнула и упала на меня.\n\
Я ... Балка пролетела в нескольких сантиметраз от меня и врезалась\n\
в большой булыжник, который был сзади меня, булыжник  придавил меня.\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"Продолжить", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"Сделал шаг назад\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"Сделал шаг вперед\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventBoiler()
{
	text.resize(3);
	max = 0;
	t_btn.resize(3);
	setText(L" Откуда такой ужасный запах? Около лестницы стоял большой булькающий котел\n\
В нем была вязкая зеленая жидкость, от которой исходил неприятный запах.\n\
Рядом лежал половник.\n Я решил ...\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"Попробовать\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"Пойти дальше\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventTitle()
{
	text.resize(2);
	max = -1;
	t_btn.resize(1);
	setText(L"	Я осмотрелся и увидел на стенах еле заметные надписи:\n\
There's not a soul out there No one to hear my prayer\n\
Кажется кто то просил о помощи. \n\
Gimme gimme gimme a man after midnight  Won't somebody help me chase the shadows away .\n\
Неужели монстры здесь такие умные, что умеют писать?\n", text[0], normallFont, 553, 799, white, n);
	setText(L"Идти дальше\n", t_btn[1], normallFont, 646, 959, white, n);
}
void RandomEvent::EventDeadFriend()
{
	text.resize(1);
	setText(L" Мертвый приключенец\n ", text[0], normallFont, 553, 799, white, n);
	//setText(L"Пнуть")
}
void RandomEvent::EventNoiseFighting()
{
	text.resize(1);
	setText(L"Шум борьбы\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventOffice()
{
	text.resize(1);
	setText(L"Кабинет мага\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventStrawDoll()
{
	text.resize(1);
	setText(L"Соломенная кукла\n ", text[0], normallFont, 553, 799, white, n);
	
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
void RandomEvent::EventHallucinations()
{
	text.resize(1);
	setText(L"Галюцинации\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventCorpse()
{
	text.resize(1);
	setText(L"Чей-то труп...\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventReflections()
{
	text.resize(1);
	setText(L"Размышления\n ", text[0], normallFont, 553, 799, white, n);
	
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
	int test = 3;
	switch (test)
	{
	case 0:
	{
		EventEffectSurprise();
		break;
	}
	case 1:
	{
		EventChest();
	}break;
	case 2:
	{
		EventMimik();
	}break;
	case 3:
	{
		EventSacredAltar();
	}break;
	case 4:
	{
		EventBloodyAltar();
	}break;
	case 5:
	{
		EventTrap();
	}break;
	case 6:
	{
		EventStone();
	}break;
	case 7:
	{
		EventBoiler();
	}break;
	case 8:
	{
		EventTitle();
	}break;
	case 9:
	{
		EventDeadFriend();
	}break;
	case 10:
	{
		EventNoiseFighting();
	}break;
	case 11:
	{
		EventOffice();
	}break;
	case 12:
	{
		EventStrawDoll();
	}break;
	case 13:
	{
		EventViewTower();
	}break;
	case 14:
	{
		EventHallucinations();
	}break;
	case 15:
	{
		EventCorpse();
	}break;
	case 16:
	{
		EventReflections();
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
