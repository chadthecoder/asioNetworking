#include <TAS.hpp>

TAS::TAS(asio::io_context& io_context)
    : io_context_(io_context),
      acceptor_(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 1025))
{
    start_accept();
}

void TAS::start_accept()
{
    TAScon::pointer new_connection =
      TAScon::create(io_context_);

    acceptor_.async_accept(new_connection->socket(),
        std::bind(&TAS::handle_accept, this, new_connection,
          std::placeholders::_1));
}

void TAS::handle_accept(TAScon::pointer new_connection,
      const asio::error_code& error)
{
    if (!error)
    {
      new_connection->start();
    }

    start_accept();
}