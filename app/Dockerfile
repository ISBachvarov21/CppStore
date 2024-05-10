FROM alpine:3.19.1

RUN apk update
RUN apk add coreutils
RUN apk add build-base
RUN apk add cmake
RUN apk add xdg-utils
RUN apk add firefox
RUN apk add wslu

WORKDIR /server

COPY . .

RUN cmake -S . -B build
RUN cmake --build build

# copy build files to /app
RUN mkdir /app
RUN cp -r build/* /app

EXPOSE 80

CMD [ "stdbuf", "-oL", "./build/CppHttp" ]