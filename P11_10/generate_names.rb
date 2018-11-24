#!/usr/bin/env ruby
require 'Faker'

n = 200

filename = "/Users/christianmeyer/cpp/ch11/P11_10/names.txt"
File.open(filename, 'w') {|f|
    printline = ""
    Faker::Config.random.seed
    n.times do |name, salary|
        name = Faker::Name.name
        separate = "|";
        salary = (rand() * rand(500000)).round(2)
        endline = "\n";
        f.write(name, separate, salary, endline)
    end

}
