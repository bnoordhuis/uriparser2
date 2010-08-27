#include <stdlib.h>
#include <string.h>

#include "uri.h"
#include "uriparser/Uri.h"

#define SIZE(c)	((c).afterLast - (c).first)

static const char *copy_range(const UriTextRangeA *r, char **buffer) {
	const char *s = *buffer;

	const int size = SIZE(*r) + 1;
	memcpy(*buffer, r->first, size);
	*buffer[size] = '\0';
	*buffer += size;

	return s;
}

static URI *create_uri(const UriUriA *uu) {
	URI *uri = malloc(sizeof(*uri)
		+ SIZE(uu->scheme)
		+ SIZE(uu->userInfo) + 1	/* userinfo will be split on : */
		+ SIZE(uu->hostText)
		+ SIZE(uu->query)
		+ SIZE(uu->fragment));

	if (uri) {
		char *buffer = (char *) (uri + 1);
		uri->scheme = copy_range(&uu->scheme, &buffer);
		uri->host = copy_range(&uu->hostText, &buffer);
		uri->query = copy_range(&uu->query, &buffer);
		uri->fragment = copy_range(&uu->fragment, &buffer);
	}

	return uri;
}

URI *uri_parse(const char *uri) {
	UriParserStateA state;
	UriUriA uu;
	URI *rv;

	state.uri = &uu;
	if (URI_SUCCESS == uriParseUriA(&state, uri)) {
		rv = create_uri(&uu);
	} else {
		rv = 0;
	}
	uriFreeUriMembersA(&uu);

	return rv;
}

char *uri_build(const URI *uri) {
	return 0;
}
