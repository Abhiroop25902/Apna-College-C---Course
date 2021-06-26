import matplotlib.pyplot as plt
import pandas
import numpy as np

dataset_df = pandas.read_csv("./dataset.csv")

# expectime timecomplexity is O(nlgn)

size = dataset_df['size'].to_numpy()
avg_time = dataset_df['avg_time_ms'].to_numpy()

y_axis = avg_time/(size*np.log2(size))

plt.figure("Time Ratio")
plt.plot(y_axis)
plt.savefig('obs.png')
