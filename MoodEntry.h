#ifndef MOODENTRY_H
#define MOODENTRY_H

#include <string>
using namespace std;

class MoodEntry {
    private:
        string mood;
        int rating;
        string note;
        string timeStamp;
    public: 
        MoodEntry();
        MoodEntry(string mood, int rating, string note, string timeStamp);

        //setters
        void setMood(string* mood);
        void setRating(int rating);
        void setNote(string note);
        void setTimeStamp(string timeStamp);

        //getters
        string getMood() const;
        int getRating() const;
        string getNote() const;
        string getTimeStamp() const;

        virtual void display() const;
        virtual void saveToFile(const string& fileName) const;
};
#endif