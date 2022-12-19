#include <curl/curl.h>
#include <string>

class Request
{
public:
    static std::string get(const std::string &url)
    {
        return send_request("GET", url, "", "");
    }

    static std::string post(const std::string &url, const std::string &data)
    {
        return send_request("POST", url, data, "application/x-www-form-urlencoded");
    }

    static std::string put(const std::string &url, const std::string &data)
    {
        return send_request("PUT", url, data, "application/x-www-form-urlencoded");
    }

    static std::string del(const std::string &url)
    {
        return send_request("DELETE", url, "", "");
    }

    static std::string send_request(const std::string &method,
                                    const std::string &url,
                                    const std::string &data,
                                    const std::string &content_type)
    {
        CURL *curl = curl_easy_init();
        if (!curl)
        {
            return "";
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(cif (method == "POST" || method == "PUT" || method == "DELETE") {
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
            if (!content_type.empty())
            {
                struct curl_slist *headers = NULL;
                std::string header = "Content-Type: " + content_type;
                headers = curl_slist_append(headers, header.c_str());
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
            }

            std::string response;
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK)
            {
                return "";
            }

            curl_easy_cleanup(curl);
            return response;
        }
    }

private:
    static size_t write_callback(char *ptr, size_t size, size_t nsize, void *userdata)
    {
        std::string *response = static_caststd::string * (userdata);
        response->append(ptr, size * nmemb);
        return size * nmemb;
    };
}
