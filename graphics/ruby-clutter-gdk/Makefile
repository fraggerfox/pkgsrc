# $NetBSD: Makefile,v 1.3 2020/03/10 22:10:13 wiz Exp $
#

DISTNAME=		clutter-gdk-${VERSION}
COMMENT=		Ruby binding of GDK specific API of Clutter
PKGREVISION=		2
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		ruby-gnome2-clutter-gdk-[0-9]*
SUPERSEDES+=		ruby-gnome2-clutter-gdk-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-clutter>=${VERSION}:../../graphics/ruby-clutter
DEPENDS+=	${RUBY_PKGPREFIX}-gdk3>=${VERSION}:../../graphics/ruby-gdk3

.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
