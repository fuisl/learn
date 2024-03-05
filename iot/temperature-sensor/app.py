from counterfit_connection import CounterFitConnection
CounterFitConnection.init()
import time
from counterfit_shims_seeed_python_dht import DHT
import json



sensor = DHT("11", 5)

while True:
    _, temp = sensor.read()
    print(f"Temperature: {temp}°C")
    time.sleep(10)

