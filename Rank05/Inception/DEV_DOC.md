# DEVELOPER DOCUMENTATION

## Set up the environment

You need to intall Makefile and [Docker Engine](https://docs.docker.com/engine/install/).  
Run `sudo echo "127.0.0.1 login.42.fr" >> /etc/hosts` in your terminal.  
Create srcs/.env file with the same variables as the provided srcs/.env.example, with your values.  

## Build the project

- `make all`: the first time you want to run this project. This will create the volumes and build and start the containers.  
- `make down`: when you want to stop the containers.  
- `make up`: when you want to restart the continers.  
- `make clean`: deletes containers, images and cache.  
- `make fclean`: same as clean, but deletes the volumes too. Persistent data is deleted. You may need sudo to delete the volumes.  

## Manage containers and volumes

`docker container ls`: lists all containers.  
`docker container inspect <name>`: shows information about that container.  
`docker volume ls`: lists all volumes.  
`docker volume inspect <name>`: shows information about that volume.  

## Persistent data

The volumes are created at /home/login/data so that it persists.  
A DB volume stores the databse files.  
A WordPress volume stores the WordPress files.  
