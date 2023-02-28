#ifndef DISPLAY_H_
#define DISPLAY_H_

//class to manage data of display
class Display {
public:
	void info();
	void input();

	//getters, setters
	unsigned int getLightLevel();
	unsigned int getLightScreenLevel();
	unsigned int getLightTabloLevel();

	void setLightLevel(unsigned int light_level);
	void setLightScreenLevel(unsigned int light_screen_level);
	void setLightTabloLevel(unsigned int light_tablo_level);
private:
	unsigned int light_level_ = 0;
	unsigned int light_screen_level_ = 0;
	unsigned int light_tablo_level_ = 0;
};
#endif // ! DISPLAY_H_


