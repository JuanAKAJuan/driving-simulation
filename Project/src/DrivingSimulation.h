#pragma once

#include "Simulation.h"

class DrivingSimulation : public Simulation {
public:
	DrivingSimulation(void);
	~DrivingSimulation(void);
	virtual void InitializeSimulation(int argc, char** argv);
	virtual void InitializeGraphics();
	virtual void Update();
	virtual void Draw();
	virtual void Reshape(int w, int h);
	virtual void Keyboard(unsigned char key, int x, int y);
	virtual void SpecialKey(int key, int x, int y);
	virtual void MouseMove(int x, int y);
	virtual void PassiveMouseMove(int x, int y);
};

