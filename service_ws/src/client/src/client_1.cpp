#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
class server_client : public rclcpp::Node
{
    public:
        server_client(std::string name) : Node(name){   
            // 构造函数,有一个参数为节点名称
            RCLCPP_INFO(this->get_logger(), "server_client node start");
            // 创建客户端
            client = this->create_client<example_interfaces::srv::AddTwoInts>("service_server");
        }
        void send_request(int a, int b){
            RCLCPP_INFO(this->get_logger(), "client_request");
            // 1.等待服务端上线
            while(!client->wait_for_service(std::chrono::seconds(1))){
                //等待时检测rclcpp的状态
                if(!rclcpp::ok()){
                    RCLCPP_INFO(this->get_logger(), "broken");
                    return ;
                }
                RCLCPP_INFO(this->get_logger(), "waitting");
            }
            // 2.构造请求的
            auto request = std::make_shared<example_interfaces::srv::AddTwoInts_Request>();
            request->a = a;
            request->b = b;
            // 3.发送异步请求，然后等待返回，返回时调用回调函数
            client->async_send_request(request, std::bind(&server_client::service_client_callback, this, std::placeholders::_1));
        }
    private:
        // 声明客户端
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
    /*创建对应节点的共享指针对象*/
    auto node = std::make_shared<server_client>("client");
    /* 运行节点，并检测退出信号*/
    rclcpp::Rate r(1);
    int a=3; int b=6;

    while (rclcpp::ok())
    {
        node->send_request(a++, b++);
        r.sleep();
    }
    rclcpp::spin(node);
    return 0;
}
