#include <iostream>
#include <string>
#include <chrono>  // timer ke liye
using namespace std;
using namespace std::chrono;

// -------- Function to Show Paragraph --------
string getParagraph() {
    // Sample paragraph
    return "this is a simple typing test. your goal is to type exactly what you see here. "
           "make sure to match every letter and space. typing speed is measured in words per minute "
           "and accuracy is the percentage of correct characters you typed. "
           "good luck and type carefully to get the best score possible. remember, practice makes perfect. "
           "this test will help you improve your typing skills and measure your current speed.";
}

// -------- Function to Calculate Accuracy --------
double calculateAccuracy(const string &typed, const string &original) {
    int correctChars = 0;
    for (size_t i = 0; i < typed.size() && i < original.size(); i++) {
        if (typed[i] == original[i]) {
            correctChars++;
        }
    }
    return (double)correctChars / original.size() * 100.0;
}

// -------- Function to Count Words --------
int countWords(const string &text) {
    int count = 0;
    for (char c : text) {
        if (c == ' ') count++;
    }
    return count + 1; // last word count
}

// -------- Main Program --------
int main() {
    string paragraph = getParagraph();

    // Intro
    cout << "------ TYPING SPEED TEST ------\n";
    cout << "Type the following paragraph:\n\n";
    cout << paragraph << "\n\n";
    cout << "Press Enter when ready...";
    cin.ignore();

    // Start typing
    cout << "\nStart typing below:\n";
    auto startTime = high_resolution_clock::now();

    string typedText;
    getline(cin, typedText);

    auto endTime = high_resolution_clock::now();

    // Calculate time taken
    duration<double> elapsed = endTime - startTime;
    double timeInMinutes = elapsed.count() / 60.0;

    // Calculate results
    double accuracy = calculateAccuracy(typedText, paragraph);
    int wordCount = countWords(typedText);
    double wpm = wordCount / timeInMinutes;

    // Show results
    cout << "\n------ RESULTS ------\n";
    cout << "Time Taken: " << elapsed.count() << " seconds\n";
    cout << "Words Typed: " << wordCount << "\n";
    cout << "Typing Speed (WPM): " << wpm << "\n";
    cout << "Accuracy: " << accuracy << "%\n";

    return 0;
}
