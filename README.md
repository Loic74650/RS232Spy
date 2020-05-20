# RS232Spy
 Intercept ASCII communication between two RS232 devices
 
 The setup is based on two RS232-to-TTL converters connected to each other. The RX pin from one is connected to TX pin from the other.<br />
 Two RS232 devices, a master (eg. a computer running a software) and a slave (eg. a robot) are connected together with this setup placed in between.<br />
 The Arduino (it requires two extra serial ports, eg. a Mega 2560) reads the RX pins from both devices and prints the output to the Serial monitor.<br />
 This is useful to debug or reverse-engineer the command set necessary to drive RS232 devices, for instance.<br /><br />
 
 Example output on serial monitor:<br /><br />
 
		S1: SERIAL?<br />
		S2: 6571108<br />
		S1: CALDATE?<br />
		S2: 12/12/19<br />
		S1: WAVELENGTH?<br />
		S2: 660<br />
		S1: SOFTVER?<br />
		S2: MPC-B-4.0.1<br />
		S1: POWER?<br />
		S2:  0004mW<br />
		S1: SETCURRENT1?<br />
		S2:  054.8%<br /><br />

Note that for fast baud rates, the chronological order of the intercepted data may not be preserved accurately<br /><br />
 
 <p align="center"> <img src="/Docs/Hardware.jpg" width="600" title="Overview"> </p> <br /><br />
 <p align="center"> <img src="/Docs/wiring.png" width="600" title="Overview"> </p> <br /><br />
