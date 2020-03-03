#include "Controller.hpp"

Controller::Controller(){
  web::uri_builder endpointBuilder;
  endpointBuilder.set_host(m_address);
  endpointBuilder.set_port(m_port);
  endpointBuilder.set_scheme("http");
  endpointBuilder.set_path(m_endpoint);
  m_listener = web::http::experimental::listener::http_listener(endpointBuilder.to_uri());

}

pplx::task<void> Controller::accept() {
  initRestOpHandlers();
  return m_listener.open(); //server starts  at this moment
}
pplx::task<void> Controller::shutdown() {
  return m_listener.close(); //kills serverx
}

void Controller::initRestOpHandlers(){
  m_listener.support(web::http::methods::GET,std::bind(&Controller::handleGet,this,
					   std::placeholders::_1));
}

std::vector<utility::string_t> Controller::requestPath(const web::http::http_request& message)
{
  auto relativePath = web::http::uri::decode(message.relative_uri().path());
  return web::http::uri::split_path(relativePath);
}

void Controller::handleGet(web::http::http_request message) {
  std::vector<std::string> path = requestPath(message);
  for (auto const& s : path)
    std::cout << s << std::endl;
  if(path[0]=="welcome") {
    message.reply(web::http::status_codes::OK,"Hello World!\n");
  }

  else {
    message.reply(web::http::status_codes::NotFound);
  }
    
}
