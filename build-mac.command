c++ -target x86_64-apple-darwin21.1.0 -std=c++11 -Wall -o hello hello.cpp cpp/api.cpp -I include -I cpp/include -lcurl -framework CoreFoundation -framework IOKit -L lib -lldclientapi
