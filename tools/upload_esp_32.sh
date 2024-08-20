port="$1"
board='esp32:esp32:heltec_wifi_lora_32_V2'

if test -c $port; then
   test -d get_temps/ && rm -rf get_temps/
   mkdir get_temps
   cp ../get_temps.ino get_temps/

   arduino-cli compile get_temps \
      -b esp32:esp32:heltec_wifi_lora_32_V2 || exit 1

   arduino-cli upload get_temps -p "$port" \
      -b esp32:esp32:heltec_wifi_lora_32_V2

   rm -rf get_temps/
fi
