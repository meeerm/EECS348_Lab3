#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Department preferences
unordered_map<int, vector<int>> department_preferences = {
    {1, {1, 1, 3, 3, 4}},
    {2, {5, 3, 4, 1, 3}},
    {3, {3, 4, 2, 2, 1}},
    {4, {2, 2, 5, 4, 2}},
    {5, {4, 5, 1, 5, 5}}
};

// Programmer preferences
unordered_map<int, vector<int>> programmer_preferences = {
    {1, {3, 4, 2, 4, 3}},
    {2, {1, 3, 5, 5, 2}},
    {3, {2, 1, 4, 2, 1}},
    {4, {5, 5, 1, 1, 5}},
    {5, {4, 2, 3, 3, 4}}
};

// Initialize mappings
unordered_map<int, int> department_to_programmer;
unordered_map<int, int> programmer_to_department;

int main() {
    // Initialize list of free departments
    vector<int> free_departments;
    for (int i = 1; i <= department_preferences.size(); i++) {
        free_departments.push_back(i);
    }

    // While there are free departments
    while (!free_departments.empty()) {
        // Get the next free department
        int department = free_departments[0];
        free_departments.erase(free_departments.begin());

        // Get the department's preference list
        vector<int> preferences = department_preferences[department];

        // Find the highest ranked programmer that has not been rejected by the department
        for (int i = 0; i < preferences.size(); i++) {
            int programmer = preferences[i];
            if (department_to_programmer.find(department) == department_to_programmer.end()
                && programmer_to_department.find(programmer) == programmer_to_department.end()) {
                department_to_programmer[department] = programmer;
                programmer_to_department[programmer] = department;
                break;
            } else if (programmer_to_department[programmer] != department) {
                vector<int> programmer_preferences_list = programmer_preferences[programmer];
                if (programmer_preferences_list[department - 1] < programmer_preferences_list[programmer_to_department[programmer] - 1]) {
                    int previous_department = programmer_to_department[programmer];
                    department_to_programmer[department] = programmer;
                    programmer_to_department[programmer] = department;
                    free_departments.push_back(previous_department);
                    break;
                }
            }
        }
    }
    
    for (auto department_programmer_pair : department_to_programmer) {
        std::cout << "Department " << department_programmer_pair.first << ": Programmer " << department_programmer_pair.second << endl;
    }
}