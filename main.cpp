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


    MoodEntry moodEntries[10];
    int moodCount = 0;


    cout << "You can log up to 10 moods." << endl;
    cout << "To exit, please enter 'exit' as your mood." << endl;
    for (int i = 0; i < 10; ++i) {
        string userMood, userNote, userTimeStamp;
        cout << "Mood: ";
        getline(cin, userMood);
        if (userMood == "exit") {
            break;
        }
        cout << "Mood Rating (1-5): ";
        int userRating;
        cin >> userRating;
        cin.ignore(); // Clear the newline character from the input buffer
        if (userRating < 1 || userRating > 5) {
            cout << "Invalid rating. Please enter a number between 1 and 5." << endl;
            --i; // Decrement i to retry this entry
            continue;
        }
        cout << "Note: ";
        getline(cin, userNote);
        cout << "Timestamp (mm/dd/yyyy hh:mm AM/PM): ";
        getline(cin, userTimeStamp);
        cout << "---" << endl;
        moodEntries[i].setMood(&userMood);
        moodEntries[i].setNote(userNote);
        moodEntries[i].setTimeStamp(userTimeStamp);
        moodCount++;
    }
    cout << " === Your profile === " << endl;
    teen.display();
    cout << "\n === Your mood entries === " << endl;
    for (int i = 0; i < moodCount; i++) {
        moodEntries[i].display();
    }
    cout << "\nSaving your profile and mood entries..." << endl;
    teen.saveToFile("user_log.txt");
    for (int i = 0; i < moodCount; i++) {    
        moodEntries[i].saveToFile("mood_log.txt");
    }

    cout << "Thank you for using MoodMate! Your profile and entries were saved within user_log.txt and mood_log.txt." << endl;

    return 0;
}