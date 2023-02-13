#include "SOptions.pb.h"

namespace lrl {

class Options
{
 public:
  // getter
  float uncertainty() { return uncertainty_; }
  float slackMargin() { return slack_margin_; }

  bool ignoreClk() { return ignore_clk_; }
  bool getDebugReport() { return debug_report_; }
  bool isWireBudModeRC() { return wire_bud_mode_rc_; }

  const char* spefFileName() const { return spef_file_; }
  const char* dotFileName() const { return dot_file_; }

  // setter
  void setUncertainty(float uncertainty) { uncertainty_ = uncertainty; }
  void setSlackMargin(float slack_margin) { slack_margin_ = slack_margin; }

  void analyzeClk() { ignore_clk_ = false; }
  void debugReport() { debug_report_ = true; }
  void setWireBudModeRC() { wire_bud_mode_rc_ = true; }
  void resetWireBudMode() { wire_bud_mode_rc_ = false; }

  void setSpefFile(const char* file_name) { spef_file_ = file_name; }
  void setDotFile(const char* file_name) { dot_file_ = file_name; }

  void write_soptions(SOptions& soptions) const;
  void write(const char* file) const;
  void read_soptions(SOptions& soptions);
  void read(const char* file);

  // checkers
  bool hasSpefFile() { return spef_file_; }

 private:
  float uncertainty_ = 0.05f;
  float slack_margin_ = 0.0f;

  bool ignore_clk_ = true;
  bool debug_report_ = false;
  bool wire_bud_mode_rc_ = false;

  const char* spef_file_ = nullptr;
  const char* dot_file_ = nullptr;
};

}  // namespace lrl