
#include <boost/shared_ptr.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "vision.pb.h"
#include "bites.h"

using namespace std;
using namespace boost;
using namespace bites::vision;
using namespace bites;

// Main function: Reads a Vision image from a file and writes it back
//
int main(int argc, char *const argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the header we compiiled against
  GOOGLE_PROTOBUF_VERIFY_VERSION;


  if (argc < 2 || argc > 5) {
    cerr << "Usage:  " << argv[0]
      << " HOME_DIRECTORY [STORE_PREFIX] [STORE_NAME] [STORE_SUFFIX]" << endl;
    return -1;
  }

  shared_ptr<DB_ENV> env(init_env(argv[1]));

  shared_ptr<ProtoStore> store;
  switch (argc) {
    case 2:
      store.reset(new ProtoStore(env));
      break;
    case 3:
      store.reset(new ProtoStore(env, argv[1]));
      break;
    case 4:
      store.reset(new ProtoStore(env, argv[1], argv[2]));
      break;
    case 5:
      store.reset(new ProtoStore(env, argv[1], argv[2], argv[3]));
      break;
  }

  shared_ptr<Image> image(new Image());
  image->set_encoding(bites::vision::Image::YUV422);
  image->set_width(320);
  image->set_height(240);
  image->set_data("hello world");

  store->put("foo", image);
  return 0;
}
