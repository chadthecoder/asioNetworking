#include <TAScon.hpp>

TAScon::pointer TAScon::create(asio::io_context& io_context)
{
    return pointer(new TAScon(io_context));
}

asio::ip::tcp::socket& TAScon::socket()
{
    return socket_;
}

void TAScon::start()
{
    message_ = make_daytime_string();

    asio::async_write(socket_, asio::buffer(message_),
        std::bind(&TAScon::handle_write, shared_from_this()));
}