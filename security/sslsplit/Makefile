# $NetBSD: Makefile,v 1.6 2020/01/18 21:50:48 jperkin Exp $

DISTNAME=	sslsplit-0.5.5
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://mirror.roe.ch/rel/sslsplit/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.roe.ch/sslsplit/
COMMENT=	Transparent and scalable SSL/TLS interception
LICENSE=	2-clause-bsd

MAKE_FILE=	GNUmakefile
USE_TOOLS+=	gmake

MAKE_ENV+=	LIBEVENT_BASE=${BUILDLINK_PREFIX.libevent}
MAKE_ENV+=	OPENSSL_BASE=${BUILDLINK_PREFIX.openssl}
MAKE_ENV+=	LIBNET_BASE=${BUILDLINK_PREFIX.libnet11}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sslsplit ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sslsplit.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libnet11/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
