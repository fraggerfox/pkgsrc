# $NetBSD: Makefile,v 1.15 2020/03/12 19:39:35 nia Exp $

FIREFOX_VER=		${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
MOZ_BRANCH=		68.6
MOZ_BRANCH_MINOR=	.0esr

DISTNAME=	firefox-${FIREFOX_VER}.source
PKGNAME=	${DISTNAME:S/.source//:S/b/beta/:S/esr//:S/firefox-/firefox68-/}
CATEGORIES=	www
MASTER_SITES+=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.mozilla.com/en-US/firefox/
COMMENT=	Web browser with support for extensions (version ${FIREFOX_VER:C/\..*//})
LICENSE=	mpl-1.1

WRKSRC=		${WRKDIR}/firefox-${FIREFOX_VER:S/esr//}

MOZILLA_DIR=	# empty

# Note: when updating remember to conditionalise about-background.png in PLIST
CONFIGURE_ARGS+=	--enable-application=browser

CFLAGS+=	-I${PREFIX}/include/nspr
# for lang/gcc6
CFLAGS+=	-D_GLIBCXX_INCLUDE_NEXT_C_HEADERS
CFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGBASE}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS.DragonFly+=	-lplc4 -lnspr4
LDFLAGS.FreeBSD+=	-lplc4 -lnspr4
LDFLAGS.Linux+=		-lnspr4
LDFLAGS.SunOS+=		-lm

NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/${MOZILLA}
NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/${MOZILLA}-bin
NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/plugin-container

ALL_ENV+=		MOZ_APP_NAME=${MOZILLA}

# Avoid ld "invalid section index" errors.
BUILDLINK_TRANSFORM.SunOS+=	rm:-fdata-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-ffunction-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-pie

SUBST_CLASSES+=			dfly_malloc_h
SUBST_STAGE.dfly_malloc_h=	pre-configure
SUBST_MESSAGE.dfly_malloc_h=	Dont include malloc.h on dragonflybsd
SUBST_SED.dfly_malloc_h=	-e 's,HAVE_MALLOC_H,HAVE_MALLOC_H \&\& !defined(__DragonFly__),g'
SUBST_FILES.dfly_malloc_h+=	media/ffvpx/libavutil/mem.c

.include "mozilla-common.mk"
.include "options.mk"

CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/xpt.py

CHECK_WRKREF_SKIP+=	lib/${MOZILLA}/chrome/toolkit/content/global/buildconfig.html

MOZILLA=	${PKGBASE}
MOZILLA_ICON=	${WRKSRC}/${OBJDIR}/dist/${MOZILLA}/browser/chrome/icons/default/default48.png
.if !empty(PKG_OPTIONS:Mofficial-mozilla-branding)
MOZILLA_NAME=	Firefox
.else
MOZILLA_NAME=	Browser
.endif

post-extract:
	${CP} ${FILESDIR}/cubeb_sun.c ${WRKSRC}/media/libcubeb/src/cubeb_sun.c
	mv ${WRKSRC}/gfx/ycbcr/yuv_row_arm.s ${WRKSRC}/gfx/ycbcr/yuv_row_arm.S
# XXX Hack taken from lang/rust.
# patch(1) in NetBSD does not handle .cargo-checksum.json like long width file.
# Replace checksum fields for following patches:
# patch-third__party_rust_libc_src_unix_bsd_netbsdlike_netbsd_mod.rs,v 1.1
# patch-third__party_rust_libc_src_unix_bsd_netbsdlike_netbsd_other_mod.rs,v 1.1
	${CP} ${WRKSRC}/third_party/rust/libc/.cargo-checksum.json \
	      ${WRKSRC}/third_party/rust/libc/.cargo-checksum.json.orig
	${CAT} ${WRKSRC}/third_party/rust/libc/.cargo-checksum.json.orig | \
		${SED} -e 's/4d9f7091af8e166943ac6f42ce85558909e5b6e61325039bff7adfbcf4b90212/7f3da734d5e2e9426051da4f406e46d9e9bed43ed2d7d048e8afc8af7ed44795/' | \
		${SED} -e 's/1cd66ed5967c788562d4ad626cfbeb1544f4b9267111de5f6790379b8327f28e/6ae549dd21581748b2f1d82880eaca3445c11e3354965e5b49b20342075a3e52/' \
		> ${WRKSRC}/third_party/rust/libc/.cargo-checksum.json
	${CP} ${WRKSRC}/third_party/rust/bindgen/.cargo-checksum.json \
		${WRKSRC}/third_party/rust/bindgen/.cargo-checksum.json.orig
	${CAT} ${WRKSRC}/third_party/rust/bindgen/.cargo-checksum.json.orig | \
		${SED} -e 's/5788372d27bdbaaf0454bc17be31a5480918bc41a8a1c4832e8c61185c07f9cd/8c92a52c0f859c7bec7bfbc36b9d18f904baab0c8c9dc1b3e7af34de1a0b0da4/' | \
		${SED} -e 's/8dc10043d872e68e660ef96edca4d9733f95be45cdad4893462fa929b335014f/71f1a37f75b971ea5b0d8457473cc410947dbf706cb6d2c0338916910b78a675/' | \
		${SED} -e 's/34f9aa76b6c9c05136bb69dcd6455397faef571a567254d2c541d50a962994db/e5581852eec87918901a129284b4965aefc8a19394187a8095779a084f28fabe/' \
		> ${WRKSRC}/third_party/rust/bindgen/.cargo-checksum.json

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC}/${OBJDIR} && touch old-configure.vars

post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@FIREFOX_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop

INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${ECHO} '#! /bin/sh' > ${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${ECHO} '${PREFIX}/lib/${MOZILLA}/${MOZILLA} "$$@"' >> \
		${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}					\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
