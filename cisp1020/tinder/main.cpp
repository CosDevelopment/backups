#include "heap.h"
#include "people.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    char beginMatching, sportChoice, seePerson;  // Selections for loops
    People choicePerson;  // person for inserting match information
    ifstream infile("Wamen.txt"); // wamen file
    Heap<People> matches([](People &people1, People &people2) {if (people1.value <people2.value)return true; else false; }); // heap with comparatir
  ///UI for inputting information
    cout << "Welcome to CISP1020, the 1020th iteration of the \" Compatability Inferencing System Protocal\"" << endl;
    cout << "Today we will ask you a series of questions to help you find your PERFECT MATCH!" << endl;
    cout << "Are you ready to begin... (Y/N):";
    cin >> beginMatching;
    if (beginMatching == 'Y' || beginMatching == 'y')
    {
        cout << "Please pick an eye color from the list below by typing EXACTLY the color as displayed " << endl;
        cout << "Blue, Brown, Green, Hazel: ";
        cin >> choicePerson.eyeColor;

        cout << "Do you want your mate to like sports? (Y/N): ";
        cin >> sportChoice;
        if (sportChoice == 'Y' || sportChoice == 'y')
            choicePerson.sport = true;
        else
            choicePerson.sport = false;

        cout << "Please enter in the the minimum niceness value you would want your homosapien mate to have (0-10): " << endl;
        cin >> choicePerson.nice;

        cout << "How important is this to you? (0-10): " << endl;
        cin >> choicePerson.niceImportance;

        cout << "Please enter in the the minimum attractiveness value you would want your homosapien mate to have (0-10): " << endl;
        cin >> choicePerson.attractiveness;

        cout << "How important is this to you? (0-10): " << endl;
        cin >> choicePerson.attractivenessImportance;

        cout << "Please enter in the the minimum intelligence value you would want your homosapien mate to have (0-10): " << endl;
        cin >> choicePerson.intelligence;

        cout << "How important is this to you? (0-10): " << endl;
        cin >> choicePerson.intelligenceImportance;

        cout << "Please pick a hair color from the list below by typing EXACTLY the color as displayed " << endl;
        cout << "Blonde, Brunette, Red, Black, Other: ";
        cin >> choicePerson.hair;

        cout << "Please pick a dress type from the list below by typing EXACTLY the choice as displayed " << endl;
        cout << "Hipster, Business,Formal,Casual,Other: ";
        cin >> choicePerson.dress;

        cout << "Please pick a phone type from the list below by typing EXACTLY the choice as displayed " << endl;
        cout << "Iphone, Android, Other:";
        cin >> choicePerson.phone;

        cout << "Please pick a preferred DnD class from the list below by typing EXACTLY the choice as displayed " << endl;
        cout << "Wizard, Warrior, Barbarian, Cleric, Amazon, Other: ";
        cin >> choicePerson.preferredClass;

        cout << "Please pick the physique from the list below by typing EXACTLY the choice as displayed " << endl;
        cout << "Athletic, Twiggy, Sedentary, Fat, Hefty, Obese, Feederism, Other: ";
        cin >> choicePerson.physique;

        People::buildPeople(infile, matches, choicePerson);
        infile.close();
        // loop to output people
        while (!matches.isEmpty())
        {
            cout << "Would you like to see a match? (Y/N)" << endl;
            cin >> seePerson;
            if (seePerson == 'y' || seePerson == 'Y')
            {
                People::print(matches.removeMax());
            }
            else
            {
                break;
            }
        }
        cout<<"NO MORE MATCHES :), for a small subscription of $150, we can search for more :)"<<endl;
    }
    else
    {
        cout << "GoodBye!" << endl;
    }
    cout << "Initalizing exit protocol" << endl;

    return 0;
}
