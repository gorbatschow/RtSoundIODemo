#include <RtSoundClient.h>
#include <RtSoundIO.h>
#include <chrono>
#include <cmath>
#include <thread>

class SineGenerator : public RtSoundClient {
  const int _channel{0};
  const float _frequency{1e3};
  const float _amplitude{0.5f};

  void configureStream(RtSoundSetup &setup) override {
    setup.setOutputEnabled(true);
    setup.setOutputChannels(1);
  }

  void streamDataReady(const RtSoundData &data) override {
    const auto dt = streamSetup().timeResolution();
    auto t{data.streamTime()};
    const auto buffer{data.outputBuffer(_channel)};
    for (int i = 0; i != data.framesN(); ++i) {
      buffer[i] = _amplitude * cos(2.0f * M_PI * _frequency * t);
      t += dt;
    }
  }
};

int main(int argc, char **argv) {
  using namespace std::chrono_literals;

  const auto gen{std::make_shared<SineGenerator>()};
  auto io{RtSoundIO()};
  io.addClient(gen);
  io.startSoundStream();
  std::this_thread::sleep_for(1s);
  io.stopSoundStream();

  return 0;
}
