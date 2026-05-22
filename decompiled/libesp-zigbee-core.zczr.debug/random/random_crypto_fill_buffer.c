/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    random_noncrypto_range_u32(0,(uVar3 & 0xffff) + 1);
  }
  return;
}

