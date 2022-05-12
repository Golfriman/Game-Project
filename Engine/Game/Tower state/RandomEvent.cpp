#include "RandomEvent.h"


void RandomEvent::EventEffectSurprise()
{
	
	
	////Текстура 
	//texture = new sf::Texture[4];
	////Загрузка текстуры
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	////Размер массива текста
	text.resize(1);
	//Установить текст
	setText(L"Привет\n", text[0], normallFont, 553, 799, white, n);

	text.resize(1);
	setText(L"Продолжить\n", text[0], normallFont, 646, 959, white, n);
}
void RandomEvent::EventChest()
{
	texture = new sf::Texture[4];
	loadTexture("resources//Image//Textures//RandomFrame.png", &texture[0]);
	/*texture = new sf::Texture[4];
	loadTexture("resources//Image//Textures//...", &texture[0]);*/
	text.resize(1);
	setText(L" Я отворил дверь в одну из комнат. Комната была богато убрана, со стен свисали портьеры, а пол устлан коврами. \n В середине комнаты стоял большой красивый сундук.\n Я подошел и увидел гравировку A.B.B.A..\n Кажется это был  фамильный герб владельцев башни. Что ж посмотрим, какие драгоценности здесь есть.\n", text[0], normallFont, 553, 799, white, n);
	//insertButton(1, buttons, 0, 0, 0, 0, &texture[0]);
	text.resize(1);
	setText(L"Открыть\n", text[0], normallFont, 646, 959, white, n);

}
void RandomEvent::EventMimik()
{
	/*texture = new sf::Texture[4];
	loadTexture("resources//Image//Textures//...", &texture[0]);*/
	text.resize(1);
	setText(L"Комната в которую я вошел, была роскошной, вся в позолоте и мебели, ручной работы. \nОчень дорого и вызывающе. В центре комнате был пьедестал,  на котором возвышался огромный сундук. \n Он был весь в драгоценных камнях и притягивал внимание. Он будто манил к себе и хотел чтобы его открыли.\nЯ протянул руку к крышке и неожиданно огромный язык обвил мою руку . Я решил ...\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"Отдернуть руку\n", text[0], normallFont, 646, 959, white, n);
	text.resize(1);
	setText(L"Открыть крышку\n", text[0], normallFont, 946, 959, white, n);
}
void RandomEvent::EventSacredAltar()
{
	/*texture = new sf::Texture[4];
	loadTexture("resources//Image//Textures//...", &texture[0]);*/
	text.resize(1);
	setText(L"Я стоял в грязном темном коридоре, уставший и раненый. Посмотрев вокруг себя, я увидел недалеко приоткрытую дверь.\n Из просвета исходил голубой цвет. Я подошел и заглянул внутрь.  В комнате находилась скульптура плачущей женщины,\n  из глаз которой капали слезы. Они стекали к ее ногам, у которых стоял кубок, наполненый чем-то.\n Атмосфера комнаты не выглядела зловеще, а была скорее сострадающей.\n Я подошел к кубку и...\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"Выпил\n", text[0], normallFont, 646, 959, white, n);
	text.resize(1);
	setText(L"Вылил\n", text[0], normallFont, 946, 959, white, n);

}
void RandomEvent::EventBloodyAltar()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"Чето делает\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"Выпил\n", text[0], normallFont, 646, 959, white, n);
	text.resize(1);
	setText(L"Вылил\n", text[0], normallFont, 946, 959, white, n);
}
void RandomEvent::EventTrap()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"Лестница на следующий этаж двигается! И как мне пройти дальше? \n Придется прыгать по ступенькам и надеяться, что я не свалюсь на пики точеные. Но я вижу еще неподалеку выход на балкон, если попробовать забраться по камням на следующий этаж...\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"Пойти по ступенькам\n", text[0], normallFont, 646, 959, white, n);
	text.resize(1);
	setText(L"Выйти на балкон\n", text[0], normallFont, 946, 959, white, n);
}
void RandomEvent::EventStone()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L" Я шел по полуразрушенному коридору, везде были кучи камней, досок и костей. Кажется это местечко опасное. То и дело слышался шорох крыс и от них сыпалась с потолка пыль.\n Неожиданно огромная крыса прыгнула на балку надо мной и от ее веса, балка хрустнула и упала на меня. \n Я ... Балка пролетела в нескольких сантиметраз от меня и врезалась в большой булыжник, который был сзади меня, булыжник  придавил меня.\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"Сделал шаг назад\n", text[0], normallFont, 646, 959, white, n);
	text.resize(1);
	setText(L"Сделал шаг вперед\n", text[0], normallFont, 946, 959, white, n);
}
void RandomEvent::EventBoiler()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L" Откуда такой ужасный запах? Около лестницы стоял большой булькающий котел.\n В нем была вязкая зеленая жидкость, от которой исходил неприятный запах. Рядом лежал половник.\n Я решил ...\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"Попробовать\n", text[0], normallFont, 646, 959, white, n);
	text.resize(1);
	setText(L"Пойти дальше\n", text[0], normallFont, 946, 959, white, n);
}
void RandomEvent::EventTitle()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"  Я осмотрелся и увидел на стенах еле заметные надписи:\nThere's not a soul out there No one to hear my prayer \nКажется кто то просил о помощи. \nGimme gimme gimme a man after midnight  Won't somebody help me chase the shadows away .\n Неужели монстры здесь такие умные, что умеют писать?\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"Продолжить\n", text[0], normallFont, 646, 959, white, n);
}
void RandomEvent::EventDeadFriend()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L" Мертвый приключенец\n ", text[0], normallFont, 553, 799, white, n);
}
void RandomEvent::EventNoiseFighting()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"Шум борьбы\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventOffice()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"Кабинет мага\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventStrawDoll()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"Соломенная кукла\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventViewTower()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"Почему в башнях всегда проблемы со светом? Я хочу узнать обстановку снаружи, в какой местности я нахожусь и сколько сейчас времени. О кажется впереди туннеля есть какой-то свет...\n Ха ха это всего лишь окошко, замечательно, могло быть и хуже. Я выглянул из маленького окошка в конце длинного коридора.Вид, который мне открылся, был завораживающим.\nНа небе розоватая луна, освещала развалины башни, равнину и темный лес.Больше ничего не было.Как так получилось, что башня одна единственная постройка на такое огромное расстояние? \nЛес выглядел зловеще, но через его макушки проглядывали первые лучи солнца. Надо спешить, уже светает.\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventHallucinations()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"Галюцинации\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventCorpse()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"Чей-то труп...\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventReflections()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"Размышления\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent ::CreateRect()
{
	area.setPosition(486, 719);
	area.setSize(sf::Vector2f(944, 334));
	area.setTexture(&texture[0], true);
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
	handle->draw(area);
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
	std::uniform_int_distribution<int> num(0, 3);
	texture = new sf::Texture[4];
	loadTexture("resources//Image//Textures//RandomFrame.png", &texture[0]);
	loadTexture("resources//Image//Textures//RandomEventButton.png", &texture[1]);
	insertButton(0, buttons, 556, 949, 323, 49, &texture[1]);
	
	CreateRect();
	
	switch (num(mersenne))
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
}

void RandomEvent::removeSource()
{
}

RandomEvent::~RandomEvent()
{
}
