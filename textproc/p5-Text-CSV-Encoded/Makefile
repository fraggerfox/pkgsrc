# $NetBSD: Makefile,v 1.15 2019/08/11 13:23:42 wiz Exp $

DISTNAME=	Text-CSV-Encoded-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-CSV-Encoded
COMMENT=	Encoding aware Text::CSV
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-CSV>=1.31:../../textproc/p5-Text-CSV

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Text/CSV/Encoded/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
