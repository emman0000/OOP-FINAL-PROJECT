//this code works but not all of its functions have been called. someone needs to implement the remaining functions which havent been called, in the main. 
//also, need to figure out how to add other symptom without entering infinite loop. i tried introducing an option (enter -2 to enter other symptom) within the 
//recordsymptoms function but it enters an inifinite loop once the name of the other symptom is entered

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip> // for setw
#include <limits>
#include <regex> // for regular expressions

using namespace std;

// Forward declaration of OtherSymptoms class
class OtherSymptoms;

class Symptom {
protected:
    vector<string> symptoms;

public:
    Symptom() {
        // Initialize with some default symptoms
        symptoms.push_back("Cramps");
        symptoms.push_back("Headache");
        symptoms.push_back("Fatigue");
        symptoms.push_back("Mood swings");
        symptoms.push_back("Bloating");
        symptoms.push_back("Breast tenderness");
        symptoms.push_back("Acne");
    }

    void addSymptom(const string& symptom) {
        symptoms.push_back(symptom);
    }

    void displaySymptoms() {
        cout << "Symptoms" << endl;
        int c = 0;
        for (const auto& symptom : symptoms) {
            cout << c++ << "- " << symptom << endl;
        }
    }

    // Friend class to Symptom for additional functionality
    friend class OtherSymptoms;
};

class OtherSymptoms {
public:
    static void displaySymptomFrequency(const Symptom& symptom) {
        cout << "Symptom Frequency" << endl;
        for (const auto& s : symptom.symptoms) {
            cout << s << ": " << symptomFrequency[s] << endl;
        }
    }

    // Static map to keep track of symptom frequency
    static unordered_map<string, int> symptomFrequency;

    // Increment the frequency of a symptom
    static void incrementFrequency(const string& symptom) {
        symptomFrequency[symptom]++;
    }

    // Reset symptom frequency
    static void resetFrequency() {
        symptomFrequency.clear();
    }

    // Allow Symptom class to access private members
    friend class Symptom;
};

unordered_map<string, int> OtherSymptoms::symptomFrequency;

class CyclePhase {
public:
    virtual void recordData() = 0;
    virtual string getName() = 0;
    virtual void storeDataToFile() = 0;
    virtual void recordSymptoms() = 0;
    virtual void recordDates() = 0;
};

class FollicularPhase : public CyclePhase, public Symptom {
public:
    void recordData() override {
        cout << "Recording data for the Follicular Phase..." << endl;
        char choice;
        cout << "\nDo you want to record symptoms? (y/n): ";
        cin >> choice;
        bool flag = false;
        try {
            if (choice == 'y' || choice == 'Y') {
                recordSymptoms();
                flag = true;
            }
            else if (choice == 'n' || choice == 'N') {
                throw("No symptom to append file.\n");
            }
            else {
                throw("Invalid choice.\n");
            }
        }
        catch (const char* msg) {
            cout << msg;
        }
        catch (...) {
            cout << "Invalid choice.\n";
        }
        cout << "\nDo you want to record dates? (y/n): ";
        cin >> choice;
        try {
            if (choice == 'y' || choice == 'Y') {
                recordDates();
                flag = true;
            }
            else if (choice == 'n' || choice == 'N') {
                throw("No date to append file.\n");
            }
            else {
                throw("Invalid choice.\n");
            }
        }
        catch (const char* msg) {
            cout << msg;
        }
        catch (...) {
            cout << "Invalid choice.\n";
        }
        // Store the recorded data in files
        try {
            if (flag)
                storeDataToFile();
            else
                throw("No data to append to follicular_data.txt\n");
        }
        catch (const char* msg) {
            cout << msg;
        }
    }

    string getName() override {
        return "Follicular Phase";
    }

