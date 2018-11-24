#include "appointment.hpp"

Appointment::Appointment(){
    time_given = false;
    
};
Appointment::Appointment(std::string desc, std::string startdate, std::string enddate, std::string starttime, std::string endtime){
    description = desc;
    SD = startdate;
    ED = enddate;
    interpret_date_start();
    interpret_date_end();
    ST = starttime;
    ET = endtime;
    if ((ST.length() > 0) && (ET.length() > 0)){
        time_given = true;
        interpret_time_start();
        interpret_time_end();
    } else {
        ST_hour = -1; ST_minute = -1;
        ET_hour = -1; ET_minute = -1;
        time_given = false;
    }
    set_start_mins_from_2000();
    set_end_mins_from_2000();
    set_appointment_duration();
}
void Appointment::set_start_mins_from_2000(){
    //std::cout << "IN #set_start_mins_from_2000" << std::endl;
    long int years = SD_year - 2000;
    //std::cout << "  years: " << years << std::endl;
    long int months = SD_month + (12*years);
    //std::cout << "  months: " << years << std::endl;
    long int days = SD_day + (365*months);
    //std::cout << "  days: " << days << std::endl;
    total_start_mins = (days * 24 * 60);
    if (time_given){
        long int mins = ST_minute + (60*ST_hour);
        //std::cout << "  mins: " << mins << std::endl;
        total_start_mins += mins;
    }
}
void Appointment::set_end_mins_from_2000(){
    if (time_given == false){
        total_end_mins = total_start_mins;
        return;
    }
    //std::cout << "IN #set_end_mins_from_2000" << std::endl;
    long int years = ED_year - 2000;
    //std::cout << "  years: " << years << std::endl;
    long int months = ED_month + (12*years);
    //std::cout << "  months: " << years << std::endl;
    long int days = ED_day + (365*months);
    //std::cout << "  days: " << days << std::endl;
    total_end_mins = (days * 24 * 60);
    if (time_given){
        long int mins = ET_minute + (60*ET_hour);
        //std::cout << "  mins: " << mins << std::endl;
        total_end_mins += mins;
        if (total_end_mins < total_start_mins){
            ED_day++;
            std::ostringstream oss;
            std::string insert_day;
            if (ED_day < 10){
                oss << '0';
                oss << ED_day;
                insert_day = oss.str();
            } else {
                oss << ED_day;
                insert_day = oss.str();
            }
            ED.replace(8, 2, insert_day);
            set_end_mins_from_2000();
        }
    }
    //std::cout << std::endl;
    if (time_given && total_end_mins < total_start_mins){
        ED_day += 1;
        set_end_mins_from_2000();
    }
}
void Appointment::set_appointment_duration(){
    if (time_given) duration_mins = total_end_mins - total_start_mins;
    else duration_mins = 0;
}

bool Appointment::operator==(const Appointment& a) const{
    if (this->get_start_mins_from_2000() == a.get_start_mins_from_2000()) return true;
    else return false;
}
bool Appointment::operator<(const Appointment& a) const{
    if (this->get_start_mins_from_2000() < a.get_start_mins_from_2000()) return true;
    else return false;
}

void Appointment::interpret_date_start(){
    if (SD.length() >= 10){
        std::string y = SD.substr(0, 4);
        SD_year = stoi(y);
        std::string m = SD.substr(6, 2);
        SD_month = stoi(m);
        std::string d = SD.substr(8, 2);
        SD_day = stoi(d);
    }
}
void Appointment::interpret_date_end(){
    if (ED.length() >= 10){
        std::string y = ED.substr(0, 4);
        ED_year = stoi(y);
        std::string m = ED.substr(6, 2);
        ED_month = stoi(m);
        std::string d = ED.substr(8, 2);
        ED_day = stoi(d);
    }
}
void Appointment::interpret_time_start(){
    if (ST.length() >= 5){
        std::string h = ST.substr(0, 2);
        ST_hour = stoi(h);
        std::string m = ST.substr(3, 2);
        ST_minute = stoi(m);
    }
}
void Appointment::interpret_time_end(){
    if (ET.length() >= 5){
        std::string h = ET.substr(0, 2);
        ET_hour = stoi(h);
        std::string m = ET.substr(3, 2);
        ET_minute = stoi(m);
    }
}
std::string Appointment::get_description() const{
    return description;
}
std::string Appointment::get_start_date() const{
    return SD;
}
std::string Appointment::get_end_date() const{
    return ED;
}
std::string Appointment::get_start_time() const{
    return ST;
}
std::string Appointment::get_end_time() const{
    return ET;
}
bool Appointment::get_time_given() const{
    return time_given;
}
long int Appointment::get_start_mins_from_2000() const{
    return total_start_mins;
}
long int Appointment::get_end_mins_from_2000() const{
    return total_end_mins;
}
int Appointment::get_appointment_duration() const{
    return duration_mins;
}

