# $NetBSD: Makefile,v 1.16 2020/01/18 23:32:20 rillig Exp $

DISTNAME=	a2ping
PKGNAME=	tex-${DISTNAME}-2.83p
PKGREVISION=	2
TEXLIVE_REV=	46893

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/a2ping
COMMENT=	Advanced PS, PDF, EPS converter
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run sh:run

REPLACE_SH=	bin/a2ping

SUBST_CLASSES+=		perl
SUBST_MESSAGE.perl=	Setting path to perl.
SUBST_STAGE.perl=	pre-configure
SUBST_FILES.perl=	bin/a2ping
SUBST_SED.perl=		-e 's,@PERL@,${PERL5},g'

TEX_TEXMF_DIRS=	none

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/a2ping/a2ping.pl ${WRKSRC}/bin/a2ping
	${RM} -r ${WRKSRC}/texmf-dist

pre-install:
	${RM} ${WRKSRC}/bin/*.orig

.include "../../mk/bsd.pkg.mk"
