//
// Created by julim on 30/06/2022.
//

#ifndef TP_FINAL_PRUEBA_JAM_H
#define TP_FINAL_PRUEBA_JAM_H
#include "Constants.h"
#include "Reading.h"
#include "Historical.h"
#include "Novel.h"
#include "Tale.h"
#include "Poem.h"
#include <string>
#include <iostream>

bool validateNumber(std::string string);

int requestNum(const std::string& text);

bool validateString(std::string string);

std::string requestAlpha(const std::string& text);

std::string requestAlphanum(std::string text);

int requestISNI();

int requestType();

std::string requestTitle();

unsigned int requestMinutes();

unsigned int requestPublishYear();

Genres requestGenre();

char* reserveMemoryTheme(unsigned long stringLength);

char *themeCreation();

Reading* newNovel(int isni ,unsigned int minutes, unsigned int publishYear, std::string title);

Reading* newTale(int isni ,unsigned int minutes, unsigned int publishYear, std::string title);

Reading* newPoem(int isni ,unsigned int minutes, unsigned int publishYear, std::string title);

std::string requestAuthorsName();

std::string requestNationality();

int requestBirth();

int requestDeath();





#endif //TP_FINAL_PRUEBA_JAM_H
