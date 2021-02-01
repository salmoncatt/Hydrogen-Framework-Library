
#ifndef HGE_MEMORY_UTIL_HEADER_INCLUDE
#define HGE_MEMORY_UTIL_HEADER_INCLUDE

namespace HGE {


	/**
	* Copies data from one memory adress to another
	* 
	* @author Salmoncatt
	* 
	* @param Destination of data
	* @param Source of data
	* @param Length of the data
	*/
	void* memcpy(void* destination, const void* source, size_t length) {
		//have references to the data we want to copy and the destination it goes to
		char* destinationData = (char*)destination;
		const char* sourceData = (char*)source;

		//loop through all the data and copy it, reverse while loop is the fastest so we use that (which is why we copied that length data and didnt make a reference to it)
		while (length--)
			*destinationData++ = *sourceData++; //weird shit

		return destination;
	}
	
	/**
	* Returns the length of a string of characters not including the termination character
	* 
	* @param the character data
	* 
	* @author Salmoncatt
	*/
	size_t strlen(const char* data) {
		size_t length = 0;

		while (data[length])
			length += 1;

		return length;
	}


	char* strcpy(char* destination, const char* source) {
		return (char*)memcpy(destination, source, strlen(source) + 1);
	}

	char* strcpy(char* destination, const char* source, const size_t& offset) {
		return (char*)memcpy(destination, source + offset, strlen(source) + 1 - offset);
	}



}




#endif