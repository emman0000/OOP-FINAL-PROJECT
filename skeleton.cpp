#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip> // for setw
#include <limits>

using namespace std;

class CyclePhase {
public:
    virtual void recordData() = 0;
    virtual string getName() = 0;
    virtual void storeDataToFile() = 0;
    virtual void recordSymptoms() = 0;
    virtual void recordDates() = 0;
};

class FollicularPhase : public CyclePhase {
public:
    void recordData() override {
        cout << "Recording data for the Follicular Phase..." << endl;
        char choice;
        cout << "Do you want to record symptoms? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            recordSymptoms();
        }
        cout << "Do you want to record dates? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            recordDates();
        }
        // Store the recorded data in files
        storeDataToFile();
    }

    string getName() override {
        return "Follicular Phase";
    }

    void recordSymptoms() override {
        cout << "Enter symptoms for the Follicular Phase (enter 'done' to finish): ";
        string symptom;
        while (true) {
            cin >> symptom;
            if (symptom == "done") {
                break; // Exit the loop if the user inputs "done"
            }
            symptoms.push_back(symptom);
        }
        // Clear input stream to prevent infinite loop
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void recordDates() override {
        cout << "Enter start date of the Follicular Phase (MM/DD/YYYY): ";
        cin >> startDate;
        cout << "Enter end date of the Follicular Phase (MM/DD/YYYY): ";
        cin >> endDate;
    }

    void storeDataToFile() override {
        ofstream file("follicular_data.txt", ios_base::app); // Open a file for appending
        if (file.is_open()) {
            if (!symptoms.empty() || (!startDate.empty() && !endDate.empty())) {
                file << "+---------------------+---------------------+---------------------+" << endl; // Top border
                file << "| " << left << setw(20) << "Start Date" << "| " << setw(20) << "End Date" << "| " << setw(20) << "Symptoms" << "|" << endl;
                file << "|---------------------|---------------------|---------------------|" << endl;
                file << "| " << left << setw(20) << startDate << "| " << setw(20) << endDate << "| " << setw(20) << "" << "|" << endl;
                if (!symptoms.empty()) {
                    for (const string& symptom : symptoms) {
                        file << "| " << setw(20) << "" << "| " << setw(20) << "" << "| " << setw(20) << symptom << "|" << endl;
                    }
                }
                file << "+---------------------+---------------------+---------------------+" << endl; // Bottom border
                file << endl; 
            }
            file.close(); // Close the file
            cout << "Data appended to follicular_data.txt" << endl;
        } else {
            cerr << "Error: Unable to open file for writing" << endl;
        }
    }

private:
    string startDate;
    string endDate;
    vector<string> symptoms;
};

class OvulationPhase : public CyclePhase {
public:
    void recordData() override {
        cout << "Recording data for the Ovulation Phase..." << endl;
        char choice;
        cout << "Do you want to record symptoms? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            recordSymptoms();
        }
        cout << "Do you want to record dates? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            recordDates();
        }
        // Store the recorded data in files
        storeDataToFile();
    }

    string getName() override {
        return "Ovulation Phase";
    }

    void recordSymptoms() override {
        cout << "Enter symptoms for the Ovulation Phase (enter 'done' to finish): ";
        string symptom;
        while (true) {
            cin >> symptom;
            if (symptom == "done") {
                break; // Exit the loop if the user inputs "done"
            }
            symptoms.push_back(symptom);
        }
        // Clear input stream to prevent infinite loop
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void recordDates() override {
        cout << "Enter start date of the Ovulation Phase (MM/DD/YYYY): ";
        cin >> startDate;
        cout << "Enter end date of the Ovulation Phase (MM/DD/YYYY): ";
        cin >> endDate;
    }

    void storeDataToFile() override {
        ofstream file("ovulation_data.txt", ios_base::app); // Open a file for appending
        if (file.is_open()) {
            if (!symptoms.empty() || (!startDate.empty() && !endDate.empty())) {
                file << "+---------------------+---------------------+---------------------+" << endl; // Top border
                file << "| " << left << setw(20) << "Start Date" << "| " << setw(20) << "End Date" << "| " << setw(20) << "Symptoms" << "|" << endl;
                file << "|---------------------|---------------------|---------------------|" << endl;
                file << "| " << left << setw(20) << startDate << "| " << setw(20) << endDate << "| " << setw(20) << "" << "|" << endl;
                if (!symptoms.empty()) {
                    for (const string& symptom : symptoms) {
                        file << "| " << setw(20) << "" << "| " << setw(20) << "" << "| " << setw(20) << symptom << "|" << endl;
                    }
                }
                file << "+---------------------+---------------------+---------------------+" << endl; // Bottom border
                file << endl; 
            }
            file.close(); // Close the file
            cout << "Data appended to ovulation_data.txt" << endl;
        } else {
            cerr << "Error: Unable to open file for writing" << endl;
        }
    }

private:
    string startDate;
    string endDate;
    vector<string> symptoms;
};

