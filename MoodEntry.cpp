#include "MoodEntry.h"
#include <iostream>
#include <fstream>

using namespace std;

MoodEntry::MoodEntry() {
    mood = "Unknown";
    note = "Unknown";
    timeStamp = "01/01/2001 00:00:00";
}

MoodEntry::MoodEntry(string userMood, string userNote, string userTimeStamp) {
    mood = userMood;
    note = userNote;
    timeStamp = userTimeStamp;
}

//setters
void MoodEntry::setMood(string* userMood) {
    if (userMood != nullptr) {
        mood = *userMood;
    }
}

void MoodEntry::setNote(string userNote) {
    note = userNote;
}

void MoodEntry::setTimeStamp(string userTimeStamp) {
    timeStamp = userTimeStamp;
}

//getters
string MoodEntry::getMood() const { return mood; }
string MoodEntry::getNote() const { return note; }
string MoodEntry::getTimeStamp() const { return timeStamp; }

void MoodEntry::display() const {
    cout << "Mood: " << mood << endl;
    cout << "Note: " << note << endl;
    cout << "Timestamp: " << timeStamp << endl;
}

void MoodEntry::saveToFile(const string& fileName) const {
    ofstream outFile(fileName, ios::app);
    if (!outFile) {
        cerr << "Could not open file." << endl;
        return;
    }

    outFile << "\nMood: " << getMood() << "\nNote: " << getNote() << "\nTime: " << getTimeStamp() << "\n---" << endl;
    outFile.close();
}

