# solar-tracking-system

☀️ Imagine You're Watching the Sun
You take two photos of the Sun, one right after the other — just like a mini video. You want to see how things on the Sun have moved between the two photos.

🤖 What the Neural Network Does:
It looks at both photos.
It figures out how each pixel (tiny dot) moved between the first and second photo.
Did it shift left? Right? Up? Down?
It outputs a kind of "motion map" — showing the direction and speed of motion at every point. This is called optical flow.
🔁 Then What?
It uses this motion map to "slide" or warp the first image so it lines up with the second.
If the motion map is accurate, the warped image will look almost exactly like the second image.
🧠 How It Learns:
The network trains itself by comparing:
The warped image it creates, and
The real second image.
It adjusts itself to make better and better motion predictions.
It also tries to keep the motion smooth and realistic (no crazy pixel jumps).
🔭 Why This Is Useful:
By doing this, the model can track how solar features like sunspots or plasma flows are moving, helping scientists study solar dynamics without manually analyzing the data.
🎓 Training (Teaching the Model)

Imagine:
You're showing the model two pictures of the Sun, taken one after another — and asking:

“Can you figure out how everything moved between these two?”
Step-by-step:
Input: Two images → Image A (before), Image B (after)
The model (CNN) guesses how each part of Image A moved to become Image B → This guess is called the optical flow (vx, vy).
The spatial transformer uses that guess to move pixels in Image A, creating a warped image.
The model compares the warped image to the real Image B:
If it looks similar → good job!
If not → the model adjusts its internal settings.
This process repeats with thousands of image pairs until the model gets really good at guessing.
🧪 Testing (Using the Trained Model)

Now, the model is ready to work on new images.

What happens:
You give it two new solar images.
The model quickly calculates the optical flow — how everything moved.
You can:
Visualize this movement as arrows or colored maps
Warp the first image to match the second
Analyze solar activity (like how fast a sunspot is moving)
🧠 Analogy:
Training: Like teaching a student to track clouds across the sky in time-lapse photos.
Testing: Like handing them a new video and asking, “Which way are the clouds moving now?”
https://sdmntprwestus.oaiusercontent.com/files/00000000-fa4c-5230-a375-d9e5113446a5/raw?se=2025-04-09T08%3A39%3A26Z&sp=r&sv=2024-08-04&sr=b&scid=17d24192-569d-55e9-a177-1ff5c20ca8aa&skoid=acefdf70-07fd-4bd5-a167-a4a9b137d163&sktid=a48cca56-e6da-484e-a814-9c849652bcb3&skt=2025-04-09T04%3A06%3A54Z&ske=2025-04-10T04%3A06%3A54Z&sks=b&skv=2024-08-04&sig=LetRFOYLNNAnY6upVKECyWGh5b%2Bi92htqXHOM%2B0I5yk%3D![image](https://github.com/user-attachments/assets/511d6179-b42e-44af-9c3c-2451cdae4084)

🔧 Dependencies
numpy
h5py
astropy
tqdm
PyTorch
scikit-image


This project applies a Convolutional Neural Network (CNN) to forecast yearly sunspot numbers, using historical data from 1700 to 2014. Sunspots are a key indicator of solar activity and forecasting them is critical for space weather prediction, satellite operations, and understanding long-term climate patterns.

📘 Project Overview

Objective: Predict the sunspot number for future years (e.g., 2015) using deep learning.
Approach: Use a 1D CNN model to learn patterns from time-series data.
Dataset: Yearly sunspot numbers from 1700 to 2014.
Output: Forecasted sunspot numbers and evaluation metrics (MAE, RMSE, MAPE, ISE).

🧠 Model Architecture

Preprocessing: Min-Max Normalization, windowing
CNN Layers:
1D Convolution Layer
ReLU Activation
Flatten Layer
Dense Output Layer
Loss Function: Mean Squared Error
Optimizer: Adam
📂 Directory Structure

sunspot-cnn-forecast/
├── sunspot_forecasting_lstm.ipynb     # Colab notebook (LSTM)
├── sunspot_forecasting_cnn.ipynb      # Colab notebook (CNN)
├── sunspotnumber.csv                  # Historical data file
├── sunspot_forecast_results.csv       # Output predictions
├── arima_model_summary.txt            # ARIMA baseline results
├── README.md                          # This file
🧪 Evaluation Metrics


Metric	Description
MAE	Mean Absolute Error
RMSE	Root Mean Squared Error
MAPE	Mean Absolute Percentage Error
ISE	Integral of Squared Error
📊 Results


Year	Predicted (CNN)       	Actual
2015	XX.XX	                [To be filled]



🔍 Key Features

End-to-end deep learning pipeline using CNNs
Comparison with ARIMA model
Dataset included (1700–2014)
Easily adaptable for forecasting other time series


🧠 Novelty

This project is one of the few that:

Applies 1D CNNs to univariate sunspot time series
Bridges a gap noted in recent solar forecasting literature
Demonstrates that CNNs can be lightweight alternatives to LSTM for temporal prediction


