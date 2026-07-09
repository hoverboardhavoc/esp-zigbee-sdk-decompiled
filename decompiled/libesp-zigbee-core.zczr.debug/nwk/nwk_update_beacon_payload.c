/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_update_beacon_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_update_beacon_payload(void)

{
  undefined4 uVar1;
  undefined3 uVar2;
  undefined4 uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  byte bVar10;
  
  iVar5 = core_globals_get();
  *(undefined1 *)(iVar5 + 0xa3f) = 0;
  *(byte *)(iVar5 + 0xa40) = *(byte *)(iVar5 + 0xa40) & 0xf0 | 2;
  *(undefined1 *)(iVar5 + 0xa40) = 0x22;
  iVar6 = core_globals_get();
  bVar10 = *(byte *)(iVar5 + 0xa41) & 0x87;
  bVar4 = (byte)((*(byte *)(iVar6 + 0xa3c) & 0xf) << 3);
  *(byte *)(iVar5 + 0xa41) = bVar10 | bVar4;
  *(byte *)(iVar5 + 0xa41) = bVar10 | bVar4 | 4;
  uVar7 = nwk_neighbor_table_get_ed_num();
  uVar8 = nwk_neighbor_table_get_ed_capacity();
  if (uVar7 < uVar8) {
    uVar7 = nwk_neighbor_table_get_ed_num();
    iVar6 = core_globals_get();
    if (uVar7 < *(byte *)(iVar6 + 0x9db)) {
      iVar6 = 1;
    }
    else {
      iVar6 = 0;
    }
  }
  else {
    iVar6 = 0;
  }
  *(byte *)(iVar5 + 0xa41) = *(byte *)(iVar5 + 0xa41) & 0x7f | (byte)(iVar6 << 7);
  puVar9 = (undefined4 *)nwk_get_extended_panid();
  uVar1 = *puVar9;
  uVar2 = *(undefined3 *)(puVar9 + 1);
  uVar3 = puVar9[1];
  *(char *)(iVar5 + 0xa42) = (char)*(undefined3 *)puVar9;
  *(char *)(iVar5 + 0xa43) = (char)((uint)uVar1 >> 8);
  *(char *)(iVar5 + 0xa44) = (char)((uint)uVar1 >> 0x10);
  *(char *)(iVar5 + 0xa45) = (char)((uint)uVar1 >> 0x18);
  *(char *)(iVar5 + 0xa46) = (char)uVar2;
  *(char *)(iVar5 + 0xa47) = (char)((uint)uVar3 >> 8);
  *(char *)(iVar5 + 0xa48) = (char)((uint)uVar3 >> 0x10);
  *(char *)(iVar5 + 0xa49) = (char)((uint)uVar3 >> 0x18);
  *(undefined1 *)(iVar5 + 0xa4a) = 0xff;
  *(undefined1 *)(iVar5 + 0xa4b) = 0xff;
  *(undefined1 *)(iVar5 + 0xa4c) = 0xff;
  iVar6 = core_globals_get();
  *(undefined1 *)(iVar5 + 0xa4d) = *(undefined1 *)(iVar6 + 0x9df);
  return;
}

