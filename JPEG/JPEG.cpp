#include <iostream>
#include <string>


class ImageProcessor {
public:
    virtual void load(std::string filename) = 0;
    virtual void save(std::string filename) = 0;
    virtual void process() = 0;
    virtual ~ImageProcessor() = default;
};

class JpegImageProcessor : public ImageProcessor {
public:
    void load(std::string filename) override {
        std::cout << "Downloaded JPEG image from file: " << filename << std::endl;
    }

    void save(std::string filename) override {
        std::cout << "Saved JPEG image to file: " << filename << std::endl;
    }

    void process() override {
        std::cout << "JPEG Image Processing" << std::endl;
    }
};


class PngImageProcessor : public ImageProcessor {
public:
    void load(std::string filename) override {
        std::cout << "Downloaded PNG image from file: " << filename << std::endl;
    }

    void save(std::string filename) override {
        std::cout <<"Saved PNG image to file: " << filename << std::endl;
    }

    void process() override {
        std::cout << "Обробка PNG-зображення" << std::endl;
    }
};

class ImageProcessorFactory {
public:
    virtual ImageProcessor* createProcessor() = 0;
    virtual ~ImageProcessorFactory() = default;
};


class JpegImageProcessorFactory : public ImageProcessorFactory {
public:
    ImageProcessor* createProcessor() override {
        return new JpegImageProcessor();
    }
};


class PngImageProcessorFactory : public ImageProcessorFactory {
public:
    ImageProcessor* createProcessor() override {
        return new PngImageProcessor();
    }
};

int main() {
    ImageProcessorFactory* factory = new JpegImageProcessorFactory();
    ImageProcessor* processor = factory->createProcessor();

    processor->load("image.jpg");
    processor->process();
    processor->save("processed_image.jpg");

    
    delete processor;
    delete factory;

    return 0;
}