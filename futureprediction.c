import pandas as pd
import matplotlib.pyplot as plt
from statsmodels.tsa.arima.model import ARIMA
from statsmodels.tsa.seasonal import seasonal_decompose
from pandas.plotting import register_matplotlib_converters
import io

register_matplotlib_converters()

# === Load and Prepare Dataset ===
# Load sample sunspot data
data = """
Year,Month,SunspotNumber
1749,1,58.0
1749,2,62.6
1749,3,70.0
1749,4,55.7
1749,5,85.0
1749,6,83.5
1749,7,94.8
1749,8,66.3
1749,9,75.9
1749,10,75.5
"""
df = pd.read_csv(io.StringIO(data))

# Create a datetime index
df['Date'] = pd.to_datetime(df['Year'].astype(str) + '-' + df['Month'].astype(str))
df.set_index('Date', inplace=True)

# === Seasonal Decomposition Plot ===
# Adjust the period to match the data frequency or provide more data
decomposition = seasonal_decompose(df['SunspotNumber'], model='additive', period=3)  # Changed period to 3 for demonstration
decomposition.plot()
plt.suptitle('Seasonal Decomposition of Sunspot Numbers', fontsize=16)
plt.tight_layout()
plt.savefig('seasonal_decomposition.png', dpi=300)
plt.show()

# === ARIMA Forecasting ===
train = df['SunspotNumber'][:-2]  # Adjust for sample data
test = df['SunspotNumber'][-2:]   # Adjust for sample data

model = ARIMA(train, order=(5, 1, 0))
fitted_model = model.fit()
forecast = fitted_model.forecast(steps=2)  # Adjust for sample data

# === Plot and Save Forecast ===
plt.figure(figsize=(12, 6))
plt.plot(train.index, train, label='Train')
plt.plot(test.index, test, label='Test')
plt.plot(test.index, forecast, label='Forecast', linestyle='--')
plt.title('ARIMA Forecast of Sunspot Numbers')
plt.xlabel('Date')
plt.ylabel('Sunspot Number')
plt.legend()
plt.grid(True)
plt.savefig('sunspot_forecast_plot.png', dpi=300)
plt.show()

# === Export Forecast to CSV ===
forecast_df = pd.DataFrame({
    'Date': test.index,
    'Actual': test.values,
    'Forecast': forecast.values
})
forecast_df.to_csv('sunspot_forecast_results.csv', index=False)

# === Save Model Summary to TXT ===
with open('arima_model_summary.txt', 'w') as f:
    f.write(fitted_model.summary().as_text())
    from sklearn.metrics import mean_absolute_error, mean_squared_error
import numpy as np

# Calculate accuracy metrics
mae = mean_absolute_error(test, forecast)
mse = mean_squared_error(test, forecast)
rmse = np.sqrt(mse)
mape = np.mean(np.abs((test - forecast) / test)) * 100

# Print results
print(f"📊 Forecast Accuracy:")
print(f"MAE  = {mae:.2f}")
print(f"MSE  = {mse:.2f}")
print(f"RMSE = {rmse:.2f}")
print(f"MAPE = {mape:.2f}%")

# Optional: Save accuracy to file
with open('forecast_accuracy.txt', 'w') as f:
    f.write(f"Forecast Accuracy:\n")
    f.write(f"MAE  = {mae:.2f}\n")
    f.write(f"MSE  = {mse:.2f}\n")
    f.write(f"RMSE = {rmse:.2f}\n")
    f.write(f"MAPE = {mape:.2f}%\n")


forecast_year = pd.date_range(start='2015', periods=2, freq='Y')
print(f"Predicted Sunspot Number for 2015: {forecast.values[1]}")




