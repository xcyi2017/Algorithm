//
// Created by xcy on 2020/9/30.
//

#ifndef DAY4_STUDENT_H
#define DAY4_STUDENT_H

<<<<<<< HEAD
#include <iostream>
#include <string>

struct Student {
    std::string name;
    double score;

    bool operator<(const Student &otherStudent) const {
        return score < otherStudent.score;
    }

    friend std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << "Student:" << student.name << " " << student.score << std::endl;
        return os;
    }
};
=======
>>>>>>> a04c13b... day4练习--选择排序与归并排序
#endif //DAY4_STUDENT_H
