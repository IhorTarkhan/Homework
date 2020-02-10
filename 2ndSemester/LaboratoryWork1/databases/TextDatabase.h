#pragma once

#include <iostream>
#include <fstream>
#include "taskConditions.h"
#include "MemoryDatabase.h"

using namespace std;

class TextDatabase {
private:
    constexpr static const char *PATH = "../2ndSemester/LaboratoryWork1/DataBase_txt.txt";
    constexpr static const char *newPATH = "../2ndSemester/LaboratoryWork1/DataBase_txt.txt.new.txt";

public:
    static void saveMemoryToIt() {
        clearTrains();
        for (int i = 0; i < trainsInMemory.size(); i++) {
            saveTrain(trainsInMemory[i]);
        }
    }

    static void saveItToMemory() {
        MemoryDatabase::clearTrains();
        string number;
        string optionalName;
        Destination destination;
        string arriveHourString;
        string arriveMinuteString;
        string arriveDayString;
        string arriveMonthString;
        string arriveYearString;
        string departureHourString;
        string departureMinuteString;
        string departureDayString;
        string departureMonthString;
        string departureYearString;
        string rateString;
        Date arrive;
        Date departure;

        ifstream file(TextDatabase::PATH);
        string line;
        while (getline(file, line)) {
            if (line.substr(0, NUMBER.length()) == NUMBER) {
                line = line.substr(NUMBER.length());
                number = line;
                continue;
            }
            if (line.substr(0, OPTIONAL_NAME.length()) == OPTIONAL_NAME) {
                line = line.substr(OPTIONAL_NAME.length());
                optionalName = line;
                continue;
            }
            if (line.substr(0, DESTINATION.length()) == DESTINATION) {
                line = line.substr(DESTINATION.length());
                for (int i = 0; i < DestinationMap.size(); ++i) {
                    if (line == DestinationMap[i]) {
                        destination = DestinationList[i];
                        break;
                    }
                }
                continue;
            }
            if (line.substr(0, ARRIVE.length()) == ARRIVE) {
                line = line.substr(ARRIVE.length());
                arriveHourString = line.substr(0, line.find_first_of(":"));
                line = line.substr(line.find_first_of(":") + 1);

                arriveMinuteString = line.substr(0, line.find_first_of(" "));
                line = line.substr(line.find_first_of(" ") + 1);

                arriveDayString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                arriveMonthString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                arriveYearString = line;

                arrive = Date(stoi(arriveHourString), stoi(arriveMinuteString),
                              stoi(arriveDayString), stoi(arriveMonthString), stoi(arriveYearString));
                continue;
            }
            if (line.substr(0, DEPARTURE.length()) == DEPARTURE) {
                line = line.substr(DEPARTURE.length());
                departureHourString = line.substr(0, line.find_first_of(":"));
                line = line.substr(line.find_first_of(":") + 1);

                departureMinuteString = line.substr(0, line.find_first_of(" "));
                line = line.substr(line.find_first_of(" ") + 1);

                departureDayString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                departureMonthString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                departureYearString = line;

                departure = Date(stoi(departureHourString), stoi(departureMinuteString),
                                 stoi(departureDayString), stoi(departureMonthString), stoi(departureYearString));
                continue;
            }
            if (line.substr(0, RATE.length()) == RATE) {
                line = line.substr(RATE.length());
                rateString = line;
                Train train = Train(number, optionalName, destination, arrive, departure, stod(rateString));
                trainsInMemory.push_back(train);
                continue;
            }
        }
        file.close();
    }

    static int getMaxID() {
        int maxID = 0;
        string line;
        ifstream file(TextDatabase::PATH);
        while (getline(file, line)) {
            if (line.substr(0, ID.length()) == ID) {
                if (stoi(line.substr(ID.length())) > maxID)
                    maxID = stoi(line.substr(ID.length()));
            }
        }
        return maxID;
    }

    static void saveTrain(Train train) {
        int maxID = getMaxID();
        ofstream file(TextDatabase::PATH, ios_base::app);
        string textToSave = "";
        textToSave += ID + to_string(++maxID) + "\n" + train.getInText() + "\n";
        file << textToSave;
        file.close();
    }

    static string getTrains() {
        string trainsInString = "";
        ifstream file(TextDatabase::PATH);
        string line;
        while (getline(file, line)) {
            if (line.substr(0, ID.length()) != ID) {
                trainsInString += line + "\n";
            }
        }
        file.close();
        return trainsInString;
    }

    static void clearTrains() {
        ofstream file(TextDatabase::PATH);
        file << "";
        file.close();
    }

    static string getTrainsWithID() {
        string trainsInString = "";
        ifstream file(TextDatabase::PATH);
        string line;
        while (getline(file, line)) {
            trainsInString += line + "\n";
        }
        file.close();
        return trainsInString;
    }

