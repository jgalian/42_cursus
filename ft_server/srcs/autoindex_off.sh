#! /bin/bash

sed -i 's/autoindex on/autoindex off/' /etc/nginx/sites-available/localhost_config
service nginx restart

#bash
