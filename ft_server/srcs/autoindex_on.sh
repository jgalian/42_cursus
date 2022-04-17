#! /bin/bash

sed -i 's/autoindex off/autoindex on/' /etc/nginx/sites-available/localhost_config
service nginx restart

#bash
