/*
* FileAppender.cpp
* Created on: 28/8/2024
* aurthor : Moin Shaikh
*/
#define _CRT_SECURE_NO_WARNINGS


#include"FileAppender.hpp"
#include"LogLevels.hpp"

#include<ios>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<chrono>
#include<cstdint>
using std::string;
using std::cout;
using std::ios_base;
using std::ostringstream;
using std::chrono::system_clock;
using std::chrono::duration;
using std::chrono::duration_cast;


namespace logging {


	FileAppender::FileAppender(LogLevel LogLevel, string fileName) : Appender(logLevel) {
		file.open(fileName, std::ios::out);
		if (!file.is_open()) {
			throw ios_base::failure("Error: Could not open or create log-file: " + fileName);

		}
		file << getCurrentTime() << "Starting logging at log-level " << logLevelToString(LogLevel) << "to file" << fileName << "\n";

	}

	FileAppender::~FileAppender()
	{
		file.close();
	}
	void FileAppender::log(const LogLevel logLevel, const string loggerName, const string logMessage) {
	if (logLevel <= this->logLevel)
		file << getCurrentTime() << ' ' << logLevelToString(logLevel) << ' ' << "[" << loggerName << "] " << logMessage << std::endl;
	}

	string FileAppender::getCurrentTime()
	{
		system_clock::time_point now = system_clock::now();
		duration<int64_t, std::ratio<1>> seconds = duration_cast<duration<int64_t, std::ratio<1>>>(now.time_since_epoch());
		duration<int64_t, std::milli> milliseconds = duration_cast<duration<int64_t, std::milli>>(now.time_since_epoch());
		duration<int64_t, std::milli> msec = milliseconds - seconds;

		std::time_t t_now = system_clock::to_time_t(now);
		struct tm* tm_now = std::localtime(&t_now);
		ostringstream os;
		os.fill('0');
		os << (1900 + tm_now->tm_year) << '-' << std::setw(2) << (1 + tm_now->tm_mon) << '-' << std::setw(2) << tm_now->tm_mday;
		os << ' ' << std::setw(2) << tm_now->tm_hour << ':' << std::setw(2) << tm_now->tm_min << ':' << std::setw(2) << tm_now->tm_sec;
		os << '.' << std::setw(3) << msec.count();
		return os.str();
	}

}


