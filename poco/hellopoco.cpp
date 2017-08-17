#include <iostream>
#include <Poco/Util/Application.h>
#include <Poco/Process.h>

// Based on documentation from:
// https://pocoproject.org/docs/package-Foundation.Processes.html
// https://pocoproject.org/slides/150-Processes.pdf

class HelloPocoApplication : public Poco::Util::Application
{
protected:
  virtual int main(const std::vector<std::string> &args)
  {
    std::cout << "Hello, POCO C++ Libraries!" << std::endl;
    
    std::string cmd("/usr/bin/touch");
    std::vector<std::string> pargs;
    pargs.push_back("-f");  // Does nothing. Just for the sake of demonstration.
    pargs.push_back("testfile.txt");
    std::string dir("/home/dmc");
    
    Poco::ProcessHandle ph = Poco::Process::launch(cmd, pargs, dir);
    
    std::cout << "Process started. Waiting..." << std::endl;
    Poco::Process::wait(ph);
    std::cout << "All done!" << std::endl;
    
    return EXIT_OK;
  }
};

POCO_APP_MAIN(HelloPocoApplication);
