#ifndef CONTROLLER_HH
#define CONTROLLER_HH

#include <cpprest/http_listener.h>
#include <cpprest/http_msg.h>
#include <pplx/pplxtasks.h>
#include <string>

using namespace std;
using namespace web;
using namespace http;
using namespace http::experimental::listener;

class Controller{
  const string _end_point = "/";
  const string _port = "1234";
  const string _address  = "localhost";
  web::uri_builder endpointBuilder;
  http_listener _listener;
public:
  
  Controller();
  void initRestOpHandlers();
  std::vector<utility::string_t> requestPath(const http_request & message);
  pplx::task<void> accept();
  pplx::task<void> shutdown();
  void handleGet(http_request message);
  
    

};
  
#endif
