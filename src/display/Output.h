
#ifndef OUTPUT_H
#define OUTPUT_H



class Output {
public:
  Output() = default;
  virtual ~Output() = default;

  virtual void write_line(const std::string &output) = 0;
};



#endif //OUTPUT_H
