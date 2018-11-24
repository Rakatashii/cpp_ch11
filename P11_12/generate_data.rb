#!/usr/bin/env ruby
require 'Faker'
require 'as-duration'

n = 500

def is_numeric?(obj)
   obj.to_s.match(/\A[+-]?\d+?(\.\d+)?\Z/) == nil ? false : true
end

filename = "/Users/christianmeyer/cpp/ch11/P11_12/data.txt"
File.open(filename, 'w') { |f|
    Faker::Config.random.seed
    printline = ""
    sep = "|";
    endl = "\n";
    n.times do |name, salary|
        #name = Faker::Name.name
        #printline += name + "|"
        description = Faker::MichaelScott.quote
        printline += description + "|"

        hours = 1 + rand(6);
        datetime_start = Faker::Time.forward(1000, :all)
        datetime_end = datetime_start + (60*60*hours)

        date_start = datetime_start.to_s[0, 10]
        date_end = datetime_end.to_s[0, 10]

        if (!is_numeric?(date_start[6])) then
            date_start.insert(5, "0")
        end
        if (!is_numeric?(date_start[9])) then
            date_start.insert(8, "0")
        end
        if (!is_numeric?(date_end[6])) then
            date_end.insert(5, "0")
        end
        if (!is_numeric?(date_end[9])) then
            date_end.insert(8, "0")
        end

        printline += date_start + "|" + date_end
        decider = rand();
        if (decider >= 0.4) then
            time_start = datetime_start.to_s[12, 4]
            time_end = datetime_end.to_s[12, 4]

            if (!is_numeric?(time_start[1])) then
                time_start.insert(0, "0")
                if (time_start[1] == "0") then
                    time_start[0] = "1"
                    time_start[1] = "2"
                end
            end
            if (!is_numeric?(time_start[4])) then
                time_start.insert(3, "0")
            end
            if (!is_numeric?(time_end[1])) then
                time_end.insert(0, "0")
                if (time_end[1] == "0") then
                    time_end[0] = "1"
                    time_end[1] = "2"
                end
            end
            if (!is_numeric?(time_end[4])) then
                time_end.insert(3, "0")
            end

            printline += "|" + time_start + "|" + time_end + "\n"
        else
            printline += "\n"
        end
        f.write(printline)
    end
}
