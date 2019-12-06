#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

#ifndef SANITIZATION_H
#define SANITIZATION_H

void cinIntCheck(std::string message, int *optionPTR);
void cinDoubleCheck(std::string message, double *optionPTR);
void possitiveIntCheck(std::string message, int *inputPTR);
void possitiveDoubleCheck(std::string message, double *inputPTR);
void intOptionsCheck(std::string message, int numOfOptions, int *optionPTR);
void militaryHourCheck(std::string message, int *hourPTR);
void minCheck(std::string message, int *minPTR);
void monthCheck(std::string message, int *monthPTR);
void dayCheck(std::string message, int *dayPTR);
void yearCheck(std::string message, int *yearPTR);
void ynCheck(std::string message, char *inputPTR);
void configName(std::string message, std::string *namePTR);

#endif
