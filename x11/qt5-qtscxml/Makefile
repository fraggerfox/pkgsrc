# $NetBSD: Makefile,v 1.5 2020/03/10 22:09:14 wiz Exp $

DISTNAME=	qtscxml-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtscxml-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 module for scxml framework

BUILD_TARGET=		sub-src
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Scxml.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
