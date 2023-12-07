/*
* Author : Deniz Polat
* ID: 22103590 
* Section : 1 
* Homework : 3 
* Description : The main Hospital Simulator program that parses the input file and takes patients for
* examination in order from the priority queue.
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <typeinfo>
#include "PriorityQueue.hpp"
#include "Doctor.hpp"

/**
 * Method to parse the input file to creat new Patients with the given information about their
 * ids, priorities, arrival and examination durations.  
*/
Patient* getPatientsFromFile(std::string fileName, int& noOfPatients) {
    std::ifstream file(fileName);
    
    file >> noOfPatients;
    Patient* patients = new Patient[noOfPatients];
    int currentPatient = 0;
    for (int i = 0; i < noOfPatients;  ++i)
    {
        int patientId;
        int patientPriority;
        int patientArTime;
        int patientExTime;
        file >> patientId;
        file >> patientPriority; 
        file >> patientArTime; 
        file >> patientExTime;
        Patient aPatient(patientId, patientPriority, patientArTime, patientExTime);
        patients[currentPatient] = aPatient;
        currentPatient++;
    }

    return patients;
}

/*
    Method to set the id's of doctors in order.
*/
void setDoctorIds(Doctor* doctors, int numberOfDoctors)
{
    for (int i = 0; i < numberOfDoctors;  i++)
    {
        doctors[i].setId(i);
    }
}

/*
    Method to find the minimum number of doctors to complete the examination 
    of all the patients within the given average waiting time
*/
void findNoOfDoctors(int avgWaitingTimeLimit, Patient*& patientList, int noOfPatients)
{
    int noOfDoctors = 1;
    bool lessThanAverageTime = false; // we will be adding doctors until our average waiting time is under the limit.
    double avgWaitingTime = .0;
    while(!lessThanAverageTime)
    {
        Doctor* doctors = new Doctor[noOfDoctors];
        std::string *outputMessage = new std::string[noOfPatients];
        setDoctorIds(doctors, noOfDoctors);
        PriorityQueue<Patient> qPatient(noOfPatients);
        double totalWaitingTime = .0;
        int patientsExaminated = 0;
        int currentTime = 0;
        while(patientsExaminated < noOfPatients)
        {
            currentTime++;
            for (int i = 0; i < noOfPatients; ++i)
            {
                if(patientList[i].getArrivalTime() == currentTime) 
                {
                    qPatient.pqInsert(patientList[i]); //adding patients to the priority queue in order if they are arrived.
                }
            }
            for (int i = 0; i < noOfDoctors; ++i)
            {
                if (doctors[i].getNextAvailableTime() <= currentTime  && !qPatient.pqIsEmpty()) {
                    Patient currentPatient = qPatient.top();
                    qPatient.pqDelete(currentPatient);
                    doctors[i].addPatient(currentPatient, currentTime);
                    outputMessage[patientsExaminated] = "Doctor " + std::to_string(doctors[i].getId()) + 
                      " takes patient " + std::to_string(currentPatient.getId()) + 
                      " at minute " + std::to_string(currentTime) +
                      " (wait: " + std::to_string(currentPatient.getWaitingTime()) +
                      " mins)";
                    currentPatient.setTimeOfExamination(currentTime);
                    totalWaitingTime += currentPatient.getWaitingTime();
                    patientsExaminated++;
                }
            } 
        }

        if (patientsExaminated > 0) {
            avgWaitingTime = totalWaitingTime / patientsExaminated;
            lessThanAverageTime = avgWaitingTime <= avgWaitingTimeLimit;
        }

        if(!lessThanAverageTime)
        {
            noOfDoctors++; //repeat the process with more doctors.
        }
         else
        {
            std::cout << "Minimum number of doctors required: " << noOfDoctors << std::endl;
            std::cout << "\nSimulation with " << noOfDoctors << " doctors: \n" << std::endl;
            for (int i = 0; i < noOfPatients; ++i)
            {
                std::cout << outputMessage[i] << std::endl;
            }
            std::cout << "\nAverage waiting time: " << avgWaitingTime << " minutes" << std::endl;
        }
        delete[] doctors;
        delete[] outputMessage;

    }
}

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        std::cout << "Missing arguments" << std::endl;
    } else
    {
        std::string fileName = argv[1];
        int timeLimit = atoi(argv[2]);
        int numberOfPatients = 0;
        Patient *patientList = new Patient[numberOfPatients];
        patientList = getPatientsFromFile(fileName, numberOfPatients);
        findNoOfDoctors(timeLimit, patientList, numberOfPatients);
    }
    
}