    void recordSymptoms() override {
        cout << "Select symptoms for the " << getName() << " (enter 'done' to finish): " << endl;
        int c = 0;
        while (true) {
            cout << "Select symptom #" << c + 1 << " by choosing the corresponding number. Enter -1 to finish." << endl;
            c++;
            displaySymptoms();
            int choice;
            cin >> choice;
            if (choice >= 0 && choice < symptoms.size()) {
                selectedSymptoms.push_back(symptoms[choice]);
                OtherSymptoms::incrementFrequency(symptoms[choice]); // Increment frequency
            }
            else if (choice == symptoms.size()) {
                recordOtherSymptom();
            }
            else if (choice == -1) {
                break; // Exit the loop if the user inputs -1
            }
            else {
                cout << "Invalid choice. Please enter a valid number or -1 to finish." << endl;
            }
        }
        // Clear input stream to prevent infinite loop
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    void recordDates() override {
        cout << "Enter start date of the Follicular Phase (MM/DD/YYYY): ";
        startDate = validateDateInput();
        cout << "Enter end date of the Follicular Phase (MM/DD/YYYY): ";
        endDate = validateDateInput();
    }

    string validateDateInput() {
        string date;
        regex datePattern("(0[1-9]|1[0-2])/(0[1-9]|[1-2][0-9]|3[0-1])/([0-9]{4})");
        while (true) {
            cin >> date;
            if (regex_match(date, datePattern)) {
                break;
            }
            else {
                cout << "Invalid date format. Please enter in MM/DD/YYYY format: ";
            }
        }
        return date;
    }

    void storeDataToFile() override {
        ofstream file("follicular_data.txt", ios_base::app); // Open a file for appending
        if (file.is_open()) {
            if (!selectedSymptoms.empty() || (!startDate.empty() && !endDate.empty())) {
                file << "+---------------------+---------------------+---------------------+" << endl; // Top border
                file << "| " << left << setw(20) << "Start Date" << "| " << setw(20) << "End Date" << "| " << setw(20) << "Symptoms" << "|" << endl;
                file << "|---------------------|---------------------|---------------------|" << endl;
                file << "| " << left << setw(20) << startDate << "| " << setw(20) << endDate << "| " << setw(20) << "" << "|" << endl;
                if (!selectedSymptoms.empty()) {
                    for (const string& symptom : selectedSymptoms) {
                        file << "| " << setw(20) << "" << "| " << setw(20) << "" << "| " << setw(20) << symptom << "|" << endl;
                    }
                }
                file << "+---------------------+---------------------+---------------------+" << endl; // Bottom border
                file << endl;
            }
            file.close(); // Close the file
            cout << "\nData appended to follicular_data.txt" << endl;
        }
        else {
            cerr << "Error: Unable to open file for writing" << endl;
        }
    }

private:
    string startDate;
    string endDate;
    vector<string> selectedSymptoms;
public:
    void recordOtherSymptom() {
        string newSymptom;
        cout << "Enter a new symptom: ";
        cin >> newSymptom;
        try {
            if (checkExistingSymptom(newSymptom)) {
                throw("Symptom already exists.\n");
            }
            else {
                selectedSymptoms.push_back(newSymptom);
                cout << "Do you want to add this symptom to the default list of symptoms? (y/n): ";
                char choice;
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    addSymptom(newSymptom);
                    cout << "Symptom added to the default list." << endl;
                }
            }
        }
        catch (const char* msg) {
            cout << msg;
        }
    }

    bool checkExistingSymptom(const string& symptom) {
        for (const auto& s : symptoms) {
            if (s == symptom) {
                return true;
            }
        }
        return false;
    }
};

class OvulationPhase : public CyclePhase, public Symptom {
public:
    void recordData() override {
        cout << "Recording data for the Ovulation Phase..." << endl;
        char choice;
        cout << "\nDo you want to record symptoms? (y/n): ";
        cin >> choice;
        bool flag = false;
        try {
            if (choice == 'y' || choice == 'Y') {
                recordSymptoms();
                flag = true;
            }
            else if (choice == 'n' || choice == 'N') {
                throw("No symptom to append file.\n");
            }
            else {
                throw("Invalid choice.\n");
            }
        }
        catch (const char* msg) {
            cout << msg;
        }
        catch (...) {
            cout << "Invalid choice.\n";
        }
        cout << "\nDo you want to record dates? (y/n): ";
        cin >> choice;
        try {
            if (choice == 'y' || choice == 'Y') {
                recordDates();
                flag = true;
            }
            else if (choice == 'n' || choice == 'N') {
                throw("No date to append to file.\n");
            }
            else {
                throw("Invalid choice.\n");
            }
        }
        catch (const char* msg) {
            cout << msg;
        }
        catch (...) {
            cout << "Invalid choice.\n";
        }
        // Store the recorded data in files
        try {
            if (flag)
                storeDataToFile();
            else
                throw("No data to append to ovulation_data.txt\n");
        }
        catch (const char* msg) {
            cout << msg;
        }
    }

    string getName() override {
        return "Ovulation Phase";
    }

