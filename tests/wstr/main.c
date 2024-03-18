#include <stdio.h>
#include <swilib.h>
#include <time.h>
#include <fcntl.h>
#include <math.h>
#include <dirent.h>
#include <stdbool.h>
#include <stdlib.h>

static void init_stdio(void) {
	__setup_stdout_fd(open("0:\\Misc\\stdout.txt", O_CREAT | O_TRUNC | O_WRONLY));
	__setup_stderr_fd(open("0:\\Misc\\stderr.txt", O_CREAT | O_TRUNC | O_WRONLY));
}

void dump_ws(WSHDR *ws) {
	printf("WS[%d]:", wstrlen(ws));
	for (int i = 0; i < wstrlen(ws) + 1; i++) {
		printf(" %04X", ws->wsbody[i]);
	}
	printf("\n");
}

void test_AllocWS() {
	printf("--------------------- %s\n", __func__);
	WSHDR *ws = AllocWS(128);
	printf("AllocWS(128):\n");
	printf(" ws->wsbody = %p\n", ws->wsbody);
	printf(" ws->ws_malloc = %p\n", ws->ws_malloc);
	printf(" ws->ws_mfree = %p\n", ws->ws_mfree);
	printf(" ws->isbody_allocated = %d\n", ws->isbody_allocated);
	printf(" ws->maxlen = %d\n", ws->maxlen); // 128+1
	printf(" ws->unk1 = %d\n", ws->unk1); // ?
	printf(" wstrlen=%d\n", wstrlen(ws));
	FreeWS(ws);

}

void test_str_2ws() {
	printf("--------------------- %s\n", __func__);
	WSHDR *ws = AllocWS(128);
	str_2ws(ws, "hello world", 128);
	printf("str_2ws:\n");
	printf(" ws->wsbody = %p\n", ws->wsbody);
	printf(" ws->ws_malloc = %p\n", ws->ws_malloc);
	printf(" ws->ws_mfree = %p\n", ws->ws_mfree);
	printf(" ws->isbody_allocated = %d\n", ws->isbody_allocated);
	printf(" ws->maxlen = %d\n", ws->maxlen); // 128+1
	printf(" ws->unk1 = %d\n", ws->unk1); // ?
	printf(" wstrlen=%d\n", wstrlen(ws));
	FreeWS(ws);
}

void test_CreateWS() {
	printf("--------------------- %s\n", __func__);
	WSHDR *ws2 = (WSHDR *) CreateWS(malloc_adr(), mfree_adr(), 128);
	printf("CreateWS(128):\n");
	printf(" ws->wsbody = %p\n", ws2->wsbody);
	printf(" ws->ws_malloc = %p\n", ws2->ws_malloc);
	printf(" ws->ws_mfree = %p\n", ws2->ws_mfree);
	printf(" ws->isbody_allocated = %d\n", ws2->isbody_allocated);
	printf(" ws->maxlen = %d\n", ws2->maxlen); // 128+1
	printf(" ws->unk1 = %d\n", ws2->unk1); // ?
	printf(" wstrlen=%d\n", wstrlen(ws2));
	FreeWS(ws2);
}

void test_CreateLocalWS() {
	printf("--------------------- %s\n", __func__);
	uint16_t body[128];
	WSHDR ws2;
	CreateLocalWS(&ws2, body, 128);
	printf("CreateWS(128):\n");
	printf(" ws->wsbody = %p\n", ws2.wsbody);
	printf(" ws->ws_malloc = %p\n", ws2.ws_malloc);
	printf(" ws->ws_mfree = %p\n", ws2.ws_mfree);
	printf(" ws->isbody_allocated = %d\n", ws2.isbody_allocated);
	printf(" ws->maxlen = %d\n", ws2.maxlen); // 128
	printf(" ws->unk1 = %d\n", ws2.unk1); // ?
	printf(" wstrlen=%d\n", wstrlen(&ws2));
}

void test_CutWSTR() {
	printf("--------------------- %s\n", __func__);
	WSHDR *ws = AllocWS(128);
	str_2ws(ws, "hello world", 128);
	printf(" wstrlen=%d\n", wstrlen(ws));
	CutWSTR(ws, 4);
	printf(" wstrlen=%d\n", wstrlen(ws));
	CutWSTR(ws, 0);
	printf(" wstrlen=%d\n", wstrlen(ws));
	FreeWS(ws);
}

void test_cat() {
	printf("--------------------- %s\n", __func__);
	WSHDR *ws = AllocWS(128);
	WSHDR *ws2 = AllocWS(128);
	WSHDR *ws3 = AllocWS(128);
	
	str_2ws(ws, "hello", 128);
	str_2ws(ws2, " world!", 128);
	
	printf(" hello=%d\n", wstrlen(ws));
	printf(" world=%d\n", wstrlen(ws2));
	
	wstrcat(ws3, ws);
	printf(" stage0=%d\n", wstrlen(ws3));
	
	wstrcat(ws3, ws2);
	printf(" stage1=%d\n", wstrlen(ws3));
	
	wsAppendChar(ws3, 0x0033);
	printf(" stage2=%d\n", wstrlen(ws3));
	
	char *utf8_buffer = malloc(128 + 1);
	int utf8_len = 0;
	ws_2utf8(ws3, utf8_buffer, &utf8_len, 128);
	printf(" utf8_buffer=%s [utf8_len=%d]\n", utf8_buffer, utf8_len);
	free(utf8_buffer);
	
	FreeWS(ws);
	FreeWS(ws2);
	FreeWS(ws3);
}

