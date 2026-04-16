/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> random.o -> random_noncrypto_fill_buffer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void random_noncrypto_fill_buffer(uint8_t *buffer,uint16_t size)

{
  uint32_t uVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  
  uVar2 = CONCAT22(in_register_0000202e,size);
  while (uVar2 != 0) {
    uVar1 = random_noncrypto_get_u32();
    *buffer = (uint8_t)uVar1;
    buffer = buffer + 1;
    uVar2 = uVar2 - 1 & 0xffff;
  }
  return;
}

