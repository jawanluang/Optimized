//---------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Particle.h"
#include "Matrix.h"

Particle::Particle()
	: prev_Row0	(Vect4D()),
	  prev_Row1	(Vect4D()),
	  prev_Row2	(Vect4D()),
	  prev_Row3	(Vect4D()),
	  curr_Row0	(Vect4D()),
	  curr_Row1	(Vect4D()),
	  curr_Row2	(Vect4D()),
	  curr_Row3	(Vect4D()),
	  position(0.0f, 0.0f, -10.0f),
	  velocity(-3.0f, 0.0f, 0.0f),
	  scale(1.0f, 1.0f, 1.0f),
	  diff_Row0 (Vect4D()),
	  diff_Row1 (Vect4D()),
	  diff_Row2 (Vect4D()),
	  diff_Row3 (Vect4D()),
	  life(0.0f), 
	  rotation(0.0f),
	  rotation_velocity(-0.25f),
	  pad01 (0.0f),
	  pad02(0.0f),
	  pad03(0.0f),
	  next(nullptr), 
	  prev(nullptr)
{
}

Particle::~Particle()
{
	// nothing to do
}

Particle::Particle(const Particle &r )
{
	// copy the data only
	// this way of copying data is more efficient that element by element
	this->prev_Row0 = r.prev_Row0;
	this->prev_Row1 = r.prev_Row1;
	this->prev_Row2 = r.prev_Row2;
	this->prev_Row3 = r.prev_Row3;
	this->curr_Row0 = r.curr_Row0;
	this->curr_Row1 = r.curr_Row1;
	this->curr_Row2 = r.curr_Row2;
	this->curr_Row3 = r.curr_Row3;

	this->position = r.position;
	this->velocity = r.velocity;
	this->scale    = r.scale;

	this->diff_Row0 = r.diff_Row0;
	this->diff_Row1 = r.diff_Row1;
	this->diff_Row2 = r.diff_Row2;
	this->diff_Row3 = r.diff_Row3;

	this->rotation = r.rotation;
	this->rotation_velocity = r.rotation_velocity;
	this->life     = r.life;

	this->pad01 = 0.0f;
	this->pad02 = 0.0f;
	this->pad03 = 0.0f;

	this->next = this->next;
	this->prev = this->prev;
}

void Particle::Update(const float& time_elapsed)
{
	// Rotate the matrices
	Vect4D tmp_Row0;
	tmp_Row0 = curr_Row0;
	prev_Row0 = tmp_Row0;

	Vect4D tmp_Row1;
	tmp_Row1 = curr_Row1;
	prev_Row1 = tmp_Row1;

	Vect4D tmp_Row2;
	tmp_Row2 = curr_Row2;
	prev_Row2 = tmp_Row2;

	Vect4D tmp_Row3;
	tmp_Row3 = curr_Row3;
	prev_Row3 = tmp_Row3;

	Matrix tmp;

	tmp.set(Matrix::MatrixRow::MATRIX_ROW_0, &this->diff_Row0);
	tmp.set(Matrix::MatrixRow::MATRIX_ROW_1, &this->diff_Row1);
	tmp.set(Matrix::MatrixRow::MATRIX_ROW_2, &this->diff_Row2);
	tmp.set(Matrix::MatrixRow::MATRIX_ROW_3, &this->diff_Row3);

	float MatrixScale = -3.0f*tmp.Determinant();

	// serious math below - magic secret sauce
	life += time_elapsed;
	position = position + (velocity * time_elapsed);
	Vect4D z_axis(0.0f, 0.0f, 3.0f);
	Vect4D v(2.0f,2.0f,0.0f);
	position.Cross( z_axis, v);
	v.norm(v);
	position = position + v * 0.05f * life;

	if( MatrixScale > 1.0f )
	{
		MatrixScale = 1.0f/MatrixScale;
	};

	rotation = rotation + MatrixScale + rotation_velocity * time_elapsed * 2.0f;
}

// --- End of File ---
