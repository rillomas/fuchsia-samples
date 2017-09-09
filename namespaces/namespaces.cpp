#include <iostream>
#include <mxio/namespace.h>
#include <magenta/status.h>
#include <magenta/process.h>

int main(int argc, char** argv) {
	std::cout << "Testing namespaces..." << std::endl;
	auto ph = mx_process_self();
	if (ph == MX_HANDLE_INVALID) {
		std::cerr << "Failed to get process handle" << std::endl;
		return -1;
	}
	std::cout << "Got process handle: " << ph << std::endl;
	mxio_ns_t* ns;
	auto stat = mxio_ns_create(&ns);
	if (stat != MX_OK) {
		std::cerr << "Failed to create namespace: " << mx_status_get_string(stat) << std::endl;
		return -1;
	}
	return 0;
}
