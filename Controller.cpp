#include "Controller.hh"

Controller::Controller(){
  endpointBuilder.set_host(_address);
  endpointBuilder.set_port(_port);
  endpointBuilder.set_scheme("http");
  endpointBuilder.set_path(_end_point);
  _listener = http_listener(endpointBuilder.to_uri());

}

pplx::task<void> Controller::accept() {
    initRestOpHandlers();
    return _listener.open(); //server starts form at this moment
}
pplx::task<void> Controller::shutdown() {
  return _listener.close(); //kills server
}

void Controller::initRestOpHandlers(){
  _listener.support(methods::GET,std::bind(&Controller::handleGet,this,
					   std::placeholders::_1));
}

std::vector<utility::string_t> Controller::requestPath(const http_request& message)
{
    auto relativePath = uri::decode(message.relative_uri().path());
    return uri::split_path(relativePath);
}

void Controller::handleGet(http_request message) {
  vector<string> path = requestPath(message);

  if(path[0]=="welcome") {
    message.reply(status_codes::OK,"Hello World!\n");
  }

  else {
    message.reply(status_codes::BadRequest);
  }
    
}
