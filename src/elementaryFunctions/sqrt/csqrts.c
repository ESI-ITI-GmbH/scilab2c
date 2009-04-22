/*
 *  Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 *  Copyright (C) 2008-2008 - INRIA - Bruno JOFRET
 *
 *  This file must be used under the terms of the CeCILL.
 *  This source file is licensed as described in the file COPYING, which
 *  you should have received as part of this distribution.  The terms
 *  are also available at
 *  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 *
 */

#include <math.h>
#include "sqrt.h"
#include "lapack.h"
#include "abs.h"
#include "sign.h"
#include "pythag.h"

#ifdef _MSC_VER
#include <float.h>
#define isnan(x) _isnan((double)x)
#endif

#define _sign(a, b) b >=0 ? a : -a

floatComplex	csqrts(floatComplex in) {
  float RMax =  (float) getOverflowThreshold();
  float BRMin = 2.0f * (float) getUnderflowThreshold();

  float RealIn = creals(in);
  float ImgIn = cimags(in);

  float RealOut = 0;
  float ImgOut = 0;

  if(RealIn == 0)
    {/* pure imaginary case */
      if(dabss(ImgIn >= BRMin))
	RealOut = ssqrts(0.5f * sabss(ImgIn));
      else
	RealOut = ssqrts(sabss(ImgIn)) * ssqrts(0.5);

      ImgOut = _sign(1, ImgIn) * RealOut;
    }
  else if( sabss(RealIn) <= RMax && sabss(ImgIn) <= RMax)
    {/* standard case : a (not zero) and b are finite */
      float Temp = ssqrts(2.0f * (sabss(RealIn) + spythags(RealIn, ImgIn)));
      /* overflow test */
      if(Temp > RMax)
	{/*     handle (spurious) overflow by scaling a and b */
	  float RealTemp = RealIn / 16.0f;
	  float ImgTemp = ImgIn / 16.0f;
	  Temp = ssqrts(2.0f * (sabss(RealIn) + spythags(RealIn, ImgTemp)));
	  if(RealTemp >= 0)
	    {
	      RealOut	= 2 * Temp;
	      ImgOut	= 4 * ImgTemp / Temp;
	    }
	  else
	    {
	      RealOut	= 4 * sabss(ImgIn) / Temp;
	      ImgOut	= _sign(2, ImgIn) * Temp;
	    }
	}
      else if(RealIn >= 0) /* classic switch to get the stable formulas */
	{
	  RealOut	= 0.5f * Temp;
	  ImgOut	= ImgIn / Temp;
	}
      else
	{
	  RealOut	= sabss(ImgIn) / Temp;
	  ImgOut	= (_sign(0.5f, ImgIn)) * Temp;
	}
    }
  else
    {
      /*
      //Here we treat the special cases where a and b are +- 00 or NaN.
      //The following is the treatment recommended by the C99 standard
      //with the simplification of returning NaN + i NaN if the
      //the real part or the imaginary part is NaN (C99 recommends
      //something more complicated)
      */

      if(isnan(RealIn) == 1 || isnan(ImgIn) == 1)
	{/* got NaN + i NaN */
	  RealOut	= RealIn + ImgIn;
	  ImgOut	= RealOut;
	}
      else if( dabss(ImgIn) > RMax)
	{/* case a +- i oo -> result must be +oo +- i oo  for all a (finite or not) */
	  RealOut	= sabss(ImgIn);
	  ImgOut	= ImgIn;
	}
      else if(RealIn < -RMax)
	{/* here a is -Inf and b is finite */
	  RealOut	= 0;
	  ImgOut	= _sign(1, ImgIn) * sabss(RealIn);
	}
      else
	{/* here a is +Inf and b is finite */
	  RealOut	= RealIn;
	  ImgOut	= 0;
	}
    }

  return FloatComplex(RealOut, ImgOut);
}
