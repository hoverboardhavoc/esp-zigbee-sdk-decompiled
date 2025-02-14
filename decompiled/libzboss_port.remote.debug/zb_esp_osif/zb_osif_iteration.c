/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_osif.o -> zb_osif_iteration
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_osif_iteration(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 extraout_a1;
  
  if (param_1 == 0) {
    uVar1 = 0;
    uVar2 = 0;
  }
  else {
    uVar1 = zb_osif_calc_blocking_time();
    uVar2 = extraout_a1;
  }
  zb_osif_iteration_process(uVar1,uVar2);
  return;
}

