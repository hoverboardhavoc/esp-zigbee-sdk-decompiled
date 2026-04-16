/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_intrp_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void af_intrp_data_indication(af_intrp_data_ind_t *ind)

{
  if (ind == (af_intrp_data_ind_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/af/af_core.c",0x109,"af_intrp_data_indication",
                  0x102d0);
  }
  else if (ind->profile_id != 0xc05e) goto _L0;
  zcl_intrp_indication_handler();
_L0:
  zmsg_free(ind->asdu);
  return;
}

