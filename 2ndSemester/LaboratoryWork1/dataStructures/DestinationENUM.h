#pragma once

#include "vector"

enum Destination {
    FAST,
    INTERNATIONAL,
    NEARCITY,
    SIMPLE
};

const vector<string> DestinationMap = {"FAST", "INTERNATIONAL", "NEARCITY", "SIMPLE"};
const vector<Destination> DestinationList = {FAST, INTERNATIONAL, NEARCITY, SIMPLE};
