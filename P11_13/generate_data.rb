#!/usr/bin/env ruby

require 'Faker'

n = 200

filename = "/Users/christianmeyer/cpp/ch11/P11_13/data.txt"
name_width = 20
salary_width = 10
#line length = 20 + 10 + 2 (+2 for pipe and newline chars)
File.open(filename, 'w') {|f|
    printline = ""
    Faker::Config.random.seed
    n.times do |name, salary|
        name = Faker::Name.name.ljust(name_width)
        separate = "|";
        salary = (rand() * rand(500000)).round(2).to_s.ljust(salary_width)
        endline = "\n";
        if (name.size <= name_width && salary.size <= salary_width && !name.include?(". ") && !name.include?("?iss :"))
            f.write(name, separate, salary, endline)
        end
    end

}
