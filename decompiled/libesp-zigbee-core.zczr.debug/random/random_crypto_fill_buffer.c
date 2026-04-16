/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> random.o -> random_crypto_fill_buffer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void random_crypto_fill_buffer(uint8_t *buffer,uint16_t size)

{
  int iVar1;
  uint uVar2;
  undefined2 in_register_0000202e;
  uint extraout_a1;
  uint uVar3;
  
  iVar1 = ezb_plat_crypto_random_get(CONCAT22(in_register_0000202e,size));
  if (iVar1 == 0) {
    return;
  }
  uVar2 = __assert_func("//build/esp-zigbee/src/core/crypto/random.c",0x82,
                        "random_crypto_fill_buffer",
                        "(ezb_plat_crypto_random_get(buffer, size)) == 0");
  if (uVar2 != 0xffffffff) {
    uVar3 = extraout_a1;
    if (~uVar2 < extraout_a1) {
      uVar3 = ~uVar2;
    }
    uVar3 = uVar3 & 0xffff;
    if (0xfffe < uVar3) {
      uVar3 = 0xfffffffe;
    }
    random_noncrypto_range_u32(0,(uVar3 & 0xffff) + 1);
  }
  return;
}

