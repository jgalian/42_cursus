FROM alpine

RUN apk -U upgrade \
	&& apk add vsftpd openssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-subj "/C=SP/ST=Madrid/L=Madrid/O=42Madrid/OU=jgalian/CN=ft_services_ftps" \
	-keyout /etc/ssl/private/vsftpd.key -out /etc/ssl/certs/vsftpd.crt

RUN echo "root:toor" | chpasswd

COPY /vsftpd.conf /etc/vsftpd
COPY /ftps.sh .

#Port 21 works in active and passive mode. Port 30021 only passive mode works.
EXPOSE 21 30021

ENTRYPOINT sh ftps.sh
