/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
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
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  byte bVar11;
  
  iVar6 = core_globals_get();
  *(undefined1 *)(iVar6 + 0xa3f) = 0;
  *(byte *)(iVar6 + 0xa40) = *(byte *)(iVar6 + 0xa40) & 0xf0 | 2;
  *(undefined1 *)(iVar6 + 0xa40) = 0x22;
  iVar7 = core_globals_get();
  bVar11 = *(byte *)(iVar6 + 0xa41) & 0x87;
  bVar4 = (byte)((*(byte *)(iVar7 + 0xa3c) & 0xf) << 3);
  *(byte *)(iVar6 + 0xa41) = bVar11 | bVar4;
  *(byte *)(iVar6 + 0xa41) = bVar11 | bVar4 | 4;
  uVar8 = nwk_neighbor_table_get_ed_num();
  uVar9 = nwk_neighbor_table_get_ed_capacity();
  if (uVar8 < uVar9) {
    uVar8 = nwk_neighbor_table_get_ed_num();
    iVar7 = core_globals_get();
    if (uVar8 < *(byte *)(iVar7 + 0x9db)) {
      iVar7 = 1;
    }
    else {
      iVar7 = 0;
    }
  }
  else {
    iVar7 = 0;
  }
  *(byte *)(iVar6 + 0xa41) = *(byte *)(iVar6 + 0xa41) & 0x7f | (byte)(iVar7 << 7);
  puVar10 = (undefined4 *)nwk_get_extended_panid();
  uVar1 = *puVar10;
  uVar2 = *(undefined3 *)(puVar10 + 1);
  uVar3 = puVar10[1];
  *(char *)(iVar6 + 0xa42) = (char)*(undefined3 *)puVar10;
  *(char *)(iVar6 + 0xa43) = (char)((uint)uVar1 >> 8);
  *(char *)(iVar6 + 0xa44) = (char)((uint)uVar1 >> 0x10);
  *(char *)(iVar6 + 0xa45) = (char)((uint)uVar1 >> 0x18);
  *(char *)(iVar6 + 0xa46) = (char)uVar2;
  *(char *)(iVar6 + 0xa47) = (char)((uint)uVar3 >> 8);
  *(char *)(iVar6 + 0xa48) = (char)((uint)uVar3 >> 0x10);
  *(char *)(iVar6 + 0xa49) = (char)((uint)uVar3 >> 0x18);
  *(undefined1 *)(iVar6 + 0xa4a) = 0xff;
  *(undefined1 *)(iVar6 + 0xa4b) = 0xff;
  *(undefined1 *)(iVar6 + 0xa4c) = 0xff;
  uVar5 = nwk_get_update_id();
  *(undefined1 *)(iVar6 + 0xa4d) = uVar5;
  return;
}

