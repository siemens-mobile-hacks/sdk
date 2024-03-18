#pragma once

#ifndef __IN_SWILIB__
#include "base.h"
#endif

__swilib_begin

/**
 * @addtogroup OpenSSL
 * @brief Built-in OpenSSL.
 * See openssl docs for more info.
 * 
 * Usage: `#include <swilib.h>` or `#include <swilib/openssl.h>`
 * 
 * Also, you can use standart openssl headers with `#include <builtin/openssl/...>`
 * Alternatively, you can add `-Ipath/to/include/builtin` to the compiler flags.
 * 
 * @note **For GCC:** These functions is available only when define `-DSWILIB_OPENSSL` is specified in compiler flags.
 * @note Alternatively, you can include these functions directly by `#include <swilib/openssl.h>`
 * @{
 */

#if !defined(__IN_SWILIB__) || defined(SWILIB_OPENSSL)

#include "../builtin/openssl/rsa.h"
#include "../builtin/openssl/md5.h"
#include "../builtin/openssl/sha.h"
#include "../builtin/openssl/ssl.h"
#include "../builtin/openssl/bn.h"
#include "../builtin/openssl/rand.h"
#include "../builtin/openssl/evp.h"

/**
 * @name Bignum
 * @{
 * */

/**
 * Convert the positive integer in big-endian form into a BIGNUM.
 * If ret is NULL, a new BIGNUM is created.
 * @param s			positive integer in big-endian
 * @param len		size of `s`
 * @param[out] ret	result of converting
 * 
 * @return When `ret` is NULL, then a new BIGNUM is allocated.
 * @return When `ret` is specified, then it returns `ret`.
 * */
__swi_begin(0x1C2)
BIGNUM *BN_bin2bn(const unsigned char *s, int len, BIGNUM *ret)
__swi_end(0x1C2, BN_bin2bn, (s, len, ret));

/** @} */

/**
 * @name MD5 hashing
 * @{
 * */

/**
 * Calculate MD5 hash by single function.
 * @param data			pointer to the data
 * @param len			size of the data
 * @param[out] hash		pointer to the uint8_t[16] for md5 hash result (can be NULL)
 * 
 * @return When `hash` is NULL, then it returns the pointer to the static buffer with MD5 hash.
 * @return When `hash` is specified, then it returns `hash`.
 * */
__swi_begin(0x240)
uint8_t *MD5_Hash(const uint8_t *data, unsigned long len, uint8_t *hash)
__swi_end(0x240, MD5_Hash, (data, len, hash));

/**
 * Initialize a MD5_CTX structure.
 * @param c		pointer to the MD5_CTX
 * */
__swi_begin(0x23D)
void MD5_Init(MD5_CTX *c)
__swi_end(0x23D, MD5_Init, (c));

/**
 * Hash chunk of the data.
 * @param c		pointer to the MD5_CTX
 * @param data	pointer to the data
 * @param len	size of the data
 * */
__swi_begin(0x23E)
void MD5_Update(MD5_CTX *c, const void *data, unsigned long len)
__swi_end(0x23E, MD5_Update, (c, data, len));

/**
 * Finalize the MD5 calculation and get hash.
 * @param[out] hash		pointer to the uint8_t[16] for md5 hash result
 * @param c				pointer to the MD5_CTX
 * */
__swi_begin(0x23F)
void MD5_Final(uint8_t *hash, MD5_CTX *c)
__swi_end(0x23F, MD5_Final, (hash, c));

/** @} */

/**
 * @name SHA256 hashing
 * @{
 * */

/**
 * Initialize a SHA_CTX structure.
 * @param c		pointer to the SHA_CTX
 * */
__swi_begin(0x1BC)
void SHA1_Init(SHA_CTX *c)
__swi_end(0x1BC, SHA1_Init, (c));

/**
 * Hash chunk of the data.
 * @param c		pointer to the SHA_CTX
 * @param data	pointer to the data
 * @param len	size of the data
 * */
__swi_begin(0x1BD)
void SHA1_Update(SHA_CTX *c, const void *data, unsigned long len)
__swi_end(0x1BD, SHA1_Update, (c, data, len));

/**
 * Finalize the SHA1 calculation and get hash.
 * @param[out] hash		pointer to the uint8_t[16] for md5 hash result
 * @param c				pointer to the SHA_CTX
 * */
__swi_begin(0x1BE)
void SHA1_Final(unsigned char *hash, SHA_CTX *c)
__swi_end(0x1BE, SHA1_Final, (hash, c));

/** @} */

/**
 * @name RSA digest
 * @{
 * */

/**
 * Allocate and initialize an RSA structure so that method will be used for the RSA operations.
 * @param method	RSA method
 * @return pointer to the allocated and initialized RSA structure
 * */
__swi_begin(0x1BF)
RSA *RSA_new_method(RSA_METHOD *method)
__swi_end(0x1BF, RSA_new_method, (method));

/**
 * Sign message digest by the RSA.
 * @param type			message digest algorithm
 * @param m				input message
 * @param m_len			input message length
 * @param[out] sigret	output RSA signature
 * @param[out] siglen	output RSA signature length
 * @param rsa			initialized RSA structure
 * @return 1: success, 0: error
 * */
__swi_begin(0x1C1)
int RSA_sign(int type, unsigned char *m, unsigned int m_len, unsigned char *sigret, unsigned int *siglen, RSA *rsa)
__swi_end(0x1C1, RSA_sign, (type, m, m_len, sigret, siglen, rsa));

/**
 * Free RSA structure.
 * @param rsa			initialized RSA structure
 * */
__swi_begin(0x1C0)
void RSA_free(RSA *rsa)
__swi_end(0x1C0, RSA_free, (rsa));

