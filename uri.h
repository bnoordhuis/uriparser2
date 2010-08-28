#ifndef URI_H_
#define URI_H_

typedef struct {
	const char *scheme;
	const char *user;
	const char *pass;
	const char *host;
	unsigned short port;
	const char *path;
	const char *query;
	const char *fragment;
} URI;

URI *uri_parse(const char *uri);

char *uri_build(const URI *uri);

int uri_compare(URI *a, URI *b);

#endif	/* uri.h */
