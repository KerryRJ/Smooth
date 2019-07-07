#pragma once

#include "responses/IRequestResponeOperation.h"
#include "IServerResponse.h"
#include <memory>

namespace smooth::application::network::http
{
    class MIMEParser;

    using RequestHandlerSignature = std::function<void(
            IServerResponse& response,
            const std::string& url,
            bool first_part,
            bool last_part,
            const std::unordered_map<std::string, std::string>& headers,
            const std::unordered_map<std::string, std::string>& request_parameters,
            const std::vector<uint8_t>& content,
            MIMEParser& mime
    )>;

}