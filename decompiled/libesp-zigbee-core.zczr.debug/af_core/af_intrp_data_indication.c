/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_core.c",0x10b,
                  "af_intrp_data_indication",0x102dc);
  }
  else if (ind->profile_id != 0xc05e) goto _L0;
  zcl_intrp_indication_handler();
_L0:
  zmsg_free(ind->asdu);
  return;
}

