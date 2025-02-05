//base readme

Upload the program and open cutecom (19200, 8N1)


mouse protocol:
        D7      D6      D5      D4      D3      D2      D1      D0

Byte 1  X       1       LB      RB      Y7      Y6      X7      X6
Byte 2  X       0       X5      X4      X3      X2      X1      X0
Byte 3  X       0       Y5      Y4      Y3      Y2      Y1      Y0

LB is the state of the left button (1 means down)
RB is the state of the right button (1 means down)
X7-X0 movement in X direction since last packet (signed byte)
Y7-Y0 movement in Y direction since last packet (signed byte)

source: https://roborooter.com/post/serial-mice/