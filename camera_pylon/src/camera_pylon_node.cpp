#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace : std::camera_pylon;

class ClientReturn : public rclcpp::Node
{
    public:
    ClientReturn()
    : Node("ClientReturn"), count_(0)
    {
         publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
    }

    private:
    void timer_callback()
    {
    const readline = require('readline');

    const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
    });

    rl.question('Qual o tipo de mídia ', (midia) => {
    console.log(`Mídia escolhida, ${midia}!`);
    });
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    size_t count_;

};
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ClientReturn>());
  rclcpp::shutdown();
  return 0;
}
