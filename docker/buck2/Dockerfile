FROM amd64/debian
RUN apt update
RUN apt install -y curl
RUN curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs > rust_install.sh
RUN chmod u+x ./rust_install.sh
RUN ./rust_install.sh -y
RUN . "$HOME/.cargo/env"
ENV PATH=$PATH:/root/.cargo/bin
RUN rustup install nightly-2024-02-01
RUN apt install -y git
RUN apt install -y build-essential
RUN cargo +nightly-2024-02-01 install --git https://github.com/facebook/buck2.git buck2

