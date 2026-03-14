#include <ardupilotmega/mavlink.h> 
#include <string> 
#include "mavutil/serial_port.h" 
#include "mavutil/udp_port.h"
using namespace std; 
class MAV {
	private:
		Serial_Port serial_; 
		UDP_Port udp_; 
	public: 
		MAV(string port, int baud); 
		~MAV() = default;
		bool connect();
		void disconnect(); 
		void set_servo();
		void get_message(); 
}; 
