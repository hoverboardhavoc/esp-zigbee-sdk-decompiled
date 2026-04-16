/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> random.o -> random_add_jitter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t random_add_jitter(uint32_t value,uint16_t jitter)

{
  uint32_t uVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  
  if (value != 0xffffffff) {
    uVar2 = CONCAT22(in_register_0000202e,jitter);
    if (~value < CONCAT22(in_register_0000202e,jitter)) {
      uVar2 = ~value;
    }
    uVar2 = uVar2 & 0xffff;
    if (0xfffe < uVar2) {
      uVar2 = 0xfffffffe;
    }
    uVar1 = random_noncrypto_range_u32(0,(uVar2 & 0xffff) + 1);
    value = uVar1 + value;
  }
  return value;
}