class LutealPhase : public CyclePhase {
public:
    void recordData() override {
        cout << "Recording data for the Luteal Phase..." << endl;
        char choice;
        cout << "Do you want to record symptoms? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            recordSymptoms();
        }
        cout << "Do you want to record dates? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            recordDates();
        }
        // Store the recorded data in files
        storeDataToFile();
    }

    string getName() override {
        return "Luteal Phase";
    }

    void recordSymptoms() override {
        cout << "Enter symptoms for the Luteal Phase (enter 'done' to finish): ";
        string symptom;
        while (true) {
            cin >> symptom;
            if (symptom == "done") {
                break; // Exit the loop if the user inputs "done"
            }
            symptoms.push_back(symptom);
        }
        // Clear input stream to prevent infinite loop
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void recordDates() override {
        cout << "Enter start date of the Luteal Phase (MM/DD/YYYY): ";
        cin >> startDate;
        cout << "Enter end date of the Luteal Phase (MM/DD/YYYY): ";
        cin >> endDate;
    }

    void storeDataToFile() override {
        ofstream file("luteal_data.txt", ios_base::app); // Open a file for appending
        if (file.is_open()) {
            if (!symptoms.empty() || (!startDate.empty() && !endDate.empty())) {
                file << "+---------------------+---------------------+---------------------+" << endl; // Top border
                file << "| " << left << setw(20) << "Start Date" << "| " << setw(20) << "End Date" << "| " << setw(20) << "Symptoms" << "|" << endl;
                file << "|---------------------|---------------------|---------------------|" << endl;
                file << "| " << left << setw(20) << startDate << "| " << setw(20) << endDate << "| " << setw(20) << "" << "|" << endl;
                if (!symptoms.empty()) {
                    for (const string& symptom : symptoms) {
                        file << "| " << setw(20) << "" << "| " << setw(20) << "" << "| " << setw(20) << symptom << "|" << endl;
                    }
                }
                file << "+---------------------+---------------------+---------------------+" << endl; // Bottom border
                file << endl; 
            }
            file.close(); // Close the file
            cout << "Data appended to luteal_data.txt" << endl;
        } else {
            cerr << "Error: Unable to open file for writing" << endl;
        }
    }

private:
    string startDate;
    string endDate;
    vector<string> symptoms;
};

