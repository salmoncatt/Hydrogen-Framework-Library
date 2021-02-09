
#ifndef HFL_STRING_HEADER_INCLUDE
#define HFL_STRING_HEADER_INCLUDE

#include "MemoryUtil.h"
#include "vector.h"

namespace HGE {

	class string {
	private:
		//the size of the character string (useful later)
		size_t size;

		//the character data array
		char* data;

		void __cleanup__() {
			if (data != nullptr)
				delete[] data;
			size = 0;
		}

	public:
		
		static const size_t npos = -1;

		/*
		* Creates a new empty string
		* 
		* @author Salmoncatt
		*/
		string() : size(0), data(nullptr) {
			data = new char[1];
			data[0] = '\0';
		}

		/*
		* Copies a string from another one
		*
		* @param The source string to copy from
		* 
		* @author Salmoncatt
		*/
		string(const string& source) : size(0) {
			//set size
			size = source.size;
			
			//allocate string data into memory
			data = new char[size + 1];

			//copy the source data over using my own library :)
			strcpy(data, source.data);

			//in case the data isn't null terminated for some reason
			if (data[size] != '\0')
				data[size] = '\0';
		}

		/*
		* Creates a string from character data
		*
		* @param Character array
		*
		* @author Salmoncatt
		*/
		string(char* source) : size(0) {
			//get size
			size = strlen(source);
			
			//allocate data size
			data = new char[size + 1];
			
			//copy the source data over using my own library :)
			strcpy(data, source);

			//in case the data isn't null terminated for some reason
			if (data[size] != '\0')
				data[size] = '\0';
		}

		/*
		* Creates a string from character data
		*
		* @param Character array
		*
		* @author Salmoncatt
		*/
		string(const char* source) : size(0) {
			//set size
			size = strlen(source);

			//allocate string data into memory
			data = new char[size + 1];

			//copy the source data over using my own library :)
			strcpy(data, source);

			//in case the data isn't null terminated for some reason
			if(data[size] != '\0')
				data[size] = '\0';
		}

		/*
		* Creates a string from a character
		*
		* @param Character array
		*
		* @author Salmoncatt
		*/
		string(const char& source) : size(1) {

			if (source != '\0') {
				//allocate memory for data
				data = new char[size + 1];

				//put in the character and null terminator character
				data[0] = source;
				data[1] = '\0';
			}
			else {
				//allocate memory for data
				data = new char[size];
				data[0] = '\0';
			}

		}


		/*
		* Copies a string from another one
		*
		* @param The source string to copy from
		*
		* @author Salmoncatt
		*/
		string& operator=(const string& source) {
			//cleanup if memory is allocated
			__cleanup__();

			//set size
			size = source.size;

			//allocate string data into memory
			data = new char[size + 1];

			//copy the source data over using my own library :)
			strcpy(data, source.data);

			//in case the data isn't null terminated for some reason
			if (data[size] != '\0')
				data[size] = '\0';

			return *this;
		}

		/*
		* Creates a string from character data
		*
		* @param Character array
		*
		* @author Salmoncatt
		*/
		string& operator=(char* source) {

			__cleanup__();

			//get size
			size = strlen(source);

			//allocate data size
			data = new char[size + 1];

			//copy the source data over using my own library :)
			strcpy(data, source);

			//in case the data isn't null terminated for some reason
			if (data[size] != '\0')
				data[size] = '\0';

			return *this;
		}

		/*
		* Creates a string from a character
		*
		* @param Character array
		*
		* @author Salmoncatt
		*/
		string& operator=(const char& source) {

			__cleanup__();

			//set size to one character
			size = 1;

			if (source != '\0') {
				//allocate memory for data
				data = new char[size + 1];

				//put in the character and null terminator character
				data[0] = source;
				data[1] = '\0';
			}
			else {
				//allocate memory for data
				data = new char[size];
				data[0] = '\0';
			}

			return *this;
		}

