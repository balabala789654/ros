#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
class server_client : public rclcpp::Node
{
    public:
        server_client(std::string name) : Node(name){   
            RCLCPP_INFO(this->get_logger(), "server_client node start");
        }
        void send_request(int a, int b){
            RCLCPP_INFO(this->get_logger(), "client_request");
            while(!client->wait_for_service(std::chrono::seconds(1))){
                if(!rclcpp::ok()){
                    RCLCPP_INFO(this->get_logger(), "broken");\
                    return ;
                }
                RCLCPP_INFO(this->get_logger(), "waitting");
            }
            auto request = std::make_shared<example_interfaces::srv::AddTwoInts_Request>();
            request->a = a;
            request->b = b;
            client->async_send_request(request, std::bind(&server_client::service_client_callback, this, std::placeholders::_1));
        }
    private:
        rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client;
        void service_client_callback(rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedFuture result_future){
            auto response = result_future.get();
            RCLCPP_INFO(this->get_logger(), "response %ld", response->sum);
        }


};
int main(int argc, char *argv[])
{
    /* code */
    rclcpp::init(argc, argv);
    auto node = std::make_shared<server_client>("client");
    
    while (rclcpp::ok(     ))
    {
        /* code */
        node->send_request(1, 2);
    }
    
    rclcpp::spin(node);

    return 0;
}