    static void changeTrain(int id, Train train) {
        if (id <= 0 || id > getMaxID()) {
            throw invalid_argument("incorrect id");
        }
        ifstream file(TextDatabase::PATH);
        ofstream newFile(TextDatabase::newPATH);
        string line;
        bool ignore_lines = false;
        while (getline(file, line)) {
            if (line.substr(0, ID.length()) == ID) {
                newFile << line << endl;
                if (stoi(line.substr(ID.length())) == id) {
                    ignore_lines = true;
                    newFile << train.getInText() << endl;
                } else {
                    ignore_lines = false;
                }
            } else if (!ignore_lines) {
                newFile << line << endl;
            }
        }
        file.close();
        newFile.close();
        remove(TextDatabase::PATH);
        rename(TextDatabase::newPATH, TextDatabase::PATH);
    }

    static void deleteTrain(int id) {
        if (id <= 0 || id > getMaxID()) {
            throw invalid_argument("incorrect id");
        }
        ifstream file(TextDatabase::PATH);
        ofstream newFile(TextDatabase::newPATH);
        string line;
        bool ignore_lines = false;
        while (getline(file, line)) {
            if (line.substr(0, ID.length()) == ID) {
                if (stoi(line.substr(ID.length())) == id) {
                    ignore_lines = true;
                } else {
                    newFile << line << endl;
                    ignore_lines = false;
                }
            } else if (!ignore_lines) {
                newFile << line << endl;
            }
        }
        file.close();
        newFile.close();
        remove(TextDatabase::PATH);
        rename(TextDatabase::newPATH, TextDatabase::PATH);
    }

    static vector<Train> task1(string lastFragmentOfName) {
        vector<Train> res;

        string number;
        string optionalName;
        Destination destination;
        string arriveHourString;
        string arriveMinuteString;
        string arriveDayString;
        string arriveMonthString;
        string arriveYearString;
        string departureHourString;
        string departureMinuteString;
        string departureDayString;
        string departureMonthString;
        string departureYearString;
        string rateString;
        Date arrive;
        Date departure;

        ifstream file(TextDatabase::PATH);
        string line;
        while (getline(file, line)) {
            if (line.substr(0, NUMBER.length()) == NUMBER) {
                line = line.substr(NUMBER.length());
                number = line;
                continue;
            }
            if (line.substr(0, OPTIONAL_NAME.length()) == OPTIONAL_NAME) {
                line = line.substr(OPTIONAL_NAME.length());
                optionalName = line;
                continue;
            }
            if (line.substr(0, DESTINATION.length()) == DESTINATION) {
                line = line.substr(DESTINATION.length());
                for (int i = 0; i < DestinationMap.size(); ++i) {
                    if (line == DestinationMap[i]) {
                        destination = DestinationList[i];
                        break;
                    }
                }
                continue;
            }
            if (line.substr(0, ARRIVE.length()) == ARRIVE) {
                line = line.substr(ARRIVE.length());
                arriveHourString = line.substr(0, line.find_first_of(":"));
                line = line.substr(line.find_first_of(":") + 1);

                arriveMinuteString = line.substr(0, line.find_first_of(" "));
                line = line.substr(line.find_first_of(" ") + 1);

                arriveDayString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                arriveMonthString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                arriveYearString = line;

                arrive = Date(stoi(arriveHourString), stoi(arriveMinuteString),
                              stoi(arriveDayString), stoi(arriveMonthString), stoi(arriveYearString));
                continue;
            }
            if (line.substr(0, DEPARTURE.length()) == DEPARTURE) {
                line = line.substr(DEPARTURE.length());
                departureHourString = line.substr(0, line.find_first_of(":"));
                line = line.substr(line.find_first_of(":") + 1);

                departureMinuteString = line.substr(0, line.find_first_of(" "));
                line = line.substr(line.find_first_of(" ") + 1);

                departureDayString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                departureMonthString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                departureYearString = line;

                departure = Date(stoi(departureHourString), stoi(departureMinuteString),
                                 stoi(departureDayString), stoi(departureMonthString), stoi(departureYearString));
                continue;
            }
            if (line.substr(0, RATE.length()) == RATE) {
                line = line.substr(RATE.length());
                rateString = line;
                Train train = Train(number, optionalName, destination, arrive, departure, stod(rateString));
                if (task1Boolean(train, lastFragmentOfName)) {
                    res.push_back(train);
                }
                continue;
            }
        }
        file.close();
        return res;
    }

