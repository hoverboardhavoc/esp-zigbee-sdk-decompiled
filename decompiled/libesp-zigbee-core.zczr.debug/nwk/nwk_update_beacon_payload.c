/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_update_beacon_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_update_beacon_payload(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ezb_extpanid_t *peVar9;
  
  iVar5 = core_globals_get();
  *(undefined1 *)(iVar5 + 0xa3f) = 0;
  *(byte *)(iVar5 + 0xa40) = *(byte *)(iVar5 + 0xa40) & 0xf0 | 2;
  *(undefined1 *)(iVar5 + 0xa40) = 0x22;
  uVar6 = nwk_neighbor_table_get_router_num();
  uVar7 = nwk_neighbor_table_get_router_capacity();
  *(byte *)(iVar5 + 0xa41) = *(byte *)(iVar5 + 0xa41) & 0xfb | (uVar6 < uVar7) << 2;
  iVar8 = core_globals_get();
  *(byte *)(iVar5 + 0xa41) =
       *(byte *)(iVar5 + 0xa41) & 0x87 | (byte)((*(byte *)(iVar8 + 0xa3c) & 0xf) << 3);
  uVar6 = nwk_neighbor_table_get_ed_num();
  uVar7 = nwk_neighbor_table_get_ed_capacity();
  *(byte *)(iVar5 + 0xa41) = *(byte *)(iVar5 + 0xa41) & 0x7f | (uVar6 < uVar7) << 7;
  peVar9 = nwk_get_extended_panid();
  uVar2 = *(undefined4 *)&peVar9->field_0;
  puVar1 = (undefined4 *)((int)&peVar9->field_0 + 4);
  uVar3 = *(undefined3 *)puVar1;
  uVar4 = *puVar1;
  *(char *)(iVar5 + 0xa42) = (char)*(undefined3 *)&peVar9->field_0;
  *(char *)(iVar5 + 0xa43) = (char)((uint)uVar2 >> 8);
  *(char *)(iVar5 + 0xa44) = (char)((uint)uVar2 >> 0x10);
  *(char *)(iVar5 + 0xa45) = (char)((uint)uVar2 >> 0x18);
  *(char *)(iVar5 + 0xa46) = (char)uVar3;
  *(char *)(iVar5 + 0xa47) = (char)((uint)uVar4 >> 8);
  *(char *)(iVar5 + 0xa48) = (char)((uint)uVar4 >> 0x10);
  *(char *)(iVar5 + 0xa49) = (char)((uint)uVar4 >> 0x18);
  *(undefined1 *)(iVar5 + 0xa4a) = 0xff;
  *(undefined1 *)(iVar5 + 0xa4b) = 0xff;
  *(undefined1 *)(iVar5 + 0xa4c) = 0xff;
  iVar8 = core_globals_get();
  *(undefined1 *)(iVar5 + 0xa4d) = *(undefined1 *)(iVar8 + 0x9df);
  return;
}

