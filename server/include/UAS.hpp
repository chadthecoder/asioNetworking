//UDP Async Server
#pragma once

#define ASIO_STANDALONE
#include <asio.hpp>

#include <iostream>

#include <utils/utils.cpp>

class UAS
{
public:
  UAS(asio::io_context& io_context, asio::ip::port_type port_num);
  void start_receive();

private:
  void handle_receive(const asio::error_code& error,
      std::size_t /*bytes_transferred*/);

  void handle_send(std::shared_ptr<std::string> /*message*/,
      const asio::error_code& /*error*/,
      std::size_t /*bytes_transferred*/);

  asio::ip::udp::socket socket_;
  asio::ip::udp::endpoint remote_endpoint_;
  std::array<char, 128> recv_buffer_;
};