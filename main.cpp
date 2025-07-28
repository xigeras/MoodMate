#include <iostream>
#include "TeenUser.h"
#include "MoodEntry.h"
using namespace std;

int main() {
    cout << "Welcome to MoodMate!" << endl;
    
    TeenUser teen;
    // Pass by value
    cout << "Enter your name: ";
    string name;
    getline(cin, name);
    teen.setName(name);
    
    // Pass by reference
    cout << "Enter your age: ";
    int age;
    cin >> age;
    teen.setAge(age);

    // Pointer
    cout << "Enter your school name: ";
    cin.ignore();
    string school;
    getline(cin, school);
    teen.setSchool(&school);


    MoodEntry moodEntry;
    cout << "You can log up to 10 moods." << endl;
    cout << "To exit, please enter 'exit' as your mood." << endl;
    for (int i = 0; i < 10; ++i) {
        string userMood, userNote, userTimeStamp;
        cout << "Mood: ";
        getline(cin, userMood);
        if (userMood == "exit") {
            break;
        }
        cout << "Note: ";
        getline(cin, userNote);
        cout << "Timestamp (dd/mm/yyyy hh:mm AM/PM): ";
        getline(cin, userTimeStamp);
        cout << "---" << endl;
        moodEntry.setMood(&userMood);
        moodEntry.setNote(userNote);
        moodEntry.setTimeStamp(userTimeStamp);
    }

    teen.saveToFile("user_log.txt");
    moodEntry.saveToFile("mood_log.txt");
    cout << "Thank you for using MoodMate! Your profile and entries were saved within user_log.txt and mood_log.txt." << endl;

    return 0;
}