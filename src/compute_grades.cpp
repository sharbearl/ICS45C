#include <stdexcept>
#include <iostream>
#include <fstream>
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
                    [](int score){return score < 0 || score > 0;}); 
                                  found != quiz.end())
        throw std::domain_error("Error: invalid percentage " +
                                std::to_string(*found));
    if(auto found = std::find_if(hw.begin(), hw.end(), [](int score)
                    {return score < 0 || score > 0;}); found != hw.end())
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

friend std::istream& Student::operator>>(std::istream& in, Student& s)
{
    std::string line;
    while(getline(in, line))
    {
        if(line == '\n')
            break;
        else if(line.starts_with("Name")
        {
            std::vector<std::string>::iterator start = line.begin() + 5;
            auto split = std::partition_point(start, line.end(), []
                         (std::string i) {return i == " ";});
            std::copy(start, split, first_name);
            std::copy(split, line.end(), last_name);
        }
        else if(line.starts_with("Quiz")
        {
            std::vector<int>::iterator start = line.begin() + 5;
            std::copy(start, line.end(), quiz);
        }
        else if(line.starts_with("Hw")
        {
            std::vector<int>::iterator start = line.begin() + 3;
            std::copy(start, line.end(), hw);
        }
        else if(line.starts_with("final")
        {
            final = std::stod(line.substr(6));
        }
}

friend std::ostream& Student::operator<<(std::ostream& out, const Student& s);

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
        quiz_avg = std::accumulate(quiz.begin(), quiz.end(), 0) /
                   quiz.size();
    }
}

void Student::compute_hw_avg()
{
    hw_avg = std::accumulate(hw.begin(), hw.end(), 0) / hw.size();
}

void Student::compute_course_score()
{
    course_score = std::round(((quiz_avg * .4) + (hw_avg * .3) + 
                              (final_score * .3)) * 100);
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
/*
void Gradebook::compute_grades();
void Gradebook::sort();
void Gradebook::validate() const;
*//*
friend std::istream& Gradebook::operator>>(std::istream& in, Gradebook& b)
{
    
}*/
//friend std::ostream& Gradebook::operator<<(std::ostream& out, const Gradebook& b);
