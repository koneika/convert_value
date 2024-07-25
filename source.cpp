#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 

using namespace std;

// it`s code works only on linux OS (arch), idk about windows OS
int main()
{
    // for open the python file in my project, via command line
    string command = "python3 web_scraper.py";
    system(command.c_str()); 

    string a;
    short counter = 0, counter1 = 0;
    string string_usd_yen_etc[32];
    string value_usd_yen_etc[32];
    bool switcher = true;

    // need, because 
    // it`s like a class from c++ ?
    fstream file;

    // here we open text file, ios::in - in read mode
    file.open("my_file.txt", ios::in);

    // if cant open, we will see it
    // check some errors, before start my program
    if (!file.is_open()) 
    {
        cerr << "Error, can`t open that file" << endl;
        return 1;
    }

    // work while my file have text
    while (file >> a)
    {
        // // A-Z and a-z = not search, only search digit
        // if( !(a[0] >= 'A' && a[0] <= 'Z') && !(a[0] >= 'a' && a[0] <= 'z') ) 
        // {
        //     cout << a << endl;
        // }

        // для первой записи слова в массив и тд.
        if (switcher == true)
        {
            string_usd_yen_etc[counter] = a;
            counter++;
            switcher = false;
        }

        cout << a << " ";
        
        if( !(a[0] >= 'A' && a[0] <= 'Z') && !(a[0] >= 'a' && a[0] <= 'z') )
        {
            value_usd_yen_etc[counter1] = a;
            counter1++;
            cout << endl;
            switcher = true;
        }


    }

    for(short i = 0; i < 32; i++)
    {
        cout << value_usd_yen_etc[i] << " " << string_usd_yen_etc[i] << endl;
    }

    file.close();
    return 0;
}