
# Request Library

The Request library is a simple C++ library that provides basic HTTP request functionality using the `curl` library. It includes support for making `GET`, `POST`, `PUT`, and `DELETE` requests.

## Usage

To use the library, include the header file in your project and create an instance of the `Request` class. Then, call the appropriate function for the type of request you want to make:
```cpp
#include "request.h"

int main() {
  // Make a GET request
  std::string response = Request::get("https://www.example.com");

  // Make a POST request
  std::string data = "key=value";
  std::string response = Request::post("https://www.example.com", data);

  // Make a PUT request
  std::string data = "key=value";
  std::string response = Request::put("https://www.example.com", data);

  // Make a DELETE request
  std::string response = Request::del("https://www.example.com");

  return 0;
}
```

## Advanced Usage

The library also includes a `send_request` function that allows you to specify the method and any additional data or headers for the request:

```cpp
std::string Request::send_request(const std::string& method,
                                  const std::string& url,
                                  const std::string& data,
                                  const std::string& content_type);
```

For example, to make a `POST` request with a JSON payload and a custom `Content-Type` header, you can use the following code:
```cpp
std::string data = "{\"key\":\"value\"}";
std::string response = Request::send_request("POST", "https://www.example.com", data, "application/json");
```
