#include "psub2-2/pub.hpp"

Pub::Pub() : Node("mypub"), count_(0)
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    pub_ = this->create_publisher<geometry_msgs::msg::Vector3>("mytopic", qos_profile);
    timer_ = this->create_wall_timer(1s, std::bind(&Pub::publish_msg, this));
}
void Pub::publish_msg()
{
    static double x = 0, y = 0, z = 0;
    geometry_msgs::msg::Vector3 msg;
    msg.x = x++;
    msg.y = y++;
    msg.z = z++;
    RCLCPP_INFO(this->get_logger(), "x: %lf y: %lf z: %lf\n", msg.x, msg.y, msg.z);
    pub_->publish(msg);
}