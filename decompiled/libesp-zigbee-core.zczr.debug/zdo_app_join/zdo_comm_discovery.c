/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_comm_discovery(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uStack_15;
  uint auStack_14 [2];
  
  iVar2 = core_globals_get();
  auStack_14[0] = *(uint *)(iVar2 + 8);
  uStack_15 = 3;
  iVar2 = core_globals_get();
  uVar1 = *(uint *)(iVar2 + 0xcdc);
  uVar3 = nwk_is_device_zed();
  zdo_comm_get_scan_duration(&uStack_15);
  zdo_comm_get_channel_mask(auStack_14);
  iVar2 = core_globals_get();
  auStack_14[0] =
       auStack_14[0] & 0xf8000000 | auStack_14[0] & 0x7ffffff & *(uint *)(iVar2 + 8) & 0x7ffffff;
  nwk_network_discovery(uStack_15,uVar1 & 1 ^ 1,uVar3);
  return;
}

