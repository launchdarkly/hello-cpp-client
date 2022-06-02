#include <cstring>
#include <launchdarkly/api.hpp>

// Set MOBILE_KEY to your LaunchDarkly mobile key.
#define MOBILE_KEY "YOUR_MOBILE_KEY"

// Set FEATURE_KEY to the feature flag you want to evaluate.
#define FEATURE_KEY "YOUR_FEATURE_KEY"

int main() {

    if (strlen(MOBILE_KEY) == 0) {
        printf("*** Please edit hello.cpp to set MOBILE_KEY to your LaunchDarkly mobile key first\n\n");
        return 1;
    }

    LDConfigureGlobalLogger(LD_LOG_INFO, LDBasicLogger);

    auto *config = LDConfigNew(MOBILE_KEY);

    // Set up the user properties. This user should appear on your LaunchDarkly users dashboard
    // soon after you run the demo.
    auto *user = LDUserNew("example-user-key");
    LDUserSetName(user, "Sandy");

    // wait up to 3 seconds to connect
    auto *client = LDClientCPP::Init(config, user, 3000);

    if (client->isInitialized()) {
        printf("*** SDK successfully initialized!\n\n");
    } else {
        printf("*** SDK failed to initialize\n\n");
        return 1;
    }

    auto flag_value = client->boolVariation(FEATURE_KEY, false);

    printf("*** Feature flag '%s' is %s for this user\n\n", FEATURE_KEY, flag_value ? "true" : "false");

    // Here we ensure that the SDK shuts down cleanly and has a chance to deliver analytics
    // events to LaunchDarkly before the program exits. If analytics events are not delivered,
    // the user properties and flag usage statistics will not appear on your dashboard. In a
    // normal long-running application, the SDK would continue running and events would be
    // delivered automatically in the background.
    client->close();
}
