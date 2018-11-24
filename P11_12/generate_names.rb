#!/usr/bin/env ruby
require 'Faker'
require 'as-duration'

n = 200

filename = "/Users/christianmeyer/cpp/ch11/P11_10/data.txt"
File.open(filename, 'w') {|f|
    Faker::Config.random.seed
    printline = ""
    sep = "|";
    endl = "\n";
    n.times do |name, salary|
        name = Faker::Name.name
        printline += name + "|"
        description = Faker::MichaelScott.quote
        printline += description + "|"

        hours = rand(12);
        datetime_start = Faker::Time.forward(1000, :all)
        datetime_end = time_start + (60*60*hours)
        date_start = datetime_start.to_s[0, 10]
        date_end = datetime_end.to_s[0, 10]

        printline += date_start + "|" + date_end
        decider = rand();
        if (decider >= 0.4) {
            time_start = datetime_start.to_s[12, 16]
            time_end = datetime_end.to_s[12, 16]
            printline += "|" + time_start + "|" + time_end + "\n"
        } else {
            printline += "\n"
        }
        f.write(printline)
    end
}
