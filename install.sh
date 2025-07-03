#!/bin/bash

echo "🔧 Installing Ransomware Defender Pro..."
sleep 1

# Python venv
python3 -m venv venv
source venv/bin/activate

# Install dependencies
pip install --upgrade pip
pip install -r requirements.txt

echo "✅ Installation complete."
echo "🧪 To run: source venv/bin/activate && python gui_main.py"
