#!/bin/sh

# php --help (-S, --server; Start the internal web server / -t, --docroot; Specify the root of the document for the internal web server).
php -S 0.0.0.0:5000 -t /www/phpmyadmin