class MenstrualPhase : public CyclePhase {
public:
    void recordData() override {
        cout << "Recording data for the Menstrual Phase..." << endl;
        char choice;
        cout << "Do you want to record symptoms? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            recordSymptoms();
        }
        cout << "Do you want to record dates? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            recordDates();
        }
        // Store the recorded data in files
        storeDataToFile();
    }

    string getName() override {
        return "Menstrual Phase";
    }

    void recordSymptoms() override {
        cout << "Enter symptoms for the Menstrual Phase (enter 'done' to finish): ";
        string symptom;
        while (true) {
            cin >> symptom;
            if (symptom == "done") {
                break; // Exit the loop if the user inputs "done"
            }
            symptoms.push_back(symptom);
        }
        // Clear input stream to prevent infinite loop
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void recordDates() override {
        cout << "Enter start date of the Menstrual Phase (MM/DD/YYYY): ";
        cin >> startDate;
        cout << "Enter end date of the Menstrual Phase (MM/DD/YYYY): ";
        cin >> endDate;
    }

    void storeDataToFile() override {
        ofstream file("menstrual_data.txt", ios_base::app); // Open a file for appending
        if (file.is_open()) {
            if (!symptoms.empty() || (!startDate.empty() && !endDate.empty())) {
                file << "+---------------------+---------------------+---------------------+" << endl; // Top border
                file << "| " << left << setw(20) << "Start Date" << "| " << setw(20) << "End Date" << "| " << setw(20) << "Symptoms" << "|" << endl;
                file << "|---------------------|---------------------|---------------------|" << endl;
                file << "| " << left << setw(20) << startDate << "| " << setw(20) << endDate << "| " << setw(20) << "" << "|" << endl;
                if (!symptoms.empty()) {
                    for (const string& symptom : symptoms) {
                        file << "| " << setw(20) << "" << "| " << setw(20) << "" << "| " << setw(20) << symptom << "|" << endl;
                    }
                }
                file << "+---------------------+---------------------+---------------------+" << endl; // Bottom border
                file << endl; 
            }
            file.close(); // Close the file
            cout << "Data appended to menstrual_data.txt" << endl;
        } else {
            cerr << "Error: Unable to open file for writing" << endl;
        }
    }

private:
    string startDate;
    string endDate;
    vector<string> symptoms;
};

class SymptomTracker {
public:
    static void trackSymptoms() {
        cout << "Welcome to symptom soother!" << endl;
        cout << "Please choose from the following symptoms:" << endl;
        cout << "1. Headaches" << endl;
        cout << "2. Cramps" << endl;
        cout << "3. Diarrhea" << endl;
        cout << "4. Other" << endl;

        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                recommendHeadache();
                break;
            case 2:
                recommendCramps();
                break;
            case 3:
                recommendDiarrhea();
                break;
            case 4:
                recommendOther();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

private:
    static void recommendHeadache() {
        cout << "Recommendations for headaches:" << endl;
        cout << "- Rest in a quiet, dark room" << endl;
        cout << "- Apply a cold compress to your forehead" << endl;
        cout << "- Drink plenty of water" << endl;
        cout << "- Take pain relievers such as ibuprofen or acetaminophen" << endl;
    }

    static void recommendCramps() {
        cout << "Recommendations for cramps:" << endl;
        cout << "- Apply a heating pad to your abdomen" << endl;
        cout << "- Take a warm bath" << endl;
        cout << "- Practice relaxation techniques such as deep breathing" << endl;
        cout << "- Take pain relievers such as ibuprofen or acetaminophen" << endl;
        cout << "On a scale of 1 to 4, how severe are your cramps? (1 being mild, 4 being severe): ";
        int severity;
        cin >> severity;
        if (severity >= 3) {
            cout << "Consider consulting a healthcare provider for further evaluation and treatment." << endl;
        }
    }

    static void recommendDiarrhea() {
        cout << "Recommendations for diarrhea:" << endl;
        cout << "- Drink plenty of fluids to stay hydrated" << endl;
        cout << "- Eat bland, easy-to-digest foods such as bananas, rice, applesauce, and toast (BRAT diet)" << endl;
        cout << "- Avoid dairy products, caffeine, and fatty or spicy foods" << endl;
        cout << "- Consider taking over-the-counter medications such as loperamide (Imodium) to help reduce diarrhea" << endl;
    }

    static void recommendOther() {
        cout << "For other symptoms, it is recommended to consult a healthcare provider for personalized advice and treatment." << endl;
    }
};

int main() {
    // Create instances of each phase and record data for them
       // Track symptoms
    SymptomTracker::trackSymptoms();
    FollicularPhase follicular;
    follicular.recordData();
    OvulationPhase ovulation;
    ovulation.recordData();
    LutealPhase luteal;
    luteal.recordData();
    MenstrualPhase menstrual;
    menstrual.recordData();

    return 0; 
}//end main