    void recordSymptoms() override {
        cout << "Select symptoms for the " << getName() << " (enter 'done' to finish): " << endl;
        int c = 0;
        while (true) {
            cout << "Select symptom #" << c + 1 << " by choosing the corresponding number. Enter -1 to finish." << endl;
            c++;
            displaySymptoms();
            int choice;
            cin >> choice;
            if (choice >= 0 && choice < symptoms.size()) {
                selectedSymptoms.push_back(symptoms[choice]);
                OtherSymptoms::incrementFrequency(symptoms[choice]); // Increment frequency
            }
            else if (choice == symptoms.size()) {
                recordOtherSymptom();
            }
            else if (choice == -1) {
                break; // Exit the loop if the user inputs -1
            }
            else {
                cout << "Invalid choice. Please enter a valid number or -1 to finish." << endl;
            }
        }
        // Clear input stream to prevent infinite loop
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    void recordDates() override {
        cout << "Enter start date of the Ovulation Phase (MM/DD/YYYY): ";
        startDate = validateDateInput();
        cout << "Enter end date of the Ovulation Phase (MM/DD/YYYY): ";
        endDate = validateDateInput();
    }

    string validateDateInput() {
        string date;
        regex datePattern("(0[1-9]|1[0-2])/(0[1-9]|[1-2][0-9]|3[0-1])/([0-9]{4})");
        while (true) {
            cin >> date;
            if (regex_match(date, datePattern)) {
                break;
            }
            else {
                cout << "Invalid date format. Please enter in MM/DD/YYYY format: ";
            }
        }
        return date;
    }

    void storeDataToFile() override {
        ofstream file("ovulation_data.txt", ios_base::app); // Open a file for appending
        if (file.is_open()) {
            if (!selectedSymptoms.empty() || (!startDate.empty() && !endDate.empty())) {
                file << "+---------------------+---------------------+---------------------+" << endl; // Top border
                file << "| " << left << setw(20) << "Start Date" << "| " << setw(20) << "End Date" << "| " << setw(20) << "Symptoms" << "|" << endl;
                file << "|---------------------|---------------------|---------------------|" << endl;
                file << "| " << left << setw(20) << startDate << "| " << setw(20) << endDate << "| " << setw(20) << "" << "|" << endl;
                if (!selectedSymptoms.empty()) {
                    for (const string& symptom : selectedSymptoms) {
                        file << "| " << setw(20) << "" << "| " << setw(20) << "" << "| " << setw(20) << symptom << "|" << endl;
                    }
                }
                file << "+---------------------+---------------------+---------------------+" << endl; // Bottom border
                file << endl;
            }
            file.close(); // Close the file
            cout << "\nData appended to ovulation_data.txt" << endl;
        }
        else {
            cerr << "Error: Unable to open file for writing" << endl;
        }
    }

private:
    string startDate;
    string endDate;
    vector<string> selectedSymptoms;

public:
    void recordOtherSymptom() {
        string newSymptom;
        cout << "Enter a new symptom: ";
        cin >> newSymptom;
        try {
            if (checkExistingSymptom(newSymptom)) {
                throw("Symptom already exists.\n");
            }
            else {
                selectedSymptoms.push_back(newSymptom);
                cout << "Do you want to add this symptom to the default list of symptoms? (y/n): ";
                char choice;
                cin >> choice;
                if (choice == 'y' || choice == 'Y') {
                    addSymptom(newSymptom);
                    cout << "Symptom added to the default list." << endl;
                }
            }
        }
        catch (const char* msg) {
            cout << msg;
        }
    }

    bool checkExistingSymptom(const string& symptom) {
        for (const auto& s : symptoms) {
            if (s == symptom) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    FollicularPhase follicularPhase;
    OvulationPhase ovulationPhase;
    // Record data for the Follicular Phase
    cout<<"-------------------------------------------"<<endl
    << "Recording data for the follicular phase..." << endl;
    follicularPhase.recordData();
    // Record data for the Ovulation Phase
    cout<<"-------------------------------------------"<<endl
    << "Recording data for the ovulation phase..." << endl;
    ovulationPhase.recordData();

    // Display symptom frequency
    cout<<"-------------------------------------------------"<<endl
        <<"Displaying symptom frequency for follicular phase...\n"<<endl;
    OtherSymptoms::displaySymptomFrequency(follicularPhase);
    OtherSymptoms::resetFrequency(); // Reset symptom frequency for next phase
    cout<<"-------------------------------------------------"<<endl
        <<"Displaying symptom frequency for ovulation phase...\n"<<endl;
    OtherSymptoms::displaySymptomFrequency(ovulationPhase);

    return 0;
}
