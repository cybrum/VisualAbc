
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <stdexcept>
#include <fstream>

#include "fileio.h"
#include "visualabccheckprerequisites.h"

ribi::CheckPrerequisites::CheckPrerequisites()
{
  CheckAbc2midi();
  CheckAbcm2ps();
  CheckConvert();
  CheckPlaysound();
}

void ribi::CheckPrerequisites::CheckAbc2midi() const
{
  const std::string s { fileio::FileIo().GetTempFileName() };
  assert(!fileio::FileIo().IsRegularFile(s));
  const std::string cmd {
    "abc2midi > " + s
  };
  const int result
    = std::system(cmd.c_str());
  if (result != 0)
  {
    throw std::runtime_error(
      "\'abc2midi\' not present. "
      "Type \'sudo apt-get install abcmidi\' to install");
  }
  fileio::FileIo().DeleteFile(s);
  assert(!fileio::FileIo().IsRegularFile(s));
}

void ribi::CheckPrerequisites::CheckAbcm2ps() const
{
  const std::string s { fileio::FileIo().GetTempFileName() };
  assert(!fileio::FileIo().IsRegularFile(s));
  const std::string cmd {
    "abcm2ps > " + s
  };
  const int result
    = std::system(cmd.c_str());
  if (result != 0)
  {
    throw std::runtime_error(
      "\'abcm2ps\' not present. "
      "Type \'sudo apt-get install abcm2ps\' to install");
  }

  fileio::FileIo().DeleteFile(s);
  assert(!fileio::FileIo().IsRegularFile(s));
}

void ribi::CheckPrerequisites::CheckConvert() const
{
  const std::string s { fileio::FileIo().GetTempFileName() };
  assert(!fileio::FileIo().IsRegularFile(s));
  const std::string cmd {
    "convert --help > " + s
  };
  const int result
    = std::system(cmd.c_str());
  if (result != 0)
  {
    //FileExists("tmp.txt"))
    throw std::runtime_error(
      "\'convert\' not present. "
      "Type \'sudo apt-get install imagemagick\' to install");
  }
  fileio::FileIo().DeleteFile(s);
  assert(!fileio::FileIo().IsRegularFile(s));
}

void ribi::CheckPrerequisites::CheckPlaysound() const
{
  const std::string s { fileio::FileIo().GetTempFileName() };
  assert(!fileio::FileIo().IsRegularFile(s));
  const std::string cmd {
    "timidity --version > " + s
  };
  const int error
    = std::system(cmd.c_str());
  if (error || !fileio::FileIo().IsRegularFile(s))
  {
    assert(error);
    throw std::runtime_error(
      "\'timidity\' not present. "
      "Type \'sudo apt-get install timidity\' to install");
  }
  fileio::FileIo().DeleteFile(s);

  assert(!fileio::FileIo().IsRegularFile(s));
}
