#!/bin/bash

/root/prometheus/prometheus --config.file=/root/prometheus/prometheus.yml &
/root/node_exporter/node_exporter &

java -jar /root/lab6.jar