    static vector<Train> task2(Destination destinationRequested, string numberMIN, string numberMAX) {
        vector<Train> res;

        string number;
        string optionalName;
        Destination destination;
        string arriveHourString;
        string arriveMinuteString;
        string arriveDayString;
        string arriveMonthString;
        string arriveYearString;
        string departureHourString;
        string departureMinuteString;
        string departureDayString;
        string departureMonthString;
        string departureYearString;
        string rateString;
        Date arrive;
        Date departure;

        ifstream file(TextDatabase::PATH);
        string line;
        while (getline(file, line)) {
            if (line.substr(0, NUMBER.length()) == NUMBER) {
                line = line.substr(NUMBER.length());
                number = line;
                continue;
            }
            if (line.substr(0, OPTIONAL_NAME.length()) == OPTIONAL_NAME) {
                line = line.substr(OPTIONAL_NAME.length());
                optionalName = line;
                continue;
            }
            if (line.substr(0, DESTINATION.length()) == DESTINATION) {
                line = line.substr(DESTINATION.length());
                for (int i = 0; i < DestinationMap.size(); ++i) {
                    if (line == DestinationMap[i]) {
                        destination = DestinationList[i];
                        break;
                    }
                }
                continue;
            }
            if (line.substr(0, ARRIVE.length()) == ARRIVE) {
                line = line.substr(ARRIVE.length());
                arriveHourString = line.substr(0, line.find_first_of(":"));
                line = line.substr(line.find_first_of(":") + 1);

                arriveMinuteString = line.substr(0, line.find_first_of(" "));
                line = line.substr(line.find_first_of(" ") + 1);

                arriveDayString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                arriveMonthString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                arriveYearString = line;

                arrive = Date(stoi(arriveHourString), stoi(arriveMinuteString),
                              stoi(arriveDayString), stoi(arriveMonthString), stoi(arriveYearString));
                continue;
            }
            if (line.substr(0, DEPARTURE.length()) == DEPARTURE) {
                line = line.substr(DEPARTURE.length());
                departureHourString = line.substr(0, line.find_first_of(":"));
                line = line.substr(line.find_first_of(":") + 1);

                departureMinuteString = line.substr(0, line.find_first_of(" "));
                line = line.substr(line.find_first_of(" ") + 1);

                departureDayString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                departureMonthString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                departureYearString = line;

                departure = Date(stoi(departureHourString), stoi(departureMinuteString),
                                 stoi(departureDayString), stoi(departureMonthString), stoi(departureYearString));
                continue;
            }
            if (line.substr(0, RATE.length()) == RATE) {
                line = line.substr(RATE.length());
                rateString = line;
                Train train = Train(number, optionalName, destination, arrive, departure, stod(rateString));
                if (task2Boolean(train, destinationRequested, numberMIN, numberMAX)) {
                    res.push_back(train);
                }
                continue;
            }
        }
        file.close();
        return res;
    }

    static vector<Train> task3(Date departureGet) {
        vector<Train> res;

        string number;
        string optionalName;
        Destination destination;
        string arriveHourString;
        string arriveMinuteString;
        string arriveDayString;
        string arriveMonthString;
        string arriveYearString;
        string departureHourString;
        string departureMinuteString;
        string departureDayString;
        string departureMonthString;
        string departureYearString;
        string rateString;
        Date arrive;
        Date departure;

        ifstream file(TextDatabase::PATH);
        string line;
        while (getline(file, line)) {
            if (line.substr(0, NUMBER.length()) == NUMBER) {
                line = line.substr(NUMBER.length());
                number = line;
                continue;
            }
            if (line.substr(0, OPTIONAL_NAME.length()) == OPTIONAL_NAME) {
                line = line.substr(OPTIONAL_NAME.length());
                optionalName = line;
                continue;
            }
            if (line.substr(0, DESTINATION.length()) == DESTINATION) {
                line = line.substr(DESTINATION.length());
                for (int i = 0; i < DestinationMap.size(); ++i) {
                    if (line == DestinationMap[i]) {
                        destination = DestinationList[i];
                        break;
                    }
                }
                continue;
            }
            if (line.substr(0, ARRIVE.length()) == ARRIVE) {
                line = line.substr(ARRIVE.length());
                arriveHourString = line.substr(0, line.find_first_of(":"));
                line = line.substr(line.find_first_of(":") + 1);

                arriveMinuteString = line.substr(0, line.find_first_of(" "));
                line = line.substr(line.find_first_of(" ") + 1);

                arriveDayString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                arriveMonthString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                arriveYearString = line;

                arrive = Date(stoi(arriveHourString), stoi(arriveMinuteString),
                              stoi(arriveDayString), stoi(arriveMonthString), stoi(arriveYearString));
                continue;
            }
            if (line.substr(0, DEPARTURE.length()) == DEPARTURE) {
                line = line.substr(DEPARTURE.length());
                departureHourString = line.substr(0, line.find_first_of(":"));
                line = line.substr(line.find_first_of(":") + 1);

                departureMinuteString = line.substr(0, line.find_first_of(" "));
                line = line.substr(line.find_first_of(" ") + 1);

                departureDayString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                departureMonthString = line.substr(0, line.find_first_of("/"));
                line = line.substr(line.find_first_of("/") + 1);

                departureYearString = line;

                departure = Date(stoi(departureHourString), stoi(departureMinuteString),
                                 stoi(departureDayString), stoi(departureMonthString), stoi(departureYearString));
                continue;
            }
            if (line.substr(0, RATE.length()) == RATE) {
                line = line.substr(RATE.length());
                rateString = line;
                Train train = Train(number, optionalName, destination, arrive, departure, stod(rateString));
                if (task3Boolean(train, departureGet)) {
                    res.push_back(train);
                }
                continue;
            }
        }
        file.close();
        return res;
    }
};
