#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class listener : public rclcpp::Node{

    public:
        listener(std::string name):Node(name){
            RCLCPP_INFO(this->get_logger(), "listener is working");
            listener_sub = this->create_subscription<std_msgs::msg::String>("aaa", 10, std::bind(&listener::sub_callback, this, std::placeholders::_1));
        }
    private:
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr listener_sub;
        void sub_callback(const std_msgs::msg::String::SharedPtr massage){
            RCLCPP_INFO(this->get_logger(), "listener rec msg: %s", massage->data.c_str());
        }


};
int main(int argc, char *argv[])
{
    /* code */
    rclcpp::init(argc, argv);
    auto node = std::make_shared<listener>("listener");

    rclcpp::spin(node);
    return 0;
}
