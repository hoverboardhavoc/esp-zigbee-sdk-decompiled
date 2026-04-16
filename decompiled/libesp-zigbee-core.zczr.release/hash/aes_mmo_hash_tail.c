/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> hash.o -> aes_mmo_hash_tail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aes_mmo_hash_tail(uint8_t *last_block,uint32_t orig_len,uint8_t *hash)

{
  uint extraout_a1;
  ushort uVar1;
  ushort uVar2;
  uint __n;
  int iVar3;
  uint8_t local_30 [4];
  uint8_t padding_block [16];
  
  if (0x1fffffff < orig_len) {
    hash = (uint8_t *)0x0;
    last_block = (uint8_t *)__assert_func(0,0,0,0);
    orig_len = extraout_a1;
  }
  __n = orig_len & 0xf;
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
  if (__n != 0) {
    memcpy(local_30,last_block,__n);
  }
  padding_block[__n - 4] = 0x80;
  iVar3 = 6;
  if (orig_len < 0x2000) {
    iVar3 = 2;
  }
  if (0x10 < __n + 1 + iVar3) {
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
  if (iVar3 == 2) {
    uVar1 = (ushort)(byte)((orig_len << 0x13) >> 0x18) | (ushort)(orig_len << 0xb);
    padding_block[10] = (char)uVar1;
    padding_block[0xb] = (char)(uVar1 >> 8);
  }
  else {
    uVar1 = (ushort)((orig_len << 0x1b) >> 0x10) | (ushort)(((orig_len & 0x1fe0) << 0xb) >> 0x10);
    uVar2 = (ushort)((orig_len << 3) >> 8) & 0xff00 | (ushort)(byte)((orig_len << 3) >> 0x18);
    padding_block[6] = (char)uVar2;
    padding_block[7] = (char)(uVar2 >> 8);
    padding_block[8] = (char)uVar1;
    padding_block[9] = (char)(uVar1 >> 8);
  }
  aes_mmo_hash_core(local_30,hash);
  return;
}

