#include <stdlib.h>

static const Block blocks[] = {
    /* icon, command, interval, signal */
    {"  ", 
     "top -bn1 | grep '%Cpu(s)' | awk '{printf \"%02d%%\", int($2 + $4 + $6 + 0.5)}'", 
     1, 0}, // CPU Usage
     
    {"  ", 
     "sensors | grep 'Tctl' | awk '{temp = int(substr($2, 2) + 0.5); printf \"%02d°C\", temp}'", 
     1, 0}, // CPU Temp

    {"      ", 
     "nvidia-smi --query-gpu=utilization.gpu --format=csv,noheader | awk '{printf \"%02d%%\", $1}'", 
     1, 0}, // GPU Utilization

    {"  ", 
     "nvidia-smi --query-gpu=temperature.gpu --format=csv,noheader | awk '{printf \"%02.0f°C\", $1}'", 
     1, 0}, // GPU Temp

    {"      ", 
     "top -bn1 | grep 'MiB Mem' | awk '{used=$8; total=$4; printf \"%02d%%\", int((used/total)*100 + 0.5)}'", 
     1, 0}, // Memory Usage

    {"    󰥔  ", 
     "bash -c 'date +\"%H:%M:%S   %-d %B %Y\"'", 
     1, 0},
};

static char delim[] = "";
static unsigned int delimLen = 0;
