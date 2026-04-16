/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void af_data_indication_handler(af_data_ind_t *ind)

{
  uint16_t uVar1;
  
  if ((ind == (af_data_ind_t *)0x0) || ((ind->addr_info).dst_ep == 0xff)) {
    __assert_func("//build/esp-zigbee/src/core/af/af_core.c",0x72,"af_data_indication_handler",
                  "ind && ind->addr_info.dst_ep != 0xFFU");
  }
  else {
    uVar1 = (ind->addr_info).profile_id;
    if ((uVar1 != 0x104) && (uVar1 != 0xc05e)) {
      if (uVar1 == 0) {
        zdo_indication_handler();
      }
      goto _L0;
    }
  }
  zcl_indication_handler(ind);
_L0:
  zmsg_free(ind->asdu);
  return;
}

