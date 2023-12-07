/*
* Author : Deniz Polat
* ID: 22103590 
* Section : 1 
* Homework : 3 
* Description : The implementation file of Doctor class
*/
#include "Doctor.hpp"

Doctor::Doctor(){};

int Doctor::getId()
{
    return id_;
}

void Doctor::setId(int id)
{
    id_ = id;
}

int Doctor::getNextAvailableTime()
{
    return availableTime_;
}

void Doctor::addPatient(Patient &patient, int currentTIme)
{
    if(currentTIme < patient.getArrivalTime() || availableTime_ == 0)
    {
        patient.setWaitingTime(0);
    }
    else {
        patient.setWaitingTime(currentTIme - patient.getArrivalTime());
    }

    availableTime_ = (currentTIme + patient.getServiceTime());
}