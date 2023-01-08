#pragma once

#include <chrono>
#include <random>
#include <ctime>

const int screenWidth = 1400;
const int screenHeight = 900;

const int PeopleWidth = 50;
const int PeopleHeight = 70;

const int TrafficLightWidth = 72;
const int TrafficLightHeight = 72;

const int VehicleWidth = 113;
const int VehicleHeight = 70;

const int AnimalWidth = 48;
const int AnimalHeight = 48;

const int CoinWidth = 36;
const int CoinHeight = 36;

const int NumberOfLine = 9;
const int MaxCoinPerLine = 2;

const int LaneHeight = screenHeight / NumberOfLine; // 1 map = 9 lanes
const int LaneWidth = screenWidth;

const int NumberOfCharacter = 3;
const int NumberOfTrafficLight = 3;
const int NumberOfVehicle = 3;
const int NumberOfAnimal = 4;
const int NumberOfItems = 3;

const float BaseSpeed = 100.0f;
const float AnimalAnimationSpeed = 1.25f;
