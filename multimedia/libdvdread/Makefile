# $NetBSD: Makefile,v 1.33 2020/03/26 12:01:12 nia Exp $

DISTNAME=	libdvdread-6.1.0
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/libdvdread/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdnav.mplayerhq.hu/
COMMENT=	DVD access library
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99

PKGCONFIG_OVERRIDE=	misc/dvdread.pc.in

MESSAGE_SUBST+=		PKGBASE=${PKGBASE}

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