/** @} */


/**
 * @name Random
 * @{
 * */
 
/**
 * Get selected random method.
 * @return pointer to random method
 * */
__swi_begin(0x8394)
RAND_METHOD *RAND_get_rand_method(void)
__swi_end(0x8394, RAND_get_rand_method, ());

/** @} */

/**
 * @name SSL
 * @{
 * */

/**
 * Get selected SSL method.
 * @return pointer to SSL method
 * */
__swi_begin(0x395)
SSL_METHOD *TLSv1_client_method()
__swi_end(0x395, TLSv1_client_method, ());

/**
 * Allocate and initialize an SSL_CTX structure so that method will be used for the SSL operations.
 * @param meth	SSL method
 * @return pointer to the allocated and initialized SSL_CTX structure
 * */
__swi_begin(0x396)
SSL_CTX *SSL_CTX_new(SSL_METHOD *meth)
__swi_end(0x396, SSL_CTX_new, (meth));

/**
 * Free SSL_CTX structure.
 * @param ctx			initialized SSL_CTX structure
 * */
__swi_begin(0x397)
void SSL_CTX_free(SSL_CTX *ctx)
__swi_end(0x397, SSL_CTX_free, (ctx));

/**
 * Manipulate settings of the SSL_CTX object.
 * @param ctx			initialized SSL_CTX structure
 * @param cmd			internal command
 * @param larg, parg	command arguments
 * @return The return values depend on the command supplied via the cmd parameter.
 * */
__swi_begin(0x398)
long SSL_CTX_ctrl(SSL_CTX *ctx, int cmd, long larg, void *parg)
__swi_end(0x398, SSL_CTX_ctrl, (ctx, cmd, larg, parg));

/**
 * Create an SSL structure for a connection.
 * @param ctx			initialized SSL_CTX structure
 * @return pointer to the allocated and initialized SSL structure
 * */
__swi_begin(0x399)
SSL *SSL_new(SSL_CTX *ctx)
__swi_end(0x399, SSL_new, (ctx));

/**
 * Connect the SSL object with a file descriptor.
 * @param s		initialized SSL structure
 * @param fd	socked descriptor
 * @return 1 or error
 * */
__swi_begin(0x39A)
int SSL_set_fd(SSL *s, int fd)
__swi_end(0x39A, SSL_set_fd, (s, fd));

/**
 * Initiate the TLS/SSL handshake with an TLS/SSL server.
 * @param ssl		initialized SSL structure
 * @return 1 or error
 * */
__swi_begin(0x39B)
int SSL_connect(SSL *ssl)
__swi_end(0x39B, SSL_connect, (ssl));

/**
 * Shut down a SSL connection.
 * @param ssl		initialized SSL structure
 * @return 1 or error
 * */
__swi_begin(0x39C)
int SSL_shutdown(SSL *ssl)
__swi_end(0x39C, SSL_shutdown, (ssl));

/**
 * Read bytes from a SSL connection.
 * @param ssl		initialized SSL structure
 * @param buf		pointer to a buffer for the read data
 * @param num		maximum size for read
 * @return count of readed bytes or error (<= 0)
 * */
__swi_begin(0x39D)
int SSL_read(SSL *ssl, void *buf, int num)
__swi_end(0x39D, SSL_read, (ssl, buf, num));

/**
 * Read bytes from a SSL connection.
 * @note #SSL_peek() are identical to #SSL_read() respectively except no bytes are actually removed from the underlying BIO during the read,
 * 	so that a subsequent call to #SSL_read() will yield at least the same bytes.
 * @param ssl		initialized SSL structure
 * @param buf		pointer to a buffer for the read data
 * @param num		maximum size for read
 * @return count of readed bytes or error (<= 0)
 * */
__swi_begin(0x39E)
int SSL_peek(SSL *ssl, void *buf, int num)
__swi_end(0x39E, SSL_peek, (ssl, buf, num));

/**
 * Write bytes to a SSL connection.
 * @param ssl		initialized SSL structure
 * @param buf		pointer to a buffer with data to be written
 * @param num		maximum size for write
 * @return count of written bytes or error (<= 0)
 * */
__swi_begin(0x39F)
int SSL_write(SSL *ssl, const void *buf, int num)
__swi_end(0x39F, SSL_write, (ssl, buf, num));

/**
 * Free an allocated SSL structure.
 * @param ssl		initialized SSL structure
 * */
__swi_begin(0x3A0)
void SSL_free(SSL *ssl)
__swi_end(0x3A0, SSL_free, (ssl));

/**
 * Set a SSL session to be used during SSL connect.
 * @param ssl		initialized SSL structure
 * @param session	pointer to the #SSL_SESSION
 * @return 1 or error
 * */
__swi_begin(0x3A1)
int SSL_set_session(SSL *ssl, SSL_SESSION *session)
__swi_end(0x3A1, SSL_set_session, (ssl, session));

/**
 * Free an allocated SSL_SESSION structure.
 * @param sess		initialized SSL_SESSION structure
 * */
__swi_begin(0x3A2)
void SSL_SESSION_free(SSL_SESSION *sess)
__swi_end(0x3A2, SSL_SESSION_free, (sess));

/** @} */

/**
 * @name EVP
 * @{
 * */

/**
 * Add new EVP cipher.
 * @param c		pointer to the #EVP_CIPHER
 * @return 1 or error
 * */
__swi_begin(0x3AC)
int EVP_add_cipher(EVP_CIPHER *c)
__swi_end(0x3AC, EVP_add_cipher, (c));

/** @} */

#endif /* SWILIB_OPENSSL */

__swilib_end

/** @} */
