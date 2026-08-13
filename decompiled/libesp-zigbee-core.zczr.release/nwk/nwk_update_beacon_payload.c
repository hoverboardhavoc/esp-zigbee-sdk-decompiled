/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_update_beacon_payload
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
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar5 = core_globals_get();
  *(undefined1 *)(iVar5 + 0xa40) = 0x22;
  *(undefined1 *)(iVar5 + 0xa3f) = 0;
  iVar6 = core_globals_get();
  *(byte *)(iVar5 + 0xa41) =
       (byte)((*(byte *)(iVar6 + 0xa3c) & 0xf) << 3) | 4 | *(byte *)(iVar5 + 0xa41) & 0x83;
  uVar7 = nwk_neighbor_table_get_ed_num();
  uVar8 = nwk_neighbor_table_get_ed_capacity();
  uVar9 = 0;
  if (uVar7 < uVar8) {
    uVar7 = nwk_neighbor_table_get_ed_num();
    iVar6 = core_globals_get();
    uVar9 = (uint)(uVar7 < *(byte *)(iVar6 + 0x9db));
  }
  *(byte *)(iVar5 + 0xa41) = (byte)(uVar9 << 7) | *(byte *)(iVar5 + 0xa41) & 0x7f;
  iVar6 = core_globals_get();
  uVar1 = *(undefined4 *)(iVar6 + 0x9ef);
  uVar2 = *(undefined3 *)(iVar6 + 0x9f3);
  uVar3 = *(undefined4 *)(iVar6 + 0x9f3);
  *(char *)(iVar5 + 0xa42) = (char)*(undefined3 *)(iVar6 + 0x9ef);
  *(char *)(iVar5 + 0xa43) = (char)((uint)uVar1 >> 8);
  *(char *)(iVar5 + 0xa45) = (char)((uint)uVar1 >> 0x18);
  *(char *)(iVar5 + 0xa47) = (char)((uint)uVar3 >> 8);
  *(char *)(iVar5 + 0xa49) = (char)((uint)uVar3 >> 0x18);
  *(char *)(iVar5 + 0xa44) = (char)((uint)uVar1 >> 0x10);
  *(char *)(iVar5 + 0xa46) = (char)uVar2;
  *(char *)(iVar5 + 0xa48) = (char)((uint)uVar3 >> 0x10);
  *(undefined1 *)(iVar5 + 0xa4a) = 0xff;
  *(undefined1 *)(iVar5 + 0xa4b) = 0xff;
  *(undefined1 *)(iVar5 + 0xa4c) = 0xff;
  uVar4 = nwk_get_update_id();
  *(undefined1 *)(iVar5 + 0xa4d) = uVar4;
  return;
}

