/*
 Exercise P11.12.
 Write a program that keeps an appointment book. Make a class Appointment that stores a description of the appointment, the appointment day, the starting time, and the ending time.
 Your program should keep the appointments in a sorted vector. Users can add appointments and print out all appointments for a given day. When a new appointment is added, use binary search to find where it should be inserted in the vector. Do not add it if it conflicts with another appointment.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "appointment.hpp"

using namespace std;

void print_appointments(vector<Appointment> v, string vect_name = "v");

// NOT DEFINED IN APPOINTMENT CLASS!
bool compare_start(const Appointment& a, const Appointment& b);
bool compare_end(const Appointment& a, const Appointment& b);

int main(int argc, const char * argv[]) {
    vector<Appointment> v;
    Appointment appt = Appointment();
    string desc, date_start, date_end;
    
    // A ruby script file 'project_directory/generate_data.rb' is used to create a flat records file containing appointment data.
    // Careful resizing vector. The while loop is based on the vector size. Most likely, nbot every record in the data file will be contained in the vector due to the constraint of having appointments with times that do not overlap.
    const string data = "/Users/christianmeyer/cpp/ch11/P11_12/data.txt";
    fstream fs(data.c_str());
    while (v.size() < 100 ){
        bool start_time_in_vector = true, end_time_in_vector = true; // These will be set to false if new appointments have an overlapping date and time with an appointment obj already inside the vector
        // DATES formatted 'yyyy-mm-dd'
        // TIMES formatted 'hh:mm'
        string time_start = "", time_end = "";
        getline(fs, desc, '|');
        getline(fs, date_start, '|');
        getline(fs, date_end, '\n');
        if (date_end.length() > 10){
            // If there are times given at all, the last getline would have stored both of them along with the date_end string all in the same string. So now need to extract the three substrings from temp_date_end.
            string temp_date_end = date_end; // Temp string is created so that date_end can be assigned the first substring within itself, while preserving the rest of the string contents
            int count = 0, start = 0;
            for (int i = 0; i < temp_date_end.length(); i++){
                count++;
                if (temp_date_end[i] == '|' && start == 0){
                    date_end = temp_date_end.substr(start, count-1);
                    start = i+1;
                    count = 0;
                } else if (temp_date_end[i] == '|'){
                    time_start = temp_date_end.substr(start, count-1);
                    start = i+1;
                    count = 0;
                }
            }
            time_end = temp_date_end.substr(start, count);
            // If a the data contains time information, a new appointment will be created with time argument provided. Otherwise, the new appointment object will have only dates.
            appt = Appointment(desc, date_start, date_end, time_start, time_end);
            // Although it may be redundant, the vector must be sorted in order to perform a binary search to check if a new appointment object has a start/end time that interferes with the start/end time of any appointment object already in the vector.
            // Note: There is only a need to compare vectors if there are times associated with the appt. There is no way of knowing whether appointments that are the same day (but do not have times) would interfere with one another.
            sort(v.begin(), v.end(), compare_start); // default quicksort #Compare
            start_time_in_vector = binary_search(v.begin(), v.end(), appt, compare_start);
            sort(v.begin(), v.end(), compare_end);
            end_time_in_vector = binary_search(v.begin(), v.end(), appt, compare_end);
        } else {
            appt = Appointment(desc, date_start, date_end);
        }
        if (!start_time_in_vector && !end_time_in_vector) v.push_back(appt);
    }
    fs.close();
    
    // Sorting one more time in case the last 1+ vector entries did not have times associated with them and were not sorted at the end of the previous while loop.
    sort(v.begin(), v.end(), compare_start);
    print_appointments(v, "Appointment  v");

    return 0;
}

void print_appointments(vector<Appointment> v, std::string vect_name){
    for (int i = 0; i < v.size(); i++){
        cout << vect_name << "[" << i << "]:\n";
        cout << "Description: " << v[i].get_description() << endl;
        cout << left << setw(13) << "Date_Start: " << v[i].get_start_date() << endl;
        cout << left << setw(13) << "Date_End: " << v[i].get_end_date() << endl;
        if (v[i].get_time_given()){
            cout << left << setw(13) << "Time_Start: " << v[i].get_start_time() << endl;
            cout << left << setw(13) << "Time_End: " << v[i].get_end_time() << endl;
        }
        cout << left << setw(22) << "start_mins_from_2000: " << v[i].get_start_mins_from_2000() << " minutes" << endl;
        cout << left << setw(22) << "end_mins_from_2000: " << v[i].get_end_mins_from_2000() << " minutes" << endl;
        int hours = v[i].get_appointment_duration() / 60;
        int mins = v[i].get_appointment_duration() % 60;
        cout << left << setw(22) << "appointment_duration: " << right << setfill('0') << setw(2) << hours << ":" << setw(2) << mins << " hours" << endl;
        cout << setfill(' ') << "\n";
    }
}

// There are used for the #sort and #binary_search functions as the comparison function for the start and end times
bool compare_start(const Appointment& a, const Appointment& b){
    if (a.get_start_mins_from_2000() < b.get_start_mins_from_2000()) return true;
    else return false;
}
bool compare_end(const Appointment& a, const Appointment& b){
    if (a.get_end_mins_from_2000() < b.get_end_mins_from_2000()) return true;
    else return false;
}
