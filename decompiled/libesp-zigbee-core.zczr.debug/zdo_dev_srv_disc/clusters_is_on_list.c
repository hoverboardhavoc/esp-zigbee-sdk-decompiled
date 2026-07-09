/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> clusters_is_on_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 clusters_is_on_list(int param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (param_2 <= uVar2) {
      return 0;
    }
    for (uVar1 = 0; uVar1 < param_4; uVar1 = uVar1 + 1 & 0xff) {
      if (*(short *)(uVar2 * 2 + param_1) == *(short *)(uVar1 * 2 + param_3)) {
        return 1;
      }
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while( true );
}

