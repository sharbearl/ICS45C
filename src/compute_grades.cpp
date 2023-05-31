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
    return last_name - other.last_name;
}

bool Student::operator==(const Student& other) const
{
    return (first_name == other.first_name) && 
           (last_name == other.last_name);
}
/*
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
friend std::ostream& Student::operator<<(std::ostream& out, const Student& s);*/

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
void Student::fill(std::string first, std::string last, 
                   std::vector<int> quizzes, std::vector<int> hws, 
                   double fin)
{
    first_name = first;
    last_name = last;
    quiz = quizzes;
    hw = hws;
    final_score = fin;

    compute_quiz_avg();
    compute_hw_avg();
    compute_course_score();
}*/
/*
void Gradebook::compute_grades();
void Gradebook::sort();
void Gradebook::validate() const;

friend std::istream& Gradebook::operator>>(std::istream& in, Gradebook& b);
friend std::ostream& Gradebook::operator<<(std::ostream& out, const Gradebook& b);*/
