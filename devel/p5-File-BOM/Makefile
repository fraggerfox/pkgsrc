# $NetBSD: Makefile,v 1.16 2019/11/03 10:15:53 rillig Exp $

DISTNAME=	File-BOM-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-BOM
COMMENT=	Utilities for handling Byte Order Marks
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly
# for make test
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/File/BOM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
