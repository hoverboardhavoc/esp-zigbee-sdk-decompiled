/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_comm_discovery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_comm_discovery(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  ezb_err_t eVar4;
  uint8_t uStack_15;
  uint uStack_14;
  uint8_t scan_duration;
  channel_page_t scan_channels;
  
  iVar2 = core_globals_get();
  uStack_14 = *(uint *)(iVar2 + 8);
  uStack_15 = '\x03';
  iVar2 = core_globals_get();
  uVar1 = *(uint *)(iVar2 + 0xd40);
  uVar3 = nwk_is_device_zed();
  zdo_comm_get_scan_duration(&uStack_15);
  zdo_comm_get_channel_mask(&stack0xffffffec);
  iVar2 = core_globals_get();
  uStack_14 = uStack_14 & 0xf8000000 | uStack_14 & 0x7ffffff & *(uint *)(iVar2 + 8) & 0x7ffffff;
  eVar4 = nwk_network_discovery(uStack_15,uVar1 & 1 ^ 1,uVar3);
  return eVar4;
}

