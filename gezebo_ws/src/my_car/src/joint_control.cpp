#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

using sensor_msgs::msg::JointState;
class joint_control_node : public rclcpp::Node
{
private:
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_control_publisher;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr joint_control_sub;

    rclcpp::TimerBase::SharedPtr timer;

    void topic_public_callback(){
        // auto jointstate = JointState();

        sensor_msgs::msg::JointState jointstate;
        jointstate.velocity.push_back(1.0);
        RCLCPP_INFO(this->get_logger(), "123");
        joint_control_publisher->publish(jointstate);
        
    }

    void topic_sub_callback(){

    }
public:
    joint_control_node() : Node("joint_control_node"){
        RCLCPP_INFO(this->get_logger(), "start");
        joint_control_publisher = this->create_publisher<sensor_msgs::msg::JointState>("/joint_states", 10);
        // joint_control_sub = this->create_subscription<sensor_msgs::msg::JointState>("/joint_states", 10, std::bind(&joint_control_node::topic_sub_callback, this, std::placeholders::_1));
        timer = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&joint_control_node::topic_public_callback, this));
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    
    rclcpp::spin(std::make_shared<joint_control_node>());
    rclcpp::shutdown();
    return 0;

}
