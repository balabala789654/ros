#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class talker : public rclcpp::Node{

	public:
		// 构造函数,有一个参数为节点名称
		talker(std::string name):Node(name){
			RCLCPP_INFO(this->get_logger(), "talker is working");
			talker_publish = this->create_publisher<std_msgs::msg::String>("aaa", 10);
			// 创建定时器，500ms为周期，定时发布
			time = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&talker::timer_callback, this));
		}
	private:
		void timer_callback(){
				// 创建消息
				std_msgs::msg::String msg;
				msg.data="helloworld";
				// 日志打印
				RCLCPP_INFO(this->get_logger(), "%s", msg.data.c_str());
				// 发布消息
				talker_publish->publish(msg);
		}
		// 声明话题发布者指针
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr talker_publish;
		// 声名定时器指针
		rclcpp::TimerBase::SharedPtr time;


};

int main(int argc, char *argv[])
{
	/* code */
	rclcpp::init(argc, argv);
	auto node = std::make_shared<talker>("talker");

	//rclcpp::Rate r(10);
	
	rclcpp::spin(node);
	//r.sleep();
	return 0;
}
