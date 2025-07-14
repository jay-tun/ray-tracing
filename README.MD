# Ray Tracing in One Weekend - Notes and Summary

This document summarizes the key ideas, concepts, and personal notes from the book [*Ray Tracing in One Weekend*](https://raytracing.github.io/books/RayTracingInOneWeekend.html). It covers foundational elements for building a basic ray tracer from scratch using C++.

---

## 📘 Book Overview

* **Title:** Ray Tracing in One Weekend
* **Author:** Peter Shirley
* **Link:** [raytracing.github.io/books/RayTracingInOneWeekend.html](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
* **Goal:** Create a minimal ray tracer that outputs a PPM image using spheres, materials, and recursive ray scattering.

---

## 🛠️ Project Structure

```
ray-tracing/
├── CMakeLists.txt
├── build/
├── images/
├── src/
│   ├── main.cc
│   ├── vec3.h
│   ├── ray.h
│   ├── color.h
│   ├── hittable.h
│   ├── hittable_list.h
│   ├── sphere.h
│   ├── camera.h
│   ├── material.h
│   └── rtweekend.h
```

---

## 📐 Core Concepts

### 1. **Vectors (vec3.h)**

* 3D vector class for positions, colors, directions
* Supports arithmetic, dot product, cross product, normalization

### 2. **Rays (ray.h)**

* Ray = origin + t \* direction
* Used to cast into the scene and determine what is hit

### 3. **Color (color.h)**

* Converts color from float to byte (0–255)
* Handles gamma correction and pixel output

### 4. **Spheres and Hittables**

* `sphere.h` defines sphere hit logic using quadratic formula
* `hittable.h` is an abstract base class
* `hittable_list.h` aggregates multiple objects

### 5. **Camera (camera.h)**

* Defines viewport and projection logic
* Handles depth of field using defocus disk sampling
* Shoots rays per pixel using jittered sampling for anti-aliasing

### 6. **Materials (material.h)**

* Supports Lambertian (diffuse), Metal (reflective), Dielectric (glass)
* Each defines a `scatter()` function controlling ray behavior after hitting the object

---

## 🌌 Rendering Pipeline

1. **Scene Setup:** Define geometry, materials, and camera
2. **Sampling:** Multiple rays per pixel for anti-aliasing
3. **Recursion:** Ray bounces are recursively traced
4. **Color Accumulation:** Accumulate samples and average
5. **Output:** Write colors to `std::cout` in PPM format

---

## ⚙️ Optimization Tips

* Avoid writing to `std::cout` in parallel
* Use OpenMP only when output is buffered or saved after rendering
* Implement resume-from-scanline using a progress tracker and append mode

---

## ✅ Completion Milestone

* ✅ Successfully rendered `final_scene` with:

  * 1200x675 resolution
  * 500 samples per pixel
  * 50 ray bounces
* ✅ Verified material scattering and depth-of-field
* ✅ Refactored and modularized codebase

---

## 📚 Citation

Shirley, Peter. [*Ray Tracing in One Weekend*](https://raytracing.github.io/books/RayTracingInOneWeekend.html).
