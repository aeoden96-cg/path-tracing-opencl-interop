#pragma once
#include <CL/opencl.h>



struct Material {
	cl_double refraction;
	cl_double reflection;
	/*
	* 0: light
	* 1: diffuse
	* 2: metal
	* 3: dieletric
	* 4: fuzz metal
	*/
	cl_int type;
	cl_double3 color;
};

struct Sphere {
	cl_double radius;
	cl_double3 pos;
	Material mat;
};

cl_double3& operator /= (cl_double3& o1, const double o2);

cl_double3 operator / (const cl_double3 o1, const double o2);

void initScene1(Sphere sphere[], int& sphereSize, int winWidth, int winHeight);
void initScene2(Sphere sphere[], int& sphereSize, int winWidth, int winHeight);