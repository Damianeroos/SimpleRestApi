#include "Controller.hpp"

int main(){
  Controller server;
  server.accept().wait();
  for(;;){
    sleep(1000);
  }
  
  return 0;
}
