/*
* Author : Deniz Polat
* ID: 22103590 
* Section : 1 
* Homework : 3 
* Description : The header file of Patient class
*/

#ifndef PATIENT_HPP
#define PATIENT_HPP

class Patient {
private:
    int id_;
    int priority_;
    int arrivalTime_;
    int serviceTime_;
    int waitingTime_;
    int examinationTime;

public:
    Patient();
    Patient(const int id, int priority, int arrival_time, int service_time);
    bool operator<(const Patient& other) const;
    void setTimeOfExamination(int time);
    int getId() const;
    int getPriority();
    int getArrivalTime() const;
    int getServiceTime();
    int getWaitingTime();
    int getTotalPriorityValue();
    void setWaitingTime(int wTime);

};

#endif
