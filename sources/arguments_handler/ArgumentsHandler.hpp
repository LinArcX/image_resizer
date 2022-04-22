#ifndef ARGUMENTS_HANDLER_HPP
#define ARGUMENTS_HANDLER_HPP

#include <iostream>

class ArgumentsHandler{

public:
  int handle_arguments(int argc, char** argv);

  void setRatio(float ratio) { this->ratio = ratio;}
  void setQuality(int quality) { this->quality = quality;}
  void setInput(std::string input) {this->input = input;}
  void setOutput(std::string output) { this->output = output; }
  void setAlgorithm(std::string algorithm) {this->algorithm = algorithm;}

  int getQuality() {return quality;}
  float getRatio() {return ratio;}
  std::string getInput() {return input;}
  std::string getOutput() {return output;}
  std::string getAlgorithm() {return algorithm;}

private:
  int quality = 100;
  float ratio = 1.0f;
  std::string output;
  std::string input;
  //std::string input = "/home/linarcx/saeed.png";
  //std::string output = "/home/linarcx/hamid.png";
  std::string algorithm = "bicubic";
};

#endif
