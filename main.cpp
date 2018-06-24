#include "hwlib.hpp"
#include "SDDevice.hpp"

int main() {
	// kill the watchdog (ATSAM3X8E specific)
	WDT->WDT_MR = WDT_MR_WDDIS;

	// wait for the COM port to be setup for IO
	hwlib::wait_ms( 1000 );
	//    char test;
	//    hwlib::cin >> test;
	auto SS = hwlib::target::pin_out( 3, 7 );
	auto SCLK = hwlib::target::pin_out( 2, 21 );
	auto MOSI = hwlib::target::pin_out( 2, 22 );
	auto MISO = hwlib::target::pin_in( 2, 25 );
	SS.set( true );
	SCLK.set( false );
	MOSI.set( true );
	hwlib::wait_ms( 500 );
	SDDevice SDCard( MOSI, SS, SCLK, MISO );

	SDCard.init_card();
	SDCard.generateDirectoryListing();
	SDCard.printDirectoryListing();
	for ( ;; ) {
		hwlib::cout << "What folder or file would you like to open? (Select by typing the number to the left of the entry)" << hwlib::endl;
		hwlib::cout << "CAUTION: by selecting a file, the file will be opened and printed." << hwlib::endl;
		char temp;
		uint16_t filenumber = 0;
		do {
			hwlib::cin >> temp;
			if ( ( temp >= 48 && temp <= 57 ) ) {
				hwlib::cout << "temp: " << temp;
				filenumber += temp - '0';
				hwlib::cout << " || temp after: " << filenumber << hwlib::endl;
			}
		} while ( temp != 13 );
		if ( SDCard.filenumberIsADirectory( filenumber ) ) {
			hwlib::cout << "Directory listing for directory number: " << filenumber << hwlib::endl;
			SDCard.printDirectoryListing( filenumber );
		} else {
			hwlib::cout << "Will print soon" << hwlib::endl;
		}


	}
	return 0;
}