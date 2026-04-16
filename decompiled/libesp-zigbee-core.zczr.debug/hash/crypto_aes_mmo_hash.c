/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> crypto_aes_mmo_hash
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t crypto_aes_mmo_hash(uint8_t *input,uint32_t input_len,uint8_t *output)

{
  uint uVar1;
  ezb_err_t eVar2;
  
  if (input_len < 0x20000000) {
    memset(output,0,0x10);
    uVar1 = 0;
    while (uVar1 + 0x10 <= input_len) {
      aes_mmo_hash_core(input + uVar1,output);
      uVar1 = uVar1 + 0x10;
    }
    aes_mmo_hash_tail(input + uVar1,input_len,output);
    eVar2 = 0;
  }
  else {
    eVar2 = 2;
  }
  return eVar2;
}

