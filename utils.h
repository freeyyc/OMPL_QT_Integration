#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

QStringList convert_vector_to_qstringlist(const std::vector<std::string> & vec){
    QStringList list;
    for(const auto & str:vec){
        list << str.c_str();
    }
    return list;
}

#endif // UTILS_H
