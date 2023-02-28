#ifndef GENERAL_H_
#define GENERAL_H_

#include <string>
#include<vector>

using namespace std;

//class to manage data of general(timezone, language,...)
class General {
public:
	void info();
	void input();

	//Getters, Setters
	string getTimezone();
	string getLanguage();

	void setTimezone(string timezone);
	void setLanguage(string language);

	/*
	read data of timezone, language from file text
	@param file_path: link of that file or name of file if it was saved in the same folder
	*/
	static void downloadTimezone(string file_path);
	static void downloadLanguage(string file_path);
private:
	string timezone_ = "GMT-00:00";
	string language_ = "English";

	void inputTimezone();
	void inputLanguage();

	//format the string of timezone_list(ex:(GMT-00:00)/ Monrovia, Reykjavik)
	static vector<string> timezone_list_;

	//format the string of language_list(ex:(18/ French))
	static vector<string> language_list_;

	//sort the list of timezone depend on the decreasing of UTC
	static void sortTimezoneList();

	/*
	sort the array vector<string> depend on the alphabet
	@param &v: the reference of array vector<string>
	@param pos_begin: the starting positon to sort the string
	*/
	static void sortString(vector<string>& v, int pos_begin = 0);
};

#endif // !GENERAL_H_

