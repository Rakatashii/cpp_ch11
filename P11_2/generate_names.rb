#!/usr/bin/env ruby
require 'Faker'

n = 50

filename = "/Users/christianmeyer/cpp/ch11/P11_2/names.txt"
File.open(filename, 'w') {|f|
    n.times do |name|
        name = Faker::Name.name
        name += "\n"
        f.write(name)
    end
}
