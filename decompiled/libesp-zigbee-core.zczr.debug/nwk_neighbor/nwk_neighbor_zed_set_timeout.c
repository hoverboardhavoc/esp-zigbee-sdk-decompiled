/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_zed_set_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_neighbor_zed_set_timeout(nwk_neighbor_t *nbr,uint8_t timeout)

{
  undefined3 in_register_0000202d;
  uint uVar1;
  
  if (((*(uint *)&nbr->field_0xc & 3) == 2) || ((*(uint *)&nbr->field_0xc & 0x3c0) == 0)) {
    *(uint *)((int)&nbr->dev + 4) =
         *(uint *)((int)&nbr->dev + 4) & 0xff0fffff | (timeout & 0xf) << 0x14;
    if (CONCAT31(in_register_0000202d,timeout) != 0) {
      uVar1 = 0x3c << (timeout & 0x1f);
      goto _L0;
    }
  }
  else {
    nbr = (nwk_neighbor_t *)
          __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0xab,
                        "nwk_neighbor_zed_set_timeout",0x1082c);
  }
  uVar1 = 10;
_L0:
  *(uint *)((int)&nbr->dev + 4) = *(uint *)((int)&nbr->dev + 4) & 0xfff00000 | uVar1 & 0xfffff;
  return;
}

