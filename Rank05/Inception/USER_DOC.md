# USER DOCUMENTATION

## Services provided

- Nginx: the only entry point. It handles HTTPS and forwards PHP to WordPress.  
- Mariadb: the database where the content is stored.  
- Wordpress: the blog you see (pages, posts, comments...).  

## Start and stop the project

- `make all`: the first time you want to run this project. This will create the volumes and build and start the containers.  
- `make down`: when you want to stop the containers.  
- `make up`: when you want to restart the continers.  
- `make clean`: deletes containers, images and cache.  
- `make fclean`: same as clean, but deletes the volumes too. Persistent data is deleted. You may need sudo to delete the volumes.  

## Access the website and the admin panel

You access the website through https://localhost. To access through https://login.42.fr, you have to add to your /etc/hosts the following line (you'll need privileges):  
`127.0.0.1 login.42.fr`  
The TLS is self-signed so you'll receive a warning it's not safe. Click on `Advanced` and proceed to the page.  
You can log in at https://login.42.fr/wp-login.php.  
The admin panel is at https://login.42.fr/wp-admin.  

## Locate and manage credentials

Before running the application, create a .env file by copying the given .env.example file at srcs. Then edit every variable you want to change.  

## Check running services

`make ps` will show you all running services.  
