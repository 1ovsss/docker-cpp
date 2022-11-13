#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <iostream>

#define table_len 129
#define column_len 25

namespace nice {
std::string print_column(std::size_t column_length, const std::string& content) {
        std::size_t LeftSide_spaces = (column_length - content.length()) / 2;
        std::size_t RightSide_spaces = column_length - content.length() - LeftSide_spaces;
        return std::string(LeftSide_spaces, ' ') + content +
               std::string(RightSide_spaces, ' ');
}

void print_divider() {
        std::string divider = '|' + std::string(table_len, '-') + '|';
        std::cout << divider << '\n';
}

void print_endls() {
        for (std::size_t i = 0; i < 3; i++) {
                std::cout << '\n';
        }
}

void print_header(const std::string& type) {
        print_divider();
        std::cout << '|' << print_column(table_len, type) << '|' << std::endl;
        print_divider();
        std::cout << '|' << print_column(column_len, "operations") << '|'
                  << print_column(column_len, "sec") << '|'
                  << print_column(column_len, "operations / sec") << '|'
                  << print_column(column_len, "processor clocks") << '|'
                  << print_column(column_len, "processor clocks / sec") << '|' << '\n';
        print_divider();
}

void print_line(std::size_t operations, double seconds, double operations_per_second,
                uint64_t processor_clocks, double processor_clocks_per_second) {
        std::cout << "|" << print_column(column_len, std::to_string(operations)) << '|'
                  << print_column(column_len, std::to_string(seconds)) << '|'
                  << print_column(column_len, std::to_string(operations_per_second))
                  << '|' << print_column(column_len, std::to_string(processor_clocks))
                  << '|'
                  << print_column(column_len, std::to_string(processor_clocks_per_second))
                  << '|' << '\n';
}
}  // namespace nice

#endif
