# $NetBSD: Makefile,v 1.3 2019/12/06 19:32:18 markd Exp $

DISTNAME=	opensans
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	51458

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/opensans
COMMENT=	Open Sans font family, and LaTeX support
LICENSE=	apache-2.0 AND lppl-1.3c

TEX_MAP_FILES+=	opensans.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
