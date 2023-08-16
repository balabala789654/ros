#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class server : public rclcpp::Node{

    public:
        server(std::string name):Node(name){
            RCLCPP_INFO(this->get_logger(), "server node start");
            service_server = this->create_service<example_interfaces::srv::AddTwoInts>("service_server", std::bind(&server::server_handle, this, std::placeholders::_1, std::placeholders::_2));
        }

    private:
        rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service_server;
        void server_handle(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request, 
                            std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response){
            RCLCPP_INFO(this->get_logger(), "request %ld %ld", request->a, request->b);
            response->sum = request->a + request->b;
        }


};
int main(int argc, char *argv[])
{
    /* code */
    rclcpp::init(argc, argv);
    auto node = std::make_shared<server>("server");
    rclcpp::spin(node);
    
    return 0;
}
