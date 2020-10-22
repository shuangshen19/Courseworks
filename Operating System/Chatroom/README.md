# Chatroom

written by szyu, jenny, shuang
===========================================================
Use the Virtualbox installed by project1 and ubuntu 18.04 LTS to implement a multiplayer chat room

## Descriptions:
Use C to implement a socket multi-person chat room (a server corresponds to multiple clients), on the server side. Use multithread to receive multiple client connections.
* Run the code (there are as many clients as there are terminals)
* Execute the server command ./server <port>
* Add another terminal and execute the client command ./client <ip address> <port>
* After the server is connected, wait for the client's connection command to determine the connection, and each client transmits
* The message (request) is sent to the server and pushed to each client screen to achieve communication.

Open terminal and get into the folder which our codes in it 
<server> 
./server <port>
Then run:
./server 8080

<client> (each client use one terminal)
./client <ip address> <port> 
Open another terminal and run:
./client 127.0.0.1 8080

## References:
* https://beej-zhtw-gitbook.netdpi.net/socketff0d_qu_de_file_descriptor.html
* https://en.wikipedia.org/wiki/Readers%E2%80%93writers_problem
* http://www.syscom.com.tw/ePaper_Content_EPArticledetail.aspx?id=213&EPID=176&j=5&HeaderName=NonStop%E5%B0%88%E6%AC%84
* https://gist.github.com/aethur/72737
* https://blog.csdn.net/chenglibin1988/article/details/8812506
* http://www.ezonesoft.com.tw/onlinegame/TCPChat.htm
* http://speed.cis.nctu.edu.tw/~ydlin/course/cn/np/chatroom/ChatRoom.htm
* https://blog.csdn.net/Small_Pond/article/details/78632702
* http://zake7749.github.io/2015/03/17/SocketProgramming/