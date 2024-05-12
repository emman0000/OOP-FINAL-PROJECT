#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SymptomTracker {
public:
    // Function to record symptoms
    void recordSymptoms() {
        // Display list of symptoms to choose from
        displaySymptomList();

        // Ask user to input symptoms
        cout << "Enter the number of symptoms you are experiencing: ";
        int numSymptoms;
        cin >> numSymptoms;

        cout << "Enter the corresponding numbers for the symptoms you are experiencing:" << endl;
        for (int i = 0; i < numSymptoms; ++i) {
            int choice;
            cout << "Symptom " << i + 1 << ": ";
            cin >> choice;

            // Validate user input
            if (choice >= 1 && choice <= symptomList.size()) {
                selectedSymptoms.push_back(symptomList[choice - 1]);
            } else {
                cout << "Invalid choice. Please enter a valid symptom number." << endl;
                --i; // Decrement i to re-ask for the current symptom
            }
        }
    }

    // Function to provide recommendations based on recorded symptoms
    void provideRecommendations() {
        // Iterate over selected symptoms and provide recommendations
        cout << "Based on your symptoms, here are some recommendations:" << endl;
        for (const string& symptom : selectedSymptoms) {
            if (symptom == "Headache") {
                cout << "- Take painkiller XYZ." << endl;
                cout << "- Rest in a quiet, dark room." << endl;
            } else if (symptom == "Cramps") {
                cout << "- Apply heat (e.g., hot water bottle) to the lower abdomen." << endl;
                cout << "- Try gentle exercise, such as walking or yoga." << endl;
            } else if (symptom == "Diarrhea") {
                cout << "- Stay hydrated by drinking plenty of fluids." << endl;
                cout << "- Eat bland, easily digestible foods." << endl;
            }
            // Add more recommendations for other symptoms as needed
        }
    }

private:
    // List of available symptoms
    vector<string> symptomList = {"Headache", "Cramps", "Diarrhea"}; // Add more symptoms as needed

    // Vector to store selected symptoms
    vector<string> selectedSymptoms;

    // Function to display the list of symptoms
    void displaySymptomList() {
        cout << "Please select from the following symptoms:" << endl;
        for (int i = 0; i < symptomList.size(); ++i) {
            cout << i + 1 << ". " << symptomList[i] << endl;
        }
    }
};
//implement like so in the main function for this to work.
int main() {
    SymptomTracker tracker;
    tracker.recordSymptoms();
    tracker.provideRecommendations();
    return 0;
}//end main  
