README for logo file
====================
For PDI's project, the logo file must be named ar6mx.bmp.
The bitmap file should have an indexed color palette with
240 or less colors.  The total number of pixels (W x H) must
be divisible by 8.

The standard u-boot also requires the BMP has a standard
40 byte header.  GIMP will create that only if you select 
   `Compatibility->Do Not Write Color Space Info`
when saving.  Otherwise it creates a V4 header.  I modified the 
u-boot source code to account for larger headers, so this is not 
a requirement for our BMP's.
