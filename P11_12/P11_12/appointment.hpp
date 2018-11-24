/*
 Exercise P11.12.
 Write a program that keeps an appointment book. Make a class Appointment that stores a description of the appointment, the appointment day, the starting time, and the ending time.
 Your program should keep the appointments in a sorted vector.
 Users can add appointments and print out all appointments for a given day. When a new appointment is added, use binary search to find where it should be inserted in the vector.
 Do not add it if it conflicts with another appointment.
*/

#ifndef appointment_hpp
#define appointment_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

class Appointment{
public:
    Appointment();
    Appointment(std::string desc, std::string startdate, std::string enddate, std::string starttime = "", std::string endtime = "");
    //Appointment(std::string desc, int startdate_y, int startdate_m, int startdate_d, int enddate_y, int enddate_m, int enddate_d, int starttime_h = -1, int starttime_m = -1, int endtime_h = -1, int endtime_m = -1);
    void interpret_date_start();
    void interpret_date_end();
    void interpret_time_start();
    void interpret_time_end();
    
    void set_start_mins_from_2000();
    void set_end_mins_from_2000();
    void set_appointment_duration();
    
    bool operator==(const Appointment& a) const;
    bool operator<(const Appointment& a) const;
    
    std::string get_description() const;
    std::string get_start_date() const;
    std::string get_end_date() const;
    std::string get_start_time() const;
    std::string get_end_time() const;
    bool get_time_given() const;
    long int get_start_mins_from_2000() const;
    long int get_end_mins_from_2000() const;
    int get_appointment_duration() const;
    
    int get_SD_year() const { return SD_year; }
    int get_SD_month() const { return SD_month; }
    int get_SD_day() const { return SD_day; }
    int get_ED_year() const { return ED_year; }
    int get_ED_month() const { return ED_month; }
    int get_ED_day() const { return ED_day; }
    
    int get_ST_hour() const { return ST_hour; }
    int get_ST_minute() const { return ST_minute; }
    int get_ET_hour() const { return ET_hour; }
    int get_ET_minute() const { return ET_minute; }
    
private:
    std::string description;
    std::string SD, ED, ST, ET;
    int SD_year, SD_month, SD_day;
    int ED_year, ED_month, ED_day;
    int ST_hour, ST_minute;
    int ET_hour, ET_minute;
    bool time_given;
    long int total_start_mins, total_end_mins;
    int duration_mins;
};


#endif /* appointment_hpp */
