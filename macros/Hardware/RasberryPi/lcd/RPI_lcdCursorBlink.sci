// Copyright (C) 2017 - IIT Bombay - FOSSEE
//
// This file must be used under the terms of the CeCILL.
// This source file is licensed as described in the file COPYING, which
// you should have received as part of this distribution.  The terms
// are also available at
// http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
// Organization: FOSSEE, IIT Bombay
// Email: toolbox@scilab.in

function RPI_lcdCursorBlink(fd,state)
// Function to turn cursor blinking on/off
//
// Calling Sequence
//  RPI_lcdCursorBlink(fd,state)
//
// Parameters
//  fd   : file-descriptor obtained using RPI_lcdInit function  
//  state: 0 (for off) or 1 (for on)
//
// Description
//  This function sets the blinking of cursor.
//
// Examples
//  RPI_lcdCursorBlink(13,1)
// See also
//  RPI_lcdCharDef, RPI_lcdClear, RPI_lcdCursor, RPI_lcdDisplay, RPI_lcdHome, RPI_lcdInit, RPI_lcdPutchar, RPI_lcdPosition, RPI_lcdPrintf, RPI_lcdPuts, RPI_lcdSendCommand
//
// Authors
//  Jorawar Singh
//
// Bibliography
//  http://wiringpi.com/reference/

    commande="lCB#2#"+string(fd)+"#"+string(state)+"#";
    if getos=="Linux" then
        unix_w("python -c ""import socket;s=socket.socket();s.connect((''"+RPI_piAdress+"'',9077));s.send(''"+commande+"'');print(s.recv(1024));s.close()""");
    elseif getos=="Windows" then
        RPI_winR=dos("python -c ""import socket;s=socket.socket();s.connect((''"+RPI_piAdress+"'',9077));s.send(''"+commande+"'');print(s.recv(1024));s.close()""");
    end
endfunction
