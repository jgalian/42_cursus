FROM alpine

USER root
# Install Nginx and SSL / SSH toolkit
# /run/ is the repository for temporary system files that are not needed across system reboot
RUN apk -U upgrade \
	&& apk add nginx openssl openssh \
	&& mkdir -p /run/nginx

# Configure SSL certificate
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-subj "/C=SP/ST=Madrid/L=Madrid/O=42Madrid/OU=jgalian/CN=ft_services_nginx" \
	-keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt

# Configure SSH
RUN adduser -D "admin" \
	&& echo "admin:admin" | chpasswd \
	&& ssh-keygen -A

# Copy Nginx configuration file, web site, and script
COPY /nginx.conf /etc/nginx/
COPY /nginx.sh .
COPY /index.html /var/www/

EXPOSE 80 443

ENTRYPOINT	sh nginx.sh
