# LaunchDarkly Sample C++ Client-Side Application
We've built a simple console application that demonstrates how LaunchDarkly's SDK works. Below, you'll find the basic build procedure, but for more comprehensive instructions, you can visit your [Quickstart page](https://app.launchdarkly.com/quickstart#/) or the [C/C++ SDK reference guide](https://docs.launchdarkly.com/sdk/client-side/c-c--).

## Build instructions
1. Edit `hello.cpp` and set the value of `mobile_key` to your LaunchDarkly mobile key. If there is an existing boolean feature flag in your LaunchDarkly project that you want to evaluate, set `feature_key` to the flag key.

```
const char *mobile_key = "YOUR_MOBILE_KEY";
const char *feature_key = "YOUR_FEATURE_KEY";
```

2. Download the latest SDK for your platform with `fetch-linux.sh`, `fetch-mac.command`, or `fetch-windows.ps1`.
3. Build for your platform with `build-linux.sh`, `build-mac.command`, or `build-windows.ps1`.
4. On the command line, run `./hello`.

You should see the message `"Feature flag '<flag key>' is <true/false> for this user"`.
