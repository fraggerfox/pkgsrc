# $NetBSD: Makefile,v 1.12 2019/10/28 12:31:58 mef Exp $

DISTNAME=	Term-Table-0.014
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/E/EX/EXODIST/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/E/EX/EXODIST/
COMMENT=	Format a header and rows into a table
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple
TEST_DEPENDS+=	p5-Importer-[0-9]*:../../devel/p5-Importer

PERL5_PACKLIST=	auto/Term/Table/.packlist


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
