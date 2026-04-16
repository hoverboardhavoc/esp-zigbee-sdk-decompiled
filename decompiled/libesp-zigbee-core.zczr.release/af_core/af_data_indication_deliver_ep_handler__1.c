/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> af_data_indication_deliver_ep_handler__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void af_data_indication_deliver_ep_handler(void *arg)

{
  af_data_ind_t *extraout_a0;
  
  if (arg == (void *)0x0) {
    af_data_indication_deliver_ep_handler((void *)0x0);
    arg = extraout_a0;
  }
  af_data_indication_handler((af_data_ind_t *)arg);
  mm_free(arg);
  return;
}

