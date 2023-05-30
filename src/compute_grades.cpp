#include <iostream>
#include <fstream>
#include <iterator>
#include <numeric>
#include <cmath>
#include "compute_grades.hpp"
/*
void Student::validate() const;

void Student::compute_grade();

std::strong_ordering Student::operator<=>(const Student& other) const;*/
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
