#include <Arduino.h>
#include <Core/Application.h>

BenchBuddy::Application application;

void setup() {
  application.begin();
}

void loop() {
  application.update();
}
