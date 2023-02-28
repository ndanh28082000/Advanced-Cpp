#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

#include"General.h"
#include"Setting.h"

using namespace std;

vector<string> General::timezone_list_;
vector<string> General::language_list_;

/*
check str_input is a number from 1 to num_of_choices
@param str_input:string that need to check
@param num_of_choices:total of choices that user can input
@return 1->num_of_choices if check success
        -1 if check fail
*/
int checkNumberSelection(string str_input, size_t num_of_choices) {
    if (Setting::checkUnsignedInteger(str_input)) {
        unsigned int temp = stoi(str_input);
        if (temp > 0 && temp <= num_of_choices)return temp;
    }
    return -1;
}

void General::info() {
    cout << left;
    cout << "    "
        << setw(15) << "General:"
        << setw(40) << "Timezone"
        << setw(40) << "Language" << endl;
    cout << "    "
        << setw(15) << ""
        << setw(40) << timezone_
        << setw(40) << language_ << endl;
}
void General::input() {
    inputTimezone();
    inputLanguage();
}

//Getters
string General::getTimezone() {
    return timezone_;
}
string General::getLanguage() {
    return language_;
}

//Setters
void General::setTimezone(string timezone) {
    timezone_ = timezone;
}
void General::setLanguage(string language) {
    language_ = language;
}

void General::downloadTimezone(string file_path) {
    while (true) {
        ifstream fin;
        fin.exceptions(ifstream::failbit | ifstream::badbit);
        try {
            fin.open(file_path);
            string str_temp = "";
            while (!fin.eof()) {
                getline(fin, str_temp);
                if (str_temp != "") {
                    //"(GMT-09:00) /  Alaska" -> (GMT-09:00) Alaska
                    str_temp.erase(12, 2);
                    timezone_list_.push_back(str_temp);
                }
            }
            fin.close();
            if (timezone_list_.size() == 0) {
                //file of timezone_list has no data before
                throw ifstream::failure("");
            }
            else {
                //sort data of timezone depend on the decreasing of UTC
                sortTimezoneList();
                return;
            }
        }
        catch (const ifstream::failure&) {
            //File has no data before or there are not file before
            //Write into file
            string timezone_data =
                "(GMT-12:00) / International Date Line West\n"
                "(GMT-11:00) / Midway Island, Samoa\n"
                "(GMT-10:00) / Hawaii\n"
                "(GMT-09:00) / Alaska\n"
                "(GMT-08:00) / Tijuana, Baja California\n"
                "(GMT-07:00) / Chihuahua, La Paz, Mazatlan - New\n"
                "(GMT-06:00) / Guadalajara, Mexico City, Monterrey - New\n"
                "(GMT-05:00) / Eastern Time(US and Canada)\n"
                "(GMT-04:00) / Atlantic Time(Canada)\n"
                "(GMT-03:30) / Newfoundland\n"
                "(GMT-02:00) / Mid - Atlantic\n"
                "(GMT-01:00) / Azores\n"
                "(GMT-00:00) / Monrovia, Reykjavik\n"
                "(GMT+01:00) / Belgrade, Bratislava, Budapest, Ljubljana, Prague\n"
                "(GMT+02:00) / Minsk\n"
                "(GMT+03:00) / Moscow, St.Petersburg, Volgograd\n"
                "(GMT+04:00) / Abu Dhabi, Muscat\n"
                "(GMT+04:30) / Kabul\n"
                "(GMT+05:00) / Tashkent\n"
                "(GMT+05:30) / Chennai, Kolkata, Mumbai, New Delhi\n"
                "(GMT+05:45) / Kathmandu\n"
                "(GMT+06:00) / Astana, Dhaka\n"
                "(GMT+06:30) / Yangon(Rangoon) /\n"
                "(GMT+07:00) / Bangkok, Hanoi, Jakarta\n"
                "(GMT+08:00) / Beijing, Chongqing, Hong Kong, Urumqi\n"
                "(GMT+08:00) / Irkutsk, Ulaanbaatar\n"
                "(GMT+09:00) / Seoul\n"
                "(GMT+09:30) / Adelaide\n"
                "(GMT+10:00) / Canberra, Melbourne, Sydney\n"
                "(GMT+11:00) / Magadan, Solomon Islands, New Caledonia\n"
                "(GMT+12:00) / Fiji, Kamchatka, Marshall Is.\n"
                "(GMT+13:00) / Nuku'alofa";
            ofstream fout(file_path, ios::out | ios::trunc);
            fout << timezone_data;
            fout.close();
        }
    }
}
void General::downloadLanguage(string file_path) {
    while (true) {
        ifstream fin;
        fin.exceptions(ifstream::failbit | ifstream::badbit);
        try {
            fin.open(file_path);
            string str_temp = "";
            while (!fin.eof()) {
                getline(fin, str_temp);
                if (str_temp != "") {
                    if (str_temp[1] == ' ')str_temp.insert(0, "0");
                    language_list_.push_back(str_temp);
                }
            }
            fin.close();
            if (language_list_.size() == 0) {
                //file of language_list has no data before
                throw ifstream::failure("");
            }
            else {
                //sort data of language depend on index
                sortString(language_list_);
                return;
            }
        }
        catch (const ifstream::failure&) {
            //File has no data before or there are not file before
            //Write into file
            string language_data =
                "1 / Mandarin(entire branch)\n"
                "2 / Spanish\n"
                "3 / English\n"
                "4 / Hindi\n"
                "5 / Arabic\n"
                "6 / Portuguese\n"
                "7 / Bengali\n"
                "8 / Russian\n"
                "9 / Japanese\n"
                "10 / Punjabi\n"
                "11 / German\n"
                "12 / Javanese\n"
                "13 / Wu(inc.Shanghainese)\n"
                "14 / Malay(inc.Indonesian and Malaysian)\n"
                "15 / Telugu\n"
                "16 / Vietnamese\n"
                "17 / Korean\n"
                "18 / French\n"
                "19 / Marathi\n"
                "20 / Tamil\n"
                "21 / Urdu\n"
                "22 / Turkish\n"
                "23 / Italian\n"
                "24 / Yue(inc.Cantonese)\n"
                "25 / Thai\n"
                "26 / Gujarati\n"
                "27 / Jin\n"
                "28 / Southern Min\n"
                "29 / Persian\n"
                "30 / Polish";
            ofstream fout(file_path, ios::out | ios::trunc);
            fout << language_data;
            fout.close();
        }
    }
}

