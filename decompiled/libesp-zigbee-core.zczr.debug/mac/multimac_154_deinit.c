/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> multimac_154_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void multimac_154_deinit(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (s_devices != 0) {
    uVar5 = (uint)s_device_nr;
    iVar4 = s_devices + uVar5 * -8;
    for (uVar1 = 0; uVar1 < uVar5; uVar1 = uVar1 + 1 & 0xff) {
      piVar2 = (int *)(uVar1 * 8 + iVar4);
      iVar3 = nwk_mm_unregister_interface(*(undefined1 *)(*piVar2 + 0x2c));
      if (iVar3 != 0) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x795,
                      "multimac_154_deinit",0x12dac);
        break;
      }
      mac_deinit(*piVar2);
    }
    mm_free(iVar4);
    s_device_nr = 0;
    s_devices = 0;
  }
  return;
}

