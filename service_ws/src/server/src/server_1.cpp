#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class server : public rclcpp::Node{

    public:
        // 构造函数,有一个参数为节点名称
        server(std::string name):Node(name){
            RCLCPP_INFO(this->get_logger(), "server node start");
            // 创建服务
            service_server = this->create_service<example_interfaces::srv::AddTwoInts>("service_server", std::bind(&server::server_handle, this, std::placeholders::_1, std::placeholders::_2));
        }

    private:
         // 声明一个服务
        rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service_server;
        // 收到请求的处理函数
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
    /*创建对应节点的共享指针对象*/
    auto node = std::make_shared<server>("server");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    // while (rclcpp::ok())
    // {
    //     /* code */
    // }
    
    return 0;
}
