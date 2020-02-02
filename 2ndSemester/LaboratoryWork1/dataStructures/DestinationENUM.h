#pragma once

#include "vector"

enum Destination {
    INTERNATIONAL,
    FAST,
    SIMPLE,
    NEARCITY
};

const vector<string> DestinationMap = {"INTERNATIONAL", "FAST", "SIMPLE", "NEARCITY"};
const vector<Destination> DestinationList = {INTERNATIONAL, FAST, SIMPLE, NEARCITY};
