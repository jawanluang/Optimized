//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef PARTICLE_H
#define PARTICLE_H

// include
#include "Vect4D.h"

class Particle
{
public:
	friend class ParticleEmitter;
	
	Particle();
	Particle(const Particle& r);
	Particle& operator = (const Particle& r) = default;
	~Particle();

	void Update(const float& time_elapsed);

private:
	// Add Padding where necessary
	
	Vect4D prev_Row0; // 16 byte 
	Vect4D prev_Row1;
	Vect4D prev_Row2;
	Vect4D prev_Row3;

	Vect4D curr_Row0;
	Vect4D curr_Row1;
	Vect4D curr_Row2;
	Vect4D curr_Row3;

	Vect4D position;
	Vect4D velocity;
	Vect4D scale;

	Vect4D diff_Row0;
	Vect4D diff_Row1;
	Vect4D diff_Row2;
	Vect4D diff_Row3;

	float	life; // 4 byte
	float	rotation;
	float	rotation_velocity;
	float	pad01;
	float	pad02;
	float	pad03;

	Particle* next; // 4 byte
	Particle* prev;
};

#endif 

// --- End of File ---
