#include "Options.hh"

#include <fstream>
#include <iostream>
#include <string>

namespace lrl {

void Options::write_soptions(SOptions& soptions) const {
  soptions.set_uncertainty_(uncertainty_);
  soptions.set_slack_margin_(slack_margin_);
  soptions.set_ignore_clk_(ignore_clk_);
  soptions.set_debug_report_(debug_report_);
  soptions.set_wire_bud_mode_rc_(wire_bud_mode_rc_);
  if (spef_file_) soptions.set_spef_file_(spef_file_);
  if (dot_file_) soptions.set_dot_file_(dot_file_);
}

void Options::read_soptions(SOptions& soptions) {
  uncertainty_ = soptions.uncertainty_();
  slack_margin_ = soptions.slack_margin_();
  ignore_clk_ = soptions.ignore_clk_();
  debug_report_ = soptions.debug_report_();
  wire_bud_mode_rc_ = soptions.wire_bud_mode_rc_();
  if (soptions.spef_file_().size())
    spef_file_ = (char*)soptions.spef_file_().c_str();
  else
    spef_file_ = nullptr;
  if (soptions.dot_file_().size())
    dot_file_ = (char*)soptions.dot_file_().c_str();
  else
    dot_file_ = nullptr;
}

void Options::write(const char* file) const {
  if (!file || file == "") {
    std::cerr << "Usage: FILE" << std::endl;
    return;
  }

  SOptions soptions;
  std::fstream input(file, std::ios::in | std::ios::binary);
  if (!input) {
    std::cout << file << ": File not found.  Creating a new file." << std::endl;
  }

  write_soptions(soptions);
  std::fstream output(file, std::ios::out | std::ios::trunc | std::ios::binary);
  if (!soptions.SerializeToOstream(&output)) {
    std::cerr << "Failed to write file." << std::endl;
    return;
  }
}

void Options::read(const char* file) {
  if (!file || file == "") {
    std::cerr << "Usage: FILE" << std::endl;
    return;
  }

  SOptions soptions;
  std::fstream input(file, std::ios::in | std::ios::binary);
  if (!soptions.ParseFromIstream(&input)) {
    std::cerr << "Failed to parse file." << std::endl;
    return;
  }

  read_soptions(soptions);
}

}  // namespace lrl
