# $NetBSD: Makefile,v 1.9 2019/11/03 10:16:04 rillig Exp $

DISTNAME=	Test-EOL-2.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/E/ET/ETHER/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-EOL
COMMENT=	Check the correct line endings in your project
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/EOL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
