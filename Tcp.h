/************************************************************
* File description: Tcp header file. the class inherit from	*
* socket. methods of tcp socket type						*
************************************************************/

#ifndef TCP_H
#define TCP_H_

#include "Socket.h"


class Tcp: public Socket {
private:
	int descriptorCommunicateClient;
public:
	/***********************************************************************
	* function name: Tcp												   *
	* The Input: Boolean, true - if server, false if client and port number*
	* The output: none										               *
	* The Function operation: creating new Tcp						       *
	***********************************************************************/
    Tcp(bool isServers,string ip, int port_num);
	/***********************************************************************
	* function name: ~Tcp												   *
	* The Input: none													   *
	* The output: none										               *
	* The Function operation: default destructor					       *
	***********************************************************************/
	virtual ~Tcp();
	/***********************************************************************
	* function name: initialize											   *
	* The Input: none              										   *
	* The output: int number representing the return status		           *
	* The Function operation: initialize the Socket object and getting a   *
	* socket descriptor.												   *
	***********************************************************************/
	int initialize();
	/***********************************************************************
	* function name: sendData											   *
	* The Input: string representing the data to send		               *
	* The output: int number representing the return status		           *
	* The Function operation: sending the input data to the socket         *
	* who connect to this socket.										   *
	***********************************************************************/
	int sendData(string data);
	/***********************************************************************
	* function name: recive	`											   *
	* The Input: none										               *
	* The output: int number representing the return status	               *
	* The Function operation: getting data from the other socket and print *
	* the data															   *
	***********************************************************************/
	int reciveData(char* buffer, int size);
	//this situation when we have many connection of clients and not only one.
	int acceptOneClient();

	int closeData();
	};

#endif /* Tcp_H_ */
