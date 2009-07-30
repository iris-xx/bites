
#include <fstream>
#include <iostream>
#include <string>

#include "structs.pb.h"
#include "vision.pb.h"

using namespace std;

void PrintImageInfo(man::vision::Image *image) {

  cout << "Image" << endl;
  cout << "  encoding: " << image->encoding() << endl;
  cout << "  width: " << image->width() << endl;
  cout << "  hieght: " << image->height() << endl;
  cout << "  data:" << endl << image->data() << endl;

}

// Main function: Reads a Vision image from a file and writes it back
//
int main(int argc, char *const argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the header we compiiled against
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 2) {
    cerr << "Usage:  " << argv[0] << " IMAGE_FILE" << endl;
    return -1;
  }

  man::vision::Image image;
  
  {
    fstream input(argv[1], ios::in | ios::binary);
    if (!input) {
      cout << argv[1] << ": File not found.  Creating a new file." << endl;
    } else if (!image.ParseFromIstream(&input)) {
      cerr << "Failed to parse address book." << endl;
      return -1;
    } else {
      PrintImageInfo(&image);
    }
  }

  image.set_encoding(man::vision::Image::YUV422);
  image.set_width(320);
  image.set_height(240);

  string data("hello world");
  image.set_data(data);

  {
    fstream output(argv[1], ios::out | ios::binary);
    if (!image.SerializeToOstream(&output)) {
      cerr << "Failed to write address boook." << endl;
      return -1;
    }
  }

  google::protobuf::ShutdownProtobufLibrary();
  return 0;
}
