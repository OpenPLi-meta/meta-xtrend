DESCRIPTION = "V3DDRIVER for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
PACKAGE_ARCH = "${MACHINE_ARCH}"
PV = "${SRCDATE}"
DEPENDS = "libdrm mesa patchelf-native"

PROVIDES = "virtual/libgles2 virtual/libgles1 virtual/egl"
RPROVIDES_${PN} = "libnxpl.so libnexus.so libv3ddriver.so libEGL.so.1.4 libEGL.so.1 libEGL.so libGLESv1_CM.so.1.1 libGLESv1_CM.so.1 libGLESv1_CM.so libGLESv2.so.2.0 libGLESv2.so.2 libGLESv2.so"

SRC_URI = "http://downloads.openpli.org/archive/xtrend/${MACHINE}-v3ddriver-${SRCDATE}.zip"

S = "${WORKDIR}"

do_configure() {
}

do_compile() {
}

do_install_append() {
	install -d ${D}${libdir}
	install -m 0755 ${S}/libnxpl.so ${D}${libdir}/
	install -m 0755 ${S}/libnexus.so ${D}${libdir}/
	install -m 0755 ${S}/libv3ddriver.so ${D}${libdir}/
	patchelf --set-soname libv3ddriver.so ${D}${libdir}/libv3ddriver.so
	(cd ${D}/${libdir} && ln -sf libv3ddriver.so libEGL.so.1.4 \
	&& ln -sf libEGL.so.1.4 libEGL.so.1 \
	&& ln -sf libEGL.so.1 libEGL.so)
	(cd ${D}/${libdir} && ln -sf libv3ddriver.so libGLESv1_CM.so.1.1 \
	&& ln -sf libGLESv1_CM.so.1.1 libGLESv1_CM.so.1 \
	&& ln -sf libGLESv1_CM.so.1 libGLESv1_CM.so)
	(cd ${D}/${libdir} && ln -sf libv3ddriver.so libGLESv2.so.2.0 \
	&& ln -sf libGLESv2.so.2.0 libGLESv2.so.2 \
	&& ln -sf libGLESv2.so.2 libGLESv2.so)
}

do_package_qa() {
}

FILES_${PN} = "${libdir}"
FILES_${PN}-dev = "${incdir}"

INSANE_SKIP_${PN} += "already-stripped dev-so ldflags"

# The driver is missing EGL/GLES headers and pkgconfig files. Handle
# the conflicts as mesa and the driver are both providing the same shared libraries.
RREPLACES_${PN} = "libegl libegl1 libgles1 libglesv1-cm1 libgles2 libglesv2-2"
RPROVIDES_${PN} = "libegl libegl1 libgles1 libglesv1-cm1 libgles2 libglesv2-2"
RCONFLICTS_${PN} = "libegl libegl1 libgles1 libglesv1-cm1 libgles2 libglesv2-2"
