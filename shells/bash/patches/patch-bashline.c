$NetBSD: patch-bashline.c,v 1.2 2020/03/17 21:59:48 rillig Exp $

Fix array subscript with char index.

https://lists.gnu.org/archive/html/bug-bash/2020-03/msg00056.html

--- bashline.c.orig	2020-03-17 16:57:19.058552795 +0000
+++ bashline.c
@@ -4050,7 +4050,7 @@ set_filename_bstab (string)
 
   memset (filename_bstab, 0, sizeof (filename_bstab));
   for (s = string; s && *s; s++)
-    filename_bstab[*s] = 1;
+    filename_bstab[(unsigned char) *s] = 1;
 }
 
 /* Quote a filename using double quotes, single quotes, or backslashes
