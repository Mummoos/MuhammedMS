#include <pgmspace.h>

#define SECRET
#define THINGNAME "ESP_CAM"

const char WIFI_SSID[] = "JioFiber-rJ4A6";
const char WIFI_PASSWORD[] = "Verdant@9876";
const char AWS_IOT_ENDPOINT[] = "alq5vzvrt1h0b-ats.ap-northeast-1.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVALKSo5OKZr3E1wM451f0vj6AYZRHMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMjExMjIwNTU0
MTVaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCbyZ3UmnAK49Il3RJ1
Z5P0e+Yv0EtchlsEdV4ckDkkNMV7Eo7sUlufOosz4vHcHYxn42k0Jfr44ZKgbog3
M03BSxDrWxIM72pe7ihJeELOooZnvLEKOxNOBJuXZ1tSXqg5u1zffddxSRPfjxaY
mzvVLpFTZZV6AjuMrfrv8R+bAzYxVg5cvLkWXU26d7Lb+qM16Y0ILh//O39rVMVd
WCcYb9Ju261ehyr1oaEcdr08dc2vK9rMh7NBvu5bv+P7p4GBgaTAH7ksTXfWsmUI
hkmVZVt7oW2PhLCnsIkVELcLX8IqS0khPX4Da9ECsg93cfC4K2BJU2ihUUfwfwlv
addBAgMBAAGjYDBeMB8GA1UdIwQYMBaAFAC0DQ8/TV+uWK3E9rTwK2GwaQcmMB0G
A1UdDgQWBBToCegvnLsGS9IsiLh/WB3fXD9T7zAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAdZ7iOunCaV+BL1wDHyTHlC1B
O6aUcOffHRhaYr9Ke4QF/Ti0fbJ4Ma6QcjEDLXFMlc6jLNH3Ay/1aZ/DaUzgyE+q
UwMG8uTcAf0EUKJR20A6iZ7EpkbjN8Cd7g/JFar2AXBLRU0gqn1shwz2y/klMgd9
l6gndwgcTNQx5fjiImTbDOV+2AiJYrJ6JHtUo/CU/eK4HCK5eoI2wb3Iy0zxV9b5
LjyQMF/aVwHX3Zib37rI/3YRXqsoiD5nzMdSgU7Jg78dYXxq09j/WU2UfkGu01SO
WrPW0SRUItlfisVlIoC0K8WpwroU2WqFqEjGpDWopZS+0j0qFPGdVFHJamIIwA==
-----END CERTIFICATE-----

)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEAm8md1JpwCuPSJd0SdWeT9HvmL9BLXIZbBHVeHJA5JDTFexKO
7FJbnzqLM+Lx3B2MZ+NpNCX6+OGSoG6INzNNwUsQ61sSDO9qXu4oSXhCzqKGZ7yx
CjsTTgSbl2dbUl6oObtc333XcUkT348WmJs71S6RU2WVegI7jK367/EfmwM2MVYO
XLy5Fl1Nuney2/qjNemNCC4f/zt/a1TFXVgnGG/SbtutXocq9aGhHHa9PHXNryva
zIezQb7uW7/j+6eBgYGkwB+5LE131rJlCIZJlWVbe6Ftj4Swp7CJFRC3C1/CKktJ
IT1+A2vRArIPd3HwuCtgSVNooVFH8H8Jb2nXQQIDAQABAoIBAQCaelAxM3sKsWH+
/bqCBNVnxzw4CVnRQ8EZKLDLrg+bYWC5a2uh1wDXYZwLNW0TEZHaqlv1w/ubs0JM
J46W/h6KHz+FweaiQP2/aHU2dTP55ptUXn1HYdEAufz3IxwhD4/Mv4eWbhimUwqL
0j1b0gKAoA6nHcIdG/2kwBhmuTjX4cka0y4wkZfK1/+cRgl/lNEGidFXJYCfgCyc
tJNbTcpdj3yGX6l77eejkbV0BZf8hQ+cIEVQtLYbkwX+LSUGucGCrkQaudblm/tT
dlvN+Rc+09tQn2NVutm0JJXne9n9JHaM4XBG60gjI88VGYYAzvbnI7w+TNPeF+bv
zQxQv9BpAoGBAM7t1i4x7INo/n2r5DNfiuut0O4QBJJ8VdgrUqELlG2LeM4OFgzV
1unmLPOJkXWljMhfOZSvApBEpzW7I6gOhCl9zSkpzUPQV4agbRtPgaGprt00TvrJ
3jZrwfdSZbv8D5Kgnaqi8jL/Wbylwm70dsi8Hm5rpcz7eVYayzDIHZp/AoGBAMC7
Go13YvCObo1rIrVkokOFgDOglIubzl8eKDoUo0Actf6YfSTzlog64qLJ/pwAJhJY
w1XUTc9PBp5Q4c4xg3ZITBJ7hO4sEizvIsZOWJUDK8oj03wKchhCckatSUmzRf3x
yUzOb+qkmQQK9ukOgfPf/gZt0jgjIViAkvfmoi4/AoGADLsVMkJgCrWq8pBguchn
A5juAbd6kIiVv3bq3n2X5CVwiTzUnnWJg1pl6ZXNHS/SOYGiSUN7JOUUZHne97fs
6aCTvrSTrFhlCiNUkxmRICEQYQuW0FcbFL4McOrg12/qhVrcWGMuA3UyUCjijXD8
3dy1ApYc3T+bd3Cuj5HAQIECgYAo9xwbuaaUDxI8iOsltzAuPfAUCSvJyOJCoXxX
bA+PDws4BF2FPyld53ZIt7qgmf99otRSKAAp8lgrynFUjH2u5IsW2p5UqZVra6Du
mbSGZ9gk7RyEnwvFUEpN74NGYQ6dfYkWBEMRks7bZyE4RFcm6RNrdmhaek0aLKoQ
ezs5rQKBgFWLB2IyiutvtVwQzdK4enWPVNw2XhdUYkLfR7g5YuDuQFLJq50CXF/k
Gn+6gAQNQfSQIuBQsLCdyHLEdie/b+tIQaeJ5VxMm5Ycd//mHJbshEUGJ+wHHno5
WqX/jUqAqNQCY/TdjJeLZ/bjFJwKQ/TrkDmYv4XRQ/eTFWqj+bxV
-----END RSA PRIVATE KEY-----

)KEY";
