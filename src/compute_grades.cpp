#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <cmath>
#include "compute_grades.hpp"

void Student::validate() const
{
    if(final_score < 0 || final_score > 100)
        throw std::domain_error("Error: invalid percentage " + 
                                std::to_string(final_score));
    if(auto found = std::find_if(quiz.begin(), quiz.end(), 
                    [](int score){return score < 0 || score > 100;}); 
                                  found != quiz.end())
        throw std::domain_error("Error: invalid percentage " +
                                std::to_string(*found));
    if(auto found = std::find_if(hw.begin(), hw.end(), [](int score)
                    {return score < 0 || score > 100;}); found != hw.end())
        throw std::domain_error("Error: invalid percentage " +
                                std::to_string(*found));
}

void Student::compute_grade()
{
    compute_quiz_avg();
    compute_hw_avg();
    compute_course_score();
}

std::strong_ordering Student::operator<=>(const Student& other) const
{
    if(last_name != other.last_name)
        return last_name <=> other.last_name;
    return first_name <=> other.first_name;
}

bool Student::operator==(const Student& other) const
{
    return (first_name == other.first_name) && 
           (last_name == other.last_name);
}

std::istream& operator>>(std::istream& in, Student& s)
{
    std::string line;
    while(getline(in, line))
    {
        std::stringstream stream(line);
        std::string word;
        stream >> word;
        if(line.empty())
            break;
        else if(word == "Name")
        {
            stream >> word;
            s.first_name = word;
            s.last_name = line.substr(s.first_name.size() + 5);
        }
        else if(word == "Quiz")
        {
            std::istream_iterator<int> start(stream);
            std::copy(start, std::istream_iterator<int>(), 
                      std::back_inserter(s.quiz));
        }
        else if(word == "HW")
        {
            std::istream_iterator<int> start(stream);
            std::copy(start, std::istream_iterator<int>(), 
                      std::back_inserter(s.hw));
        }
        else if(word == "Final")
        {
            stream >> word;
            s.final_score = std::stod(word);
        }
    }

    if(s.quiz.size() == 0)
        s.quiz.push_back(0);
    if(s.hw.size() == 0)
        s.hw.push_back(0);

    return in;
}

std::ostream& operator<<(std::ostream& out, const Student& s)
{
    std::stringstream temp;
    temp << std::left;
    
    std::for_each(s.hw.begin(), s.hw.end(), [&temp](auto v){temp << v;});
    std::string name = s.first_name + s.last_name;
    temp << std::setw(8) << "Name: " << name << std::endl;
    temp << std::setw(8) << "HW Ave: " << s.hw_avg << std::endl;
    temp << std::setw(8) << "QZ Ave: " << s.quiz_avg << std::endl;
    temp << std::setw(8) << "Final: " << s.final_score << std::endl;
    temp << std::setw(8) << "Total: " << s.course_score << std::endl;
    temp << std::setw(8) << "Grade: " << s.course_grade << std::endl;

    out << temp.str();

    return out;
}

void Student::compute_quiz_avg()
{
    if(quiz.size() == 0)
        quiz_avg = 0;
    else if(quiz.size() == 1)
        quiz_avg = quiz[0];
    else
    {
        std::sort(quiz.begin(), quiz.end());
        quiz.erase(quiz.begin());
        double avg = quiz.size();
        quiz_avg = std::accumulate(quiz.begin(), quiz.end(), 0) / avg;
    }
}

void Student::compute_hw_avg()
{
    double avg = hw.size();
    hw_avg = std::accumulate(hw.begin(), hw.end(), 0) / avg;
}

void Student::compute_course_score()
{
    course_score = std::round(((quiz_avg * .4) + (hw_avg * .3) + 
                              (final_score * .3)));
    if(course_score <= 59)
        course_grade = "F";
    else if(course_score <= 62)
        course_grade = "D-";
    else if(course_score <= 66)
        course_grade = "D";
    else if(course_score <= 69)
        course_grade = "D+";
    else if(course_score <= 72)
        course_grade = "C-";
    else if(course_score <= 76)
        course_grade = "C";
    else if(course_score <= 79)
        course_grade = "C+";
    else if(course_score <= 82)
        course_grade = "B-";
    else if(course_score <= 86)
        course_grade = "B";
    else if(course_score <= 89)
        course_grade = "B+";
    else if(course_score <= 92)
        course_grade = "A-";
    else if(course_score <= 96)
        course_grade = "A";
    else if(course_score <= 100)
        course_grade = "A+";
}

void Gradebook::compute_grades()
{
    std::transform(students.begin(), students.end(), students.begin(), []
                   (Student s) {s.compute_grade(); return s;});
}

void Gradebook::sort()
{
    std::sort(students.begin(), students.end());
}

void Gradebook::validate() const
{
    std::for_each(students.begin(), students.end(), 
                  [](Student s){s.validate();});
}

std::istream& operator>>(std::istream& in, Gradebook& b)
{
    std::istream_iterator<Student> stream (in);
    std::copy(stream, std::istream_iterator<Student>(), 
              std::back_inserter(b.students));
    return in;
}
std::ostream& operator<<(std::ostream& out, const Gradebook& b)
{
    std::copy(b.students.begin(), b.students.end(), 
              std::ostream_iterator<Student>(out, "\n"));
    return out;
}
