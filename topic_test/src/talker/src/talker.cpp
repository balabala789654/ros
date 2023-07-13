#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class talker : public rclcpp::Node{

	public:
		talker(std::string name):Node(name){
			RCLCPP_INFO(this->get_logger(), "talker is working");
			talker_publish = this->create_publisher<std_msgs::msg::String>("aaa", 10);
			time = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&talker::timer_callback, this));
		}
	private:
		void timer_callback(){
				std_msgs::msg::String msg;
				msg.data="helloworld";
				RCLCPP_INFO(this->get_logger(), "%s", msg.data.c_str());
				talker_publish->publish(msg);
		}
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr talker_publish;
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
