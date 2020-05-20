# RS232Spy
 Intercept ASCII communication between two RS232 devices
 
 The setup is based on two RS232-to-TTL converters connected to each other. The RX pin from one is connected to TX pin from the other.<br />
 Two RS232 devices, a master (eg. a computer running a software) and a slave (eg. a robot) are connected together with this setup placed in between.<br />
 The Arduino (it requires two extra serial ports, eg. a Mega 2560) reads the RX pins from both devices and prints the output to the Serial monitor.<br />
 This is useful to debug or reverse-engineer the command set necessary to drive RS232 devices, for instance.<br /><br />
 
 Example output on serial monitor:<br /><br />
 
		S1: SERIAL?
		S2: 6571108
		S1: CALDATE?
		S2: 12/12/19
		S1: WAVELENGTH?
		S2: 660
		S1: SOFTVER?
		S2: MPC-B-4.0.1
		S1: POWER?
		S2:  0004mW
		S1: SETCURRENT1?
		S2:  054.8%

Note that for fast baud rates, the chronological order of the intercepted data may not be preserved accurately<br /><br />
 
 <p align="center"> <img src="/Docs/Hardware.jpg" width="600" title="Overview"> </p> <br /><br />
 <p align="center"> <img src="/Docs/wiring.png" width="600" title="Overview"> </p> <br /><br />
