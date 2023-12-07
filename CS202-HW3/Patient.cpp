/*
* Author : Deniz Polat
* ID: 22103590 
* Section : 1 
* Homework : 3 
* Description : The implementation file of Patient class
*/
#include "Patient.hpp"

Patient::Patient() = default;

Patient::Patient(int id, int priority, int arrival_time, int service_time) : id_(id), priority_(priority), arrivalTime_(arrival_time), serviceTime_(service_time)
{}

bool Patient::operator<(const Patient& other) const {
    if (priority_ != other.priority_) {
    return priority_ < other.priority_;
        
    }
    return arrivalTime_ > other.arrivalTime_;
}

int Patient::getId() const
{
    return id_;
}

int Patient::getPriority()
{
    return priority_;
}

int Patient::getArrivalTime() const
{
    return arrivalTime_;
}

void Patient::setTimeOfExamination(int time)
{
    examinationTime = time;
}

int Patient::getServiceTime()
{
    return serviceTime_;
}

int Patient::getWaitingTime()
{
    return waitingTime_;
}

void Patient::setWaitingTime(int wTime)
{
    waitingTime_ = wTime;
}

int Patient::getTotalPriorityValue()
{
    return (priority_ * 1000) - arrivalTime_;
}