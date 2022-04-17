#!/bin/sh

# Kill all processes.
#minikube delete
killall -TERM kubectl minikube VBoxHeadless

# Start Docker and wait untill service is up to continue
# I do that checking the returned value of the command "docker version"...
# ...if it is 1 means that the service is still down
echo "N" | bash ./srcs/init_docker.sh
while
	docker version > /dev/null 2>&1
	(($? == 1))
do
	sleep 5
	echo "\033[1;33m+>\033[0;33m Waiting for docker ... \n"
done

# Start minikube
minikube start --driver=virtualbox

# Use the docker daemon from minikube
eval $(minikube docker-env)

# Enable addons
minikube addons enable dashboard
minikube addons enable metallb
#minikube addons enable ingress
minikube addons enable metrics-server

# Build docker images
docker build -t my_nginx srcs/nginx > /dev/null 2>&1
# docker build -t my_wordpress srcs/wordpress > /dev/null 2>&1
# docker build -t my_mysql srcs/mysql > /dev/null 2>&1
# docker build -t my_phpmyadmin srcs/phpmyadmin > /dev/null 2>&1
# docker build -t my_ftps srcs/ftps > /dev/null 2>&1
# docker build -t my_grafana srcs/grafana > /dev/null 2>&1
# docker build -t my_influxdb srcs/influxdb > /dev/null 2>&1

# Apply yaml resources
# kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
# kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
kubectl apply -f srcs/metalLB.yaml
kubectl apply -f srcs/nginx/nginx.yaml
# kubectl apply -f srcs/mysql.yaml
# kubectl apply -f srcs/ftps.yaml
# kubectl apply -f srcs/phpmyadmin.yaml
# kubectl apply -f srcs/wordpress.yaml
# kubectl apply -f srcs/grafana.yaml
# kubectl apply -f srcs/influxdb.yaml

# Open dashboard
minikube dashboard
