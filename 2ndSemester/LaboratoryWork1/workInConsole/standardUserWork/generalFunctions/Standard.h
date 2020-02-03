#pragma once

void saveTo__(void saveTrainIn__(Train), Train train) {
    saveTrainIn__(train);
}

void print__(string getTrainsFrom__()) {
    cout << getTrainsFrom__();
}

void clear__(void clearTrainsIn__()) {
    clearTrainsIn__();
}

void changeIn__(string getTrainsWithIDFrom__(), void changeIn__(int, Train), Train train) {
    int id = 0;
    cout << getTrainsWithIDFrom__();
    cout << "Witch id change?" << endl << "id = ";
    cin >> id;
    changeIn__(id, train);
}

void deleteIn__(string getTrainsWithIDFrom__(), void deleteIn__(int)) {
    int id = 0;
    cout << getTrainsWithIDFrom__();
    cout << "Witch id delete?" << endl << "id = ";
    cin >> id;
    deleteIn__(id);
}
