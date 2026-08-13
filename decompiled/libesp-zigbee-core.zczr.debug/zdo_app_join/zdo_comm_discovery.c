/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_comm_discovery(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uStack_15;
  uint auStack_14 [2];
  
  iVar3 = core_globals_get();
  auStack_14[0] = *(uint *)(iVar3 + 8);
  uStack_15 = 3;
  iVar3 = core_globals_get();
  uVar1 = *(uint *)(iVar3 + 0xcdc);
  iVar3 = core_globals_get();
  if ((*(uint *)(iVar3 + 0xcdc) & 1) == 0) {
    iVar3 = nwk_is_device_zed();
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  zdo_comm_get_scan_duration(&uStack_15);
  zdo_comm_get_channel_mask(auStack_14);
  iVar3 = core_globals_get();
  auStack_14[0] =
       auStack_14[0] & 0xf8000000 | auStack_14[0] & 0x7ffffff & *(uint *)(iVar3 + 8) & 0x7ffffff;
  nwk_network_discovery(uStack_15,uVar1 & 1 ^ 1,uVar2);
  return;
}

