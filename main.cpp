#include <iostream> 
#include  <exiv2/exiv2.hpp>
// write a basic programme using exif2 library
int main() {
    Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open("test.jpg");
    assert(image.get() != 0);
    image->readMetadata();
    Exiv2::ExifData &exifData = image->exifData();
    if (exifData.empty()) {
        std::string error("No Exif data found in file");
        throw Exiv2::Error(1, error);
    }
    Exiv2::ExifKey key("Exif.Image.DateTime");
    Exiv2::ExifData::iterator pos = exifData.findKey(key);
    if (pos != exifData.end()) {
        std::cout << pos->key() << " " << pos->value() << std::endl;
    }
    return 0;
}