FROM ubuntu:latest

# Install necessary packages
RUN apt-get update && apt-get install -y \
    clang \
    make \
    musl-dev && \
    ln -sf /usr/bin/clang++ /usr/bin/c++ && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory to /app
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app/