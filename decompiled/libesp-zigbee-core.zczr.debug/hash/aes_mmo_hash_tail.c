/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> aes_mmo_hash_tail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aes_mmo_hash_tail(uint8_t *last_block,uint32_t orig_len,uint8_t *hash)

{
  uint __n;
  ushort uVar1;
  int iVar2;
  uint8_t local_30 [4];
  uint8_t padding_block [16];
  
  __n = orig_len & 0xf;
  if (orig_len < 0x20000000) {
    local_30[0] = '\0';
    local_30[1] = '\0';
    local_30[2] = '\0';
    local_30[3] = '\0';
    padding_block[0] = '\0';
    padding_block[1] = '\0';
    padding_block[2] = '\0';
    padding_block[3] = '\0';
    padding_block[4] = '\0';
    padding_block[5] = '\0';
    padding_block[6] = '\0';
    padding_block[7] = '\0';
    padding_block[8] = '\0';
    padding_block[9] = '\0';
    padding_block[10] = '\0';
    padding_block[0xb] = '\0';
    if (__n == 0) goto _L0;
  }
  else {
    last_block = (uint8_t *)
                 __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hash.c",0x72,
                               "aes_mmo_hash_tail","orig_len <= ((1U << (2U * (16) - 3U)) - 1U)");
  }
  memcpy(local_30,last_block,__n);
_L0:
  padding_block[__n - 4] = 0x80;
  if (orig_len < 0x2000) {
    iVar2 = 2;
  }
  else {
    iVar2 = 6;
  }
  if (0x10 < __n + iVar2 + 1) {
    aes_mmo_hash_core(local_30,hash);
    local_30[0] = '\0';
    local_30[1] = '\0';
    local_30[2] = '\0';
    local_30[3] = '\0';
    padding_block[0] = '\0';
    padding_block[1] = '\0';
    padding_block[2] = '\0';
    padding_block[3] = '\0';
    padding_block[4] = '\0';
    padding_block[5] = '\0';
    padding_block[6] = '\0';
    padding_block[7] = '\0';
    padding_block[8] = '\0';
    padding_block[9] = '\0';
    padding_block[10] = '\0';
    padding_block[0xb] = '\0';
  }
  if (iVar2 == 2) {
    uVar1 = (ushort)(byte)((orig_len << 0x13) >> 0x18) | (ushort)(((orig_len << 0x13) >> 0x10) << 8)
    ;
    padding_block[10] = (char)uVar1;
    padding_block[0xb] = (char)(uVar1 >> 8);
  }
  else {
    write_be32(orig_len << 3,padding_block + 6);
  }
  aes_mmo_hash_core(local_30,hash);
  return;
}

