#include"InventoryScreen.h"

void InventoryScreen::createUI()
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 7; j++)
		{
			int id = i * 7 + j ; // 7 - это максимум по одной стороне
			insertButton(id, buttonsInventoryScreen, j * 117 + 559, 120 * i + 251, 100, 100, &texture[0], &texture[1]);
		}
	}
	setText(L"Инвентарь", *title, titleFont, 839, 174, white, 48);
}

void InventoryScreen::createDropMenu()
{
	sf::String textDropMenu[2];
	textDropMenu[0] = L"Использовать";
	textDropMenu[1] = L"Выкинуть";
	dropMenuUI = new sf::Text[2];
	for (int i = 0; i < 2; i++)
	{
		insertButton(i, buttonsDropMenu, 564 + i * 299, 949, 238, 49, &texture[1]);
		setText(textDropMenu[i], dropMenuUI[i], normallFont, 564 + i * 299, 949, white, 24);
	}
	dropItem = [this]()
	{
		inventory->removeItem(positionCreateDropMenu);
		itemInfo->setString(L"");
		isCreated = false;
	};
	useItem = [this]()
	{
		inventory->useItem(positionCreateDropMenu, hero);
		itemInfo->setString(L"");
		isCreated = false;
	};
	buttonsDropMenu[1]->setOnClick(dropItem);
	buttonsDropMenu[0]->setOnClick(useItem);
	isCreated = true;
}

void InventoryScreen::removeDropMenu()
{
	deleteArrayObject(dropMenuUI);
	for (auto& ui : buttonsDropMenu)
	{
		deleteObject(ui);
	}
	buttonsDropMenu.clear();
	isCreated = false;
}

InventoryScreen::InventoryScreen(System& system, Hero* hero)
{
	positionCreateDropMenu = 0;
	this->inventory = hero->openInventory();
	init(system, hero);
	red = sf::Color::Red;
	white = sf::Color::White;
	isCreated = false;
	isDropMenu = false;
	textArea.setSize(sf::Vector2f(869, 273));
	inventoryArea.setSize(sf::Vector2f(828, 493));
	textArea.setPosition(512, 758);
	inventoryArea.setPosition(546, 145);
	sf::Color area(0x19, 0x1C, 0x25);
	textArea.setFillColor(area);
	inventoryArea.setFillColor(area);
}

void InventoryScreen::update()
{
	if (event->type == sf::Event::MouseMoved)
	{
		sf::Vector2f coordinate = mouse->getCoordinate();
		//Для начала проверка на наведение курсора на объекта
		buttonsInventoryScreen[positionHoverItem]->setIdle();
		for (auto& ui : buttonsInventoryScreen)
		{
			if (ui->containsCursor(coordinate))
			{
				isHover = true;
				positionHoverItem = ui->getState();
				break;
			}
		}
		buttonsInventoryScreen[positionDropMenu]->setIdle();
		//Проверка на наведение курсора на выпадающее меню
		if (isDropMenu)
		{
			for (auto& ui : buttonsDropMenu)
			{
				isHover = true;
				positionDropMenu = ui->getState();
				break;
			}
		}
	}
	if (event->type == sf::Event::MouseButtonReleased)
	{
		if (event->key.code == sf::Mouse::Left)
		{

			sf::Vector2f coordinate = mouse->getCoordinate();
			//Проверка на нажатие на предмет
			for (auto& ui : buttonsInventoryScreen)
			{
				if (ui->containsCursor(coordinate))
				{
					if (inventory->getItem(ui->getState()))
					{
						if (isCreated)
						{
							removeDropMenu();
							positionCreateDropMenu = ui->getState();
							createDropMenu();
							isDropMenu = true;
						}
						else {
							positionCreateDropMenu = ui->getState();
							createDropMenu();
							isDropMenu = true;
							isCreated = true;
						}
					}
				}
			}

			//Проверка на нажатие на выпадающее меню
			for (auto& ui : buttonsDropMenu)
			{
				if (ui->containsCursor(coordinate))
				{
					isDropMenu = false;
					ui->startClick();
					removeDropMenu();
					break;
				}
			}
		}
	}
}

void InventoryScreen::draw()
{
	handle->clear(sf::Color(0xC4, 0xC4, 0xC4));
	handle->draw(inventoryArea);

	for (auto& ui : buttonsInventoryScreen)
	{
		handle->draw(ui->getRect());
	}
	handle->draw(*title);
	handle->draw(textArea);
	handle->draw(*itemInfo);
	if (isDropMenu)
	{
		for (size_t i = 0; i < 2; i++)
		{
			handle->draw(buttonsDropMenu[i]->getRect());
			handle->draw(dropMenuUI[i]);
		}

	}
	handle->draw(*inventory);
}

void InventoryScreen::render()
{
	if(isCreated)
	{
	setText(inventory->showInfo(positionCreateDropMenu), *itemInfo, normallFont, 563, 802, white, 24);
	}
}

void InventoryScreen::createSource()
{
	itemInfo = new sf::Text;
	texture = new sf::Texture[2];
	loadTexture("resources//Image//Textures//rect.png", &texture[0]);
	loadTexture("resources//Image//Textures//red.png", &texture[1]);
	title = new sf::Text;
	createUI();
}

void InventoryScreen::removeSource()
{
	for (auto& ui : buttonsInventoryScreen)
	{
		deleteObject(ui);
	}
	buttonsInventoryScreen.clear();
	deleteObject(title);
	deleteArrayObject(texture);
	deleteObject(itemInfo);
	if (isCreated)
	{
		removeDropMenu();
	}
}

void InventoryScreen::hud()
{
	return;
}
