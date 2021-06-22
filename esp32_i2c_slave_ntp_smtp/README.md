### Configure the project

```
idf.py menuconfig
```

* Configure Wi-Fi or Ethernet under "Example Connection Configuration" menu. See "Establishing Wi-Fi or Ethernet Connection" section in [examples/protocols/README.md](../README.md) for more details.

Please set the following parameters under example config for SMTP client demo to work:
  - Email server, port, sender's email ID, password, recipient's email ID.


### Build and Flash

Build the project and flash it to the board, then run monitor tool to view serial output:

```
idf.py -p PORT flash monitor
```

(Replace PORT with the name of the serial port to use.)

(To exit the serial monitor, type ``Ctrl-]``.)

## Note:
  - You might need to enable permission for less secure apps from email provider. This is because these email providers (e.g. gmail) insist on OAUTH authorization.
