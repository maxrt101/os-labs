#!/bin/bash -e

readonly SELF="$0"

build() {
  [[ ! -d "db/lab6" ]] && git clone https://github.com/maxrt101/db-labs.git -b lab6 db/lab6

  docker-compose build
}

start() {
  docker-compose up -d
}

stop() {
  docker-compose down
}

status() {
  docker-compose ps
}

logs() {
  docker logs os_lab_app
}

errors() {
  docker logs os_lab_app | grep ERROR
}

usage() {
  cat <<EOF
Usage: $SELF {help|build|start|stop|status|logs|errors}
EOF
}

if [[ "$1" == "" ]]; then
  usage
  exit 1
fi

case $1 in
  help)   usage;  exit 0 ;;
  build)  build;  exit 0 ;;
  start)  start;  exit 0 ;;
  stop)   stop;   exit 0 ;;
  status) status; exit 0 ;;
  logs)   logs;   exit 0 ;;
  errors) errors; exit 0 ;;
  *)      usage;  exit 1 ;;
esac