void test_conv() {
	printf("--------------------- %s\n", __func__);
	WSHDR *ws = AllocWS(128);
	int ret;
	ret = utf8_2ws(ws, "\xf0\x9f\x98\x8b", 128);
	printf("utf8_2ws: ret=%d, len=%d\n", ret, wstrlen(ws));
	
	char buffer[128];
	int len;
	ret = ws_2utf8(ws, buffer, &len, 127);
	printf("ws_2utf8: ret=%d, len=%d, str=%s\n", ret, len, buffer);
	
	dump_ws(ws);
	FreeWS(ws);
}

void test_cmp() {
	printf("--------------------- %s\n", __func__);
	WSHDR *ws = AllocWS(128);
	WSHDR *ws2 = AllocWS(128);
	
	str_2ws(ws, "1.1", 128);
	str_2ws(ws2, "1.2", 128);
	dump_ws(ws);
	dump_ws(ws2);
	printf("cmp1: %d\n", wstrcmp(ws, ws2));
	printf("cmp2: %d\n", wstrcmp(ws2, ws));
	
	str_2ws(ws, "1.1", 128);
	str_2ws(ws2, "1.1", 128);
	dump_ws(ws);
	dump_ws(ws2);
	printf("cmp3: %d\n", wstrcmp(ws, ws2));
	
	FreeWS(ws);
	FreeWS(ws2);
}

void test_wsbody() {
	printf("--------------------- %s\n", __func__);
	printf("WSHDR size: %d\n", sizeof(WSHDR));
	
	WSHDR *ws = AllocWS(128);
	dump_ws(ws);
	
	str_2ws(ws, "1.1", 128);
	dump_ws(ws);
	
	ws->wsbody[1] = 0;
	ws->wsbody[2] = 0;
	ws->wsbody[3] = 0;
	dump_ws(ws);
	
	FreeWS(ws);
}

void test_find() {
	printf("--------------------- %s\n", __func__);
	WSHDR *ws = AllocWS(128);
	str_2ws(ws, "TEST", 128);
	dump_ws(ws);
	
	printf("find0: %d\n", (int) wstrchr(ws, 0, 0xDDDD));
	printf("find1: %d\n", (int) wstrchr(ws, 0, 0x0053));
	
	printf("find0r: %d\n", (int) wstrrchr(ws, ws->wsbody[0] - 1, 0xDDDD));
	printf("find1r: %d\n", (int) wstrrchr(ws, ws->wsbody[0] - 1, 0x0053));
	
	FreeWS(ws);
}

void test_str_ops() {
	printf("--------------------- %s\n", __func__);
	WSHDR *ws = AllocWS(128);
	str_2ws(ws, "TEST", 128);
	dump_ws(ws);
	
	printf("ret=%d\n", wsInsertChar(ws, 0x33, 1));
	dump_ws(ws);
	
	printf("ret=%d\n", wsInsertChar(ws, 0x44, 2));
	dump_ws(ws);
	
	printf("ret=%d\n", wsInsertChar(ws, 0x77, 7));
	dump_ws(ws);
	
	wsRemoveChars(ws, 2, 4);
	dump_ws(ws);
	
	FreeWS(ws);
}

void test_wprintf() {
	printf("--------------------- %s\n", __func__);
	
	WSHDR *ws2 = AllocWS(128);
	str_2ws(ws2, "[µ®©|ппп]", 128); // CP1252?
	
	WSHDR *ws = AllocWS(1024);
	// format - CP1252 string
	// %t - cp1251 string
	// %s - cp1252 string
	// %w - utf16 string
	int ret = wsprintf(ws, "\n\nFMT: [µ®©|ппп] | s=%s, t=%t, w=%w\n", "[µ®©|ппп]", "[µ®©|ппп]", ws2);
	
	wstrcatprintf(ws, "\n\n\nadd: %08X\n", 0xAADDEEDD);
	
	char buffer[1024];
	int len;
	ws_2utf8(ws, buffer, &len, 1023);
	printf("%s\n", buffer);
	printf("ret=%d\n", ret);
	
	FreeWS(ws);
	FreeWS(ws2);
}

void run_tests() {
	test_AllocWS();
	test_str_2ws();
	test_CreateWS();
	test_CreateLocalWS();
	test_cat();
	test_conv();
	test_cmp();
	test_wsbody();
	test_find();
	test_str_ops();
	test_wprintf();
	
	fflush(stdout);
	fflush(stderr);
	fclose(stdout);
	fclose(stderr);
	
	kill_elf();
}

int main() {
	init_stdio();
	run_tests();
    return 0;
}
