//TCP Async Server
#pragma once

#define ASIO_STANDALONE
#include <asio.hpp>

#include <iostream>

//#include <utils.hpp>
#include <TAScon.hpp>

class TAS
{
public:
  TAS(asio::io_context& io_context);

private:
  void start_accept();

  void handle_accept(TAScon::pointer new_connection,
      const asio::error_code& error);

  asio::io_context& io_context_;
  asio::ip::tcp::acceptor acceptor_;
};