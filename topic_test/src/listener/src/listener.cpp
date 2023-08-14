#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class listener : public rclcpp::Node{

    public:
        // 构造函数,有一个参数为节点名称
        listener(std::string name):Node(name){
            RCLCPP_INFO(this->get_logger(), "listener is working");
            // 创建一个订阅者订阅话题
            listener_sub = this->create_subscription<std_msgs::msg::String>("aaa", 10, std::bind(&listener::sub_callback, this, std::placeholders::_1));
        }
    private:
        // 声明一个订阅者
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr listener_sub;
        // 收到话题数据的回调函数
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
