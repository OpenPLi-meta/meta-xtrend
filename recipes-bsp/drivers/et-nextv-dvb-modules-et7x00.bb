KV = "4.4.8"
SRCDATE = "20170424"
GCC = "6.3.0"

SRC_URI = "http://downloads.openpli.org/archive/xtrend/${MACHINE}-drivers-${KV}-${GCC}-${SRCDATE}.zip"

require et-nextv-dvb-modules.inc

SRC_URI[md5sum] = "ffb420f7fe0c00603cf3f4d063828cf6"
SRC_URI[sha256sum] = "48f9e09b23081eeab860c41aed08b0d9fbb1a60ab47b85d80322c2897df55e51"

COMPATIBLE_MACHINE = "et7x00"
