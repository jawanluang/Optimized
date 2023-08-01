//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "Matrix.h"
#include "Vect4D.h"
#include "Particle.h"

#include <list>

class ParticleEmitter
{
public:
	ParticleEmitter();
	ParticleEmitter(const ParticleEmitter& r) = default;
	ParticleEmitter& operator = (const ParticleEmitter& r) = default;
	~ParticleEmitter();
	
	void SpawnParticle();
	void update();
	void draw();

	void addParticleToList(Particle *p );
	void removeParticleFromList( Particle *p );

	void Execute(Vect4D& pos, Vect4D& vel, Vect4D& sc);

private:
	// add padding where necessary

	Vect4D start_position; // 16 byte 
	Vect4D start_velocity;
	Vect4D vel_variance;
	Vect4D pos_variance;

	float	spawn_frequency; // 4 byte
	float	last_spawn;
	float	last_loop;	
	float	max_life;

	int		max_particles; // 4 byte
	int		last_active_particle;
	int		bufferCount;
	int		pad01;
	int		pad02;
	int		pad03;

	Particle* drawBuffer;
	Particle *headParticle; // 4 byte
};

#endif 

// --- End of File ---
