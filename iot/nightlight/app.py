from counterfit_connection import CounterFitConnection
from counterfit_shims_grove import GroveLed
CounterFitConnection.init('127.0.0.1', 5000)
import paho.mqtt.client as mqtt
import time

CounterFitConnection()  # address and port are default

id = '0bd2db82-9248-46a9-b593-317b681f702a'
client_name = id + "nightlight_client"
mqtt_client = mqtt.Client(client_name)
mqtt_client.connect('test.mosquitto.org')
mqtt_client.loop_start()

light = GroveLed(5)



print("MQTT Connected.")