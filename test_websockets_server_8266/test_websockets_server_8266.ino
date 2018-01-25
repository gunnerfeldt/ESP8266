#include <WebSockets.h>
#include <WebSocketsClient.h>
#include <WebSocketsServer.h>

WebSocketsServer webSocket = WebSocketsServer(81); //ws will run on port 81

webSocket.begin(); 
webSocket.onEvent(webSocketEvent); 

webSocket.loop();

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length){ 
  if (type == WStype_TEXT){ 
   for(int i = 0; i < length; i++) Serial.print((char) payload[i]); 
   Serial.println(); 
  } 
} 

if (Serial.available() > 0){ 
     char c[] = {(char)Serial.read()}; 
     webSocket.broadcastTXT(c, sizeof(c)); 
   } 
