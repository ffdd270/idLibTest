#pragma once

#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

using boost::asio::ip::tcp;

class CTCP_Connection :
	public boost::enable_shared_from_this<CTCP_Connection>
{
public:
	typedef boost::shared_ptr<CTCP_Connection> pointer;

	static pointer Create(boost::asio::io_service & io_service)
	{
		return pointer(new CTCP_Connection(io_service));
	}

	tcp::socket& socket()
	{
		return sorket;
	}

	void Start();

	~CTCP_Connection();
private:
	tcp::socket sorket;
	std::string message;
	CTCP_Connection(boost::asio::io_service & io_service) : sorket(io_service)
	{
	}
	void handle_write(const boost::system::error_code &, size_t)
	{
	}
};
