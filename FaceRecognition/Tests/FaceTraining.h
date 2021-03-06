#pragma once
#include "ImageUpsampler.h"
#include <string>

//Main para test de reconocimiento de caras
int testFaces(int argc, char**argv);
//Entrenar bases de aprendizaje
int trainFaces(int argc, char** argv);
//Main realizar tests a partir de un csv
int testMultiplesDatabases(int argc, char**argv);
//Separar base de datos
int separeDatabase(int argc, char**argv);
//Leer fichero que contiene bases de im�genes
void readDatabasesFile(const std::string &file, std::vector<std::string> &databases);
//Crear directorio
bool createDir(const std::string& dirName_in);
//Generar upsampler
tfg::ImageUpsampler* generateUpsampler(int opcion);
//Realizar split de un string
void splitString(const std::string& str, const std::string& delim, std::vector<std::string> &tokens);