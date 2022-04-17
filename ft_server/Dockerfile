FROM debian:buster

# UPDATING AND INSTALLING COMANDS AND SERVICES
RUN apt-get update && apt-get -y upgrade && apt-get -y install apt-utils && apt-get -y install wget
RUN apt-get -y install nginx
RUN apt-get -y install openssl
RUN apt-get -y install mariadb-server
RUN apt-get -y install php7.3 php7.3-fpm php7.3-mysql php7.3-bcmath php7.3-curl php7.3-imagick php7.3-gd php7.3-mbstring php7.3-xml php7.3-zip php7.3-cli
RUN wget https://wordpress.org/wordpress-5.4.tar.gz -P /root/ && mkdir /var/www/localhost/ && tar -xvzf /root/wordpress-5.4.tar.gz -C /var/www/localhost/
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-english.tar.gz -P /root/ && tar -xvzf /root/phpMyAdmin-4.9.5-english.tar.gz -C /var/www/localhost/ && mv /var/www/localhost/phpMyAdmin-4.9.5-english /var/www/localhost/phpMyAdmin

# COPYING AND REMOVING FILES
COPY srcs/localhost_config /etc/nginx/sites-available/
COPY srcs/wp-config.php /var/www/localhost/wordpress/
COPY srcs/config.inc.php /var/www/localhost/phpMyAdmin/
COPY srcs/wordpress.sql /root/
COPY srcs/mysql_setup.sql /root/
COPY srcs/autoindex_on.sh .
COPY srcs/autoindex_off.sh .
COPY srcs/start.sh .

# SSL AND PERMISSES
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-localhost.key -out /etc/ssl/certs/nginx-localhost.crt -subj '/C=ES/ST=Madrid/L=Madrid/O=42/CN=localhost' && chown -R www-data:www-data /var/www/* && chmod -R 755 /var/www/*

# COPYING WORDPRESS DATABASE
RUN service mysql start && mysql -u root mysql < /root/mysql_setup.sql && mysql wordpress -u root < /root/wordpress.sql

# ORGANIZING AND CLEANING UP FILES
RUN ln -s /etc/nginx/sites-available/localhost_config /etc/nginx/sites-enabled/ && rm -rf /root/wordpress-5.4.tar.gz && rm -rf /var/www/localhost/phpMyAdmin-4.9.5-english.tar.gz && rm /var/www/localhost/wordpress/wp-config-sample.php && rm /var/www/localhost/phpMyAdmin/config.sample.inc.php && rm /root/mysql_setup.sql

# STARTING SERVICES
CMD bash start.sh && tail -f /dev/null
