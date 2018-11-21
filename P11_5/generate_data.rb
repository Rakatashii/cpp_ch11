#!/usr/bin/env ruby
require 'Faker'

args = ARGV
valid_inputs = %w{name telephone}

def is_numeric?(obj)
  obj.to_s.match(/\A[+-]?\d+?(\.\d+)?\Z/) == nil ? false : true
end
def is_file_name?(obj)
  obj.to_s.match(/\w+(\.\w+)\Z/) == nil ? false : true
end

#call this:
#ruby #{this_file_name} -n=number_of_records args={name, telephone, social, salary}

filename = "/Users/christianmeyer/cpp/ch11/P11_5/data"
n = 1000
number_given = 0
file_given = 0
if is_file_name?(ARGV[ARGV.size-1].to_s)
   filename = ARGV[ARGV.size-1].to_s
   file_given = 1
end
File.open(filename, 'w') { |f|
   if (ARGV.size > 2)
       puts "generating data..."
   end
   if is_numeric?(args[0])
       n = args[0].to_i
       number_given = 1
   end

   n.times do
       num_args = ARGV.size - number_given - file_given
       print_line = "";
       args.any? {|arg|
           if arg == "name"
               name = Faker::Name.name;
               print_line += name
               num_args -= 1
               if num_args > 0
                   print_line += "|"
               end
           end
           if arg == "telephone"
               t1 = ('%3.3s' % rand(000..999).to_s).gsub(' ', '0');
               t2 = ('%3.3s' % rand(000..999).to_s).gsub(' ', '0');
               t3 = ('%4.4s' % rand(0000..9999).to_s).gsub(' ', '0');
               tele = t1+"-"+t2+"-"+t3
               print_line += tele
               num_args -= 1
               if num_args > 0
                   print_line += "|"
               end
           end
       }
       print_line += "\n"
       if print_line.length > 1
           f.write(print_line)
       end
   end
}
