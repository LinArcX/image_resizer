#include "InputOutput.hpp"

#include <string>
#include <vector>
#include <iostream>
#if defined(__APPLE__) || defined(__MACOSX) || defined(__linux__)
#include <fstream>
#elif defined(WIN32)
#include <windows.h>
#endif


char* InputOutput::data = 0;

bool InputOutput::readBinaryFile(const std::string& fileName)
{
  size_t size = 0;
  std::ifstream file;
  file.open(fileName.c_str(), std::ios::in | std::ios::binary);

  file.seekg(0, std::ios::end);
  size = file.tellg();
  file.seekg(0, std::ios::beg);

  data = new char[size - 8 + 1];
  //file.seekg(8); // skip the header
  file.read(data, size);
  //data[size] = '\0';
  return true;


// , std::vector<unsigned char>& data
//#if defined(WIN32)
//	DWORD dwBytesRead = 0;
//	HANDLE hFile = CreateFile(fileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//	unsigned long size = GetFileSize(hFile, NULL);
//	data.resize(size);
//	return ReadFile(hFile, (char*)(&(data)[0]), size, &dwBytesRead, NULL);
//#elif defined(__linux__)


  //size_t size = 0;
  //std::ifstream file;

  //file.open(fileName.c_str(), std::ios::in | std::ios::binary);
  ////char* data = 0;

  //file.seekg(0, std::ios::end);
  //size = file.tellg();
  //file.seekg(0, std::ios::beg);

  ////data = new char[size - 8 + 1];
  ////file.seekg(8); // skip the header
  //file.read(reinterpret_cast<unsigned char*>(data.data()), size);
  //file.close();

  ////data[size] = '\0';


  ////fileName = "/home/linarcx/saeed.txt";
  //std::ifstream in(fileName, std::ifstream::binary);

  //// reserve capacity
  //in.seekg(0, std::ios::end);
  ////data.reserve(in.tellg());
  //data.resize(in.tellg());
  //in.clear();
  //in.seekg(0, std::ios::beg);

  //// read into vector
  //// in.read(reinterpret_cast<char *>(data.data()), data.capacity());
  //in.read(reinterpret_cast<char *>(data.data()), data.size());

  //if(in)
  //    std::cout << "all content read successfully: " << in.gcount() << std::endl;
  //else
  //    std::cout << "error: only " << in.gcount() << " could be read" << std::endl;

  //in.close();
  //return true;
  /////////////////

  //std::ifstream input(fileName.c_str(), std::ios::binary );
  //std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});
  //return true;

    //// open the file:
    //std::ifstream file(fileName, std::ios::binary);

    //// Stop eating new lines in binary mode!!!
    //file.unsetf(std::ios::skipws);

    //// get its size:
    //std::streampos fileSize;

    //file.seekg(0, std::ios::end);
    //fileSize = file.tellg();
    //file.seekg(0, std::ios::beg);

    //// reserve capacity
    //std::vector<unsigned char> vec;
    //vec.reserve(fileSize);

    //// read the data:
    //vec.insert(vec.begin(),
    //           std::istream_iterator<unsigned char>(file),
    //           std::istream_iterator<unsigned char>());

  //std::ifstream file(fileName, std::ios::binary);
  //if(file)
  //{
  //  std::vector<unsigned char> saeed = std::vector<unsigned char>((std::istreambuf_iterator<char>(file)),
  //                          std::istreambuf_iterator<char>());
  //  return true;
  //}
  //return false;

//#elif defined(__APPLE__) || defined(__MACOSX)
//    FILE* file = std::fopen(fileName.c_str(), "rb");
//    if (file)
//    {
//        fseek(file, 0, SEEK_END);
//        long size = ftell(file);
//        rewind(file);
//        data.resize(size);
//
//        fread((char*)(&(data)[0]), 1, size, file);
//        fclose(file);
//        return true;
//    }
//
//	return false;
//#endif
}

#include <iterator>

// const std::vector<unsigned char>& data,
bool InputOutput::writeBinaryFile(const std::string& fileName, unsigned size)
{
  unsigned long length (data.size());
  if (size > 0)
  {
    length = size;
  }
//#if defined(WIN32)
//	DWORD dwBytesWritten = 0;
//	HANDLE hFile = CreateFile(fileName.c_str(), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
//	return WriteFile(hFile, (char*)(&(data)[0]), length, &dwBytesWritten, NULL);
//#elif defined(__linux__)
  //constexpr size_t amount = 4242;
  //char m_data[amount];
  //std::ifstream  src("from.bn", std::ios::binary);
  //std::ofstream file(fileName, std::ios::out | std::ios::binary);
  //file.write(reinterpret_cast<unsigned char>(data), 20);


  //std::ofstream file(fileName.c_str(), std::ios::out|std::ios::binary);
  //std::copy(data.cbegin(), data.cend(), std::ostream_iterator<unsigned char>(file));
  std::ofstream file(fileName.c_str(), std::ios::out | std::ios::binary);
  file.write((char*)(&(data)[0]), size);
  file.close();
  return true;
//#elif defined(__APPLE__) || defined(__MACOSX)
//  FILE* file = std::fopen(fileName.c_str(), "wb");
//  if (file)
//  {
//    fwrite((char*)(&(data)[0]), 1, length, file);
//    fclose(file);
//    return true;
//  }
//
//	return false;
//#endif
}
