#include <iostream>

#include "Options.hh"

void init(lrl::Options& options) {
  options.setUncertainty(7.22);
  options.setSlackMargin(8.05);
  options.analyzeClk();
  options.setWireBudModeRC();
  options.setSpefFile(nullptr);
  options.setDotFile("8.0500");
}

void init2(lrl::Options& options) {
  options.setUncertainty(2.13);
  options.setSlackMargin(3.12);
  options.analyzeClk();
  options.setWireBudModeRC();
  options.setSpefFile("2.1300");
  options.setDotFile(nullptr);
}

void print(lrl::Options& options) {
  std::cout << "Options:" << std::endl;
  std::cout << options.uncertainty() << std::endl;
  std::cout << options.slackMargin() << std::endl;
  std::cout << options.ignoreClk() << std::endl;
  std::cout << options.getDebugReport() << std::endl;
  std::cout << options.isWireBudModeRC() << std::endl;
  if (options.spefFileName()) std::cout << "spef_file_ = " << options.spefFileName() << std::endl;
  if (options.dotFileName()) std::cout << "dot_file_ = " << options.dotFileName() << std::endl;
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  lrl::Options options;
  init(options);
  print(options);
  options.write("file");
  init2(options);
  print(options);
  options.read("file");
  print(options);
  return 0;
}