# $NetBSD: Makefile,v 1.70 2020/03/10 22:10:25 wiz Exp $
#

PLUGIN_NAME=    archive

PKGREVISION= 4
.include "../../mail/claws-mail/plugins.mk"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Adds archiving to Claws-Mail

CONFIGURE_ARGS+=	--enable-${PLUGIN_NAME}-plugin

DEPENDS+=	claws-mail-${CLAWS_VERSION}{,nb[0-9]*}:../../mail/claws-mail

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
