// Copyright (C) 2016 - IIT Bombay - FOSSEE
//
// This file must be used under the terms of the CeCILL.
// This source file is licensed as described in the file COPYING, which
// you should have received as part of this distribution.  The terms
// are also available at
// http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
// Organization: FOSSEE, IIT Bombay
// Email: toolbox@scilab.in

function cvtimg = CV_Erode(srcimg,erosion_type,erosion_size,iterations,border_type,border_value)
// Erodes an image by using a specific structuring element.
//
// Calling Sequence
//     cvtimg = CV_Erode(srcimg,erosion_type,erosion_size,[iterations,border_type,border_value])
// Parameters
//     	src : input image; the number of channels can be arbitrary, but the depth should be one of CV_8U, CV_16U, CV_16S, CV_32F or CV_64F.
//	erosion_type : can be one of :	MORPH_RECT, MORPH_CROSS, MORPH_ELLIPSE	
//	erosion_size : size of kernel to be used for erosion. Must be odd
//	iterations : number of times erosion is applied.
//	border_type : pixel extrapolation method.
//	border_value : border value in case of a constant border 
//
// Description
//	This function can be used for eroding an image. Kernel used for erosion is decided by type and size. Size must always be odd. Anchor pint of kernel is always center of kernel. Input arguements 'iterations(1), border_type(BORDER_CONSTANT) and border_value' are optionals. Whwn not specified, default values as as mentioned in brackets. 
//
// 	border_type can be :
//	<itemizedlist>
//	<listitem>BORDER_REPLICATE:     	aaaaaa|abcdefgh|hhhhhhh</listitem>
//	<listitem>BORDER_REFLECT:       	fedcba|abcdefgh|hgfedcb</listitem>
//	<listitem>BORDER_REFLECT_101:   	gfedcb|abcdefgh|gfedcba</listitem>
//	<listitem>BORDER_WRAP:          	cdefgh|abcdefgh|abcdefg</listitem>
//	<listitem>BORDER_CONSTANT:		iiiiii|abcdefgh|iiiiiii</listitem>  
//	</itemizedlist>
//
// This is curretly dummy function. It provides no functionality but is required 
// for providing support for generating C code for OpenCV
//
// Examples
//	img = CV_LoadImage('~/test.jpg',0)
//	dst = CV_Erode(img,"MORPH_RECT",3,1,"BORDER_CONSTANT",0);
// See also
//     CV_LoadImage CV_Dilate
//
// Authors
//     Siddhesh Wani
//

cvtimg = 0

endfunction
