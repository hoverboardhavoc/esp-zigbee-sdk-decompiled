/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> multimac_154_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void multimac_154_deinit(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (s_devices != (mac_device *)0x0) {
    uVar5 = (uint)s_device_nr;
    iVar4 = (int)s_devices + uVar5 * -8;
    for (uVar1 = 0; uVar1 < uVar5; uVar1 = uVar1 + 1 & 0xff) {
      piVar2 = (int *)(uVar1 * 8 + iVar4);
      iVar3 = nwk_mm_unregister_interface(*(undefined1 *)(*piVar2 + 0x2c));
      if (iVar3 != 0) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x744,
                      "multimac_154_deinit",0x12b88);
        break;
      }
      mac_deinit((mac_device *)*piVar2);
    }
    mm_free(iVar4);
    s_device_nr = '\0';
    s_devices = (mac_device *)0x0;
  }
  return;
}

