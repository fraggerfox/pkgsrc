# $NetBSD: Makefile,v 1.8 2020/01/18 21:50:46 jperkin Exp $

DISTNAME=	qore-asn1-module-0.0.3
PKGREVISION=	7
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://www.qore.org/
COMMENT=	ASN.1 Qore module
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++11
PTHREAD_OPTS+=	require

INSTALLATION_DIRS+=     share/doc/qore-asn1-module
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/asn1-module-doc.html \
		${DESTDIR}${PREFIX}/share/doc/qore-asn1-module

.include "options.mk"
.include "../../lang/qore/module.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
