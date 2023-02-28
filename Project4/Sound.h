#ifndef SOUND_H_
#define SOUND_H_

// class to manage data of sound
class Sound {
public:
	void info();
	void input();

	unsigned int getMediaLevel();
	unsigned int getCallLevel();
	unsigned int getNavigationLevel();
	unsigned int getNotificationLevel();

	void setMediaLevel(unsigned int media_level);
	void setCallLevel(unsigned int calll_level);
	void setNavigationLevel(unsigned int navigation_level);
	void setNotificationLevel(unsigned int notification_level);
private:
	unsigned int media_level_ = 0;
	unsigned int call_level_ = 0;
	unsigned int navigation_level_ = 0;
	unsigned int notification_level_ = 0;
};

#endif // !SOUND_H_