		/*
		* Creates a string from character data
		*
		* @param Character array
		*
		* @author Salmoncatt
		*/
		string& operator=(const char* source) {

			__cleanup__();

			//set size
			size = strlen(source);

			//allocate string data into memory
			data = new char[size + 1];

			//copy the source data over using my own library :)
			strcpy(data, source);

			//in case the data isn't null terminated for some reason
			if (data[size] != '\0')
				data[size] = '\0';

			return *this;
		}

		/*
		* Adds a strings data to current one
		*
		* @param The source string to add from
		*
		* @author Salmoncatt
		*/
		string operator+(const string& source) {
			//create the output string
			string out = string();

			//delete the allocated memory
			out.__cleanup__();

			//set the size
			out.size = size + source.size;

			//allocate memory to the outputs data buffer
			out.data = new char[out.size + 1];

			//copy the source data over using my own library :)
			strcpy(out.data, data); //copy first string
			strcpy(out.data + size, source.data); //copy second string

			//in case the data isn't null terminated for some reason
			if (out.data[size] != '\0')
				out.data[size] = '\0';

			return out;
		}

		friend string operator+(const char* left, const string& right) {
			return string(left) + right;
		}

		/*
		* Adds a string of characters to this string
		*
		* @param The characters to add from
		*
		* @author Salmoncatt
		*/
		string operator+(const char* source) {
			//create the output string
			string out = string();

			//delete the allocated memory
			out.__cleanup__();

			//set the size
			out.size = size + strlen(source);

			//allocate memory to the outputs data buffer
			out.data = new char[out.size + 1];

			//copy the source data over using my own library :)
			strcpy(out.data, data); //copy first string
			strcpy(out.data + size, source); //copy second string

			//in case the data isn't null terminated for some reason
			if (out.data[out.size] != '\0')
				out.data[out.size] = '\0';

			return out;
		}

		/*
		* Adds a string of characters to this string
		*
		* @param The characters to add from
		*
		* @author Salmoncatt
		*/
		string operator+(char* source) {
			//create the output string
			string out = string();

			//delete the allocated memory
			out.__cleanup__();

			//set the size
			out.size = size + strlen(source);

			//allocate memory to the outputs data buffer
			out.data = new char[out.size + 1];

			//copy the source data over using my own library :)
			strcpy(out.data, data); //copy first string
			strcpy(out.data + size, source); //copy second string

			//in case the data isn't null terminated for some reason
			if (out.data[out.size] != '\0')
				out.data[out.size] = '\0';

			return out;
		}

		/*
		* Adds a character to this string
		*
		* @param The character to add from
		*
		* @author Salmoncatt
		*/
		string operator+(char& source) {
			//create the output string
			string out = string();

			//delete the allocated memory
			out.__cleanup__();

			//set the size
			out.size = size + 1;

			//allocate memory to the outputs data buffer
			out.data = new char[out.size + 1];

			//copy the source data over using my own library :)
			strcpy(out.data, data); //copy first string

			out.data[size - 1] = source;

			//in case the data isn't null terminated for some reason
			if (out.data[out.size] != '\0')
				out.data[out.size] = '\0';

			return out;
		}

		/*
		* Returns the character at a the index specified.
		*
		* @param The index for the character
		*
		* @author Salmoncatt
		*/
		char& operator[](size_t& index) {
			return data[index];
		}

		bool operator==(const string& other) {
			if (size == other.size) {
				for (size_t i = 0; i < size; ++i) {
					if (data[i] != other.data[i])
						return false;
				}
				return true;
			}
			return false;
		}

		bool operator==(const char* other) {
			if (size == strlen(other)) {
				for (size_t i = 0; i < size; ++i) {
					if (data[i] != other[i])
						return false;
				}
				return true;
			}
			return false;
		}

		bool operator==(char* other) {
			if (size == strlen(other)) {
				for (size_t i = 0; i < size; ++i) {
					if (data[i] != other[i])
						return false;
				}
				return true;
			}
			return false;
		}

		bool operator==(char& other) {
			if (size == 1) {
				return data[0] == other;
			}
			return false;
		}

