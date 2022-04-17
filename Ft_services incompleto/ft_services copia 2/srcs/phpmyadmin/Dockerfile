FROM alpine

RUN apk -U upgrade \
	&& wget https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-all-languages.tar.gz \
	&& tar -xzvf phpMyAdmin-4.9.2-all-languages.tar.gz \
	&& rm -rf phpMyAdmin-4.9.2-all-languages.tar.gz \
	&& mkdir -p /www \
	&& mv phpMyAdmin-4.9.2-all-languages /www/phpmyadmin

RUN	 apk add php7 php7-fpm php7-mysqli php7-mbstring php7-json php7-session

COPY /config.inc.php /www/phpmyadmin/
COPY /phpmyadmin.sh /

EXPOSE 5000

ENTRYPOINT sh phpmyadmin.sh
