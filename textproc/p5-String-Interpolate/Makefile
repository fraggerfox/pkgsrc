# $NetBSD: Makefile,v 1.1 2020/03/23 02:28:47 riastradh Exp $

DISTNAME=	String-Interpolate-0.32
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/String::Interpolate
COMMENT=	Wrapper for the builtin Perl interpolation engine
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp>=0:../../devel/p5-Carp
DEPENDS+=	p5-PadWalker>=0:../../devel/p5-PadWalker
DEPENDS+=	p5-Safe-Hole>=0:../../devel/p5-Safe-Hole

PERL5_PACKLIST=	auto/String/Interpolate/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
