# DeepBurst

Apply machine learning to find bursts in data streams.

## Settings

The setting of this project is identical of [BurstSketch](https://github.com/BurstSketch/BurstSketch). The very only difference between `BurstSketch` and `DeepBurst` is that the latter one uses a deep model while the first one uses a manually designed algorithm.

## Data

Data are generated using the original code from `BurstSketch`. The directory `\BurstSketch` is basically a clone of [BurstSketch](https://github.com/BurstSketch/BurstSketch). `\BurstSketch\BurstDetection\DataGenerator.cpp` is modified from `main.cpp` in the same directory and is used to generate data for deep models.