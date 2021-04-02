# DeepBurst

Apply machine learning to find bursts in data streams.

## Settings

The setting of this project is identical of [BurstSketch](https://github.com/BurstSketch/BurstSketch). The very only difference between `BurstSketch` and `DeepBurst` is that the latter one uses a deep model while the first one uses a manually designed algorithm.

## Data

Data are generated using the original code from `BurstSketch`. The directory `\BurstSketch` is basically a clone of [BurstSketch](https://github.com/BurstSketch/BurstSketch). `\BurstSketch\BurstDetection\DataGenerator.cpp` is modified from `main.cpp` in the same directory and is used to generate data for deep models.

### Generate Data for Regression

Firstly place `formatted00.dat` to `DeepBurst/BurstSketch/`.

Then convert original data to `.csv` format by running the following code:

```bash
$ cd DeepBurst/BurstSketch/BurstDetection/
$ g++ DataGenerator.cpp -o data -std=c++11
$ ./data
```

After that, convert original data to `.pickle` format by running all codes in `DeepBurst/notebooks/generate_mvp_data.ipynb`.

Finally the data is ready to use. Column `0` ~ `3` is the first IP address in orignal id while column `4` ~ `7` is the second IP address. And `DeepBurst/notebooks/generate_regression_data.ipynb` shows how to load the data.