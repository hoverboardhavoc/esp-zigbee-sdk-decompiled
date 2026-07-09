/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> multimac_154_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void multimac_154_deinit(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  if (s_devices != 0) {
    uVar5 = (uint)s_device_nr;
    piVar1 = (int *)(s_devices + uVar5 * -8);
    piVar4 = piVar1;
    for (uVar2 = 0; uVar2 != uVar5; uVar2 = uVar2 + 1 & 0xff) {
      iVar3 = nwk_mm_unregister_interface(*(undefined1 *)(*piVar4 + 0x2c));
      if (iVar3 != 0) {
        __assert_func(0,0,0,0);
      }
      mac_set_enabled(*piVar4,0);
      mac_pal_deinit();
      piVar4 = piVar4 + 2;
      random_deinit();
    }
    mm_free(piVar1);
    s_device_nr = 0;
    s_devices = 0;
  }
  return;
}

