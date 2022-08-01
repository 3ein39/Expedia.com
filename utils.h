//
// Created by hussein on 8/1/22.
//

#ifndef EXPEDIA_COM_UTILS_H
#define EXPEDIA_COM_UTILS_H

// some utilities for the project
int ReadInt(int min, int max, bool cancel_choice_allowed = false) {
    if (!cancel_choice_allowed)
        cout << "\nEnter number in range " << min << " - " << max << ": ";
    else
        cout << "\nEnter -1 to cancel or number in range " << min << " - " << max << ": ";

    int val;
    cin >> val;

    if (cancel_choice_allowed && val == -1)
        return val;

    if (min <= val && val <= max)
        return val;

    cout << "ERROR: invalid number...Try again\n";
    return ReadInt(min, max);
}

int ShowReadMenu(const vector<string> &choices, string header = "Menu") {
    cout << "\n"<<header<<":\n";
    for (int ch = 0; ch < (int) choices.size(); ++ch) {
        cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
    }
    return ReadInt(1, choices.size());
}

// get current time and date
string GetCurrentTimeDate() {   // src: https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

#endif //EXPEDIA_COM_UTILS_H
