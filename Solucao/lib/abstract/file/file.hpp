// Copyright 2020 Tobias
#ifndef SOLUCAO_LIB_ABSTRACT_FILE_HPP_
#define SOLUCAO_LIB_ABSTRACT_FILE_HPP_

#include <fstream>
#include <string>

template<class Data_type>
class File {
 public:
  File();
  virtual ~File();
  void Open(std::string input_file) = 0;
  void Write(Data_type input_data) = 0;
  void Print() = 0;
  bool FileExists() = 0;
  void CreationSuccess() = 0;
  void CreationFailed() = 0;
 protected:
  std::fstream file_;
  std::string file_name;
};

extern "C" {
  typedef File *F_load_t();
  typedef void F_unload_t(File *);
}

#endif  // SOLUCAO_LIB_ABSTRACT_FILE_HPP_
