//
// Created by xcy on 2020/10/6.
//

#ifndef DAY10_FILEOPS_H
#define DAY10_FILEOPS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// 文集相关操作
namespace fileOps {
    int firstCharacterIndex(std::string& basicString, int start);

    std::string lowerS(const std::string &s);

    // 读取文件名称为filename中的内容，并将其中包含的词语放进word中
    bool readFile(const std::string &filename, std::vector<std::string> &word) {
        // 文件读取
        std::string line;
        std::string contents = "";
        std::ifstream file(filename);

        if (file.is_open()) {
            while (getline(file, line))
                contents += (line + "\n");
            file.close();
        } else {
            std::cout << "Can not open " << filename << "!!!" << std::endl;
            return false;
        }

        // 简单分词
        int start = firstCharacterIndex(contents, 0);
        for (int i = start + 1; i <= contents.length();) {
            if (i == contents.length() || !isalpha(contents[i])) {
                word.push_back(lowerS(contents.substr(start, i - start)));
                start = firstCharacterIndex(contents, i);
                i = start + 1;
            } else ++i;
        }
        return true;
    }

    // 将字符串中的所有字母转换成小写之后返回
    std::string lowerS(const std::string &s) {
        std::string ret = "";
        for (char i : s)
            ret += tolower(i);
        return ret;
    }

    int firstCharacterIndex(std::string &basicString, int start) {
        for (int i = start; i < basicString.length(); ++i)
            if (isalpha(basicString[i]))
                return i;
        return basicString.length();
    }
}

#endif //DAY10_FILEOPS_H
