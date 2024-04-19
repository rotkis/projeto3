{ pkgs }: {
	deps = [
   pkgs.tk
   pkgs.tcl
   pkgs.qhull
   pkgs.pkg-config
   pkgs.gtk3
   pkgs.gobject-introspection
   pkgs.ghostscript
   pkgs.freetype
   pkgs.ffmpeg-full
   pkgs.cairo
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}