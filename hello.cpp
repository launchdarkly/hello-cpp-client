#include <launchdarkly/api.hpp>

const char *username = "jeff@example.com";

int main() {
    LDConfigureGlobalLogger(LD_LOG_INFO, LDBasicLogger);

    auto *config = LDConfigNew("YOUR_SDK_KEY");
    auto *user = LDUserNew(username);

    // wait up to 3 seconds to connect
    auto *client = LDClientCPP::Init(config, user, 3000);

    auto feature = client->boolVariation("YOUR_FEATURE_KEY", false);

    if (feature) {
        printf("My feature was enabled for %s\n", username);
    } else {
        printf("My feature was not enabled for %s\n", username);
    }

    // cleanup after ourselves
    client->close();
}