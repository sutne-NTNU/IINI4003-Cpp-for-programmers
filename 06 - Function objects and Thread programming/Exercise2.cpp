#include <boost/asio.hpp>
#include <iostream>


using namespace std;
using namespace boost::asio;


class EchoServer {
private:
    class Connection {
    public:
        boost::asio::ip::tcp::socket socket;

        explicit Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };


    io_service io_service;
    ip::tcp::endpoint endpoint;
    ip::tcp::acceptor acceptor;

    void handle_request(const shared_ptr<Connection> &connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();

        // Read from client until newline ("\r\n")
        async_read_until(connection->socket, *read_buffer, "\r\n",
                         [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                             // If not error:
                             if(!ec) {
                                 // Retrieve message from client as string:
                                 istream read_stream(read_buffer.get());
                                 string message;
                                 getline(read_stream, message);
                                 message.pop_back(); // Remove "\r" at the end of message

                                 cout << "Message from a connected client: " << message << endl;

                                 if(message == "exit") return;

                                 if(message == "GET / HTTP/1.1") {
                                     writeToClient(connection, 200, "This is the main page");
                                     return;
                                 }
                                 if(message == "GET /a_page HTTP/1.1") {
                                     writeToClient(connection, 200, "This is a page");
                                     return;
                                 }
                                 writeToClient(connection, 404, "Error 404: page not found");
                             }
                         });
    }

    void writeToClient(const shared_ptr<Connection> &connection, int status, string content) {
        auto write_buffer = make_shared<boost::asio::streambuf>();
        ostream write_stream(write_buffer.get());

        string header;
        if(status == 404) {
            content = "<h1 style=\"color: red\">" + content + "</h1>\r\n";
            header = "HTTP/1.0 404 Not Found\r\n";
        } else {
            content = "<h1>" + content + "</h1>\r\n";
            header = "HTTP/1.0 " + std::to_string(status) + " OK\r\n";
        }
        header +=  "Content-Length: " + std::to_string(content.length()) + "\r\n"
                   "Content-Type: text/html;\r\n"
                   "charset=UTF-8\r\n"
                   "\r\n";

        write_stream << header << content;
        async_write(connection->socket,
                    *write_buffer,
                    [this, connection, write_buffer](const boost::system::error_code &ec,
                                                     size_t) {
                        if(!ec)
                            handle_request(connection);
                    });
    }

    void accept() {
        // The (client) connection is added to the lambda parameter and handle_request
        // in order to keep the object alive for as long as it is needed.
        auto connection = make_shared<Connection>(io_service);

        // Accepts a new (client) connection. On connection, immediately start accepting a new connection
        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            accept();

            // If not error:
            if(!ec) {
                handle_request(connection);
            }
        });
    }

public:
    EchoServer() : endpoint(ip::tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();
        io_service.run();
    }
};


int main() {
    EchoServer echo_server;
    cout << "Starting server on:\n"
            "   http://localhost:8080\n"
            "   http://localhost:8080/a_page\n"
            "   http://localhost:8080/doesnt_exist - Should result to 404: Not Found\n" << endl;
    echo_server.start();
}

