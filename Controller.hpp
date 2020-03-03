#pragma once

#include <cpprest/http_listener.h>
#include <cpprest/http_msg.h>
#include <pplx/pplxtasks.h>
#include <string>


class Controller{

  
  const std::string m_endpoint = "/";
  const std::string m_port = "1234";
  const std::string m_address  = "localhost";
  web::http::experimental::listener::http_listener m_listener;
public:
  
  Controller();
  void initRestOpHandlers();
  std::vector<utility::string_t> requestPath(const web::http::http_request & message);
  pplx::task<void> accept();
  pplx::task<void> shutdown();
  void handleGet(web::http::http_request message);
};

