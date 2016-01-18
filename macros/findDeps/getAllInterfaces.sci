//
// Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
// Copyright (C) 2009-2009 - DIGITEO - Bruno JOFRET
//
// This file must be used under the terms of the CeCILL.
// This source file is licensed as described in the file COPYING, which
// you should have received as part of this distribution.  The terms
// are also available at
// http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
//
//

function allInterfaces = getAllInterfaces(OutFormat)
  //Interface files common to all types of output format
  Standalone_interfaces = [
      "src/c/auxiliaryFunctions/interfaces/int_rand.h"
      "src/c/auxiliaryFunctions/interfaces/int_sign.h"
      "src/c/auxiliaryFunctions/interfaces/int_size.h"
      "src/c/auxiliaryFunctions/interfaces/int_length.h"
      "src/c/auxiliaryFunctions/interfaces/int_type.h"
      "src/c/auxiliaryFunctions/interfaces/int_isempty.h"
      "src/c/auxiliaryFunctions/interfaces/int_isnan.h"
      "src/c/auxiliaryFunctions/interfaces/int_pythag.h"
      "src/c/auxiliaryFunctions/interfaces/int_frexp.h"
      "src/c/auxiliaryFunctions/interfaces/int_abs.h"
      "src/c/auxiliaryFunctions/interfaces/int_max.h"
      "src/c/auxiliaryFunctions/interfaces/int_min.h"
      "src/c/auxiliaryFunctions/interfaces/int_conj.h"
      "src/c/auxiliaryFunctions/interfaces/int_find.h"
      "src/c/type/int_imag.h"
      "src/c/type/int_real.h"
      "src/c/matrixOperations/interfaces/int_vmagn.h"
      "src/c/matrixOperations/interfaces/int_ones.h"
      "src/c/matrixOperations/interfaces/int_spec.h"
      "src/c/matrixOperations/interfaces/int_cat.h"
      "src/c/matrixOperations/interfaces/int_zeros.h"
      "src/c/matrixOperations/interfaces/int_OpBackSlash.h"
      "src/c/matrixOperations/interfaces/int_OpApex.h"
      "src/c/matrixOperations/interfaces/int_OpCc.h"
      "src/c/matrixOperations/interfaces/int_OpRc.h"
      "src/c/matrixOperations/interfaces/int_transpose.h"
      "src/c/matrixOperations/interfaces/int_v2magn.h"
      "src/c/matrixOperations/interfaces/int_invert.h"
      "src/c/matrixOperations/interfaces/int_OpSlash.h"
      "src/c/matrixOperations/interfaces/int_OpDotApex.h"
      "src/c/matrixOperations/interfaces/int_trace.h"
      "src/c/matrixOperations/interfaces/int_det.h"
      "src/c/matrixOperations/interfaces/int_eye.h"
      "src/c/matrixOperations/interfaces/int_OpStar.h"
      "src/c/matrixOperations/interfaces/int_chol.h"
      "src/c/matrixOperations/interfaces/int_dist.h"
      "src/c/matrixOperations/interfaces/int_fill.h"
      "src/c/matrixOperations/interfaces/int_expm.h"
      "src/c/elementaryFunctions/interfaces/int_asinh.h"
      "src/c/elementaryFunctions/interfaces/int_atanh.h"
      "src/c/elementaryFunctions/interfaces/int_sinh.h"
      "src/c/elementaryFunctions/interfaces/int_tanh.h"
      "src/c/elementaryFunctions/interfaces/int_sqrt.h"
      "src/c/elementaryFunctions/interfaces/int_OpDotHat.h"
      "src/c/elementaryFunctions/interfaces/int_OpHat.h"
      "src/c/elementaryFunctions/interfaces/int_lnp1m1.h"
      "src/c/elementaryFunctions/interfaces/int_round.h"
      "src/c/elementaryFunctions/interfaces/int_log10.h"
      "src/c/elementaryFunctions/interfaces/int_log1p.h"
      "src/c/elementaryFunctions/interfaces/int_floor.h"
      "src/c/elementaryFunctions/interfaces/int_exp10.h"
      "src/c/elementaryFunctions/interfaces/int_cos.h"
      "src/c/elementaryFunctions/interfaces/int_fix.h"
      "src/c/elementaryFunctions/interfaces/int_exp.h"
      "src/c/elementaryFunctions/interfaces/int_int.h"
      "src/c/elementaryFunctions/interfaces/int_log.h"
      "src/c/elementaryFunctions/interfaces/int_pow.h"
      "src/c/elementaryFunctions/interfaces/int_sin.h"
      "src/c/elementaryFunctions/interfaces/int_tan.h"
      "src/c/elementaryFunctions/interfaces/int_acosh.h"
      "src/c/elementaryFunctions/interfaces/int_acos.h"
      "src/c/elementaryFunctions/interfaces/int_asin.h"
      "src/c/elementaryFunctions/interfaces/int_atan.h"
      "src/c/elementaryFunctions/interfaces/int_ceil.h"
      "src/c/elementaryFunctions/interfaces/int_cosh.h"
      "src/c/elementaryFunctions/interfaces/int_uint8.h"
      "src/c/elementaryFunctions/interfaces/int_int8.h"
      "src/c/elementaryFunctions/interfaces/int_uint16.h"
      "src/c/elementaryFunctions/interfaces/int_int16.h"
      "src/c/statisticsFunctions/interfaces/int_mean.h"
      "src/c/statisticsFunctions/interfaces/int_meanf.h"
      "src/c/statisticsFunctions/interfaces/int_stdevf.h"
      "src/c/statisticsFunctions/interfaces/int_prod.h"
      "src/c/statisticsFunctions/interfaces/int_variance.h"
      "src/c/statisticsFunctions/interfaces/int_sum.h"
      "src/c/operations/interfaces/int_OpEqual.h"
      "src/c/operations/interfaces/int_OpLogNot.h"
      "src/c/operations/interfaces/int_OpLogEq.h"
      "src/c/operations/interfaces/int_OpLogNe.h"
      "src/c/operations/interfaces/int_OpLogGt.h"
      "src/c/operations/interfaces/int_OpLogGe.h"
      "src/c/operations/interfaces/int_OpLogLt.h"
      "src/c/operations/interfaces/int_OpLogLe.h"
      "src/c/operations/interfaces/int_OpLogAnd.h"
      "src/c/operations/interfaces/int_OpLogOr.h"
      "src/c/operations/interfaces/int_OpDotStar.h"
      "src/c/operations/interfaces/int_OpDotSlash.h"
      "src/c/operations/interfaces/int_OpBackSlash.h"
      "src/c/operations/interfaces/int_OpDotBackSlash.h"
      "src/c/operations/interfaces/int_OpSlash.h"
      "src/c/operations/interfaces/int_OpPlus.h"
      "src/c/operations/interfaces/int_OpMinus.h"
      "src/c/operations/interfaces/int_OpStar.h"
      "src/c/operations/interfaces/int_OpExt.h"
      "src/c/operations/interfaces/int_OpIns.h"
      "src/c/string/interfaces/int_disp.h"
      "src/c/string/interfaces/int_string.h"
      "src/c/signalProcessing/interfaces/int_ifft.h"
      "src/c/signalProcessing/interfaces/int_lpc2cep.h"
      "src/c/signalProcessing/interfaces/int_cepstrum.h"
      "src/c/signalProcessing/interfaces/int_xcorr.h"
      "src/c/signalProcessing/interfaces/int_convol.h"
      "src/c/signalProcessing/interfaces/int_hilbert.h"
      "src/c/signalProcessing/interfaces/int_levin.h"
      "src/c/signalProcessing/interfaces/int_fftshift.h"
      "src/c/signalProcessing/interfaces/int_fft.h"
      "src/c/signalProcessing/interfaces/int_lev.h"
      "src/c/implicitList/int_OpColon.h"];

  //Interface files required for "Arduino" output
  Arduino_interfaces = [
      "src/c/scilab-arduino/interfaces/int_cmd_digital_out.h"
      "src/c/scilab-arduino/interfaces/int_cmd_digital_in.h"
      "src/c/scilab-arduino/interfaces/int_cmd_analog_out.h"
      "src/c/scilab-arduino/interfaces/int_cmd_analog_in.h"
      "src/c/scilab-arduino/interfaces/int_cmd_dcmotor.h"
      "src/c/scilab-arduino/interfaces/int_cmd_servo.h"
      "src/c/scilab-arduino/interfaces/int_sleep.h"];

  //Interface files required for "AVR" output
  AVR_interfaces = [
      "src/c/hardware/avr/interfaces/int_AVRPeripheralGPIO.h"
      "src/c/hardware/avr/interfaces/int_AVRPeripheralADC.h"
      "src/c/hardware/avr/interfaces/int_AVRPeripheralADC.h"
      "src/c/hardware/avr/interfaces/int_AVRUtil.h"
	];

  if OutFormat == "StandAlone"
  allInterfaces = Standalone_interfaces;
  elseif OutFormat == "Arduino"
  allInterfaces = cat(1,Standalone_interfaces, Arduino_interfaces);
  elseif OutFormat == "AVR"
  allInterfaces = cat(1,Standalone_interfaces, AVR_interfaces);
  end

endfunction
