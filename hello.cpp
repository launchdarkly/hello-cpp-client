#include <string.h>
#include <launchdarkly/api.hpp>

// Set mobile_key to your LaunchDarkly mobile key.
const char *mobile_key = "";

// Set feature_key to the feature flag you want to evaluate.
const char *feature_key = "my-boolean-flag";

int main() {
    if (strlen(mobile_key) == 0) {
      printf("*** Please edit hello.cpp to set mobile_key to your LaunchDarkly mobile key first\n\n");
      return 1;
    }

    LDConfigureGlobalLogger(LD_LOG_INFO, LDBasicLogger);

    struct LDConfig *config = LDConfigNew(mobile_key);

    // Set up the user properties. This user should appear on your LaunchDarkly users dashboard
    // soon after you run the demo.
    struct LDUser *user = LDUserNew("example-user-key");
    LDUserSetName(user, "Sandy");

    // wait up to 3 seconds to connect
    LDClientCPP *client = LDClientCPP::Init(config, user, 3000);

    if (client->isInitialized()) {
        printf("*** SDK successfully initialized!\n\n");
    } else {
        printf("*** SDK failed to initialize\n\n");
        return 1;
    }

    auto flag_value = client->boolVariation(feature_key, false);

    printf("*** Feature flag '%s' is %s for this user\n\n", feature_key, flag_value ? "true" : "false");

    // Here we ensure that the SDK shuts down cleanly and has a chance to deliver analytics
    // events to LaunchDarkly before the program exits. If analytics events are not delivered,
    // the user properties and flag usage statistics will not appear on your dashboard. In a
    // normal long-running application, the SDK would continue running and events would be
    // delivered automatically in the background.
    client->close();
}
