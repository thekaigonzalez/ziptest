#include "string.h"
#include "zip.h"

#include <malloc.h>
#include <stdio.h>

#define string_length(x) ((x)._s)
#define string_value(x) ((x)._p)

void
addstr (string *s, const char *str) {
  while (*str) {
    string_append (s, *str);
    str++;
  }
}

main ()
{
  struct zip_t *zip = zip_open ("foo.zip", ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');
  {
    zip_entry_open (zip, "packagelist.txt");
    {
      string b;
      string1 (&b);

      addstr (&b, "package-1\npackage-2\npackage-3");

      zip_entry_write (zip, string_value (b), string_length (b));
    }
    zip_entry_close (zip);
  }
  zip_close (zip);
}
