/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> random.o -> random_crypto_fill_buffer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint random_crypto_fill_buffer(void)

{
  int iVar1;
  uint uVar2;
  uint extraout_a1;
  uint uVar3;
  
  iVar1 = ezb_plat_crypto_random_get();
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/random.c",0x82,
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
    iVar1 = random_noncrypto_range_u32(0,(uVar3 & 0xffff) + 1);
    uVar2 = iVar1 + uVar2;
  }
  return uVar2;
}

