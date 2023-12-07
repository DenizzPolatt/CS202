/*
* Author : Deniz Polat
* ID: 22103590 
* Section : 1 
* Homework : 3 
* Description : The header file of Doctor class
*/
#ifndef DOCTOR_HPP
#define DOCTOR_HPP
#include <iostream>
#include "Patient.hpp"

class Doctor
{
    int id_{};
    int availableTime_{};
public:
    Doctor();
    int getId();
    void setId(int id);
    int getNextAvailableTime();
    void addPatient(Patient &patient, int currentTime);
};
#endif