		void erase(const size_t& start, size_t length) {
			if (start >= size) {
				return;
			}

			if (start + length > size) {
				length = size - start;
			}

			char* temp = new char[size + 1 - length];

			//copy before start
			if (start > 0)
				memcpy(temp, data, start);

			//copy after start (including null terminator character)
			memcpy(temp + start, data + start + length, size + 1 - length - start);

			delete[] data;

			data = temp;
			size = size - length;

		}

		/*
		* Returns the length of the string
		*
		* @author Salmoncatt
		*
		*/
		size_t length() const{
			return size;
		}

		/*
		* Returns whether or not the string is empty
		* 
		* @author Salmoncatt
		* 
		*/
		bool empty() const{
			return (data == NULL || data[0] == '\0');
		}

		/*
		* Returns the character at a the index specified.
		* 
		* @param The index for the character
		* 
		* @author Salmoncatt
		*/
		char& at(size_t& index) {
			return data[index];
		}


		size_t find(const string& delimiter) const{
			
			if (size > delimiter.size) {
				for (size_t i = 0; i < size - delimiter.size; i += 1) {

					if (data[i] == delimiter.data[0]) {
						size_t matches = 0;

						for (size_t j = 0; j < delimiter.size; j += 1) {
							if (data[i + j] == delimiter.data[j]) matches += 1;
						}

						if (matches == delimiter.size) return i;
					}
				}
			}

			return string::npos;
		}

		string substr(const size_t& index, const size_t& size) const {
			string out = string();

			delete[] out.data;

			out.data = new char[size + 1];
			out.size = size;

			//i keeps track of second string index, j is for the first string (i do this because there is an offset involved)
			for (size_t i = index; i < (index + size); i += 1) {
				out.data[i - index] = data[i];
			}

			out.data[size] = '\0';
			out.size = size;

			return out;
		}

		string substr(const size_t& index) const {
			return substr(index, size - index);
		}

		const char* c_str() const{
			return data;
		}

		vector<string> split(const string& delimiter) {
			vector<string> out = vector<string>();

			string temp = *this;

			out.reserve(10);

			size_t index = 0;

			while ((index = temp.find(delimiter)) != string::npos) {
				out.push_back(temp.substr(0, index));

				temp.erase(0, index + delimiter.size);
			}

			//find doesnt count the last one so i add the rest of the data
			out.push_back(temp.substr(0, temp.size));

			return out;
		}

		~string() {
			__cleanup__();
		}


	};


	static float toFloat(const string& value) {
		const char* data = value.c_str();

		if (!*data || *data == '?')
			return __builtin_nanf("");

		int signed_digit = 1;

		while (*data == ' ') data++;

		if (*data == '-') {
			signed_digit = -1;
			data++;
		}


		float accumulator = 0;


		while (*data >= '0' && *data <= '9')
			accumulator = accumulator * 10 + *data++ - '0';

		if (*data == '.') {
			float decimalAccumulator = 0.1f;

			data++;

			while (*data >= '0' && *data <= '9') {
				accumulator += (*data++ - '0') * decimalAccumulator;
				decimalAccumulator *= 0.1f;
			}

		}

		if (*data != '\0')
			return __builtin_nanf("");

		return signed_digit * accumulator;
	}

	static double toDouble(const string& value) {
		const char* data = value.c_str();

		if (!*data || *data == '?')
			return __builtin_nans("");

		int signed_digit = 1;

		while (*data == ' ') data++;

		if (*data == '-')
			signed_digit = -1;


		double accumulator = 0;


		while (*data >= '0' && *data <= '9')
			accumulator = accumulator * 10 + *data++ - '0';

		if (*data == '.') {
			double decimalAccumulator = 0.1;

			data++;

			while (*data >= '0' && *data <= '9') {
				accumulator += (*data++ - '0') * decimalAccumulator;
				decimalAccumulator *= 0.1;
			}

		}

		if (*data != '\0')
			return __builtin_nans("");

		return signed_digit * accumulator;
	}


}


#endif