void General::inputTimezone() {
    //repeat until we can choose the valid timezone
    while (true)
    {
        //display the list of timezone
        system("cls");
        cout << "--- SELECT TIMEZONE DATA ---" << endl;
        cout << right;
        for (size_t i = 0; i < timezone_list_.size(); i++) {
            cout << setw(2) << i + 1 << " ";
            cout << timezone_list_[i] << endl;
        }
        //display selection to sort 
        cout << " Enter -u if you want to sort follow the decreasing of UTC" << endl;
        cout << "       -a if you want to sort follow the alaphabet" << endl;
        cout << "Your selection: ";
        string str_input = "";
        bool is_valid = false;
        //repeat if user input selection that is not valid
        while (!is_valid) {
            is_valid = true;
            getline(cin, str_input);
            // check input string
            if (str_input == "-u" || str_input == "-U") {
                //sort the Timezone depend on the decreasing of UTC
                sortTimezoneList();
            }
            else if (str_input == "-a" || str_input == "-A") {
                //sort the Timzone list depend on the alphabet
                sortString(timezone_list_, 12);
            }
            else {
                int index = checkNumberSelection(str_input, timezone_list_.size());
                if (index != -1) {
                    //input timezone success
                    timezone_ = timezone_list_[index - 1].substr(1, 9);//just use UTC-timezone part
                    return;//quit Timezone selection
                }
                else {
                    //invalid selection, display announcement and input it again
                    cout << " * Invalid selection! Please input your selection again: ";
                    is_valid = false;
                }
            }
            //if user input selections to sort the timezone list, we will display timezone list again
        }
    }
}
void General::inputLanguage() {
    //repeat until we can choose the valid language
    while (true) {
        //display the list of language
        system("cls");
        cout << "--- SELECT LANGUAGE DATA ---" << endl;
        cout << right;
        for (size_t i = 0; i < language_list_.size(); i++) {
            cout << setw(2) << i + 1 << " ";
            cout << language_list_[i] << endl;
        }
        //display selection to sort
        cout << "Enter -i to sort by index" << endl;
        cout << "      -a to sort by alphabet" << endl;
        cout << "Your selection: ";
        string str_input = "";
        bool is_valid = false;
        //repeat if user selection that is not valid
        while (!is_valid) {
            is_valid = true;
            getline(cin, str_input);
            //check input string
            if (str_input == "-i" || str_input == "-I") {
                //sort by index
                sortString(language_list_);
            }
            else if (str_input == "-a" || str_input == "-A") {
                //sort by alphabet
                sortString(language_list_, 5);
            }
            else {
                int index = checkNumberSelection(str_input, language_list_.size());
                if (index != -1) {
                    //input language success
                    language_ = language_list_[index - 1].substr(1);
                    return;//quit Language selection
                }
                else {
                    //invalid selection, display announcement and input it again
                    cout << " *Invalid selection! Please input language selection again: ";
                    is_valid = false;
                }
            }
            //if user input selection to sort the language list, we will display language list again
        }
    }
}


void General::sortTimezoneList() {
    sort(timezone_list_.begin(), timezone_list_.end(), [](const string& l, const string& r)
        {
            if (l[4] < r[4]) {
                return true;//compare at position of +/-(+ < -)
            }
            else if (l[4] == r[4]) {
                if (l > r) {
                    if (l[4] == '+') {
                        return true;
                    }
                }
                else {
                    if (l[4] == '-') {
                        return true;
                    }
                }

            }
            return false;
        });
}

void General::sortString(vector<string>& v, int pos_begin) {
    sort(v.begin(), v.end(), [pos_begin](const string& l, const string& r) {
        return l.substr(pos_begin) < r.substr(pos_begin);
        });
}
