/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_update_beacon_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_update_beacon_payload(void)

{
  undefined4 uVar1;
  undefined3 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar4 = core_globals_get();
  *(undefined1 *)(iVar4 + 0xa40) = 0x22;
  *(undefined1 *)(iVar4 + 0xa3f) = 0;
  uVar5 = nwk_neighbor_table_get_router_num();
  uVar6 = nwk_neighbor_table_get_router_capacity();
  *(byte *)(iVar4 + 0xa41) = *(byte *)(iVar4 + 0xa41) & 0xfb | (uVar5 < uVar6) << 2;
  iVar7 = core_globals_get();
  *(byte *)(iVar4 + 0xa41) =
       *(byte *)(iVar4 + 0xa41) & 0x87 | (byte)((*(byte *)(iVar7 + 0xa3c) & 0xf) << 3);
  uVar5 = nwk_neighbor_table_get_ed_num();
  uVar6 = nwk_neighbor_table_get_ed_capacity();
  *(byte *)(iVar4 + 0xa41) = *(byte *)(iVar4 + 0xa41) & 0x7f | (uVar5 < uVar6) << 7;
  iVar7 = core_globals_get();
  uVar1 = *(undefined4 *)(iVar7 + 0x9ef);
  uVar2 = *(undefined3 *)(iVar7 + 0x9f3);
  uVar3 = *(undefined4 *)(iVar7 + 0x9f3);
  *(char *)(iVar4 + 0xa42) = (char)*(undefined3 *)(iVar7 + 0x9ef);
  *(char *)(iVar4 + 0xa43) = (char)((uint)uVar1 >> 8);
  *(char *)(iVar4 + 0xa45) = (char)((uint)uVar1 >> 0x18);
  *(char *)(iVar4 + 0xa47) = (char)((uint)uVar3 >> 8);
  *(char *)(iVar4 + 0xa49) = (char)((uint)uVar3 >> 0x18);
  *(undefined1 *)(iVar4 + 0xa4a) = 0xff;
  *(undefined1 *)(iVar4 + 0xa4b) = 0xff;
  *(undefined1 *)(iVar4 + 0xa4c) = 0xff;
  *(char *)(iVar4 + 0xa44) = (char)((uint)uVar1 >> 0x10);
  *(char *)(iVar4 + 0xa46) = (char)uVar2;
  *(char *)(iVar4 + 0xa48) = (char)((uint)uVar3 >> 0x10);
  iVar7 = core_globals_get();
  *(undefined1 *)(iVar4 + 0xa4d) = *(undefined1 *)(iVar7 + 0x9df);
  return;
}

