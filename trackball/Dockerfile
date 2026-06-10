FROM qmk/qmk_cli:latest

RUN git clone --depth 1 github.com/qmk/qmk_firmware.git:0.27.1

RUN qmk setup --home ./__qmk__ --yes