//TCP Async Server Connection Class
#pragma once

#define ASIO_STANDALONE
#include <asio.hpp>

#include <memory>

#include <utils.hpp>

class TAScon
  : public std::enable_shared_from_this<TAScon>
{
public:
  typedef std::shared_ptr<TAScon> pointer;

  static TAScon::pointer create(asio::io_context& io_context);
  //pointer create(asio::io_context& io_context);

  asio::ip::tcp::socket& socket();

  void start();

private:
  TAScon(asio::io_context& io_context)
    : socket_(io_context)
  {}

  void handle_write()
  {}

  asio::ip::tcp::socket socket_;
  std::string message_;
};