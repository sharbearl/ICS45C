#include <iostream>
#include <fstream>
#include <iterator>
#include "compute_grades.hpp"

void Student::validate() const;

void Student::compute_grade();

std::strong_ordering Student::operator<=>(const Student& other) const;
bool Student::operator==(const Student& other) const;

friend std::istream& Student::operator>>(std::istream& in, Student& s)
{
    std::string word;
    while(word << in)
    {
        if(line = '\n')
            break;
        else if(line.starts_with("Name")
        {
            word << in;
            s.first_name = word;
            word << in;
            s.last_name = word;
        }
        else if(line.starts_with("Quiz")
        {
            
}
friend std::ostream& Student::operator<<(std::ostream& out, const Student& s);
