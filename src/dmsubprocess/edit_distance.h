
#ifndef _EDIT_DISTANCE_H_
#define _EDIT_DISTANCE_H_

#include <string>

int EditDistance(const std::string& s1,
    const std::string& s2,
    bool allow_replacements = true,
    int max_edit_distance = 0);

#endif  // _EDIT_DISTANCE_H_
