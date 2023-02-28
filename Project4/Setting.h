#ifndef SETTING_H_
#define SETTING_H_
#include <string>

using namespace std;

//class to manage general information
class Setting {
public:
	Setting(string personnal_key);
	virtual void info();

	//iput data of car: owner name, email, ODO, remind service
	void inputData();

	bool setOwnerName(string owner_name);
	bool setEmail(string email);
	bool setODO(string odo_number);
	bool setRemindService(string remind_service);
	void setODO(unsigned int odo_number);
	void setRemindService(unsigned int remind_service);

	//get data of car
	string getPersonalKey();
	string getOwnerName();
	string getEmail();
	int getODO();
	int getRemindService();

	/*1.check form of owner name
	@param string of owner name to check, uppercase that string after checking(ex: duY aNH->DUY ANH)
	@return true if the form of that owner name is true
	2. check form of email (ex: abc@xyz.def)
	3. check form of personnal key: personal key is a string that has 8 integer numbers
	*/
	static bool checkOwnerName(string& owner_name);
	static bool checkEmail(string email);
	static bool checkPersonalKey(string personal_key);
	static bool checkUnsignedInteger(string str);

	// input level of sth
	static int InputLevelNumber(string data_name);

private:
	string personal_key_;
	string owner_name_;
	string email_;
	int odo_number_;
	int remind_service_;

};
#endif // !SETTING_H_

