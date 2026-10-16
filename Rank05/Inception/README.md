*This project has been created as part of the 42 curriculum by pdel-olm*

# INCEPTION

## Description

Inception is a project that consists on deploying a blog using Docker.  
To achieve it, three containers are created, each with a service (nginx, wordpress and mariadb).  
For the containers to communicate with each other, an internal network is created.  
Also, there are a couple of volumes where persistent data is stored and will not be erased after the containers are deleted.

## Project description

These are some of the services and concepts used:
- Docker: a platform to package a service or application in an isolated container so that it runs the same ways in every machine.  
	- Virtualization: containers virtualize the operating system, while virtual machines virtualize hardware. This makes containers lighter and faster than virtual machines.  
	- Image: a Dockerfile file is the receipt that instruct how a container is built, both the service and its dependencies.   
	- Compose: this docker tool runs a multi-container Docker application. It uses a configuration file named docker-compose.yml.  
	- Sensitive information: since it should never be commited in version control, it must be stated in an .env or secrets file. The .env file may contain several variables, and its they are passed as environment variables to the container. A secret file contains a single variable and is mounted in the container.  
	- Networks: a bridge network is an isolated virtual network to let the containers communicate with each other. A host network uses the host's network (what did you expect?) and therefore is not isolated.  
	- Volumes: Persistent storage must live outside the container because the container starts anew every time it is built. A volume mounts a container directory in the host.  
- Nginx: a lightweight web server and reverse proxy. It uses TLS to have a secure connection.  
- Wordpress: a content management system used to host this blog.  
- Mariadb: a relational databse management system.  

## Instructions

## Resources
- Peer to peer. I could not have done this by myself (as good or as fast).  
- [Docker documentation](https://docs.docker.com/).  
- [Nginx documentation](https://nginx.org/en/docs/).  
- [Wordpress documentation](https://developer.wordpress.org/).  
- [Docker documentation](https://mariadb.com/docs/).  
- Many web searches when errors occured.  
- The man (as in the manual, obv).  
