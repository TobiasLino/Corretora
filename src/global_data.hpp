//
// TODO (tobias) : reorganizar as bibliotecas.
//
#ifndef CORRETORA_GLOBAL_Data_HPP_
#define CORRETORA_GLOBAL_Data_HPP_

#define FILE_CREATION_ERROR "ERROR::FILE CREATION FAILED"
#define FILE_READ_ERROR "ERROR::FILE DOES NOT EXISTS"

#include <iostream>
#include <string>
//
// Classe para abertura de arquivos
// Para classes com anexo de arquivos e a classe que salva os 
// dados em um arquivo
//
// Exemplo de inserção de dados do cliente em um novo arquivo:
//    Cliente cliente1;
//    std::string file_name = "client1.txt"
//    File file(file_name);
//    cliente1.WriteToFile(file);
//    file.Save();
//
template<typename Class_Type>
class File {
 public:
  File(std::string input_name) {
    this->file_name_ = input_name;
  }
  void OpenFile(std::string input_file) {
    file_.open(file_name_, std::ios::out);
    if (FileExists(input_file)) {
      FileCreationFailed();
      file.close();
    } else {
      CreateFile();
      CreationSuccess();
      file.close();
    }
  }
  void FileCreationFailed() {
    std::cout << FILE_CREATION_ERROR << std::endl
    << "Please repeat the operation or review the file name." << std::endl;
  }
  void FileNotExists() {
    std::cout << FILE_READ_ERROR << std::endl
    << "Please review the file name." << std::endl;
  }
  void Write(Class_Type input_data) {
    file_ << input_data;
    file_.close();
  }
  void Print() {
    std::string file_contents;
    file_.open(input_name, std::ios::in);
    if (FileExists(input_name)) {
      while (!file_.eof()) {
        file_ >> file_contents;
      }
      std::cout << file_contents << std::endl;
    } else {

    }
  }
  bool FileExists() {
    if (!file_) {
      FileNotExists();
      return false;
    } else {
      return true;
    }
  }
  void CreationSuccess() {
    std::cout << "FILE CREATION SUCCESS!" << std::endl
    << "Name: " << file_name_ << std::endl;
  }
 private:
  std::fstream file_;
  std::string file_name_;
};


class Contact {
 public:
  Contact() {
    this->phone_ = "";
    this->email_ = "";
  }
  void set_phone(std::string phone) {
    this->phone_ = phone;
  }
  void set_email(std::string email) {
    this->email_ = email;
  }
  std::string get_phone() {
    return phone_;
  }
  std::string get_email() {
    return email_;
  }
 private:
  std::string phone_;
  std::string email_;
};


#endif