#ifndef TOOLVISUALABCMENUDIALOG_H
#define TOOLVISUALABCMENUDIALOG_H

#include "menudialog.h"

namespace ribi {

struct VisualAbcMenuDialog final : public MenuDialog
{
  About GetAbout() const noexcept override;
  Help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override;
  std::vector<std::string> GetVersionHistory() const noexcept override;

  private:
  int ExecuteSpecific(const std::vector<std::string>& argv) noexcept override;
};

} //~namespace ribi

#endif // TOOLVISUALABCMENUDIALOG_H
