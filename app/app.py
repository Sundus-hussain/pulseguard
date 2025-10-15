from flask import Flask, jsonify
import random

app = Flask(__name__)

@app.route('/')
def home():
    return "💓 PulseGuard is running — Real-time heart monitoring!"

@app.route('/heartbeat')
def heartbeat():
    bpm = random.randint(50, 180)
    status = "Normal"
    if bpm < 60 or bpm > 120:
        status = "Alert 🚨"
    return jsonify({
        "heart_rate": bpm,
        "status": status
    })

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
