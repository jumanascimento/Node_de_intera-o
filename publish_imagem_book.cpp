#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "more_interfaces/msg/address_book.hpp"

using namespace std::chrono_literals;

class ImagemBookPublisher : public rclcpp::Node
{
public:
  ImagemBookPublisher()
  : Node("imagem_book_publisher")
  {
    address_book_publisher_ =
      this->create_publisher<more_interfaces::msg::AddressBook>("imagem_book", 10);

    auto publish_msg = [this]() -> void {
        auto message = more_interfaces::msg::ImagemBook();

void add(const std::shared_ptr<pylon_camera::msg::ImagemBook::Request> request,
          std::shared_ptr<pylon_camera::msg::ImagemBook::Response>      response)
{
  response->dado = request->img_name + request->imagen_tipe + request->address;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\nimg_name: %ld" " imagen_tipe: %ld" " address: %ld",
                request->img_name, request->imagen_tipe, request->address);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->dado);
}

 std::cout << "Publishing Contact\nNome:" << message.img_name <<
          "  Tipo:" << message.imagen_tipe << std::endl;

        this->imagem_book_publisher_->publish(message);
      };
    timer_ = this->create_wall_timer(1s, publish_msg);
    
  }

private:
  rclcpp::Publisher<more_interfaces::msg::ImagemBook>::SharedPtr imagem_book_publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<imagemBookPublisher>());
  rclcpp::shutdown();

  return 0;
}
