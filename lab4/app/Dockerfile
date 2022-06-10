FROM ubuntu:20.04

RUN apt update && apt install -y wget openjdk-17-jdk openssl

RUN wget https://github.com/maxrt101/db-labs/releases/download/lab6-v1.1/lab6.jar -O /root/lab6.jar

RUN wget https://github.com/prometheus/node_exporter/releases/download/v1.3.1/node_exporter-1.3.1.linux-amd64.tar.gz -O /root/node_exporter.tar.gz
RUN mkdir -p /root/node_exporter
RUN tar -xf /root/node_exporter.tar.gz -C /root/node_exporter --strip-components=1

RUN wget https://github.com/prometheus/prometheus/releases/download/v2.36.0/prometheus-2.36.0.linux-amd64.tar.gz -O /root/prometheus.tar.gz
RUN mkdir -p /root/prometheus
RUN tar -xf /root/prometheus.tar.gz -C /root/prometheus --strip-components=1

ADD prometheus.yml /root/prometheus/

ADD entry.sh /root/entry.sh
RUN chmod +x /root/entry.sh

ENTRYPOINT /root/entry.sh
