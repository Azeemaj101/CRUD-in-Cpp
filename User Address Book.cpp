#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#define max 8
using namespace std;

void addContacts();
void viewContacts();
void searchContact();
void editContact();
void deleteContact();

string strings[max]; // define max string

// length of the string
int len(string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

// create custom split() function
void split(string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= len(str))
    {
        if (str[i] == seperator || i == len(str))
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

int main()
{
    system("cls");
    bool run = true;
    do
    {
        int Option;
        cout << "-----------------User Address Book------------------------" << endl;
        cout << "\n";
        cout << "What would you like to do?" << endl;
        cout << "1.) Add Contact" << endl;
        cout << "2.) Edit Contact" << endl;
        cout << "3.) Delete Contact" << endl;
        cout << "4.) View All Contacts" << endl;
        cout << "5.) Search Address Book" << endl;
        cout << "6.) Exit" << endl
             << endl;
        cout << "Choose an option: ";
        cin >> Option;
        cin.ignore();
        switch (Option)
        {
        case 1:
            addContacts();
            break;
        case 2:
            editContact();
            break;
        case 3:
            deleteContact();
            break;
        case 4:
            viewContacts();
            break;
        case 5:
            searchContact();
            break;
        case 6:
            run = false;
            break;
        default:
            cout << "Please Choose between 1 to 6" << endl;
            int main();
        }
    } while (run);
    cout << "Program Terminated";
}

void addContacts()
{
    system("cls");
    string Fname, Lname, Address, Contact, list, name, Fname2, Lname2, Address2, Contact2;
    double counter, number;
    cout << "----------------------Address Book-----------------------------" << endl
         << endl;
    cout << "Enter 'quit' at First name to quit" << endl
         << endl;
    cout << "Enter First Name: ";
    getline(cin, Fname);
    char seperator = ' '; // space
    split(Fname, seperator);
    Fname = strings[0];
    strings[0] = "^";
    for (int i = 1; i < max; i++)
    {
        if (!strings[i].empty() && strings[i] != "^")
        {
            Fname += '~' + strings[i];
        }
        strings[i] = "^";
    }
    if (Fname == "quit")
        main();
    cout << "Enter Last Name: ";
    getline(cin, Lname);
    char seperator1 = ' '; // space
    split(Lname, seperator1);
    Lname = strings[0];
    strings[0] = "^";
    for (int i = 1; i < max; i++)
    {
        if (!strings[i].empty() && strings[i] != "^")
        {
            Lname += '~' + strings[i];
        }
        strings[i] = "^";
    }
    cout << "Enter Address: ";
    getline(cin, Address);
    char seperator2 = ' '; // space
    split(Address, seperator2);
    Address = strings[0];
    strings[0] = "^";
    for (int i = 1; i < max; i++)
    {
        if (!strings[i].empty() && strings[i] != "^")
        {
            Address += '~' + strings[i];
        }
        strings[i] = "^";
    }
    cout << "Enter Contact Number: ";
    getline(cin, Contact);

    ifstream asd("AddressBook.txt");
    while (asd >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
    {
        if (counter == 100)
        {
            cout << "Invalid Max number of contacts reached (100).";
            main();
        }
        else
            number = counter;
    }
    ofstream adb("AddressBook.txt", ios::app);
    number = number + 1;
    adb << number << " " << Fname << " " << Lname
        << " " << Address << " " << Contact << endl;
    system("pause");
    system("cls");
}

void viewContacts()
{
    system("cls");
    double counter;
    string Fname, Lname, Address, Contact;
    ifstream addressbook("AddressBook.txt");
    cout << "Entry #" << setw(17) << "First Name" << setw(23) << "Last Name" << setw(23) << "Address" << setw(29) << "Contact" << endl
         << endl;
    char seperator1 = '~'; // space
    while (addressbook >> counter >> Fname >> Lname >> Address >> Contact)
    {
        split(Fname, seperator1);
        Fname = strings[0];
        strings[0] = '^';
        for (int i = 1; i < max; i++)
        {
            if (!strings[i].empty() && strings[i] != "^")
            {
                Fname += ' ' + strings[i];
            }
            strings[i] = '^';
        }
        split(Lname, seperator1);
        Lname = strings[0];
        strings[0] = '^';
        for (int i = 1; i < max; i++)
        {
            if (!strings[i].empty() && strings[i] != "^")
            {
                Lname += ' ' + strings[i];
            }
            strings[i] = '^';
        }
        split(Address, seperator1);
        Address = strings[0];
        strings[0] = '^';
        for (int i = 1; i < max; i++)
        {
            if (!strings[i].empty() && strings[i] != "^")
            {
                Address += ' ' + strings[i];
            }
            strings[i] = '^';
        }
        cout << setw(3) << counter << setw(18) << Fname << setw(25) << Lname << setw(25) << Address << setw(30) << Contact << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}

void searchContact()
{
    system("cls");
    int choice;
    double counter, number;
    string Fname, Lname, Address, Contact, Fname2, Lname2, Address2, Contact2;

    cout << "----------------------Address Book-----------------------------" << endl
         << endl;
    cout << "---Search Address Book---" << endl;
    cout << "1.) Search in Accending Order" << endl;
    cout << "2.) Search in Descending Order" << endl;
    cout << "3.) Show 'A' OR 'M' Records Only" << endl;
    cout << "4.) LHR in their address " << endl;
    cout << "5.) More than 2 strings/words in their names " << endl;
    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Accending Order: ";
        cout << endl;
        break;
    case 2:
        cout << "Descending Order: ";
        cout << endl;
        break;
    case 3:
        cout << "'A' OR 'M' Data: ";
        cout << endl;
        break;
    case 4:
        cout << "LHR address: ";
        cout << endl;
        break;
    case 5:
        cout << "2 strings/words in their names: ";
        cout << endl;
        break;
    default:
        cout << "Please Enter choice from 1 to 4";
        searchContact();
    }
    ifstream search("AddressBook.txt");
    ifstream CreateArray("AddressBook.txt");
    char sortArray[100];
    fill_n(sortArray, 100, '}');
    int count = 0;
    while (CreateArray >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
    {
        sortArray[count] = Fname2[0];
        count++;
    }

    CreateArray.close();
    char seperator1 = '~';
    if (choice == 1)
    {
        char temp;
        int n = 100;
        for (int i = 0; i < n; i++)
        {
            if (sortArray[i] != '}')
            {

                for (int j = 1; j < n - i; j++)
                {
                    if (sortArray[j - 1] > sortArray[j])
                    {
                        temp = sortArray[j - 1];
                        sortArray[j - 1] = sortArray[j];
                        sortArray[j] = temp;
                    }
                }
            }
        }
        for (int i = 0; i < 100; i++)
        {
            if (sortArray[i] != '}')
            {
                ifstream search1("AddressBook.txt");
                while (search1 >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
                {
                    if (Fname2[0] == sortArray[i])
                    {
                        split(Fname2, seperator1);
                        Fname2 = strings[0];
                        strings[0] = '^';
                        for (int i = 1; i < max; i++)
                        {
                            if (!strings[i].empty() && strings[i] != "^")
                            {
                                Fname2 += ' ' + strings[i];
                            }
                            strings[i] = '^';
                        }
                        split(Lname2, seperator1);
                        Lname2 = strings[0];
                        strings[0] = '^';
                        for (int i = 1; i < max; i++)
                        {
                            if (!strings[i].empty() && strings[i] != "^")
                            {
                                Lname2 += ' ' + strings[i];
                            }
                            strings[i] = '^';
                        }
                        split(Address2, seperator1);
                        Address2 = strings[0];
                        strings[0] = '^';
                        for (int i = 1; i < max; i++)
                        {
                            if (!strings[i].empty() && strings[i] != "^")
                            {
                                Address2 += ' ' + strings[i];
                            }
                            strings[i] = '^';
                        }
                        cout << counter << "	" << Fname2 << "	" << Lname2 << "	" << Address2 << "	" << Contact2 << endl;
                    }
                }
                search1.close();
            }
        }
    }
    if (choice == 2)
    {
        char temp;
        int n = 100;
        for (int i = 0; i < n; i++)
        {
            if (sortArray[i] != '}')
            {

                for (int j = 1; j < n - i; j++)
                {
                    if (sortArray[j - 1] < sortArray[j])
                    {
                        temp = sortArray[j - 1];
                        sortArray[j - 1] = sortArray[j];
                        sortArray[j] = temp;
                    }
                }
            }
        }
        for (int i = 0; i < 100; i++)
        {
            if (sortArray[i] != '}')
            {
                ifstream search1("AddressBook.txt");
                while (search1 >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
                {
                    if (Fname2[0] == sortArray[i])
                    {
                        split(Fname2, seperator1);
                        Fname2 = strings[0];
                        strings[0] = '^';
                        for (int i = 1; i < max; i++)
                        {
                            if (!strings[i].empty() && strings[i] != "^")
                            {
                                Fname2 += ' ' + strings[i];
                            }
                            strings[i] = '^';
                        }
                        split(Lname2, seperator1);
                        Lname2 = strings[0];
                        strings[0] = '^';
                        for (int i = 1; i < max; i++)
                        {
                            if (!strings[i].empty() && strings[i] != "^")
                            {
                                Lname2 += ' ' + strings[i];
                            }
                            strings[i] = '^';
                        }
                        split(Address2, seperator1);
                        Address2 = strings[0];
                        strings[0] = '^';
                        for (int i = 1; i < max; i++)
                        {
                            if (!strings[i].empty() && strings[i] != "^")
                            {
                                Address2 += ' ' + strings[i];
                            }
                            strings[i] = '^';
                        }
                        cout << counter << "	" << Fname2 << "	" << Lname2 << "	" << Address2 << "	" << Contact2 << endl;
                    }
                }
                search1.close();
            }
        }
    }
    if (choice == 3)
    {
        ifstream search1("AddressBook.txt");
        while (search1 >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
        {
            if (Fname2[0] == 'A' || Fname2[0] == 'M')
            {
                split(Fname2, seperator1);
                Fname2 = strings[0];
                strings[0] = '^';
                for (int i = 1; i < max; i++)
                {
                    if (!strings[i].empty() && strings[i] != "^")
                    {
                        Fname2 += ' ' + strings[i];
                    }
                    strings[i] = '^';
                }
                split(Lname2, seperator1);
                Lname2 = strings[0];
                strings[0] = '^';
                for (int i = 1; i < max; i++)
                {
                    if (!strings[i].empty() && strings[i] != "^")
                    {
                        Lname2 += ' ' + strings[i];
                    }
                    strings[i] = '^';
                }
                split(Address2, seperator1);
                Address2 = strings[0];
                strings[0] = '^';
                for (int i = 1; i < max; i++)
                {
                    if (!strings[i].empty() && strings[i] != "^")
                    {
                        Address2 += ' ' + strings[i];
                    }
                    strings[i] = '^';
                }
                cout << counter << "	" << Fname2 << "	" << Lname2 << "	" << Address2 << "	" << Contact2 << endl;
            }
        }
        search1.close();
    }
    if (choice == 4)
    {
        ifstream search1("AddressBook.txt");
        while (search1 >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
        {
            if (Address2 == "LHR")
            {
                split(Fname2, seperator1);
                Fname2 = strings[0];
                strings[0] = '^';
                for (int i = 1; i < max; i++)
                {
                    if (!strings[i].empty() && strings[i] != "^")
                    {
                        Fname2 += ' ' + strings[i];
                    }
                    strings[i] = '^';
                }
                split(Lname2, seperator1);
                Lname2 = strings[0];
                strings[0] = '^';
                for (int i = 1; i < max; i++)
                {
                    if (!strings[i].empty() && strings[i] != "^")
                    {
                        Lname2 += ' ' + strings[i];
                    }
                    strings[i] = '^';
                }
                split(Address2, seperator1);
                Address2 = strings[0];
                strings[0] = '^';
                for (int i = 1; i < max; i++)
                {
                    if (!strings[i].empty() && strings[i] != "^")
                    {
                        Address2 += ' ' + strings[i];
                    }
                    strings[i] = '^';
                }
                cout << counter << "	" << Fname2 << "	" << Lname2 << "	" << Address2 << "	" << Contact2 << endl;
            }
        }
        search1.close();
    }
    if (choice == 5)
    {
        ifstream search1("AddressBook.txt");
        while (search1 >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
        {
            int a = Fname2.find('~');
            if (a >= 0)
            {
                split(Fname2, seperator1);
                Fname2 = strings[0];
                strings[0] = '^';
                for (int i = 1; i < max; i++)
                {
                    if (!strings[i].empty() && strings[i] != "^")
                    {
                        Fname2 += ' ' + strings[i];
                    }
                    strings[i] = '^';
                }
                split(Lname2, seperator1);
                Lname2 = strings[0];
                strings[0] = '^';
                for (int i = 1; i < max; i++)
                {
                    if (!strings[i].empty() && strings[i] != "^")
                    {
                        Lname2 += ' ' + strings[i];
                    }
                    strings[i] = '^';
                }
                split(Address2, seperator1);
                Address2 = strings[0];
                strings[0] = '^';
                for (int i = 1; i < max; i++)
                {
                    if (!strings[i].empty() && strings[i] != "^")
                    {
                        Address2 += ' ' + strings[i];
                    }
                    strings[i] = '^';
                }
                cout << counter << "	" << Fname2 << "	" << Lname2 << "	" << Address2 << "	" << Contact2 << endl;
            }
        }
        search1.close();
    }
    system("pause");
    system("cls");
}

void editContact()
{
    system("cls");
    double choice;
    double counter, number;
    string Fname, Lname, Address, Contact, Fname2, Lname2, Address2, Contact2, choice2, choice3;
    ifstream edit("AddressBook.txt");
    ofstream temp("Temp.txt", ios::app);

    ifstream edit1("AddressBook.txt");
    cout << "Please type the Entry number that you wish to edit: ";
    cin >> choice;
    cout << endl;
    if (choice <= 0 || choice > 100)
    {
        cout << "Error, wrong entry";
        system("pause>0");
        editContact();
    }
    int i = 0;
    while (edit1 >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
    {
        if (counter == choice)
        {
            char seperator1 = '~';
            split(Fname2, seperator1);
            Fname2 = strings[0];
            strings[0] = '^';
            for (int i = 1; i < max; i++)
            {
                if (!strings[i].empty() && strings[i] != "^")
                {
                    Fname2 += ' ' + strings[i];
                }
                strings[i] = '^';
            }
            split(Lname2, seperator1);
            Lname2 = strings[0];
            strings[0] = '^';
            for (int i = 1; i < max; i++)
            {
                if (!strings[i].empty() && strings[i] != "^")
                {
                    Lname2 += ' ' + strings[i];
                }
                strings[i] = '^';
            }
            split(Address2, seperator1);
            Address2 = strings[0];
            strings[0] = '^';
            for (int i = 1; i < max; i++)
            {
                if (!strings[i].empty() && strings[i] != "^")
                {
                    Address2 += ' ' + strings[i];
                }
                strings[i] = '^';
            }
            cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl
                 << endl;
            cout << "Is this the contact that you wish to edit? (y or n) ";
            cin >> choice3;
            cout << endl;
        }
    }
    edit1.close();
    while (edit >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
    {
        if (choice3 == "n")
        {
            main();
        }
        if (choice3 == "y")
        {
            if (counter < choice)
            {
                temp << counter << "	" << Fname2 << "	" << Lname2 << "	" << Address2 << "	" << Contact2 << endl;
            }
            if (counter == choice)
            {
                cout << "Enter First Name: ";
                cin.ignore();
                getline(cin, Fname);
                char seperator = ' '; // space
                split(Fname, seperator);
                Fname = strings[0];
                strings[0] = "^";
                for (int i = 1; i < max; i++)
                {
                    if (!strings[i].empty() && strings[i] != "^")
                    {
                        Fname += '~' + strings[i];
                    }
                    strings[i] = "^";
                }
                if (Fname == "quit")
                    main();
                cout << "Enter Last Name: ";
                getline(cin, Lname);
                char seperator1 = ' '; // space
                split(Lname, seperator1);
                Lname = strings[0];
                strings[0] = "^";
                for (int i = 1; i < max; i++)
                {
                    if (!strings[i].empty() && strings[i] != "^")
                    {
                        Lname += '~' + strings[i];
                    }
                    strings[i] = "^";
                }
                cout << "Enter Address: ";
                getline(cin, Address);
                char seperator2 = ' '; // space
                split(Address, seperator2);
                Address = strings[0];
                strings[0] = "^";
                for (int i = 1; i < max; i++)
                {
                    if (!strings[i].empty() && strings[i] != "^")
                    {
                        Address += '~' + strings[i];
                    }
                    strings[i] = "^";
                }
                cout << "Enter Contact Number: ";
                getline(cin, Contact);

                temp << choice << " " << Fname << " " << Lname << " " << Address << " " << Contact << endl;
            }
            if (counter > choice)
            {
                temp << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl;
            }
        }
    }

    edit.close();
    temp.close();

    if (choice3 == "y")
    {
        if (remove("AddressBook.txt") == 0)
        {
            cout << "Succesful Removing File" << endl;
        }
        else
        {
            cout << "Error removing" << endl;
        }
        if (rename("Temp.txt", "AddressBook.txt") == 0)
        {
            cout << "Succesful Renaming file" << endl;
        }
        else
        {
            cout << "Error renaming" << endl;
        }
        system("pause");
        system("cls");
    }
    system("cls");
}

void deleteContact()
{
    system("cls");
    int choice;
    double counter, number;
    string Fname, Lname, Address, Contact, Fname2, Lname2, Address2, Contact2, choice2, choice3;
    ifstream edit("AddressBook.txt");
    ofstream temp("Temp.txt", ios::app);
    cout << "Please type the Entry number that you wish to delete: ";
    cin >> choice;
    cout << endl;

    while (edit >> counter >> Fname2 >> Lname2 >> Address2 >> Contact2)
    {
        if (counter == choice)
        {
            char seperator1 = '~';
            split(Fname2, seperator1);
            Fname2 = strings[0];
            strings[0] = '^';
            for (int i = 1; i < max; i++)
            {
                if (!strings[i].empty() && strings[i] != "^")
                {
                    Fname2 += ' ' + strings[i];
                }
                strings[i] = '^';
            }
            split(Lname2, seperator1);
            Lname2 = strings[0];
            strings[0] = '^';
            for (int i = 1; i < max; i++)
            {
                if (!strings[i].empty() && strings[i] != "^")
                {
                    Lname2 += ' ' + strings[i];
                }
                strings[i] = '^';
            }
            split(Address2, seperator1);
            Address2 = strings[0];
            strings[0] = '^';
            for (int i = 1; i < max; i++)
            {
                if (!strings[i].empty() && strings[i] != "^")
                {
                    Address2 += ' ' + strings[i];
                }
                strings[i] = '^';
            }
            cout << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl
                 << endl;
            cout << "Is this the contact that you wish to delete? (y or n) ";
            cin >> choice3;
            cout << endl;
        }
        if (choice3 == "n")
        {
            main();
        }
        if (counter < choice)
        {
            temp << counter << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl;
        }
        if (counter > choice)
        {
            temp << counter - 1 << " " << Fname2 << " " << Lname2 << " " << Address2 << " " << Contact2 << endl;
        }
    }

    edit.close();
    temp.close();

    if (remove("AddressBook.txt") == 0)
    {
        cout << "Succesful Removing File" << endl;
    }
    else
    {
        cout << "Error removing" << endl;
    }
    if (rename("Temp.txt", "AddressBook.txt") == 0)
    {
        cout << "Succesful Renaming file" << endl;
    }
    else
    {
        cout << "Error renaming" << endl;
    }
    system("pause");
    system("cls");
}

