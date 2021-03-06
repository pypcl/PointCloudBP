/*
===============================================================================

  FILE:  laspointwriter1compressedarithmetic.h
  
  CONTENTS:
  
    Writes a point of type 1 (with gps_time) in our compressed LAS format 1.1

  PROGRAMMERS:
  
    martin isenburg@cs.unc.edu
  
  COPYRIGHT:
  
    copyright (C) 2007  martin isenburg@cs.unc.edu
    
    This software is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  
  CHANGE HISTORY:
  
    31 October 2009 -- updated to use the new Arithmetic Coder 
    7 September 2008 -- updated to support LAS format 1.2 
    21 February 2007 -- created after having the longest talk ever with my aunt
  
===============================================================================
*/
#ifndef LAS_POINT_WRITER_1COMPRESSED_ARITHMETIC_H
#define LAS_POINT_WRITER_1COMPRESSED_ARITHMETIC_H

#include "laspointwriter.h"

#include "arithmeticmodel.h"
#include "arithmeticencoder.h"
#include "arithmeticintegercompressor.h"

#include <stdio.h>

class LASpointWriter1compressedArithmetic : public LASpointWriter
{
public:
  bool write_point(LASpoint* point, double gps_time = 0, unsigned short* rgb = 0);
  LASpointWriter1compressedArithmetic(FILE* file);
  ~LASpointWriter1compressedArithmetic();

private:
  FILE* file;
  LASpoint last_point;
  int last_dir;
  int last_x_diff[2][3];
  int last_y_diff[2][3];
  int last_incr[2];
  I64F64 last_gps_time;
  I32 last_gps_time_diff;
  void init_encoder();
  ArithmeticEncoder* enc;
  ArithmeticIntegerCompressor* ic_dx;
  ArithmeticIntegerCompressor* ic_dy;
  ArithmeticIntegerCompressor* ic_z;
  ArithmeticModel* m_changed_values;
  ArithmeticIntegerCompressor* ic_intensity;
  ArithmeticModel* m_bit_byte;
  ArithmeticModel* m_classification;
  ArithmeticIntegerCompressor* ic_scan_angle_rank;
  ArithmeticModel* m_user_data;
  ArithmeticIntegerCompressor* ic_point_source_ID;
  ArithmeticIntegerCompressor* ic_gps_time;
  ArithmeticModel** m_gps_time_multi;
  int multi_extreme_counter;
};

#endif
