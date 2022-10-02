# Tensorflow Docker
By default the docker file uses tensorflow:latest version of ROCm tensorflow docker. The following insructions allow the user to pass a different version as {TENSORFLOW_VERSION} argument.

## Build - dockerfiles

```
sudo docker build --build-arg TENSORFLOW_VERSION={tensorflow_version_value} -f {DOCKER_FILE_NAME}.dockerfile -t {DOCKER_IMAGE_NAME} .
```

## Run - docker

```
sudo docker run -it --device=/dev/kfd --device=/dev/dri --cap-add=SYS_RAWIO --device=/dev/mem --group-add video --network host --env DISPLAY=unix$DISPLAY --privileged --volume $XAUTH:/root/.Xauthority --volume /tmp/.X11-unix/:/tmp/.X11-unix {DOCKER_IMAGE_NAME}
```