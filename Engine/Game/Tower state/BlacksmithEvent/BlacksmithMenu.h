#include "BlacksmithEvent.h"


class BlacksmithMenu : public BlacksmithEvent
{
	std::vector <Button*> menuButton;
	void createUI();
	bool hoverButton;
	size_t idHoverButton;
	std::function <void()> startDialog;
	std::function <void()> modification;
	std::function <void()> exit;
	sf::Texture* textureButton;
	sf::Text* textButton;
	sf::Color* white;
	std::function<void()> pressToMove;
	sf::Texture* commandAreaTexture;
	sf::RectangleShape* area;
  public:
	  BlacksmithMenu(System& system, Hero* hero, bool* isLoadSource);
	  

	 void update()override;
	 void render()override;
	 void draw()override;
 void hud()override;
	 void createSource()override;
	 void removeSource()override;
};