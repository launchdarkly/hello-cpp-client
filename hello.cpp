#include <launchdarkly/api.hpp>

const char *username = "jeff@example.com";

// update me to your own keys
const char *sdk_key = "YOUR_SDK_KEY";
const char *feature_key = "YOUR_FEATURE_KEY";

int main() {
    LDConfigureGlobalLogger(LD_LOG_INFO, LDBasicLogger);

    auto *config = LDConfigNew(sdk_key);
    auto *user = LDUserNew(username);

    // wait up to 3 seconds to connect
    auto *client = LDClientCPP::Init(config, user, 3000);

    auto feature = client->boolVariation(feature_key, false);

    if (feature) {
        printf("My feature was enabled for %s\n", username);
    } else {
        printf("My feature was not enabled for %s\n", username);
    }

    // cleanup after ourselves
    client->close();
}