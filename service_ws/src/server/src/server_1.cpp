#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class server : public rclcpp::Node{

    public:
        server(std::string name):Node(name){
            RCLCPP_INFO(this->get_logger(), "server node start");
        }
    private:

};
int main(int argc, char *argv[])
{
    /* code */
    rclcpp::init(argc, argv);
    auto node = std::make_shared<server>("server");
    rclcpp::spin(node);
    
    return 0;
}
