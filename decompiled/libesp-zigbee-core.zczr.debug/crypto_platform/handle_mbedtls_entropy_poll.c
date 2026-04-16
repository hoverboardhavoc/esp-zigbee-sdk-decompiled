/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform.o -> handle_mbedtls_entropy_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

int handle_mbedtls_entropy_poll(void *data,uchar *output,size_t output_len,size_t *olen)

{
  int iVar1;
  
  iVar1 = ezb_plat_crypto_entropy_get(output,output_len & 0xffff);
  if (iVar1 == 0) {
    iVar1 = 0;
    if (olen != (size_t *)0x0) {
      *olen = output_len;
    }
  }
  else {
    iVar1 = -0x3c;
  }
  return iVar1;
}

