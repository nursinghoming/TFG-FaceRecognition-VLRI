// Tests.cpp: define el punto de entrada de la aplicaci�n de consola.
//

#include "stdafx.h"
#include "HaarLikeFaceDetector.h"
#include <stdio.h>

using namespace std;
using namespace cv;

// Function Headers
void detectAndDisplay(Mat frame);

// Global variables
// Copy this file from opencv/data/haarscascades to target folder
string outputFolder = "output/";
string window_name = "Capture - Face detection";

// Function main
int main(void)
{
	// Read the image file
	Mat frame = imread("sources/manifestacion.jpg");

	// Apply the classifier to the frame
	if (!frame.empty()) {
		detectAndDisplay(frame);
	}
	else {
		printf(" --(!) No captured frame -- Break!");
		system("pause");
		return -1;
	}

	//Bucle infinito para evitar cierre
	while(true)
		waitKey(30);

	return 0;
}

// Function detectAndDisplay
void detectAndDisplay(Mat frame)
{
	//Detector de caras
	HaarLikeFaceDetector faceDetector;
	//Vector de im�genes con las caras encontradas
	std::vector<Mat> faces;
	//Imagen final con las caras se�aladas
	Mat outputFrame;

	//Detectar las caras
	if (faceDetector.detectFaces(frame, faces, outputFrame))
	{
		//Recorrer todas las caras
		for (unsigned int i = 0; i < faces.size(); ++i)
		{
			//Crear el nombre de fichero
			std::string filename = "";
			stringstream ssfn;
			ssfn << outputFolder << i << ".png";
			filename = ssfn.str();
			//Escribir en el fichero
			imwrite(filename, faces[i]);
		}
	}
	else
	{
		printf(" --(!) No captured faces -- Break!");
		system("pause");
		return;
	}

	//Mostrar imagen original
	imshow("original", frame);
	//Mostrar imagen detectada
	imshow("Caras detectadas", outputFrame);
}

