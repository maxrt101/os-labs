FROM ubuntu/nginx

RUN apt update && apt install openssl

ADD app.conf /etc/nginx/conf.d

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
  -keyout /etc/ssl/private/nginx-selfsigned.key \
  -out /etc/ssl/certs/nginx-selfsigned.crt \
  -subj "/C=UA/ST=Lviv/L=Lviv/O=ExampleLtd/CN=localhost"

