# $NetBSD: Makefile,v 1.4 2019/11/02 16:16:19 rillig Exp $

DISTNAME=	harminv-1.3.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://ab-initio.mit.edu/harminv/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ab-initio.mit.edu/wiki/index.php/Harminv
COMMENT=	Solver of harmonic inversion
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran77

PKGCONFIG_OVERRIDE+=	harminv.pc.in

TEST_TARGET=	check

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
