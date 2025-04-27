#ifndef CAMERA_H
#define CAMERA_H

#include "hittable.h"

class camera {
 private:
    //Private camera variables
    int image_height;
    point3 center;
    

    void initialize() {
            
    }
    
    color ray_color(const ray& r, const hittable& world){
    hit_record rec;
    if(world.hit(r, interval(0, infinity), rec)) {
        return 0.5 * (rec.normal + color(1,1,1));
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 *(unit_direction.y() + 1.0);
    return (1.0-a)* color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
    }

 public:
    double aspect_ratio = 1.0; //Ratio of image width over height
    int image_width = 100;
    
    //Public Camera parameters 
    void render(const hittable& world) {
        initialize();

        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int j = 0; j < image_height; j++)
        {
            // add progress indicator
            std::clog << "\rScanlines remaining: " << (image_height-j) << ' ' << std::flush;
            for (int i = 0; i < image_width; i++)
            {
                auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
                auto ray_direction = pixel_center - camera_center;
                ray r(camera_center, ray_direction);
                
                color pixel_color = ray_color(r, world);
                write_color(std::cout, pixel_color);
            }
            
        }
        std::clog << "\rDone!         \n";

    }
    
};


#endif